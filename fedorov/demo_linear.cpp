// MotionGL - OpenGL animation library for classical mechanics labworks
// Copyright (C) 2026 Stanislav Furmavnin (GitHub: saintninja)
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <motiongl/linear_animator.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

namespace {

constexpr double g = 9.8; 
constexpr double kStaticEps = 1e-6;

struct Params {
    double m;   
    double x0;  
    double v0;   
    double f;    
};

double accel(const Params &p, double x, double v) {
    const double F     = 2.0 * x - 2.0 * g;
    const double FsMax = p.f * p.m * g;

    // Условие покоя
    if (std::abs(v) < kStaticEps && std::abs(F) <= FsMax) {
        return 0.0; 
    }
    if (std::abs(v) < kStaticEps) {
        return (F - std::copysign(FsMax, F)) / p.m;
    }
    return (F - p.f * p.m * g * (v > 0.0 ? 1.0 : -1.0)) / p.m;
}

std::vector<std::pair<double,double>> integrate(const Params &p) {
    std::vector<std::pair<double,double>> s;
    const double h = 0.01;
    const double T = 20.0;
    
    double t = 0.0, x = p.x0, v = p.v0;
    s.emplace_back(t, x);

    while (t < T - 1e-12) {

        double k1x = v;
        double k1v = accel(p, x, v);
        
        double k2x = v + 0.5*h*k1v;
        double k2v = accel(p, x + 0.5*h*k1x, v + 0.5*h*k1v);
        
        double k3x = v + 0.5*h*k2v;
        double k3v = accel(p, x + 0.5*h*k2x, v + 0.5*h*k2v);
        
        double k4x = v + h*k3v;
        double k4v = accel(p, x + h*k3x, v + h*k3v);

        x += h/6.0 * (k1x + 2*k2x + 2*k3x + k4x);
        v += h/6.0 * (k1v + 2*k2v + 2*k3v + k4v);
        t += h;

        if (x < 0.0) {
            x = 0.0;
            v = 0.0;
        }
        // -----------------------------

        s.emplace_back(t, x);
    }
    return s;
}

} // namespace

int main(int argc, char **argv) {
    using namespace mgl;

    const int set = (argc > 1) ? std::atoi(argv[1]) : 0;

    Params p{2.0, 1.0, 0.3, 0.3}; // Вариант 5
    std::string label = "variant 5 (base)";
    
    if (set == 1) { p.m *= 2.0; label = "variant 5 (m * 2)";  }
    if (set == 2) { p.v0 *= 2.0; label = "variant 5 (v0 * 2)"; }

    auto samples = integrate(p);

    std::printf("=== %s ===\n", label.c_str());
    std::printf("g = %.2f m/s^2\n", g);
    std::printf("m = %.2f kg | v0 = %.2f m/s | x0 = %.2f m | f = %.2f\n", p.m, p.v0, p.x0, p.f);
    std::printf("x(20) = %.4f m\n\n", samples.back().second);

    LinearAnimator anim = LinearAnimatorBuilder()
        .size(1100, 640)
        .title(label)
        .variant(5)
        .timeScale(1.0)
        .loop(true)
        .build();

    anim.run(samples);
    return 0;
}