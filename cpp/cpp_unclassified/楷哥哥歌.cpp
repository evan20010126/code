#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

vector<vector<pair<int, int>>> mp;
queue<pair<int, int>> qu;
vector<pair<int, int>> ans;

int main()
{

    int lx, ly, bx, by, ex, ey;
    cin >> lx >> ly >> bx >> by >> ex >> ey;
    bx--;
    by--;
    ex--;
    ey--;

    mp.resize(lx, vector<pair<int, int>>(ly));
    while (!qu.empty())
    {
        qu.pop();
    }

    char k;
    for (int i = 0; i < lx; i++)
    {
        for (int j = 0; j < ly; j++)
        {
            cin >> k;
            if (k == '0')
            {
                mp[i][j].first = INT32_MAX;
                mp[i][j].second = INT32_MAX;
            }
            else
            {
                mp[i][j].first = -1;
                mp[i][j].second = -1;
            }
        }
    }

    qu.push(make_pair(bx, by));
    mp[bx][by].first = -2;
    pair<int, int> pa;

    while (!qu.empty())
    {
        pa = qu.front();
        qu.pop();

        if (pa.first - 1 >= 0)
        {
            if (mp[pa.first - 1][pa.second].first != -1)
            {
                if (mp[pa.first - 1][pa.second].first == INT32_MAX)
                {
                    mp[pa.first - 1][pa.second].first = pa.first;
                    mp[pa.first - 1][pa.second].second = pa.second;
                    if (pa.first - 1 == ex && pa.second == ey)
                        break;
                    qu.push(make_pair(pa.first - 1, pa.second));
                }
            }
        }

        if (pa.first - 1 >= 0 && pa.second + 1 < ly)
        {
            if (mp[pa.first - 1][pa.second + 1].first != -1)
            {
                if (mp[pa.first - 1][pa.second + 1].first == INT32_MAX)
                {
                    mp[pa.first - 1][pa.second + 1].first = pa.first;
                    mp[pa.first - 1][pa.second + 1].second = pa.second;
                    if (pa.first - 1 == ex && pa.second + 1 == ey)
                        break;
                    qu.push(make_pair(pa.first - 1, pa.second + 1));
                }
            }
        }

        if (pa.second + 1 < ly)
        {
            if (mp[pa.first][pa.second + 1].first != -1)
            {
                if (mp[pa.first][pa.second + 1].first == INT32_MAX)
                {
                    mp[pa.first][pa.second + 1].first = pa.first;
                    mp[pa.first][pa.second + 1].second = pa.second;
                    if (pa.first == ex && pa.second + 1 == ey)
                        break;
                    qu.push(make_pair(pa.first, pa.second + 1));
                }
            }
        }

        if (pa.first + 1 < lx && pa.second + 1 < ly)
        {
            if (mp[pa.first + 1][pa.second + 1].first != -1)
            {
                if (mp[pa.first + 1][pa.second + 1].first == INT32_MAX)
                {
                    mp[pa.first + 1][pa.second + 1].first = pa.first;
                    mp[pa.first + 1][pa.second + 1].second = pa.second;
                    if (pa.first + 1 == ex && pa.second + 1 == ey)
                        break;
                    qu.push(make_pair(pa.first + 1, pa.second + 1));
                }
            }
        }

        if (pa.first + 1 < lx)
        {
            if (mp[pa.first + 1][pa.second].first != -1)
            {
                if (mp[pa.first + 1][pa.second].first == INT32_MAX)
                {
                    mp[pa.first + 1][pa.second].first = pa.first;
                    mp[pa.first + 1][pa.second].second = pa.second;
                    if (pa.first + 1 == ex && pa.second == ey)
                        break;
                    qu.push(make_pair(pa.first + 1, pa.second));
                }
            }
        }

        if (pa.first + 1 < lx && pa.second - 1 >= 0)
        {
            if (mp[pa.first + 1][pa.second - 1].first != -1)
            {
                if (mp[pa.first + 1][pa.second - 1].first == INT32_MAX)
                {
                    mp[pa.first + 1][pa.second - 1].first = pa.first;
                    mp[pa.first + 1][pa.second - 1].second = pa.second;
                    if (pa.first + 1 == ex && pa.second - 1 == ey)
                        break;
                    qu.push(make_pair(pa.first + 1, pa.second - 1));
                }
            }
        }

        if (pa.second - 1 >= 0)
        {
            if (mp[pa.first][pa.second - 1].first != -1)
            {
                if (mp[pa.first][pa.second - 1].first == INT32_MAX)
                {
                    mp[pa.first][pa.second - 1].first = pa.first;
                    mp[pa.first][pa.second - 1].second = pa.second;
                    if (pa.first == ex && pa.second - 1 == ey)
                        break;
                    qu.push(make_pair(pa.first, pa.second - 1));
                }
            }
        }

        if (pa.first - 1 >= 0 && pa.second - 1 >= 0)
        {
            if (mp[pa.first - 1][pa.second - 1].first != -1)
            {
                if (mp[pa.first - 1][pa.second - 1].first == INT32_MAX)
                {
                    mp[pa.first - 1][pa.second - 1].first = pa.first;
                    mp[pa.first - 1][pa.second - 1].second = pa.second;
                    if (pa.first - 1 == ex && pa.second - 1 == ey)
                        break;
                    qu.push(make_pair(pa.first - 1, pa.second - 1));
                }
            }
        }
    }
    for (int key = 0; key <= 999; key++)
        for (int p = 0; p <= key; p++)
            ;
    int anslong = 0;
    int x, y;
    int rex, rey;
    for (x = ex, y = ey; (x != -1 && y != -1); x = mp[rex][rey].first, y = mp[rex][rey].second)
    {
        anslong++;
        ans.push_back(make_pair(x, y));
        if (x == bx && y == by)
            break;
        rex = x;
        rey = y;
    }

    cout << anslong << '\n';
    for (int i = anslong - 1; i >= 0; i--)
    {
        cout << "(" << ans[i].first + 1 << "," << ans[i].second + 1 << ")" << endl; //00->11
    }
    return 0;
}
