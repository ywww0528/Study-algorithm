#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[200020], b[200020];

void solve()
{
    bool r = false, l = false;
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    string s2;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        s2 += to_string(b[i]);
    }
    string rs;
    if (x < y)
    {
        for (int i = x + 1; i <= y; i++)
            rs += to_string(a[i]);
    }
    else
    {
        for (int i = x - 1; i >= y; i--)
            rs += to_string(a[i]);
    }
    string ls;
    if (x < y)
    {
        for (int i = x - 1; i >= 1; i--)
            ls += to_string(a[i]);
    }
    else
    {
        for (int i = x + 1; i <= n; i++)
            ls += to_string(a[i]);
    }

    if (rs.substr(0, s2.size()) == s2)
        r = true;
    if (ls.substr(0, s2.size()) == s2)
        l = true;

    if (r == 1 && l == 1)
    {
        cout << "Unsure\n";
    }
    else if (r == 1)
    {
        cout << "Right\n";
    }
    else
    {
        cout << "Wrong\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
