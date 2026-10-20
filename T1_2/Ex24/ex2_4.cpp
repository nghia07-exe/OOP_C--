#include <iostream>

#include "fraction.h"

int main() {
    std::cout << "        Fracion 1 (print fraction):\n";
    Fraction first_fraction(1, 6);
    first_fraction.Output();

    std::cout << "        Fracion 2 (Get and update):\n";
    Fraction second_fraction(3, 4);
    second_fraction.GetNum();
    second_fraction.SetNum(18);
    second_fraction.GetDenom();
    second_fraction.SetDenom(10);
    second_fraction.Output();

    std::cout << "        Fracion 2 (reduction of fraction):\n";
    Fraction r_second_fraction = second_fraction.Reduce();
    r_second_fraction.Output();

    std::cout << "        Fracion 2 (inverse of fraction):\n";
    Fraction inv_second_fraction = second_fraction.Inverse();
    inv_second_fraction.Output();

    std::cout << "        Fracion 1 ADD fraction 2 (sum of two fractions):\n";
    std::cout << "Faction 1 ";
    first_fraction.Output();
    std::cout << "Faction 2 ";
    second_fraction.Output();
    Fraction sum = first_fraction.Add(second_fraction);
    std::cout << "Sum of two fractions ";
    sum.Output();

    std::cout << "        Fracion 1 ? fraction 2 (compare two fractions):\n";
    first_fraction.Output();
    second_fraction.Output();
    int result = first_fraction.Compare(second_fraction);
    std::cout << "Fracion 1";
    if (result == 0)
        std::cout << " = ";
    else if (result == -1)
        std::cout << " < ";
    else if (result == 1)
        std::cout << " > ";
    else
        std::cout << " ? ";
    std::cout << "Fracion 2\n";

    std::cout << "        Invalid fracion 1:\n";
    Fraction set_zero_denominator(1, 5);
    set_zero_denominator.SetDenom(0);

    std::cout << "        Invalid fracion 2:\n";
    Fraction zero_numerator(0, 2);
    zero_numerator.Inverse();

    std::cout << "        Optinal fracion:\n";
    Fraction opt_frac;
    opt_frac.Input();
    opt_frac.Output();
    //...
    return 0;
}
