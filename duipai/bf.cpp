#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10009];
int ans = INT_MIN;
void dfs(int x, int u, int a[10009])
{
    int b[10009];
    if (x == 0)
    {
        ans = max(ans, a[1]);
        return;
    }
    if (u != 0)
    {
        for (int i = 1; i <= x; i++)
        {
            b[i] = max(a[i], a[i + 1]);
        }
        dfs(x - 1, u - 1, b);
    }
    for (int i = 1; i <= x; i++)
    {
        b[i] = min(a[i], a[i + 1]);
    }
    dfs(x - 1, u, b);
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(n - 1, m, a);
    cout << ans << endl;
    return 0;
}