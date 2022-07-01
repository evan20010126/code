#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxHeight(vector<vector<int>> &w)
{
    // 先?行排序
    for (auto &s : w)
        sort(s.begin(), s.end());
    sort(w.begin(), w.end(), greater<vector<int>>());

    int n = w.size();
    vector<int> f(n);
    int res = 0;

    // 01背包
    for (int i = 0; i < n; i++)
    {
        f[i] = w[i][2];
        for (int j = 0; j < i; j++)
        {
            // 升序排序，所以?前??高必?小于上次??的??高
            if (w[i][0] <= w[j][0] && w[i][1] <= w[j][1] && w[i][2] <= w[j][2])
            {
                f[i] = max(f[i], f[j] + w[i][2]);
            }
        }
        res = max(res, f[i]);
    }
    return res;
}

int main()
{
    int input1, input2, input3;
    vector<vector<int>> w;
    while (cin >> input1)
    {
        if (input1 == 0)
        {
            cout << maxHeight(w) << endl;
            w.clear();
        }
        else
        {
            cin >> input2 >> input3;
            vector<int> temp1;
            temp1.push_back(input1);
            temp1.push_back(input2);
            temp1.push_back(input3);
            w.push_back(temp1);
        }
    }
}