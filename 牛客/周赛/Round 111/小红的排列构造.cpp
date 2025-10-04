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
int a[200020];
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    int cnt = n - k;
    if (cnt < 1 || cnt > n / 2)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < cnt - 1; i++)
    {
        swap(a[i * 2 + 1], a[i * 2 + 2]);
    }

    int s = 2 * (cnt - 1) + 1;
    int t = n;
    if (t - s >= 1)
    {
        int tmp = a[s];
        for (int i = s; i < t; i++)
        {
            a[i] = a[i + 1];
        }
        a[t] = tmp;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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
