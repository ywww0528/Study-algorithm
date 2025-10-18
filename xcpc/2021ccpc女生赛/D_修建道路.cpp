#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[200020], b[200020];
int n;
int max(int a, int b)
{
    return a > b ? a : b;
}
void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += max(a[i], a[i - 1]);
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
