#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int a[200020];
int b[200020];
int c[200020];
int sum = 0;
int n;
void solve()
{
    int n;
    cin >> n;
    printf("%.15f", 1.0 / n);
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