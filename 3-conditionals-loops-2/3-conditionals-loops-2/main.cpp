#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, x1, x2, dx, F, ln, eps;
    const double kEps = 1e-15;
    int n, max_iter = 1000;
    
    cout << "ln(x), x <= 0"<< endl;
    cout << "x1 = ";
    cin >> x1;
    cout << "x2 = ";
    cin >> x2;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;
    
    if ((dx < kEps && eps < kEps) && (x1 <= 0))
    {
        cout << "Input error" << endl;
    }
    cout << string(73, '-') << endl;
    cout << "|" << setw(9) << " x " << setw(9);
    cout << "|" << setw(11) << " ln(x) " << setw(7);
    cout << "|" << setw(9) << "  ln(x) series " << setw(3);
    cout << "|" << setw(11) << " n " << setw(7)<< "|" << endl;
    cout << string(73, '-') << endl;
    
    cout << fixed;
    cout.precision(3);
    
    x = x1;
    
    while (x<=x2)
    {
        cout << "|" << setw(11) << x << setw(7) << "|";
        cout << setw(11) << log(x) << setw(7) << "|";
        ln = 0;
        for (n = 0; n < max_iter; n++)
        {
            F = (2 * pow((x - 1), (2 * n + 1))) /
            (2 * n + 1) * pow((x + 1), (2 * n + 1));
            ln += F;
            
            if (abs(F) < eps)
                break;
        }
        if (n == max_iter) {
            cout << setw(11) << "Excess limit" << setw(6) << "|";
            cout << setw(11) << " " << setw(7) << "|" << endl;
        }
        else
        {
            cout << setw(11) << ln << setw(7) << "|";
            cout << setw(11) << n << setw(7) << "|" << endl;
        }
        x += dx;
    }
    cout << string(73, '-') << endl;
    return 0;
}
