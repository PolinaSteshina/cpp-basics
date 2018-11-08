#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void PrintTableHead()
{
    cout << string(67, '-') << endl;
    cout << "|" << setw(9) << "x" << setw(9);
    cout << "|" << setw(15) << "ln(1-x) cmath" << setw(3);
    cout << "|" << setw(15) << "ln(1-x) mine" << setw(3);
    cout << "|" << setw(6) << "n" << setw(7) << "|\n";
    cout << string(67, '-') << endl;
}
double ComputeSeries(double x, double eps, double F, int &n, const int kMaxIters)
{
    double ln = 0;
    for (n = 0; n < kMaxIters; n++)
    {
        F = 2 * pow((x - 1), (2 * n + 1)) /
        ((2 * n + 1) * pow((x + 1), (2 * n + 1)));
        ln += F;
        
        if (abs(F) < eps)
            break;
        
    }
    return ln;
}
void PrintResult(double x, double ln, int n, const int kMaxIters)
{
    cout << "|" << setw(12) << x << setw(4) << "|";
    cout << setw(14) << log(x) << setw(6) << "|";
    if (n == kMaxIters)
    {
        cout << "   excess limit   |" << setw(12) << "|\n";
    }
    else
    {
        cout << setw(13) << ln << setw(6) << "|";
        cout << setw(6) << n << setw(6) << "|\n";
    }
}
int main()
{
    const double kEps = 1e-15;
    const int kMaxIters = 1000;
    
    double x1, x2, dx, eps;
    cout << "ln(x), x > 0\n";
    cout << "x1 = ";
    cin >> x1;
    cout << "x2 = ";
    cin >> x2;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;
    
    if (dx < kEps || eps < kEps || x1 < kEps || x1 > x2)
    {
        cout << "\nInput error\n";
        return 1;
    }
    
    PrintTableHead();
    
    cout << fixed;
    cout.precision(6);
    
    double x = x1, F;
    while (x <= x2)
    {
        int n;
        double ln = ComputeSeries(x, eps, n, kMaxIters);
        PrintResult(x, ln, n, kMaxIters);
        x += dx;
    }
    cout << string(67, '-');
    
    return 0;
}
