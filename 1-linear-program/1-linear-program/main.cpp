#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, z1, z2;
    cout << "x = ";
    cin >> x;
    
    z1 = (pow (x, 2) + 2 * x - 3 + (x + 1) * sqrt(pow (x, 2) - 9)) /
         (pow (x, 2) - 2 * x - 3 + (x - 1) * sqrt(pow (x, 2) - 9));
    
    z2 = sqrt((x + 3) / (x - 3));
    
    cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl;
    return 0;
}
