#include <bits/stdc++.h>
using namespace std;

char str[100];

int main()
{
    while (1)
    {
        cin >> str;
        int strLen = strlen(str);
        int binaryCnt = 0, digitCnt = 0, dotCnt = 0;

        for (int i = 0; i < strLen; i++)
        {
            if (str[i] == '0' || str[i] == '1')
            {
                binaryCnt += 1;
            }
            if (str[i] >= '0' && str[i] <= '9')
            {
                digitCnt += 1;
            }
            if (str[i] == '.')
            {
                dotCnt += 1;
            }
        }
        if (digitCnt + dotCnt == strLen && dotCnt == 0)
        {
            if (binaryCnt == strLen && str[0] == '0')
            {
                cout << "Binary Number" << endl;
            }
            else if (digitCnt == strLen && str[0] == '1')
            {
                if (strLen <= 4)
                {
                    cout << "ShortInt Number" << endl;
                }
                else if (strLen > 4)
                {
                    cout << "LongInt Number" << endl;
                }
                else
                {
                    cout << "Undefined" << endl;
                }
            }
        }
        else if (digitCnt + dotCnt == strLen && dotCnt == 1 && str[0] >= '0')
        {
            if (digitCnt <= 4)
            {
                cout << "Float number" << endl;
            }
            else
            {
                cout << "Double number" << endl;
            }
        }
        else if (str[0] >= 'a' || str[0] >= 'A')
        {
            if ((str[0] >= 'i' && str[0] <= 'n') || (str[0] >= 'I' && str[0] <= 'N'))
            {
                cout << "Integer variable" << endl;
            }
            else if (str[0] == 'c' && str[1] == 'h' && str[2] == '_' && (str[3] >= 'a' && str[3] <= 'z') || (str[3] >= 'A' && str[3] <= 'Z') || (str[3] >= '0' && str[3] <= '9'))
            {
                cout << "Character variable" << endl;
            }
            else if (str[0] == 'b' && str[1] == 'n' && str[2] == '_' && (str[3] >= 'a' && str[3] <= 'z') || (str[3] >= 'A' && str[3] <= 'Z') || (str[3] >= '0' && str[3] <= '9'))
            {
                cout << "Binary variable" << endl;
            }
            else if ((str[0] >= 'a' && str[0] <= 'h') || (str[0] >= 'A' && str[0] <= 'H') || (str[0] >= 'o' && str[0] <= 'z') || str[0] >= 'O' && str[0] <= 'Z')
            {
                cout << "Float variable" << endl;
            }
            else
            {
                cout << "Undefined" << endl;
            }
        }
        else if (str[0] == '-' && str[1] == '9' && str[2] == '9')
        {
            return 0;
        }
        else
            cout << "Undefined" << endl;
    }

    return 0;
}