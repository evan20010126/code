/**
 * @file CPE01_10041.cpp
 * @author evan
 * @brief a737. 10041 - Vito's family
 * @version 0.1
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 **/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int times;
    cin >> times;
    for (int i = 0; i < times; ++i)
    {
        int relatives_num;
        int relatives[500];
        int mid;
        int sum = 0;
        cin >> relatives_num;
        for (int j = 0; j < relatives_num; ++j)
            cin >> relatives[j];
        sort(relatives, relatives + relatives_num);
        mid = relatives_num / 2;
        for (int j = 0; j < relatives_num; ++j)
        {
            sum += abs(relatives[j] - relatives[mid]);
        }
        cout << sum << endl;
    }
    return 0;
}