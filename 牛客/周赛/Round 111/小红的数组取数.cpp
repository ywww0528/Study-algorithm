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
int mod(int a, int m)
{
    int res = 1, b = m - 2;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % m;
        a = 1LL * a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pow10(11);
    pow10[0] = 1;
    for (int i = 1; i <= 10; i++)
        pow10[i] = (pow10[i - 1] * 10) % 11;
    vector<int> cnt(11, 0);
    for (auto x : a)
    {
        cnt[x % 11]++;
    }
    int ans = 0;
    for (auto B : a)
    {
        int rB = B % 11;
        int lenB = to_string(B).size();
        int p = pow10[lenB % 10];
        int invp = mod(p, 11);
        int tem = ((11 - rB) * invp) % 11;
        ans += cnt[tem];
        if (B % 11 == tem)
            ans--;
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
