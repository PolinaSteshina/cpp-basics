#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define n 3
#define m 5

using namespace std;

template <class T>
void PrintMatrix(T a[3][5]);
template <class T>
void FindingANegativeColumn(T a[3][5]);
template <class T>
void TheOrderingOfTheMatrix(T a[3][5]);

int main() {
    
    string option;
selection:
    cout << "Select the data type (0 - integer, 1 - double, 2 - float): ";
    cin >> option;
    if (option == "0")
    {
        int a[n][m] = {1, -6, 1, 5, 1, 2, -6, -6, -6, -6, 88, -9, 0, 0, 33};
        PrintMatrix(a);
        FindingANegativeColumn(a);
        TheOrderingOfTheMatrix (a);
    }
    else if (option == "1")
    {
       double a[n][m] = {1.9, -6.7, 1.9, 5.88, 1.9, 2.3, -6.5, -6.5, -6.5, -6.5, 88.1, -9.3, 0.4, 0.4, 33.1};
        PrintMatrix(a);
        FindingANegativeColumn(a);
        TheOrderingOfTheMatrix (a);
    }
    else if (option == "2")
    {
       float a[n][m] = {1.9, -6.7, 1.9, 5.88, 1.9, 2.3, -6.5, -6.5, -6.5, -6.5, 88.1, -9.3, 0.4, 0.4, 33.1};
        PrintMatrix(a);
        FindingANegativeColumn(a);
        TheOrderingOfTheMatrix (a);
    }
    else
    {
        cout << "Wrong input!\n\n";
        goto selection;
    }
    return 0;
}
template <class T>
void PrintMatrix( T a[3][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " " << " ";
        }
        cout << endl;
    }
}
template <class T>
void FindingANegativeColumn(T a[3][5])
{
    int numj = -1;
    for (int j = 0; j < m; j++)
    {
        bool proverka = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] < 0) {
                proverka = false;
                break;
            }
        }
        if (proverka == true)
        {
            numj = j + 1;
            break;
        }
    }
    if (numj == -1)
    {
        cout << "No column" << endl;
    }
    else {
        cout<<"The number of the first column that does not contain any negative element: ";
        cout << numj << endl;
    }
}
template <class T>
void TheOrderingOfTheMatrix(T a[3][5])
{
    for (int i = 0; i < n; i++)
    {
        int maxpov = 1;
        int num_i = 0;
        int pov = 1;
        for (int j = 0;j < m-1;j++)
        {
            if (a[i][j] == a[i][j+1])
            {
                pov = pov + 1;
                num_i = i;
            }
        }
        if (pov >= maxpov)
        {
            maxpov = pov;
            swap(a[n-1], a[num_i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " " << " ";
        }
        cout << endl;
    }
}

