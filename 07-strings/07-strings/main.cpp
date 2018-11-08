#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string file_name;
    
    cout << "Write file name: ";
    cin >> file_name;
    file_name += ".txt";
    ifstream fin(file_name);
    
    if (!fin)
    {
        cout << "can't open "<< file_name << endl;
        return 1;
    }
    fin.seekg (0, ios::end);
    long len = fin.tellg();
    char *buf = new char [len + 1];
    fin.seekg (0, ios::beg);
    fin.read (buf, len);
    buf [len] = '\0';
    long a = 0, i = 0, j = 0, b = 0, c = 0, d = 0;
    
    while (buf [i])
    {
        if (buf [i] == '?')
        {for (j = a; j <= i; j++)
            cout << buf [j];
            a = i + 1;
        }
        if (buf [i] == '!' || buf [i] == '.')
            a = i + 1;
        i++;
    }
    cout << endl;
    while (buf [c])
    {
        if (buf [c] == '!')
        {
            for ( d = b; d <= c; d++)
                cout << buf [d];
            b = c + 1;
        }
        if ( buf [c] == '?' || buf [c] == '.')
            b = c + 1;
        c++;
    }
    return 0;
}
