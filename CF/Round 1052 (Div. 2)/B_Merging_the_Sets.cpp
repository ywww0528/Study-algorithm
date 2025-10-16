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
    int n, m;
    cin >> n >> m;
    vector<int> hs(m + 1, 0);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            int num;
            cin >> num;
            a[i][j] = num;
            hs[num]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (hs[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    vector<bool> one(m + 1, false);
    for (int i = 1; i <= m; i++)
    {
        if (hs[i] == 1)
        {
            one[i] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        bool f = false;
        for (int num : a[i])
        {
            if (one[num])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            cnt++;
            if (cnt >= 2)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
