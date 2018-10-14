#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n, k = 0, index = 0;
    double min,sum = 0;
    const double kEps = 1e-15;
    cout << "n = ";
    cin  >> n;
    double a[n], trans;
    if (n <= 0)
    {cout << "Input error" << endl;
        return 1;}
    
    cout << "write elements: ";
    for(int i = 0; i < n; i++)
    {cin >> a[i];}
    
    
    for (int i = 0; i < n; i++)
        if (a[i] < kEps) k++;
    {cout << k << endl;}
    

    min = abs(a[0]);
    for(int i = 0; i < n; i++)
    if(abs(a[i]) < min)
    {min = abs(a[i]); index = i;}
    
    for(int i = index + 1; i < n; i++)
    {sum += abs(a[i]);}
    cout << sum << endl;
    
   
    for(int i = 0; i < n; i++)
        if(a[i] < kEps)
        {a[i] *= a[i];}
    
    for(int i = 0; i < (n - 1); i++)
        for(int g = i + 1; g < n; g++)
            if(a[i] > a[g])
            {trans = a[i];
             a[i] = a[g];
             a[g] = trans;}
                
                for(int i = 0; i < n; i++)
                {cout << a[i] << ' ';}
    
                return 0;
            }
