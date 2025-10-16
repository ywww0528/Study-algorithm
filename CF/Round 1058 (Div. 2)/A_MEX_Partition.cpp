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
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
    {
        bool ok = false;
        for (int j = 1; j <= n; j++)
        {
            if (i == a[j])
                ok = true;
        }
        if (!ok)
        {
            cout << i << endl;
            return;
        }
    }
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
