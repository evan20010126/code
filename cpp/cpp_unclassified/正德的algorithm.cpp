#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int g[9000];
    int v[9000];
    int w;
    bool first = true;
    cin >> w;
    int a, b, c1;
    int counter = 0;
    int x;
    while (cin >> a >> b >> c1)
    {
        if (a == -1 && b == -1 && c1 == -1)
            break;
        if (first)
        {
            x = a;
            first = false;
        }
        g[a] = b;
        v[a] = c1;
        counter = a;
    }
    int **c;
    c = new int *[counter + 1];
    bool **items;
    items = new bool *[counter + 1];
    for (int i = 0; i <= counter; i++)
    {
        *(c + i) = new int[w + 1];
        *(items + i) = new bool[w + 1];
        for (int j = 0; j <= w; j++)
        {
            c[i][j] = 0;
            items[i][j] = 0;
        }
    }
    for (int i = x; i < counter; i++)
        for (int j = 0; j <= w; j++)
        {
            if (j - g[i] < 0)
                c[i + 1][j] = c[i][j];
            else
            {
                c[i + 1][j] = max(c[i][j - g[i]] + v[i], c[i][j]);
                if (c[i][j - g[i]] + v[i] > c[i][j])
                    items[i][j] = true;
            }
        }
    for (int i = counter, j = w; i >= 0; i--)
    {
        if (items[i][j])
        {
            cout << i << " ";
            j -= g[i];
        }
    }
    cout << endl
         << c[counter][w] << endl;
    return 0;
}