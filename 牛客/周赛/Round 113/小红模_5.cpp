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
const int mod = 1e9 + 7;
int f[200020];
void solve()
{
    int n;
    cin >> n;
    f[0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = (i * f[i - 1]) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        res = (res + f[n - 1] * (i % 10 % 5) % mod) % mod;
    }
    cout << res << endl;
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
