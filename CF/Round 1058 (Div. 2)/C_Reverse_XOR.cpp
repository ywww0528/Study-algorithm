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

bool hw(string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

void solve()
{
    int x;
    cin >> x;
    string n = "";
    while (x > 0)
    {
        n += (x % 2 ? '1' : '0');
        x /= 2;
    }
    reverse(n.begin(), n.end());
    if (n.empty())
        n = "0";
    string ans = "NO";
    for (int i = 1; i < 64; i++)
    {
        if ((int)n.size() <= i)
        {
            string w = string(i - n.size(), '0') + n;
            bool B = hw(w);
            if (i % 2 == 1 && w[i / 2] != '0')
                B = false;
            if (B)
                ans = "YES";
        }
    }
    cout << ans << "\n";
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
