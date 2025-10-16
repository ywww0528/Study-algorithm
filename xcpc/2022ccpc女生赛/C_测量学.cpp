#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pai 3.1415926
void solve()
{
    double n, R, c;
    cin >> n >> R >> c;
    vector<double> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    double ans;
    c = min(c, 2 * pai - c);
    if (c <= 2)
    {
        ans = R * c;
    }
    else
    {
        ans = r[n] * c + 2 * (R - r[n]);
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
