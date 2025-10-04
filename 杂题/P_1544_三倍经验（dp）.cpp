#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define int long long
int a[110][110];
int dp[110][110][110];
void solve()
{
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int p = 0; p <= k; p++)
            {
                dp[i][j][p] = -1e18;
            }
        }
    }
    dp[1][1][0] = a[1][1];
    dp[1][1][1] = 3 * a[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int p = 0; p <= k; p++)
            {
                dp[i + 1][j][p] = max(dp[i + 1][j][p], dp[i][j][p] + a[i + 1][j]);
                dp[i + 1][j + 1][p] = max(dp[i + 1][j + 1][p], dp[i][j][p] + a[i + 1][j + 1]);
                dp[i + 1][j][p + 1] = max(dp[i + 1][j][p + 1], dp[i][j][p] + a[i + 1][j] * 3);
                dp[i + 1][j + 1][p + 1] = max(dp[i + 1][j + 1][p + 1], dp[i][j][p] + a[i + 1][j + 1] * 3);
            }
        }
    }
    int ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int p = 0; p <= k; p++)
        {
            ans = max(ans, dp[n][i][p]);
        }
    }
    cout << ans << endl;
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
