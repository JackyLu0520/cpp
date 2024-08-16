#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int n, m, k, g[N];
int father[N], siz[N], tim[N], dep[N];
int find(int x)
{
    if (x == father[x])
    {
        return x;
    }
    int fa = find(father[x]);
    dep[x] = dep[father[x]] + 1;
    return fa;
}
void un(int x, int y, int t)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    if (siz[x] < siz[y])
    {
        father[x] = y;
        siz[y] += siz[x];
        tim[x] = t;
    }
    else
    {
        father[y] = x;
        siz[x] += siz[y];
        tim[y] = t;
    }
}
int merge(int u, int v)
{
    if (find(u) != find(v))
    {
        return -1;
    }
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    int ans = 0;
    while (dep[u] != dep[v])
    {
        if (tim[u] > ans)
        {
            ans = tim[u];
        }
        u = father[u];
    }
    while (u != v)
    {
        if (tim[u] > ans)
        {
            ans = tim[u];
        }
        if (tim[v] > ans)
        {
            ans = tim[v];
        }
        u = father[u];
        v = father[v];
    }
    return ans;
}
struct query
{
    int c, d, id, t;
} w[500005];
inline bool cmp(query x, query y)
{
    if (x.t != y.t)
    {
        return x.t < y.t;
    }
    return x.id < y.id;
}
signed main()
{
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        siz[i] = 1;
        cin >> g[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        un(a, b, i);
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        int c, d;
        cin >> c >> d;
        int t = merge(c, d);
        if (t == -1)
        {
            continue;
        }
        else
        {
            w[++cnt] = (query){c, d, i, t};
        }
    }
    sort(w + 1, w + cnt + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int val = min(g[w[i].c], g[w[i].d]);
        g[w[i].c] -= val;
        g[w[i].d] -= val;
        ans += val << 1;
    }
    cout << ans << endl;
    return 0;
}