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
const int mod = 1e9 + 7;
int f[220][220], g[220][220];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    g[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(m, i); j >= 1; j--)
        {
            for (int p = min(k, j); p >= 1; p--)
            {
                if (a[i] == b[j])
                {
                    f[j][p] = (f[j - 1][p] + g[j - 1][p - 1]) % mod;
                }
                else
                {
                    f[j][p] = 0;
                }
                g[j][p] = (g[j][p] + f[j][p]) % mod;
            }
        }
    }
    cout << g[m][k] << endl;
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
