#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < (int)s.size(); j++)
        {
            if (s[j] == '-')
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
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