#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char file_name[] = "If you wanna u can take! If you wanna u can take! If you wanna, If you wanna, If you wanna u can take! What do you see when you looking at me? Real-real-real star, the beat that you need";
    int r = sizeof(file_name);
    int a = 0, i = 0;
    
    while ( i < r)
    {
        if (file_name [i] == '?')
        {
            for (int j = a; j <= i; j++)
            cout << file_name [j];
            a = i + 1;
        }
        if (file_name [i] == '!' || file_name [i] == '.')
            a = i + 1;
        i++;
    }
    cout << endl;
    int b = 0, c = 0;
    while (file_name [c])
    {
        if (file_name [c] == '!')
        {
            for (int  d = b; d <= c; d++)
                cout << file_name [d];
            b = c + 1;
        }
        if ( file_name [c] == '?' || file_name [c] == '.')
            b = c + 1;
        c++;
    }
    return 0;
}
