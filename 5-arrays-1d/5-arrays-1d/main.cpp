#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    const double kEps = 1e-15;
    int n;
    cout << "n = ";
    cin  >> n;
    double a[n];
    if (n <= 0)
    {cout << "Input error" << endl;
        return 1;}
    
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {cin >> a[i];}
    
    // Кол-во отрицательных элементов массива
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < kEps) k++;
        {cout << k << endl;}
    
    // Сумма модулей элементов массива, расположенных после минимального по модулю элемента
    double min,sum = 0;
    min = abs(a[0]);
    int index = 0;
    for(int i = 0; i < n; i++)
    if(abs(a[i]) < min)
    {min = abs(a[i]); index = i;}
    
    for(int i = index + 1; i < n; i++)
    {sum += abs(a[i]);}
    cout << sum << endl;
    
    // Замена всех отрицательных элементов массива их квадратами
    for(int i = 0; i < n; i++)
        if(a[i] < kEps)
        {a[i] *= a[i];}
    
    double buf;
    for(int i = 0; i < (n - 1); i++)
        for(int g = i + 1; g < n; g++)
            if(a[i] > a[g])
            {buf = a[i];
             a[i] = a[g];
             a[g] = buf;}
                
                for(int i = 0; i < n; i++)
                {cout << a[i] << ' ';}
    
                return 0;
            }
