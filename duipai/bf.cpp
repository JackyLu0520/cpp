#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
using db = double;
int n, k;
int s[N];
bool check(db mid)
{
    multiset<db> ss;
    ss.insert(0);
    db las = s[n] - mid * n;
    if (las < 0)
        return false;
    for (int i = 1; i < n; i++)
    {
        db x = s[i] - mid * i;
        if (x < 0)
            continue;
        if (x > las)
            continue;
        auto it = ss.upper_bound(x);
        if (it != ss.end())
            ss.erase(it);
        ss.insert(x);
    }
    return ss.size() >= k;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            s[i] = s[i - 1] + x;
        }
        db l = 0, r = 1000;
        for (int cnt = 1; cnt <= 30; cnt++)
        {
            db mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        cout << fixed << setprecision(12) << l << "\n";
    }
    return 0;
}