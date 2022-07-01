#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define w_w 0
#define endl '\n'
vector<pair<int, int>> arr;
queue<pair<int, pair<int, int>>> qu;
void bfs()
{
    int sp, n, pa;
    pair<int, pair<int, int>> papp;
    // clear
    while (!qu.empty())
    {
        qu.pop();
    }
    papp.first = 1;
    papp.second.first = 0 + w_w;
    papp.second.second = 0;
    qu.push(papp);

    while (!qu.empty())
    {
        papp = qu.front();
        qu.pop();
        sp = papp.first;
        n = papp.second.first;
        pa = papp.second.second;

        int ne = n + sp;

        pa++;
        if (ne >= 100000 || ne <= 0)
            continue;
        papp.first = sp * 2;
        papp.second.first = ne;
        papp.second.second = pa;
        qu.push(papp);

        if (arr[ne].first > pa && sp > 0)
        {
            arr[ne].first = pa;
            papp.first = -1;
            papp.second.first = ne;
            papp.second.second = pa + 1;
            qu.push(papp);

            papp.first = 1;
            papp.second.first = ne;
            papp.second.second = pa + 2;
            qu.push(papp);
        }
        if (sp < 0 && arr[ne].second > pa)
        {
            arr[ne].second = pa;
            papp.first = 1;
            papp.second.first = ne;
            papp.second.second = pa + 1;
            qu.push(papp);

            papp.first = -1;
            papp.second.first = ne;
            papp.second.second = pa + 2;
            qu.push(papp);
        }
    }
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    arr.clear();
    arr.resize(100002, make_pair(2e9, 2e9));
    arr[0 + w_w].first = arr[w_w + 0].second = 0;
    bfs();
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << min(arr[n + w_w].first, arr[n + w_w].second) << endl;
    }
    return 0;
}