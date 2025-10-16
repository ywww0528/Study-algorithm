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
int get(vector<int> &a, int k, int len)
{
    map<int, int> map;
    int cnt = 0, l = 1, ans = 0;
    for (int r = 1; r < a.size(); r++)
    {
        if (map[a[r]] == 0)
            cnt++;
        map[a[r]]++;
        while (r - l + 1 > len || cnt > k)
        {
            map[a[l]]--;
            if (map[a[l]] == 0)
                cnt--;
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}
void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = get(a, k, r) - get(a, k, l - 1) - get(a, k - 1, r) + get(a, k - 1, l - 1);
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
