#include <cctype>    
#include <cmath>     
#include <iomanip>   
#include <iostream> 
#include <numbers>   
using namespace std;

// Step 3: calculates the expression, no checks inside
double f(double x)
{
    return sin(4.0 / 53.0) - 14.0 * numbers::pi + 48.0 * numbers::e * 8.0 / ((x + 9.0) * (x - 7.0)) + 4.0 * asin(x - 3.0) - 15.0 / (x + 8.0);
}
// Step 2: arcsin needs |x - 3| <= 1, so x is in [2; 4];
// the denominators (x + 9), (x - 7), (x + 8) are not zero on this interval
bool isInDomain(double x)
{
    return x >= 2.0 && x <= 4.0;
}

int main()
{
    cout << "KUZNETSOV Yura\n";
    cout << "Variant 168: calculate the value of the expression for a real x\n";
    cout << "Enter a real number x (2 <= x <= 4): ";

    double x = 0.0;
    cin >> x;

    // Step 1: input is wrong if reading failed (no number at all)
    // or if the number is followed by a non-space character (like "3abc" or "3,5")
    bool wrongInput = cin.fail() || (!cin.eof() && !isspace(static_cast<unsigned char>(cin.peek())));
    if (wrongInput)
    {
        cout << "\nwrong input\n";
        return 1;
    }

    cout << "\n***** do calculations ...";
    bool defined = isInDomain(x);              // domain is checked only once
    double result = defined ? f(x) : 0.0;      // f is called only for x from the domain
    cout << " done\n";

    cout << fixed;                             // fixed-point output instead of scientific
    cout << "for x = " << setprecision(5) << x << '\n';
    if (defined)
    {
        cout << "result = " << setprecision(9) << result << '\n';
    }
    else
    {
        cout << "result = undefined\n";
    }
    return 0;
}