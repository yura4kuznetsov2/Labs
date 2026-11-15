#include <cctype>    // isspace
#include <iomanip>   // setprecision
#include <iostream>  // cin, cout
using namespace std;
const double a = -0.2;
const double b = 0.2;
double s(double x, double eps) // function to calculate the sum of the power series S(x) with precision eps
{
    double term = x;
    double sum = x;
    double num = 2.0;  // current value of 4n + 2
    double den = 2.0;  // current value of n + 2
    while (term > eps || term < -eps)
    {
        term *= x * num / den;
        sum += term;
        num += 4.0;
        den += 1.0;
    }
    return sum;
}
bool readReal(double& value) //checks if the input is a real number and reads it into value
{
    cin >> value;
    return !cin.fail()
        && (cin.eof() || isspace(static_cast<unsigned char>(cin.peek())));
}
void printError(const char* reason) // prints error message 
{
    cout << "\n***** error\n" << reason << '\n';
}
int main()
{
    cout << "KUZNETSOV Yura\n";
    cout << "Variant 168: calculate the sum of a power series S(x) "
            "at a given point with a given precision\n";
    double x = 0.0;
    double eps = 0.0;
    cout << "Enter a real number x from [-0.2; 0.2]: "; 
    if (!readReal(x))  
    {
        printError("Input error: x must be a real number.");
        return 0;
    }
    if (x < a || x > b)
    {
        printError("Incorrect value: x is outside of [-0.2; 0.2].");
        return 0;
    }
// Resons of errors 
    cout << "Enter precision eps (a real number greater than 0): ";
    if (!readReal(eps))
    {
        printError("Input error: eps must be a real number.");
        return 0;
    }
    if (eps <= 0.0)
    {
        printError("Incorrect value: eps must be greater than 0.");
        return 0;
    }
    cout << "\n***** do calculations ...";
    double result = s(x, eps); // calculate the sum of the power series S(x) with precision eps
    cout << " done\n";
    cout << scientific << uppercase;
    cout << "for x = " << setprecision(7) << x << '\n';
    cout << "for eps = " << setprecision(9) << eps << '\n';
    cout << fixed;
    cout << "result = " << setprecision(8) << result << '\n';
    return 0;
}