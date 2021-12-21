#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string keywords[32] = {"auto", "double", "int", "struct", "break", "else", "long",
                           "switch", "case", "enum", "register", "typedef", "char",
                           "extern", "return", "union", "const", "float", "short",
                           "unsigned", "continue", "for", "signed", "void", "default",
                           "goto", "sizeof", "voltile", "do", "if", "static", "while"};
    string arithmetics[7] = {"+", "-", "*", "/", "++", "--", "%"};

    string str;
    getline(cin, str);

    int strLen = str.length();
    int digitCnt = 0, charCnt = 0;

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        string keyword = keywords[i];
        int keyLen = keyword.length();

        if (strLen == keyLen && str == keyword)
        {
            cout << "Keyword" << endl;
            return 0;
        }
    }

    for (int i = 0; i < sizeof(arithmetics) / sizeof(arithmetics[0]); i++)
    {
        string arithmetic = arithmetics[i];
        int arithLen = arithmetic.length();

        if (strLen == arithLen && arithmetic == str)
        {
            cout << "Arithmetic operator" << endl;
            return 0;
        }
    }

    if (str[0] == 'c' && str[1] == 'o' && str[2] == 'n' && str[3] == 's' && str[4] == 't' && strLen > 5)
    {
        cout << "Constant" << endl;
        return 0;
    }

    for (int i = 0; i < strLen; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            digitCnt++;
        }
        else
        {
            charCnt++;
        }
    }

    if (strLen == digitCnt)
    {
        cout << "Integer" << endl;
        return 0;
    }

    else if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
    {
        cout << "Identifier" << endl;
    }

    else if (digitCnt == (strLen - 1) && charCnt == 1)
    {
        cout << "Float" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}