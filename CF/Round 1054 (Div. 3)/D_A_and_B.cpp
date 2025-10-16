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
int n;
int get(vector<int> a)
{
    if (a.empty())
        return 0;
    int pos = a.size() / 2;
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        res += abs(a[pos] - a[i]) - abs(pos - i);
    }
    return res;
}
void solve()
{

    cin >> n;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        char tem;
        cin >> tem;
        if (tem == 'a')
        {
            a.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    int ans = 0;
    ans = min(get(a), get(b));
    cout << ans << endl;
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
