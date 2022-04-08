#include <bits/stdc++.h>
using namespace std;

int comb_no_mem(int n, int k, int n1, int k1, int number[])
{
    if (n == k || k == 0)
    {
        return 1;
    }
    else
    {
        if (n - 1 == n1 && k == k1)
        {
            number[1]++;
        }
        if (n - 1 == n1 && k - 1 == k1)
        {
            number[1]++;
        }
        return comb_no_mem(n - 1, k, n1, k1, number) + comb_no_mem(n - 1, k - 1, n1, k1, number);
    }
}

int comb_mem(int n, int k, int n1, int k1, int C[][34], int number[])
{
    if (C[n][k] != 0)
    {
        return C[n][k];
    }
    else
    {
        if (n == k || k == 0)
        {
            return 1;
        }
        else
        {
            if (n - 1 == n1 && k == k1)
            {
                number[0]++;
            }
            if (n - 1 == n1 && k - 1 == k1)
            {
                number[0]++;
            }
            C[n][k] = comb_mem(n - 1, k, n1, k1, C, number) + comb_mem(n - 1, k - 1, n1, k1, C, number);
            return comb_mem(n - 1, k, n1, k1, C, number) + comb_mem(n - 1, k - 1, n1, k1, C, number);
        }
    }
}

int main()
{
    int arr_input[4];
    while (cin >> arr_input[0] >> arr_input[1] >> arr_input[2] >> arr_input[3])
    {
        int C[34][34] = {0};
        int n = arr_input[0];
        int k = arr_input[1];
        int n1 = arr_input[2];
        int k1 = arr_input[3];
        if (n < k)
        {
            cout << "error" << endl;
        }
        else
        {
            int number[2];
            number[0] = 0;
            number[1] = 0;
            cout << comb_mem(n, k, n1, k1, C, number);
            cout << " " << number[0];
            comb_no_mem(n, k, n1, k1, number);
            cout << " " << number[1] << endl;
        }
    }
    return 0;
}