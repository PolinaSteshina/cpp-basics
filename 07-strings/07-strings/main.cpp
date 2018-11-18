#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("/Users/polinastesina/cpp-basics/07-strings/07-strings/text.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file: text.txt!\n";
        return 1;
    }
    
    fin.seekg(0, ios::end);
    long len = fin.tellg();
    char* text = new char[len + 1];
    
    fin.seekg(0, ios::beg);
    fin.read(text, len);
    text[len] = '\0';
    
    int i = 0, n = 0;
    while (text[i])
    {
        if (text[i] == '?')
        {
            for (int j = n; j <= i; j++)
                cout << text[j];
            n = i + 1;
        }
        else if (text[i] == '!' || text[i] == '.')
            n = i + 1;
        i++;
    }
    cout << endl;
    
    i = n = 0;
    while (text[i])
    {
        if (text[i] == '!')
        {
            for (int j = n; j <= i; j++)
                cout << text[j];
            n = i + 1;
        }
        if (text[i] == '?' || text[i] == '.')
            n = i + 1;
        i++;
    }
    cout << endl;
    
    return 0;
}
