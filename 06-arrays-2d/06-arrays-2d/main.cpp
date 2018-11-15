#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    
    const int n = 3, m = 5;
    int a[n][m] = {1, -6, 1, 5, 1, 2, -6, -6, -6, -6, 88, -9, 0, 0, 33};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " " << " ";
        }
        cout << endl;
    }
    
    // Поиск первого столбца без отрицательных элементов
    int numj = -1;
    for (int j = 0; j < m; j++) {
        bool proverka = true;
        for (int i = 0; i < n; i++) {
            if (a[i][j] < 0) {
                proverka = false;
                break;
            }
        }
        if (proverka == true) {
            numj = j + 1;
            break;
        }
    }
    if (numj == -1) {
        cout << "No column"<< endl;
    }
    else {
        cout<<"The number of the first column that does not contain any negative element: ";
        cout << numj << endl;
    }
    
    // Упоряд. матрицы по кол-ву повторяющихся элементов
    for (int i = 0; i < n; i++) {
        int maxpov = 1;
        int num_i = 0;
        int pov = 1;
        for (int j = 0;j < m-1;j++) {
                if (a[i][j] == a[i][j+1]) {
                    pov = pov + 1;
                    num_i = i;
                }
            }
            if (pov >= maxpov) {
                maxpov=pov;
                swap(a[n-1], a[num_i]);
            }
        }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << a[i][j] << " " << " ";
                }
                cout << endl;
            }
    
    return 0;
}

