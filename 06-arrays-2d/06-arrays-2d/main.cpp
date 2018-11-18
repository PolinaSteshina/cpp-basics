#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadMatrix(int** matrix, int num_rows, int num_cols, ifstream& fin);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
int CountRepeatedNumbers(int* row, int num_cols);
void SortMatrix(int** matrix, int num_rows, int num_cols);
int FindFirstNonNegativeColumn(int** matrix, int num_rows, int num_cols);

int main()
{
    ifstream fin("/Users/polinastesina/cpp-basics/06-arrays-2d/06-arrays-2d/matrix.txt");
    if (!fin)
    {
        cout << "\nCan't open file: matrix.txt\n";
        return 1;
    }
    
    int num_rows = 3, num_cols = 5;
    
    int** matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
        matrix[i] = new int[num_cols];
    
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

void ReadMatrix(int** matrix, int num_rows, int num_cols, ifstream& fin)
{
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
}

void PrintMatrix(int** matrix, int num_rows, int num_cols)
{
    int* repeated_numbers = new int[num_rows];
    for (int i = 0; i < num_rows; i++)
        repeated_numbers[i] = CountRepeatedNumbers(matrix[i], num_cols);
    
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << " ";
        cout << " |" << setw(2) << repeated_numbers[i] << endl;
    }
}

int CountRepeatedNumbers(int* row, int num_cols)
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

void SortMatrix(int** matrix, int num_rows, int num_cols)
{
    int* repeated_numbers = new int[num_rows];
    for (int i = 0; i < num_rows; i++)
        repeated_numbers[i] = CountRepeatedNumbers(matrix[i], num_cols);
    
    for (int i = 0; i < num_rows - 1; i++)
        for (int j = 0; j < num_rows - i - 1; j++)
            if (repeated_numbers[j] > repeated_numbers[j + 1]) {
                swap(matrix[j], matrix[j + 1]);
                swap(repeated_numbers[j], repeated_numbers[j + 1]);
            }
}

int FindFirstNonNegativeColumn(int** matrix, int num_rows, int num_cols)
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
