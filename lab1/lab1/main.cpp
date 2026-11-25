#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"
#include "plain_methods.h"

// Вспомогательная функция для Записи в CSV. 
// Обрезает Uniform, чтобы файл не весил гигабайты.
void write_log_to_csv(std::ofstream& out, int func_num, const std::string& func_name, 
                      const std::string& interval, double eps, const std::string& method, 
                      const std::vector<IterRow>& log) 
{
    int size = log.size();
    for (int i = 0; i < size; ++i) {
        if (method == "Uniform" && size > 10) {
            if (i >= 5 && i < size - 2) {
                if (i == 5) {
                    out << func_num << "," << func_name << "," << interval << "," << eps 
                        << ",...(скрыто " << size - 7 << " итераций)...,,,,\n";
                }
                continue;
            }
        }
        
        const auto& r = log[i];
        out << func_num << ","
            << func_name << ","
            << interval << ","
            << eps << ","
            << method << ","
            << r.xk << ","
            << r.xk1 << ","
            << r.fxk << ","
            << r.fxk1 << ","
            << r.d << "\n";
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(8);
    const double eps = 1e-6;

    // =========================================================================
    // TASK 1: ВЫВОД РЕЗУЛЬТАТОВ В КОНСОЛЬ
    // =========================================================================
    std::cout << "=== TASK 1: EXTREMA RESULTS ===\n\n";

    std::cout << "Uniform:\n";
    double x9  = min_uniform_search(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9);
    double x13 = min_uniform_search(0.0, 4.0, eps, foo13);
    double x17 = min_uniform_search(-3.0, 0.0, eps, nfoo17);
    double x19 = min_uniform_search(-1.0, 1.0, eps, foo19);
    double x32 = min_uniform_search(-3.0, -1.0, eps, foo32);
    double x51 = min_uniform_search(-0.5, 2.0, eps, foo51);
    std::cout << "foo9:  x = " << x9  << " f(x) = " << foo9(x9)   << '\n';
    std::cout << "foo13: x = " << x13 << " f(x) = " << foo13(x13) << '\n';
    std::cout << "foo17: x = " << x17 << " f(x) = " << foo17(x17) << '\n';
    std::cout << "foo19: x = " << x19 << " f(x) = " << foo19(x19) << '\n';
    std::cout << "foo32: x = " << x32 << " f(x) = " << foo32(x32) << '\n';
    std::cout << "foo51: x = " << x51 << " f(x) = " << foo51(x51) << '\n';

    std::cout << "Localization:\n";
    x9  = min_local(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9);
    x13 = min_local(0.0, 4.0, eps, foo13);
    x17 = min_local(-3.0, 0.0, eps, nfoo17);
    x19 = min_local(-1.0, 1.0, eps, foo19);
    x32 = min_local(-3.0, -1.0, eps, foo32);
    x51 = min_local(-0.5, 2.0, eps, foo51);
    std::cout << "foo9:  x = " << x9  << " f(x) = " << foo9(x9)   << '\n';
    std::cout << "foo13: x = " << x13 << " f(x) = " << foo13(x13) << '\n';
    std::cout << "foo17: x = " << x17 << " f(x) = " << foo17(x17) << '\n';
    std::cout << "foo19: x = " << x19 << " f(x) = " << foo19(x19) << '\n';
    std::cout << "foo32: x = " << x32 << " f(x) = " << foo32(x32) << '\n';
    std::cout << "foo51: x = " << x51 << " f(x) = " << foo51(x51) << '\n';

    std::cout << "Dichotomy:\n";
    x9  = min_dihotomia(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9);
    x13 = min_dihotomia(0.0, 4.0, eps, foo13);
    x17 = min_dihotomia(-3.0, 0.0, eps, nfoo17);
    x19 = min_dihotomia(-1.0, 1.0, eps, foo19);
    x32 = min_dihotomia(-3.0, -1.0, eps, foo32);
    x51 = min_dihotomia(-0.5, 2.0, eps, foo51);
    std::cout << "foo9:  x = " << x9  << " f(x) = " << foo9(x9)   << '\n';
    std::cout << "foo13: x = " << x13 << " f(x) = " << foo13(x13) << '\n';
    std::cout << "foo17: x = " << x17 << " f(x) = " << foo17(x17) << '\n';
    std::cout << "foo19: x = " << x19 << " f(x) = " << foo19(x19) << '\n';
    std::cout << "foo32: x = " << x32 << " f(x) = " << foo32(x32) << '\n';
    std::cout << "foo51: x = " << x51 << " f(x) = " << foo51(x51) << '\n';

    std::cout << "Golden ratio:\n";
    x9  = min_golden_ration(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9);
    x13 = min_golden_ration(0.0, 4.0, eps, foo13);
    x17 = min_golden_ration(-3.0, 0.0, eps, nfoo17);
    x19 = min_golden_ration(-1.0, 1.0, eps, foo19);
    x32 = min_golden_ration(-3.0, -1.0, eps, foo32);
    x51 = min_golden_ration(-0.5, 2.0, eps, foo51);
    std::cout << "foo9:  x = " << x9  << " f(x) = " << foo9(x9)   << '\n';
    std::cout << "foo13: x = " << x13 << " f(x) = " << foo13(x13) << '\n';
    std::cout << "foo17: x = " << x17 << " f(x) = " << foo17(x17) << '\n';
    std::cout << "foo19: x = " << x19 << " f(x) = " << foo19(x19) << '\n';
    std::cout << "foo32: x = " << x32 << " f(x) = " << foo32(x32) << '\n';
    std::cout << "foo51: x = " << x51 << " f(x) = " << foo51(x51) << '\n';

    std::cout << "Fibonacci:\n";
    x9  = min_fibonacci(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9);
    x13 = min_fibonacci(0.0, 4.0, eps, foo13);
    x17 = min_fibonacci(-3.0, 0.0, eps, nfoo17);
    x19 = min_fibonacci(-1.0, 1.0, eps, foo19);
    x32 = min_fibonacci(-3.0, -1.0, eps, foo32);
    x51 = min_fibonacci(-0.5, 2.0, eps, foo51);
    std::cout << "foo9:  x = " << x9  << " f(x) = " << foo9(x9)   << '\n';
    std::cout << "foo13: x = " << x13 << " f(x) = " << foo13(x13) << '\n';
    std::cout << "foo17: x = " << x17 << " f(x) = " << foo17(x17) << '\n';
    std::cout << "foo19: x = " << x19 << " f(x) = " << foo19(x19) << '\n';
    std::cout << "foo32: x = " << x32 << " f(x) = " << foo32(x32) << '\n';
    std::cout << "foo51: x = " << x51 << " f(x) = " << foo51(x51) << '\n';

    // =========================================================================
    // TASK 2: ЗАПИСЬ ВСЕХ ТАБЛИЦ ИТЕРАЦИЙ В ОДИН CSV
    // =========================================================================
    std::cout << "\n=== TASK 2: SAVING ITERATIONS TO iterations_tables.csv ===\n";
    std::ofstream out("iterations_tables.csv", std::ios::out | std::ios::trunc);
    out << "function_number,function,interval,epsilon,method,x_k,x_k1,f_x_k,f_x_k1,d\n";

    std::vector<IterRow> log;

    // 9
    log.clear(); min_uniform_search(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9, &log); write_log_to_csv(out, 9, "cos(x)", "[pi/2; 3pi/2]", eps, "Uniform", log);
    log.clear(); min_local(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9, &log); write_log_to_csv(out, 9, "cos(x)", "[pi/2; 3pi/2]", eps, "Localization", log);
    log.clear(); min_dihotomia(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9, &log); write_log_to_csv(out, 9, "cos(x)", "[pi/2; 3pi/2]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9, &log); write_log_to_csv(out, 9, "cos(x)", "[pi/2; 3pi/2]", eps, "Golden", log);
    log.clear(); min_fibonacci(std::numbers::pi / 2, 3 * std::numbers::pi / 2, eps, foo9, &log); write_log_to_csv(out, 9, "cos(x)", "[pi/2; 3pi/2]", eps, "Fibonacci", log);

    // 13
    log.clear(); min_uniform_search(0.0, 4.0, eps, foo13, &log); write_log_to_csv(out, 13, "x^5-5*x^3", "[0.0; 4.0]", eps, "Uniform", log);
    log.clear(); min_local(0.0, 4.0, eps, foo13, &log); write_log_to_csv(out, 13, "x^5-5*x^3", "[0.0; 4.0]", eps, "Localization", log);
    log.clear(); min_dihotomia(0.0, 4.0, eps, foo13, &log); write_log_to_csv(out, 13, "x^5-5*x^3", "[0.0; 4.0]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(0.0, 4.0, eps, foo13, &log); write_log_to_csv(out, 13, "x^5-5*x^3", "[0.0; 4.0]", eps, "Golden", log);
    log.clear(); min_fibonacci(0.0, 4.0, eps, foo13, &log); write_log_to_csv(out, 13, "x^5-5*x^3", "[0.0; 4.0]", eps, "Fibonacci", log);

    // 17
    log.clear(); min_uniform_search(-3.0, 0.0, eps, nfoo17, &log); write_log_to_csv(out, 17, "x^3-9*x", "[-3.0; 0.0]", eps, "Uniform", log);
    log.clear(); min_local(-3.0, 0.0, eps, nfoo17, &log); write_log_to_csv(out, 17, "x^3-9*x", "[-3.0; 0.0]", eps, "Localization", log);
    log.clear(); min_dihotomia(-3.0, 0.0, eps, nfoo17, &log); write_log_to_csv(out, 17, "x^3-9*x", "[-3.0; 0.0]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(-3.0, 0.0, eps, nfoo17, &log); write_log_to_csv(out, 17, "x^3-9*x", "[-3.0; 0.0]", eps, "Golden", log);
    log.clear(); min_fibonacci(-3.0, 0.0, eps, nfoo17, &log); write_log_to_csv(out, 17, "x^3-9*x", "[-3.0; 0.0]", eps, "Fibonacci", log);

    // 19
    log.clear(); min_uniform_search(-1.0, 1.0, eps, foo19, &log); write_log_to_csv(out, 19, "x^3+9*x", "[-1.0; 1.0]", eps, "Uniform", log);
    log.clear(); min_local(-1.0, 1.0, eps, foo19, &log); write_log_to_csv(out, 19, "x^3+9*x", "[-1.0; 1.0]", eps, "Localization", log);
    log.clear(); min_dihotomia(-1.0, 1.0, eps, foo19, &log); write_log_to_csv(out, 19, "x^3+9*x", "[-1.0; 1.0]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(-1.0, 1.0, eps, foo19, &log); write_log_to_csv(out, 19, "x^3+9*x", "[-1.0; 1.0]", eps, "Golden", log);
    log.clear(); min_fibonacci(-1.0, 1.0, eps, foo19, &log); write_log_to_csv(out, 19, "x^3+9*x", "[-1.0; 1.0]", eps, "Fibonacci", log);

    // 32
    log.clear(); min_uniform_search(-3.0, -1.0, eps, foo32, &log); write_log_to_csv(out, 32, "cos(x)*(x^2-5)", "[-3.0; -1.0]", eps, "Uniform", log);
    log.clear(); min_local(-3.0, -1.0, eps, foo32, &log); write_log_to_csv(out, 32, "cos(x)*(x^2-5)", "[-3.0; -1.0]", eps, "Localization", log);
    log.clear(); min_dihotomia(-3.0, -1.0, eps, foo32, &log); write_log_to_csv(out, 32, "cos(x)*(x^2-5)", "[-3.0; -1.0]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(-3.0, -1.0, eps, foo32, &log); write_log_to_csv(out, 32, "cos(x)*(x^2-5)", "[-3.0; -1.0]", eps, "Golden", log);
    log.clear(); min_fibonacci(-3.0, -1.0, eps, foo32, &log); write_log_to_csv(out, 32, "cos(x)*(x^2-5)", "[-3.0; -1.0]", eps, "Fibonacci", log);

    // 51
    log.clear(); min_uniform_search(-0.5, 2.0, eps, foo51, &log); write_log_to_csv(out, 51, "(3*x^2+2*x)*arctg(x)", "[-0.5; 2.0]", eps, "Uniform", log);
    log.clear(); min_local(-0.5, 2.0, eps, foo51, &log); write_log_to_csv(out, 51, "(3*x^2+2*x)*arctg(x)", "[-0.5; 2.0]", eps, "Localization", log);
    log.clear(); min_dihotomia(-0.5, 2.0, eps, foo51, &log); write_log_to_csv(out, 51, "(3*x^2+2*x)*arctg(x)", "[-0.5; 2.0]", eps, "Dichotomy", log);
    log.clear(); min_golden_ration(-0.5, 2.0, eps, foo51, &log); write_log_to_csv(out, 51, "(3*x^2+2*x)*arctg(x)", "[-0.5; 2.0]", eps, "Golden", log);
    log.clear(); min_fibonacci(-0.5, 2.0, eps, foo51, &log); write_log_to_csv(out, 51, "(3*x^2+2*x)*arctg(x)", "[-0.5; 2.0]", eps, "Fibonacci", log);

    out.close();
    std::cout << "Saved successfully.\n";

    // =========================================================================
    // TASK 3: ДАННЫЕ ДЛЯ ГРАФИКОВ n(h)
    // =========================================================================
    std::cout << "\n=== TASK 3: SAVING PLOT DATA ===\n";

    struct FuncInfo { std::string name; double center; double max_h; double (*f)(double); };
    std::vector<FuncInfo> funcs = {
        {"foo9",  std::numbers::pi,  std::numbers::pi,       foo9},
        {"foo13", std::sqrt(3.0),    3.4,                    foo13},
        {"foo17", -std::sqrt(3.0),   3.4,                    nfoo17},
        {"foo19", 0.0,               2.0,                    foo19}, 
        {"foo32", -2.0,              2.0,                    foo32},
        {"foo51", 0.0,               2.5,                    foo51}
    };
    
    const double eps_graph = 1e-3;

    for (const auto& fi : funcs) {
        std::string filename = fi.name + "_deps.csv";
        std::ofstream fout(filename, std::ios::out | std::ios::trunc);
        fout << "\xEF\xBB\xBFh;uniform;local;dih;gold;fib\n";

        for (double h = 0.1; h <= fi.max_h; h += 0.1) {
            double a = fi.center - h / 2.0;
            double b = fi.center + h / 2.0;
            
            if (fi.name == "foo9" && a < 0) a = 0;
            if (fi.name == "foo9" && b > 2*std::numbers::pi) b = 2*std::numbers::pi;
            if (fi.name == "foo13" && a < 0) a = 0;
            if (fi.name == "foo32" && a < -3) a = -3;
            if (fi.name == "foo32" && b > -1) b = -1;

            if (b - a < 1e-5) continue;

            int n_u = 0, n_l = 0, n_d = 0, n_g = 0, n_f = 0;
            min_uniform_search(a, b, eps_graph, fi.f, nullptr, &n_u);
            min_local(a, b, eps_graph, fi.f, nullptr, &n_l);
            min_dihotomia(a, b, eps_graph, fi.f, nullptr, &n_d);
            min_golden_ration(a, b, eps_graph, fi.f, nullptr, &n_g);
            min_fibonacci(a, b, eps_graph, fi.f, nullptr, &n_f);

            fout << h << ";" << n_u << ";" << n_l << ";" << n_d << ";" << n_g << ";" << n_f << "\n";
        }
        fout.close();
        std::cout << "Saved: " << filename << "\n";
    }

    std::cout << "DONE!\n";
    return 0;
}