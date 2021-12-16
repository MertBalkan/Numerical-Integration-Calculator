/*
    NUMERICAL ANALYSIS WORK CASE - 2

    Name Surname: Mert Balkan
    No: 20253508


    DEFINATON OF WORK CASE HAS BEEN GIVEN DOWN BELOW

         3
        /
        |  x
        | e dx  calculate for n = 30.
        |
        /
       1

        Find integral with;
            a)Left rectangle
            b)Right rectangle
            c)Mid Point
            d)Trapezoid method
            e)Simpson 1/3 method
            f)Simpson 3/8 method
            g)Weddle method
            h)Boole method

         3
        /
        |  x                          3
        | e dx  exact solution is => e - e = 17.3673
        |
        /
       1
*/

#include <iostream>
#include <math.h>
#define N 30

double a = 1; // down value
double b = 3; // up value

double Func(double x);

void LeftRectangle();                // a
void RightRectangle();               // b
void MidPointRule();                 // c
void TrapezoidalMethod();            // d
void SimpsonOneOverThreeFormula();   // e
void SimpsonThreeOverEightFormula(); // f
void WeddleMethod();                 // g
void BooleMethod();                  // h

int main()
{
    std::cout << "integral 1 to 3 e^x dx exact value is equal to: 17.3673" << std::endl;
    std::cout << "\n";

    // LEFT RECTANGLE
    std::cout << "~LEFT RECTANGLE~" << std::endl;
    LeftRectangle();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // RIGHT RECTANGLE
    std::cout << "~RIGHT RECTANGLE~" << std::endl;
    RightRectangle();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // MIDPOINT RULE
    std::cout << "~MIDPOINT RULE~" << std::endl;
    MidPointRule();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // TRAPEZOIDAL METHOD
    std::cout << "~TRAPEZOIDAL METHOD~" << std::endl;
    TrapezoidalMethod();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // SIMPSON 1/3 RULE
    std::cout << "~SIMPSON 1/3 RULE~" << std::endl;
    SimpsonOneOverThreeFormula();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // SIMPSON 3/8 RULE
    std::cout << "~SIMPSON 3/8 RULE~" << std::endl;
    SimpsonThreeOverEightFormula();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // WEDDLE METHOD
    std::cout << "~WEDDLE METHOD~" << std::endl;
    WeddleMethod();

    std::cout << "~------------------------------------------------------~" << std::endl;

    // BOOLE METHOD
    std::cout << "~BOOLE METHOD~" << std::endl;
    BooleMethod();

    return 0;
}

void LeftRectangle()
{

    double sum = 0;
    double x = 0;
    double n = 1;
    double h = 0;
    double ytSum = 0;
    for (int m = 1; m < 2; m++)
    {
        n = m * N;
        h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            x = a + (i - 1) * h;
            sum += Func(x);
        }
    }
    ytSum = h * sum;
    double deviation = ytSum - (Func(3) - Func(1));

    std::cout << "Approximate Value with Left Rectangle For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void RightRectangle()
{
    double sum = 0;
    double x = 0;
    double n = 1;
    double h = 0;
    double ytSum = 0;
    for (int m = 1; m < 2; m++)
    {
        n = m * N;
        h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            x = a + i * h;
            sum += Func(x);
        }
    }
    ytSum = h * sum;
    double deviation = ytSum - (Func(3) - Func(1));

    std::cout << "Approximate Value with Right Rectangle For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void MidPointRule()
{

    double sum = 0;
    double x = 0;
    double n = 1;
    double h = 0;
    double ytSum = 0;
    for (int m = 1; m < 2; m++)
    {
        n = m * N;
        h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            x = a + (i - 0.5) * h;
            sum += Func(x);
        }
    }
    ytSum = h * sum;
    double deviation = ytSum - (Func(3) - Func(1));

    std::cout << "Approximate Value with Mid Point Rule For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void TrapezoidalMethod()
{
    double x, sum, ytSum;
    double h = (b - a) / N;
    for (int i = 1; i < N; i++)
    {
        x = a + i * h;
        sum = sum + Func(x);
    }
    ytSum = (h / 2) * (Func(a) + Func(b) + 2 * sum);
    double deviation = (Func(3) - Func(1)) - ytSum;

    std::cout << "Approximate Value with Trapezoidal Method For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void SimpsonOneOverThreeFormula()
{
    double x, sum, ytSum;
    double h = (b - a) / N;
    for (int i = 1; i < N; i++)
    {
        x = a + i * h;
        if (i % 2 == 0)
            sum = sum + 2 * Func(x);
        else
            sum = sum + 4 * Func(x);
    }
    ytSum = (h / 3) * (Func(a) + Func(b) + sum);
    double deviation = (Func(3) - Func(1)) - ytSum;

    std::cout << "Approximate Value with Simpson One Over Three Formula For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void SimpsonThreeOverEightFormula()
{
    double x, sum, ytSum;
    double h = (b - a) / N;
    for (int i = 1; i < N; i++)
    {
        x = a + i * h;
        if (i % 3 == 0)
            sum = sum + 2 * Func(x);
        else
            sum = sum + 3 * Func(x);
    }
    ytSum = (3 * h / 8) * (Func(a) + Func(b) + sum);
    double deviation = (Func(3) - Func(1)) - ytSum;

    std::cout << "Approximate Value with Simpson Three Over Eight Formula For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void WeddleMethod()
{
    double x, sum, ytSum;
    double h = (b - a) / (N);
    int m;

    m = N / 6;

    for (int i = 1; i <= m; i++)
    {
        sum = sum + (Func(a) + Func(a + 2 * h) + 5 * Func(a + h) + 6 * Func(a + 3 * h) + Func(a + 4 * h) + 5 * Func(a + 5 * h) + Func(a + 6 * h));
        a = a + 6 * h;
    }
    ytSum = (3 * h / 10) * sum;
    double deviation = (Func(3) - Func(1)) - ytSum;

    std::cout << "Approximate Value with Weddle Method For n = " << N << " is " << ytSum
              << " and deviation is " << deviation << std::endl;
}
void BooleMethod()
{
    double sum = 7 * Func(a);
    double x, ytSum;
    double h = (b - a) / (N - 2);
    int mod;

    for (int i = 1; i < N - 1; i++)
    {
        mod = i % 4;
        if (mod == 0)
            sum += 14 * Func(a + i * h);
        else if (mod == 1)
            sum += 32 * Func(a + i * h);
        else if (mod == 2)
            sum += 12 * Func(a + i * h);
        else
            sum += 32 * Func(a + i * h);
    }
    ytSum = 2 * (h / 45) * sum;
    double deviation = (Func(3) - Func(1)) - ytSum;

    std::cout << "Approximate Value with Boole Method For n = " << N << " is " << deviation
              << " and deviation is " << ytSum << std::endl;
}
double Func(double x)
{
    return std::exp(x);
}