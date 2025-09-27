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
    int n;
    cin >> n;
    vector<int> ls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ls[i];
    }
    vector<int> a(n, 0);
    for (int x : ls)
    {
        a[x - 1]++;
    }
    sort(a.begin(), a.end());
    int s = 0;
    for (int count : a)
    {
        s += count;
    }
    int ans = s;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, s - (n - i) * a[i]);
    }
    cout << n - ans << endl;
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
