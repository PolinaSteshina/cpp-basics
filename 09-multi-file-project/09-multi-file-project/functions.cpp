#include "functions.h"

void PrintArray(double* arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize; i++)
        cout << arr[i] << "  ";
}

int NumberOfNegativeElements(double* a, const int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < kEps) k++;
    return k;
}

double SumAbs(double* a, const int n)
{
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
    return sum;
}

void Squaring(double* a, const int n)
{
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
}
