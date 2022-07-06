/**
 * @file CPE02_10055.cpp
 * @author evan
 * @brief a012: 10055 - Hashmat the Brave Warrior
 * @version 0.1
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 **/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int a, b;
    while (cin >> a >> b)
    {
        cout << abs(b - a) << endl;
    }
    return 0;
}