// range-based for loop
// reference: https://docs.microsoft.com/zh-tw/cpp/cpp/range-based-for-statement-cpp?view=msvc-170

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x[10] = {1,
                 2,
                 3,
                 4,
                 5,
                 6,
                 7,
                 8,
                 9,
                 10};

    /* range-based for loop to iterate through the array*/
    for (int y : x)
    {
        cout << y << " ";
    }
    cout << endl;

    /*The auto keyword causes type inference to be used. */
    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << endl;

    /*By reference*/
    for (auto &y : x)
    {
        y = 0;
        cout << y << " ";
    }

    return 0;
}