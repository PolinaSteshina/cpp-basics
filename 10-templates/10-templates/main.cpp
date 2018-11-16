#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
void ReadMatrix(T** matrix, int num_rows, int num_cols, ifstream& fin);

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
int CountRepeatedNumbers(T* row, int num_cols);

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
int FindFirstNonNegativeColumn(T** matrix, int num_rows, int num_cols);

template <class T>
bool Execute(string file_name);

int main()
{
    string option;
selection:
    cout << "Select the data type (0 - integer, 1 - double, 2 - float): ";
    cin >> option;
    if (option == "0")
    {
        Execute<int>("integer.txt");
    }
    else if (option == "1")
    {
        Execute<double>("double.txt");
    }
    else if (option == "2")
    {
        Execute<float>("float.txt");
    }
    else
    {
        cout << "Wrong input!\n\n";
        goto selection;
    }
    
    return 0;
}

template <class T>
bool Execute(string file_name)
{
    string path = "/Users/polinastesina/cpp-basics/10-templates/10-templates/";
    ifstream fin(path + file_name);
    if (!fin)
    {
        cout << "\nCan't open file: " << file_name << ".\n";
        return 1;
    }
    
    int num_rows = 3, num_cols = 5;
    
    T** matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++)
        matrix[i] = new T[num_cols];
    
    cout << "Initial matrix:\n";
    ReadMatrix(matrix, num_rows, num_cols, fin);
    fin.close();
    
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;
    
    cout << "Sorted matrix:\n";
    SortMatrix(matrix, num_rows, num_cols);
    PrintMatrix(matrix, num_rows, num_cols);
    
    cout<<"\nFirst column that does not contain any negative elements is: ";
    int colunm_index = FindFirstNonNegativeColumn(matrix, num_rows, num_cols);
    if (colunm_index == -1)
        cout << "no column.\n";
    else
        cout << colunm_index << endl;
    cout << endl;
    
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}

template <class T>
void ReadMatrix(T** matrix, int num_rows, int num_cols, ifstream& fin)
{
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
}

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }
}

template <class T>
int CountRepeatedNumbers(T* row, int num_cols)
{
    int num_repeated_max = 0;
    for (int i = 0; i < num_cols; i++)
    {
        int num_repeated = 0;
        for (int j = 0; j < num_cols; j++)
            if (row[j] == row[i])
                num_repeated++;
        if (num_repeated > num_repeated_max)
            num_repeated_max = num_repeated;
    }
    
    return num_repeated_max;
}

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows - 1; i++)
        for (int j = 0; j < num_rows - i - 1; j++)
            if (CountRepeatedNumbers(matrix[j], num_cols) >
                CountRepeatedNumbers(matrix[j + 1], num_cols))
                swap(matrix[j], matrix[j + 1]);
}

template <class T>
int FindFirstNonNegativeColumn(T** matrix, int num_rows, int num_cols)
{
    int colunm_index = -1;
    for (int j = 0; j < num_cols; j++)
    {
        bool no_negatives = true;
        for (int i = 0; i < num_rows; i++)
        {
            if (matrix[i][j] < 0)
            {
                no_negatives = false;
                break;
            }
        }
        
        if (no_negatives)
        {
            colunm_index = j;
            break;
        }
    }
    
    return colunm_index;
}
