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
const double g2 = 1.41421356233;
void solve()
{
    string s;
    cin >> s;
    double ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
        else if (cnt > 0)
        {
            if (cnt % 2)
            {
                ans += (cnt + 1) / 2;
            }
            else
            {
                ans += (cnt - 2) / 2 + g2;
            }
            cnt = 0;
        }
    }
    if (cnt > 0 && cnt % 2)
    {
        ans += (cnt + 1) / 2;
    }
    else if (cnt > 0 && cnt % 2 == 0)
    {
        ans += (cnt - 2) / 2 + g2;
    }
    printf("%.10lf\n", ans);
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
