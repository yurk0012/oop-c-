#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ukrainian");

    double y = 0.47;
    double z = -1.32;
    double b, a;

    double xp = -1.0;   
    double xk = 1.0;   
    double dx = 0.2;   

    cout << "Результати табулювання:" << endl;

    for (double x = xp; x <= xk; x += dx)
    {
        b = x * (
            (y + atan(pow(fabs(x * x + z), 0.1))) /
            (3.0 / x + pow(y + z, 3)) +
            y * exp(-(x + z) / (y + z))
            );

        a = (pow(sqrt(fabs(x * x - z)), 0.3) - cbrt(fabs(y + 2 * b))) /
            (1 + x + (pow(y, 2) / 2.0) + (pow(z, 3) / 6.0));

        cout << "\nx = " << x << endl;
        cout << "\na = " << a << endl;
        cout << "\nb = " << b << endl;

    }

    return 0;
}


