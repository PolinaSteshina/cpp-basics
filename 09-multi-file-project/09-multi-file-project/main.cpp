#include "functions.h"

int main()
{
    const int kArraySize = 5;
    double arr[kArraySize] = { -3, 0.2, -56, -55.8, 0.33 };
    
    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;
    
    cout << "\nNumber of negative elements = ";
    cout << NumberOfNegativeElements(arr, kArraySize) << endl;
    
    int abs_min_index = FindAbsMinELemIndex(arr, kArraySize);
    if (abs_min_index < kArraySize - 1)
    {
        cout << "\nSum of elements located after the absolute minimum element: ";
        cout << SumAbs(arr, kArraySize, abs_min_index) << endl;
    }
    else
    {
        cout << "\nNo sum: absolute minimum element is the last one.\n";
    }
    
    SquareNegativeElements(arr, kArraySize);
    SortArray(arr, kArraySize);
    cout << "\nModified and sorted array:\n";
    PrintArray(arr, kArraySize);
    cout << endl << endl;
    
    return 0;
}
