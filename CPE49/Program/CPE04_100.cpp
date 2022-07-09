/**
 * @file CPE04_100.cpp
 * @author evan
 * @brief c039: 00100 - The 3n + 1 problem
 * @version 0.1
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 **/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << n << " " << m << " ";
        if (n > m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        int max_cycle = 0;
        for (int i = n; i <= m; i++)
        {
            int test = i;
            int temp_max = 0;
            while (test != 1)
            {
                temp_max++;
                if (test % 2 == 1)
                    test = 3 * test + 1;
                else
                    test = test / 2;
            }
            temp_max++; // 因為1沒有被count到
            if (temp_max > max_cycle)
            {
                max_cycle = temp_max;
            }
        }
        cout << max_cycle << endl;
    }
    return 0;
}
