#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<char> ch;
vector<char> re;
int inputch(int n, int val)
{
    int k = 0;
    while (val != 0)
    {
        re[k] = (char)((val % 10) + '0');
        val /= 10;
        k++;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        ch[n] = re[i];
        n++;
    }
    return n;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    int len;
    re.clear();
    re.resize(10000);
    ch.clear();
    ch.resize(10000);
    while (cin >> s)
    {
        len = s.length();
        int t;
        for (t = 1; t < 10000; t++)
        {
            int le = 0;
            for (int i = 0; i < len; i++)
            {
                le = inputch(le, (int)(s[i] - 'A' + t));
            }
            //cout<<"le:"<<le<<endl;
            while (le > 3)
            {
                for (int i = 0; i < le - 1; i++)
                {
                    ch[i] = (char)('0' + ((ch[i] - '0' + ch[i + 1] - '0') % 10));
                }
                le--;
            }
            if (ch[0] == '1' && (ch[1] == '0' && ch[2] == '0'))
            {
                cout << t << endl;
                break;
            }
        }
        if (t == 10000)
        {
            cout << ":(" << endl;
        }
    }
    return 0;
}