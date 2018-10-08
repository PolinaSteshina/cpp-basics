#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
    {double x, x2, dx, ln, eps, f;
     const int max = 1000;
        
        cout << "x = ";
        cin  >> x;
        cout << "x2 = ";
        cin  >> x2;
        cout << "dx = ";
        cin  >> dx;
        cout << "eps = ";
        cin  >> eps;

        cout << string(73, '-') << endl;
        cout << "|" << setw(9) << "x" << setw(9);
        cout << "|" << setw(9) << "ln x built-in" << setw(2);
        cout << "|" << setw(9) << "  ln x series ";
        cout << "|" << setw(9) << "i" << setw(9)<< "|" << endl;
        cout << string(73, '-') << endl;
        
        cout << fixed;
        cout.precision(6);

        while (x <= x2)
        {cout << "|" << setw(11) << x << setw(7) << "|";
            cout << setw(11) << f << setw(7) << "|";
            ln = 0;
            
            for (int n = 1; n < max; n++)
            {
                f = (2 * pow((x --), (2 * n ++))) /
                    (2 * n ++) * pow((x ++), (2 * n ++));
                ln  += f;
                
                if (abs(f) < eps)
                    break;
            }
            if (int n = max) {
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
