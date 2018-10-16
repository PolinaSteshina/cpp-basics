#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string file_name;
    
    cout << "Write file name: ";
    cin >> file_name;
    file_name += ".txt";
    ifstream fin(file_name);
    
    if (!fin.is_open())
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
    long n = 0, i = 0, j = 0, w = 0, e = 0, r = 0;
    
    while (buf [i])
     {
        if (buf [i] == '?')
        {for (j = n; j <= i; j++)
            cout << buf [j];
            n = i + 1;
        }
         if (buf [i] == '!' || buf [i] == '.')
             n = i + 1;
             i++;
      }
    cout << endl;
    while (buf [e])
    {
        if (buf [e] == '!')
        {
            for ( r = w; r <= e; r++)
                cout << buf [r];
            w = e + 1;
        }
        if ( buf [e] == '?' || buf [e] == '.')
            w = e + 1;
        e++;
        }
    return 0;
}
