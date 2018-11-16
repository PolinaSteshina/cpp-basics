#include "functions.h"

void PrintArray(double* arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize; i++)
        cout << arr[i] << "  ";
}

int NumberOfNegativeElements(double* arr, const int kArraySize)
{
    int num_negatives = 0;
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] < 0) num_negatives++;
    return num_negatives;
}

int FindAbsMinELemIndex(double* arr, const int kArraySize)
{
    int abs_min_index = 0;
    for(int i = 1; i < kArraySize; i++)
        if(abs(arr[i]) < abs(arr[abs_min_index]))
            abs_min_index = i;
    return abs_min_index;
}

double SumAbs(double* arr, const int kArraySize, int abs_min_index)
{
    double sum = 0;
    for(int i = abs_min_index + 1; i < kArraySize; i++)
        sum += abs(arr[i]);
    return sum;
}

void SquareNegativeElements(double* arr, const int kArraySize)
{
    for(int i = 0; i < kArraySize; i++)
        if(arr[i] < 0)
            arr[i] *= arr[i];
}

void SortArray(double* arr, const int kArraySize)
{
    for(int i = 0; i < (kArraySize - 1); i++)
        for(int g = i + 1; g < kArraySize; g++)
            if(arr[i] > arr[g])
                swap(arr[i], arr[g]);
}
