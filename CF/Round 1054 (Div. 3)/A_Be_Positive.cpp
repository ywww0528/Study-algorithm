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
int a[10];
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            cnt++;
        }
        if (a[i] == -1)
        {
            c++;
        }
    }
    if (c % 2 == 1)
    {
        cnt++;
        cnt++;
    }
    cout << cnt << endl;
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
