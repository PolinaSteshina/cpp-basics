#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int kArraySize = 5;
    double arr[kArraySize] = {-3, 0.2, -56, -55.8, 0.33};
    
    cout << "Initial array:\n";
    for(int i = 0; i < kArraySize; i++)
        cout << arr[i] << "  ";
    cout << endl;
    
    // Кол-во отрицательных элементов массива
    int num_negatives = 0;
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] < 0) num_negatives++;
    cout << "\nNumber of negative elements: ";
    cout << num_negatives << endl;
    
    // Позиция минимального по модулю элемента
    int abs_min_index = 0;
    for(int i = 1; i < kArraySize; i++)
        if(abs(arr[i]) < abs(arr[abs_min_index]))
            abs_min_index = i;
    
    // Сумма модулей элементов массива, расположенных после минимального по модулю элемента
    if (abs_min_index < kArraySize - 1)
    {
        double sum = 0;
        for(int i = abs_min_index + 1; i < kArraySize; i++)
            sum += abs(arr[i]);
        cout << "\nSum of elements located after the absolute minimum element: ";
        cout << sum << endl;
    }
    else
    {
        cout << "\nNo sum: absolute minimum element is the last one.\n";
    }
    
    // Замена всех отрицательных элементов массива их квадратами
    for(int i = 0; i < kArraySize; i++)
        if(arr[i] < 0)
            arr[i] *= arr[i];
    
    for(int i = 0; i < kArraySize - 1; i++)
        for(int g = i + 1; g < kArraySize; g++)
            if(arr[i] > arr[g])
                swap(arr[i], arr[g]);
    
    cout << "\nModified and sorted array:\n";
    for(int i = 0; i < kArraySize; i++)
        cout << arr[i] << "  ";
    cout << endl << endl;
    
    return 0;
}
