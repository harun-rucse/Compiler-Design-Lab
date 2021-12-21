#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str, result;
    result = 'E';
    cin >> str;
    int len = str.length();
    cout << "E" << endl;
    for (int i = len - 2; i >= 0; i = i - 2)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            result = str[i] + result;
            result = 'E' + result;
            cout << result << endl;
        }
    }
    for (int i = 0; i < len; i = i + 2)
    {
        result[i] = str[i];
        cout << result << endl;
    }
}