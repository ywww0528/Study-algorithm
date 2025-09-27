#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'C')
        {
            a++;
        }
        else if (s[i] == 'P')
        {
            b++;
        }
    }
    if (a >= b * 2 + 1)
    {
        cout << b << endl;
    }
    else
    {
        cout << (a - 1) / 2 << endl;
    }
    return 0;
}