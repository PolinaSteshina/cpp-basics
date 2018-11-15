#include "functions.h"

int main() {
    const int kArraySize=5;
    double arr[kArraySize]={-3, 0.2, -56, -55.8, 0.33};
    
    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;
    
    cout << "\nNumber of negative elements = ";
    cout << NumberOfNegativeElements(arr, kArraySize) << endl;
    
    cout << "\nThe sum of the modules of the array elements = ";
    cout << SumAbs(arr, kArraySize) << endl;
    
    Squaring(arr, kArraySize);
    
    cout << "\nNew array:\n";
    PrintArray(arr, kArraySize);
    cout << endl << endl;
    
    return 0;
}
