//Primary Arithmetic --UVa10035
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        if (num1 == "0" && num2 == "0")
            break;
        int answer = 0;
        char ch1[10], ch2[10];
        int num1_len = num1.length();
        int num2_len = num2.length();
        int i = 0;
        for (; i < 10 - num1_len; i++)
        {
            ch1[i] = '0';
        }
        int j = 0;
        for (; i < 10; i++)
        {
            ch1[i] = num1[j];
            j++;
        }

        i = 0;
        for (; i < 10 - num2_len; i++)
        {
            ch2[i] = '0';
        }
        j = 0;
        for (; i < 10; i++)
        {
            ch2[i] = num2[j];
            j++;
        }

        int in = 0;
        for (int k = 9; k >= 0; k--)
        {
            //cout << ch1[k] + ch2[k] - 48 - 48 << "===========" << endl;
            if (int(ch1[k]) + int(ch2[k]) - 48 - 48 + in >= 10)
            {
                answer++;
                in = 1;
            }
            else
            {
                in = 0;
            }
        }
        if (answer == 0)
            cout << "No carry operation." << endl;
        else if (answer == 1)
            cout
                << answer << " carry "
                << "operation." << endl;
        else
            cout << answer << " carry "
                 << "operations." << endl;
    }
    return 0;
}