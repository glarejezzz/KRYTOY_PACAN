#pragma once
#include <concepts>
#include <type_traits>
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>
#include "functions.h"

struct IterRow {
    int    k;
    double xk, xk1;
    double fxk, fxk1;
    double d;
};

template <typename Function>
concept function_of_x = std::invocable<Function, double> && 
                        std::convertible_to<std::invoke_result_t<Function, double>, double>;

// 1. Равномерный перебор
template <typename Function>
double min_uniform_search(double a, double b, double eps, Function f, 
                          std::vector<IterRow>* log = nullptr, int* iter_count = nullptr) 
requires function_of_x<Function> {
    int n = static_cast<int>((b - a) / eps);
    if (n < 1) n = 1;
    double step = (b - a) / n;
    double xmin = a;
    double fmin = f(a);
    double xprev = a, fprev = fmin;
    
    for (int i = 1; i <= n; ++i) {
        double x = a + i * step;
        double fx = f(x);
        if (log) log->push_back({i - 1, xprev, x, fprev, fx, b - a});
        if (fx < fmin) { fmin = fx; xmin = x; }
        xprev = x; fprev = fx;
    }
    if (f(b) <= fmin) xmin = b;
    if (iter_count) *iter_count = n;
    return xmin;
}

// 2. Локализация
template <typename Function>
double min_local(double a, double b, double eps, Function f, 
                 std::vector<IterRow>* log = nullptr, int* iter_count = nullptr, int* k = nullptr) 
requires function_of_x<Function> {
    static int local_k = 0;
    if (!k) { local_k = 0; k = &local_k; }
    
    if (b - a < 2 * eps) {
        if (iter_count) *iter_count = local_k;
        return (a + b) / 2.0;
    }
    
    double xprev = a, fprev = f(xprev);
    double step = (b - a) / 10.0;
    double xcurrent = xprev + step, fcurrent = f(xcurrent);
    double xnext = xcurrent + step, fnext = f(xnext);
    
    while (fnext < fcurrent && xnext <= b) {
        xprev = xcurrent;
        xcurrent = std::exchange(xnext, xnext + step);
        fprev = std::exchange(fcurrent, fnext);
        fnext = f(xnext);
    }
    
    double new_b = std::min(xnext, b);
    if (log) log->push_back({(*k)++, xcurrent, new_b, fcurrent, fnext, b - a});
    
    return min_local(xprev, new_b, eps, f, log, iter_count, k);
}

// 3. Дихотомия
template <typename Function>
double min_dihotomia(double a, double b, double eps, Function f, 
                     std::vector<IterRow>* log = nullptr, int* iter_count = nullptr) 
requires function_of_x<Function> {
    int k = 0;
    while ((b - a) >= 2 * eps) {
        double xmiddle = (b + a) / 2.0;
        double xleft = (xmiddle + a) / 2.0;
        double xright = (b + xmiddle) / 2.0;
        
        double fmiddle = f(xmiddle);
        double fleft = f(xleft);
        double fright = f(xright);
        
        if (log) log->push_back({k, xleft, xright, fleft, fright, b - a});

        if (fleft < fmiddle) {
            b = xmiddle;
        } else if (fmiddle < fright) {
            a = xleft;
            b = xright;
        } else {
            a = xmiddle;
        }
        k++;
    }
    if (iter_count) *iter_count = k;
    return (a + b) / 2.0;
}

// 4. Золотое сечение
template <typename Function>
double min_golden_ration(double a, double b, double eps, Function f, 
                         std::vector<IterRow>* log = nullptr, int* iter_count = nullptr) 
requires function_of_x<Function> {
    double y = a + (3 - std::sqrt(5)) / 2.0 * (b - a);
    double z = b + a - y;
    double fy = f(y), fz = f(z);
    if (log) log->push_back({0, y, z, fy, fz, b - a});
    int k = 0;
    while ((b - a) > eps) {
        if (fy < fz) {
            b = z; z = y; fz = fy;
            y = a + b - z; fy = f(y);
        } else {
            a = y; y = z; fy = fz;
            z = a + b - y; fz = f(z);
        }
        k++;
        if (log) log->push_back({k, y, z, fy, fz, b - a});
    }
    if (iter_count) *iter_count = k;
    return fy < fz ? y : z;
}

// 5. Фибоначчи
template <typename Function> 
double min_fibonacci(double a, double b, double eps, Function f, 
                     std::vector<IterRow>* log = nullptr, int* iter_count = nullptr)
requires function_of_x<Function> {
    double fib[100];
    fib[0] = 1.0; fib[1] = 1.0;
    int count = 1;
    while (fib[count] < (b - a) / eps && count < 98) {
        count++;
        fib[count] = fib[count - 1] + fib[count - 2];
    }
    double x1 = a + fib[count - 2] / fib[count] * (b - a);
    double x2 = a + fib[count - 1] / fib[count] * (b - a);
    double f1 = f(x1), f2 = f(x2);
    if (log) log->push_back({0, x1, x2, f1, f2, b - a});
    int k = 0;
    for (int i = 1; i < count - 1; i++) {
        if (f1 < f2) {
            b = x2; x2 = x1; f2 = f1;
            x1 = a + fib[count - i - 2] / fib[count - i] * (b - a); f1 = f(x1);
        } else {
            a = x1; x1 = x2; f1 = f2;
            x2 = a + fib[count - i - 1] / fib[count - i] * (b - a); f2 = f(x2);
        }
        k++;
        if (log) log->push_back({k, x1, x2, f1, f2, b - a});
    }
    double result = (a + b) / 2.0;
    if (f(a) < f(result)) result = a;
    if (f(b) < f(result)) result = b;
    if (iter_count) *iter_count = count;
    return result;
}