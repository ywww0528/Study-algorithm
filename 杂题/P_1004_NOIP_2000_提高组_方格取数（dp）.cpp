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
int n;
int a[20][20];
int dp[10][10][10][10];
void solve()
{
    cin >> n;
    for (;;)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)
            break;
        a[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    dp[i][j][x][y] = max({dp[i - 1][j][x - 1][y], dp[i][j - 1][x - 1][y], dp[i - 1][j][x][y - 1], dp[i][j - 1][x][y - 1]});
                    if (i == x && j == y)
                    {
                        dp[i][j][x][y] += a[i][j];
                    }
                    else
                    {
                        dp[i][j][x][y] += a[i][j] + a[x][y];
                    }
                }
            }
        }
    }
    cout << dp[n][n][n][n];
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
