#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 5e6 + 10;
int a[N];
int mx[N][30];
int mn[N][30];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
void init(int n)
{
    for (int i = 0; i <= n + 1; i++)
    {
        mx[i][0] = a[i];
        mn[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) <= n + 1; i++)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int search(int l, int r)
{
    int k = log2(r - l + 1);
    int t1 = min(mn[l][k], mn[r - (1 << k) + 1][k]);
    int t2 = max(mx[l][k], mx[r - (1 << k) + 1][k]);
    return t2;
}
int qzh[1000009];
signed main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int n, q;
        n = read();
        q = read();
        for (int i = 0; i <= n + 2; i++)
        {
            a[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (i == 1)
            {
                a[i] += q;
            }
            qzh[i] = qzh[i - 1] + a[i];
        }
        n += 2;
        init(n);
        // while (q--)
        // {
        //     int l, r;
        //     l = read();
        //     r = read();
        //     cout << search(l, r) << endl;
        // }
        for (int i = 1; i <= n - 2; i++)
        {
            // cout << "i=" << i << endl;
            int maxn = search(0, i - 1);
            // cout<< "i=" << i << ' ' << "maxn=" << maxn << endl;
            if (maxn < a[i])
            {
                int umaxn = search(i + 1, n);
                if (umaxn <= a[i])
                {
                    cout << 0 << ' ';
                }
                else
                {
                    int o = qzh[i];
                    if (o >= umaxn)
                    {
                        cout << i - 1 << ' ';
                    }
                    else
                    {
                        cout << i << ' ';
                    }
                }
            }
            // else if (i == 1 && a[i] == maxn)
            // {
            //     if (search(i + 1, n) <= a[i])
            //     {
            //         cout << 0 << ' ';
            //     }
            //     else
            //     {
            //         int umaxn = search(i + 1, n);
            //         if (umaxn <= a[i])
            //         {
            //             cout << 0 << ' ';
            //         }
            //         else
            //         {
            //             int o = qzh[i];
            //             if (o >= umaxn)
            //             {
            //                 cout << i - 1 << ' ';
            //             }
            //             else
            //             {
            //                 cout << i << ' ';
            //             }
            //         }
            //     }
            // }
            else
            {
                int o = qzh[i];
                int umaxn = search(i + 1, n);
                // cout << "i=" << i << ' ' << "hou:" << umaxn << endl;
                if (umaxn <= o)
                {
                    cout << i - 1 << ' ';
                }
                else
                {
                    cout << i << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}
/*
1
3 1
2 0 3

1
5 3
5 4 3 2 1

1
6 0
2 2 2 3 3 5
*/