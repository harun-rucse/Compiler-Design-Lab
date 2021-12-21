#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    cout << "Enter input: ";
    getline(cin, str);

    int strLen = str.length(), openingIndx, closingIndx, openingCnt = 0, closingCnt = 0;

    if (str[0] == '*' || str[0] == '/' || str[strLen - 1] == '+' || str[strLen - 1] == '-' || str[strLen - 1] == '*' || str[strLen - 1] == '/' || str[strLen - 1] == '(')
    {
        cout << "Invalid" << endl;
        return 0;
    }

    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
            {
                cout << "Invalid" << endl;
                return 0;
            }
        }

        if (str[i] == ')')
        {
            closingIndx = i;
            closingCnt++;
        }
        else if (str[i] == '(')
        {
            openingIndx = i;
            openingCnt++;
            if (str[i + 1] == ')')
            {
                cout << "Invalid" << endl;
                return 0;
            }
            else if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
            {
                if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
                {
                    cout << "Invalid" << endl;
                    return 0;
                }
            }
        }
    }

    if (openingIndx > closingIndx || openingCnt != closingCnt)
    {
        cout << "Invalid" << endl;
        return 0;
    }

    cout << "Valid" << endl;

    return 0;
}