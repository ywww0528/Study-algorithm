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
    int ma = 0;
    vector<int> a(n + 1, 0);
    vector<int> ans(n + 1, 0);
    vector<int> hs(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > i)
        {
            cout << "-1" << endl;
            return;
        }
        hs[a[i]]++;
        ma = max(ma, a[i]);
    }
    for (int i = 1; i <= ma; i++)
    {
        if (hs[i] == 0)
        {
            cout << "-1" << endl;
            return;
        }
    }
    vector<vector<int>> cnt(ma + 1);
    deque<int> qu;
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]].push_back(i);
    }
    for (int i = 1; i <= ma; i++)
    {
        for (int j = cnt[i].size() - 1; j >= 0; j--)
        {
            qu.push_back(cnt[i][j]);
        }
    }
    int c = 1;
    while (!qu.empty())
    {
        int tem = qu.front();
        ans[tem] = c;
        c++;
        qu.pop_front();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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
