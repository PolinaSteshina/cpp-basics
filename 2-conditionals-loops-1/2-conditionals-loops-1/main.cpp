#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double x1, x2, dx, a, b, c, f;
    const double EPS = 1e-15;
    
    cout << "a = ";
    cin  >> a;
    cout << "b = ";
    cin  >> b;
    cout << "c = ";
    cin  >> c;
    cout << "x1 = ";
    cin  >> x1;
    cout << "x2 = ";
    cin  >> x2;
    cout << "dx = ";
    cin  >> dx;
    cout << fixed;
    
    if ((abs(dx) > EPS ) && (abs(c) > EPS))
    {
        cout << string(25, '-') << endl;
        cout << "|     X     |     F     |" << endl;
        cout << string(25, '-') << endl;
        cout.precision(3);
        
        while (x1 <= x2)
            
        {if ((abs(x1) > EPS) and (abs(b) < EPS))
        {f = a * pow(x1 + c, 2) - b;
        }
        else
            if ((abs(x1) > EPS) and (abs(b) > EPS))
        {f = (x1 - a) / -c;
        }
            else
        {f = a + x1 / c;
        }
            if (((int(a) % int(b)) & (int(a) | int(c))) != 0){
                cout << "|" << setw(6) << x1 << setw(6) << "|";
                cout << setw(6) << f << setw(6) << "|" << endl;
            }
            else
            {cout << "|" << setw(6) << x1 << setw(6) << "|";
             cout << setw(6) << int(f) << setw(6) << "|" << endl;
            }
            x1 += dx;
        }
            cout << string(25, '-') << endl;
        }
            else
            cout << "\nError!\n";

    return 0;
}