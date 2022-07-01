/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;

struct mines
{ //存放地雷的x,y軸
    int x;
    int y;
    mines *next;
};

mines *h = nullptr;

mines *x_sort(int k);

int detonate_count();

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    mines *t; // h紀錄該串列的起始
    for (int i = 0; i < c; i++)
    { //建立鏈結串列d
        mines *mine = new mines;
        cin >> mine->x >> mine->y;
        mine->next = nullptr;
        if (h == nullptr)
        {
            h = mine;
            t = mine;
        }
        else
        {
            t->next = mine;
            t = mine;
        }
    }
    h = x_sort(c - 1);                //針對地雷的x軸做排序
    cout << detonate_count() << endl; //計算引爆次數
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

mines *x_sort(int k)
{ // k is last index
    for (int i = k - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if ()
        }
    }
}

// mines *x_sort(int k)
// {
//     return h;
// }
// int detonate_count()
// {
//     bool re[102][102];
//     for (int i = 0; i < 102; i++)
//     {
//         for (int j = 0; j < 102; j++)
//         {
//             re[i][j] = true;
//         }
//     }
//     mines *u = h;
//     int ans = 0;
//     while (u != nullptr)
//     {
//         int x = u->x;
//         int y = u->y;
//         int now = 0;
//         if (re[x - 1][y] == false)
//         {
//             now += 1;
//         }
//         re[x - 1][y] = false;
//         if (re[x + 1][y - 1] == false)
//         {
//             now += 1;
//         }
//         re[x + 1][y - 1] = false;
//         if (re[x + 1][y] == false)
//         {
//             now += 1;
//         }
//         re[x + 1][y] = false;
//         if (re[x + 1][y + 1] == false)
//         {
//             now += 1;
//         }
//         re[x + 1][y + 1] = false;
//         if (re[x - 1][y - 1] == false)
//         {
//             now += 1;
//         }
//         re[x - 1][y - 1] = false;
//         if (re[x][y] == false)
//         {
//             now += 1;
//         }
//         re[x][y] = false;
//         if (re[x][y + 1] == false)
//         {
//             now += 1;
//         }
//         re[x][y + 1] = false;
//         if (re[x - 1][y + 1] == false)
//         {
//             now += 1;
//         }
//         re[x - 1][y + 1] = false;
//         if (re[x][y - 1] == false)
//         {
//             now += 1;
//         }
//         re[x][y - 1] = false;
//         p = p->next;
//         if (now == 0)
//         {
//             ans = ans + 1;
//         }
//     }
//     return ans;
// }