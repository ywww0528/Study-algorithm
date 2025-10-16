#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long

void solve()
{
    int x, t, k, n, d;
    cin >> x >> t >> k >> n >> d;
    vector<int> a(2 * n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int ini = x;
    vector<int> b(2 * n + 5);
    int xx = x;
    int cnt = 0;
    bool ok = false;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[i] <= d)
            xx--;
        else
            xx++;

        b[i] = xx;

        if (xx <= k)
            cnt++;
        else
            cnt = 0;

        if (cnt >= t)
        {
            ok = true;
            break;
        }
    }

    if (ok)
    {
        cout << "YES\n";
        return;
    }
    int de = ini;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= d)
            de--;
        else
            de++;
    }
    int del = de - ini;

    if (del < 0)
    {
        cout << "YES\n";
    }
    else if (del > 0)
    {
        cout << "NO\n";
    }
    else
    {
        bool f = true;
        int cur = ini;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= d)
                cur--;
            else
                cur++;
            if (cur > k)
                f = false;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
