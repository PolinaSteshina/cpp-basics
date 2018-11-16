#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double kEps = 1e-15;
    
    double x1, x2, dx, a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "x1 = ";
    cin >> x1;
    cout << "x2 (x2 >= x1) = ";
    cin >> x2;
    cout << "dx (dx > 0) = ";
    cin >> dx;
    
    if (dx < kEps)
    {
        cout << "Error dx";
    }
    else
    {
        cout << string(26, '-') << endl;
        cout << "|" << setw(6) << "X" << setw(6);
        cout << "|" << setw(6) << "F" << setw(7) << "|" << endl;
        cout << string(26, '-') << endl;
        
        cout << fixed;
        cout.precision(3);
        
        double f;
        while (x1 <= x2)
        {
            cout << "|" << setw(8) << x1 << setw(4) << "|";
            
            if (abs(x1) < kEps && !(abs(b) < kEps))
            {
                f = a * pow((x1 + c), 2) - b;
            }
            else
            {
                if (abs(x1) < kEps && abs(b) < kEps)
                {
                    if (abs(c) < kEps)
                    {
                        cout << "  div by 0  |\n";
                        x1 += dx;
                        continue;
                    }
                    else
                    {
                        f = (x1 - a) / (-c);
                    }
                }
                else
                {
                    if (abs(c) < kEps)
                    {
                        cout << "  div by 0  |\n";
                        x1 += dx;
                        continue;
                    }
                    else
                    {
                        f = a + x1 / c;
                    }
                }
            }
            
            int ac = static_cast<int>(a);
            int bc = static_cast<int>(b);
            int cc = static_cast<int>(c);
            if (((ac ^ bc) & ~(ac | cc)) != 0)
                cout << setw(9) << f << setw(4) << "|" << endl;
            else
                cout << setw(7) << static_cast<int>(f) << setw(6) << "|" << endl;
            
            x1 += dx;
        }
        
        cout << string(26, '-') << endl;
    }
    return 0;
}
