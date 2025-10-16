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
    int x, y, z;
    cin >> x >> y >> z;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 64; i++)
    {
        bool xx = (x >> i) & 1;
        bool yy = (y >> i) & 1;
        bool zz = (z >> i) & 1;
        if (xx)
        {
            a |= (1LL << i), b |= (1LL << i);
        }
        if (yy)
        {
            b |= (1LL << i), c |= (1LL << i);
        }
        if (zz)
        {
            a |= (1LL << i), c |= (1LL << i);
        }
    }
    if (((a & b) == x) && ((b & c) == y) && ((a & c) == z))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
