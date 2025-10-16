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
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    int aa, bb;
    cin >> aa >> bb;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int aaa, bbb;
        aaa = (aa * a % mod - b * bb % mod + mod) % mod;
        bbb = (aa * b % mod + a * bb % mod + mod) % mod;
        aa = aaa;
        bb = bbb;
    }
    cout << aa << " " << bb << endl;
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
