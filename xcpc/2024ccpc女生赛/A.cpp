#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long

void solve()
{
    int z0, h, u0, v0, u1, v1;
    cin >> z0 >> h >> u0 >> v0 >> u1 >> v1;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z < z0 || z > z0 + h)
        {
            cout << "NO" << endl;
            continue;
        }
        int xx = max(u0, u1), xm = min(u0, u1);
        int yy = max(v0, v1), ym = min(v0, v1);
        if (x > xx || x < xm)
        {
            cout << "NO" << endl;
            continue;
        }
        if (y > yy || y < ym)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
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
