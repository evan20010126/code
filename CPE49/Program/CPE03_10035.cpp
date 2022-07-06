/**
 * @file CPE03_10035.cpp
 * @author evan
 * @brief c014: 10035 - Primary Arithmetic
 * @version 0.1
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 **/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 9999, m = 1;
    int n_arr[10], m_arr[10];
    while (cin >> n >> m)
    {

        int carry_num = 0;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < 10; ++i)
        {
            n_arr[i] = n / (int)pow(10, i) % 10;
            m_arr[i] = m / (int)pow(10, i) % 10;
        }

        int carry = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (n_arr[i] + m_arr[i] + carry >= 10)
            {
                carry = 1;
                carry_num++;
            }
            else
            {
                carry = 0;
            }
        }

        switch (carry_num)
        {
        case 0:
            cout << "No carry operation.\n";
            break;
        case 1:
            cout << carry_num << " carry operation.\n";
            break;
        default:
            cout << carry_num << " carry operations.\n";
            break;
        }
        break;
    }
    return 0;
}