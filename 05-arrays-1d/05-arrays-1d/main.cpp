#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    const double kEps = 1e-15;
    const int n=5;
    double a[n]={-3, 0.2, -56, -55.8, 0.33};
    
    // Кол-во отрицательных элементов массива
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < kEps) k++;
    {cout << k << endl;}
    
    // Сумма модулей элементов массива, расположенных после минимального по модулю элемента
    double sum = 0;
    double min = abs(a[0]);
    int index = 0;
    for(int i = 0; i < n; i++)
        if(abs(a[i]) < min)
        {
            min = abs(a[i]); index = i;
        }
    
    for(int i = index + 1; i < n; i++)
    {
        sum += abs(a[i]);
    }
    cout << sum << endl;
    
    // Замена всех отрицательных элементов массива их квадратами
    for(int i = 0; i < n; i++)
        if(a[i] < kEps)
        {
            a[i] *= a[i];
        }
    
    double buf;
    for(int i = 0; i < (n - 1); i++)
        for(int g = i + 1; g < n; g++)
            if(a[i] > a[g])
            {
                buf = a[i];
                a[i] = a[g];
                a[g] = buf;
            }
    
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
        
    }
    
    return 0;
}
