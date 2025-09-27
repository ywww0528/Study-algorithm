#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> a;
int dfs(int u, int num)
{
    if (a[u].empty())
        return 0;
    int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f;
    for (int v : a[u])
    {
        int dex = dfs(v, num);
        if (dex == 0x3f3f3f3f)
            return 0x3f3f3f3f;

        if (dex + 1 > num)
            return 0x3f3f3f3f;
        mn = min(mn, dex + 1);
        mx = max(mx, dex + 1);
    }
    if (mx > num)
        return 0x3f3f3f3f;
    else
        return mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            a[x].push_back(i + 1);
        }
        int l = 0;
        int r = n - 1;
        int num = r;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (dfs(1, m) != 0x3f3f3f3f)
            {
                num = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << num << endl;
    }
    return 0;
}