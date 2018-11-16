#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void PrintTableHead()
{
    cout << string(67, '-') << endl;
    cout << "|" << setw(8) << "x" << setw(8);
    cout << "|" << setw(15) << "ln(x) cmath" << setw(5);
    cout << "|" << setw(14) << "ln(x) mine" << setw(5);
    cout << "|" << setw(6) << "n" << setw(6) << "|\n";
    cout << string(67, '-') << endl;
}

double ComputeSeries(double x, double eps, int& n, const int kMaxIters)
{
    double ln = 0, nth_term;
    for (n = 0; n <= kMaxIters; n++)
    {
        nth_term = 2 * pow((x - 1), (2 * n + 1)) /
                   ((2 * n + 1) * pow((x + 1), (2 * n + 1)));
        ln += nth_term;
        
        if (abs(nth_term) < eps) break;
    }
    return ln;
}

void PrintResult(double x, double ln, int n, const int kMaxIters)
{
    cout << "|" << setw(12) << x << setw(4) << "|";
    cout << setw(14) << log(x) << setw(6) << "|";
    if (n > kMaxIters)
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
    cout << "x2 (x2 >= x1) = ";
    cin >> x2;
    cout << "dx (dx > 0) = ";
    cin >> dx;
    cout << "eps (eps > 0) = ";
    cin >> eps;
    
    if (dx < kEps || eps < kEps || x1 < kEps || x1 > x2)
    {
        cout << "\nInput error\n";
        return 1;
    }
    
    PrintTableHead();
    
    cout << fixed;
    cout.precision(6);
    
    double x = x1;
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
