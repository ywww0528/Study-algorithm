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
    int c2 = 0, c3 = 0, c5 = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        int tt = t;
        while (tt % 2 == 0)
        {
            c2++;
            tt /= 2;
        }
        tt = t;
        while (tt % 3 == 0)
        {
            c3++;
            tt /= 3;
        }
        tt = t;
        while (tt % 5 == 0)
        {
            c5++;
            tt /= 5;
        }
    }
    cout << min({c2, c3, c5});
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
