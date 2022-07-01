//Bangla Numbers
// 網路解答https://jennaweng0621.pixnet.net/blog/post/385350754-uva10101-bangla-numbers

#include <iostream>
using namespace std;

void segmentation(long long int);

int main()
{
    long long int input;
    int time = 0;
    while (cin >> input)
    {
        cout << (++time) << ". ";
        if (input == 0)
        {
            cout << 0;
        }
        else
        {
            segmentation(input);
        }
        cout << "\n";
    }
    return 0;
}

void segmentation(long long int num)
{
    if (num / 10000000 != 0)
    {
        segmentation(num / 10000000);
        cout << "kuti ";
        num = num % 10000000;
    }
    if (num / 100000 != 0)
    {
        cout << num / 100000 << " lakh ";
        num = num % 100000;
    }
    if (num / 1000 != 0)
    {
        cout << num / 1000 << " hajar ";
        num = num % 1000;
    }
    if (num / 100 != 0)
    {
        cout << num / 100 << " shata ";
        num = num % 100;
    }
    if (num)
    {
        cout << num << " ";
    }
}