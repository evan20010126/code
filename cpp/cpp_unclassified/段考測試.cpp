#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input[12];
    for (int i = 0; i < 12; i++)
    {
        cin >> input[i];
    }

    if (input[3][1] != 9)
    {
        input[3][1] = input[3][1] + 1;
    }
    else
    {
        input[3][1] == 0;
        input[3][0] = input[3][0] + 1;
    }
    /*----*/
    if (input[5][1] != 9)
    {
        input[5][1] = input[5][1] + 1;
    }
    else
    {
        input[5][1] == 0;
        input[5][0] = input[5][0] + 1;
    }
}