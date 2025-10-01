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

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    int cnt = 0;
    int cc = c[k];
    for (int i = 0; i < k; i++)
    {
        if (c[i] == 0)
            cnt++;
    }
    int ans = max(cnt, cc);
    cout << ans << endl;
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
