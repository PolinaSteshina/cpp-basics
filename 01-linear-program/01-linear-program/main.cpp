#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    cout << "x = ";
    cin >> x;
    
    double z1 = (pow(x, 2) + 2 * x - 3 + (x + 1) * sqrt(pow(x, 2) - 9)) /
                (pow(x, 2) - 2 * x - 3 + (x - 1) * sqrt(pow(x, 2) - 9));
    double z2 = sqrt((x + 3) / (x - 3));
    
    cout << "z1 = " << z1 << "\nz2 = " << z2 << endl;
    
    return 0;
}
