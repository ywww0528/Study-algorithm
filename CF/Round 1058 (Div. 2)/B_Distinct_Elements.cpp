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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int diff = a[i + 1] - a[i];
        if (i - diff >= 0)
            res.push_back(res[i - diff]);
        else
            res.push_back(i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
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
