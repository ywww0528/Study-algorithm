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
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
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
