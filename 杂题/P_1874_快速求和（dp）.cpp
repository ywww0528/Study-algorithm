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
int dp[45][100010];
int num[45][100010];
string s;
int cnt = 0;
void solve()
{
    cin >> s >> cnt;
    int len = s.size();
    for (int i = 1; i <= len; i++)
    {
        for (int j = i; j <= len; j++)
        {
            num[i][j] = num[i][j - 1] * 10 + (s[j - 1] - '0');
        }
    }
    memset(dp, 0x3f3f3f, sizeof(dp));
    dp[0][0] = -1;
    for (int i = 1; i <= len; i++)
    {
        for (int k = 0; k <= cnt; k++)
        {
            for (int j = i; j >= 0 && num[j + 1][i] <= cnt; j--)
            {
                if (k >= num[j + 1][i])
                {
                    dp[i][k] = min(dp[i][k], dp[j][k - num[j + 1][i]] + 1);
                }
            }
        }
    }
    if (dp[len][cnt] < 45)
    {
        cout << dp[len][cnt];
    }
    else
    {
        cout << -1 << endl;
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
