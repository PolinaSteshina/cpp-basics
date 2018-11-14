#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
    srand(time(0));
    bool proverka;
    int i, j, n, m, numj = -1, k;
    cin >> n;
    cin >> m;
    int **a = new int*[n];
    int *b = new int[n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    for (i = 0; i < n; i++) {
        for (j = 0;j < m;j++) {
            a[i][j] = -3 + rand() % 17;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j] << " " << " ";
        }
        cout << endl;
    }
    // Поиск первого столбца без отрицательных элементов
    for (j = 0; j < m; j++) {
        proverka = true;
        for (i = 0; i < n; i++) {
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
        cout << "NO"<< endl;
    }
    else {
        cout << numj << endl;
    }
    // Упоряд. матрицы по кол-ву повторяющихся элементов
    for (i = 0; i < n; i++) {
        int maxpov = 1;
        for (j = 0; j < m - 1; j++) {
            int pov = 1;
            for (k = j + 1;k < m;k++) {
                if (a[i][j] == a[i][k]) {
                    pov = pov + 1;
                }
            }
            if (pov > maxpov) {
                maxpov = pov;
            }
        }
        b[i] = maxpov;
    }
    for (k = 1; k <= m; k++) {
        for (i = 0;i < n;i++) {
            if (b[i] == k) {
                for (j = 0;j < m;j++) {
                    cout << a[i][j] << "  ";
                }
                cout << b[i] << endl;
            }
        }
    }
    
    
    return 0;
}

