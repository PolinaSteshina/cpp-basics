#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int ex1(int n, int m, int **a);
int ex2(int n, int m, int **a);
int ex3(int n, int m, int **a);

int main() {
    int i, n, m;
    cin >> n;
    cin >> m;
    int **a = new int*[n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    // Ввод значений массива и его вывод
    ex3(n, m, a);
    // Поиск первого столбца без отрицательных элементов
    ex1(n, m, a);
    
    // Упоряд. матрицы по кол-ву повторяющихся элементов
    ex2(n, m, a);
    
    return 0;
}
int ex3(int n, int m, int **a) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m;j++) {
            a[i][j] = -3 + rand() % 17;
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

int ex1(int n, int m, int **a) {
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
        cout << "NO" << endl;
    }
    else {
        cout << numj << endl;
    }
    return 0;
}

int ex2(int n, int m, int **a) {
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        int maxpov = 1;
        for (int j = 0; j < m - 1; j++) {
            int pov = 1;
            for (int k = j + 1;k < m; k++) {
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
    for (int k = 1; k <= m; k++) {
        for (int i = 0;i < n;i++) {
            if (b[i] == k) {
                for (int j = 0;j < m;j++) {
                    cout << a[i][j] << "  ";
                }
                cout << b[i] << endl;
            }
        }
    }
    return 0;
}

