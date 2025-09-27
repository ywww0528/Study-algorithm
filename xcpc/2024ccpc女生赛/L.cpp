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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < 4)
    {
        cout << 0 << endl;
        return;
    }
    int ans = min(b, c);
    int res = 4;
    for (int i = 1; i <= ans; i++)
    {
        int xx = i;
        int yy = min(ans - xx, d / xx);
        res = max(res, (xx + 2) * (yy + 2));
    }
    res = max(res, 4 + ans * 2);
    cout << res << endl;
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