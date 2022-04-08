// You can say 11.
// 題目中數字最大有1000位數, long int 僅能記錄2000000000左右內的數字
// long long int 9223372036854775807左右內的數字
// 故應以char儲存數字 以(奇數-偶數 = 11的倍數[包含0])判斷是否為11的倍數
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        if (n % 11 == 0)
            cout << n << " is a multiple of 11." << endl;
        else
            cout << n << " is not a multiple of 11." << endl;
    }

    // while (true)
    // {
    //     string number;
    //     cin >> number;
    //     if (number == "0")
    //         break;
    //     else
    //     {
    //         int odd = 0;
    //         int even = 0;
    //         for (int i = 0; i < number.size(); i++)
    //         {
    //             if (i % 2 == 0)
    //             {
    //                 odd += (number[(number.size() - 1) - i] - 48);
    //             }
    //             else if (i % 2 == 1)
    //             {
    //                 even += number[(number.size() - 1) - i] - 48;
    //             }
    //         }
    //         if (abs(odd - even) % 11 == 0)
    //             cout << number << " is a multiple of 11." << endl;
    //         else
    //             cout << number << " is not a multiple of 11." << endl;
    //     }
    // }

    return 0;
}