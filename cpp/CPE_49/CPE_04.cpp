// The 3n+1 problem
#include <iostream>
using namespace std;

int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        cout << i << " " << j << " ";
        int answer = 0;
        if (i > j)
        {
            int buffer;
            buffer = j;
            j = i;
            i = buffer;
        }
        for (; i <= j; i++)
        {
            int count = 1;
            int n = i;
            while (n != 1)
            {
                count++;
                if (n % 2 == 1)
                    n = 3 * n + 1;
                else
                    n = n / 2;
            }
            if (answer < count)
                answer = count;
        }
        cout << answer << endl;
    }

    return 0;
}