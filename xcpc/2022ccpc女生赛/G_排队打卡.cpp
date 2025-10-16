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
typedef long long ll;
const ll MM = 1e18;
const int N = 5e5 + 10;
struct node
{
    ll aa, bb;
} e[N];

bool cmp(node x, node y)
{
    return x.aa < y.aa;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t, n;
    cin >> t >> n;
    ll m, k;
    cin >> m >> k;
    ll flag = 0;
    ll tt = 1, sum = MM;
    ll vv = 0;
    ll dex = 0;
    ll dd = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].aa >> e[i].bb;
    }
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        ll a = e[i].aa;
        ll b = e[i].bb;
        if (dd == 1)
        {
            cout << "Wrong Record" << endl;
            return 0;
        }
        ll v1 = vv;
        if (i == 1)
        {
            vv = a;
        }
        ll kk = dex;
        if (i >= 2)
        {
            if (dex >= (a - vv) * k)
            {
                dex -= (a - vv) * k;
            }
            else
                dex = 0;
            vv = a;
        }
        if ((a >= t && flag == 0))
        {
            if (i == 1)
            {
                if (n != 0)
                {
                    cout << "Wrong Record" << endl;
                    return 0;
                }
            }
            else
            {
                if (kk >= (t - v1) * k)
                {
                    kk -= (t - v1) * k;
                }
                else
                    kk = 0;
            }
            if (n != kk)
            {
                cout << "Wrong Record" << endl;
                return 0;
            }
            else
            {
                flag = 1;
            }
        }
        dex += b;
        if (flag == 1)
        {
            dex += 1;
            ll kk;
            if (dex % k == 0)
            {
                kk = (dex / k);
            }
            else
            {
                kk = dex / k + 1;
            }
            if (kk < sum)
            {
                sum = kk;
                tt = a;
            }
            else if (kk == sum)
            {
                tt = a;
            }
            dex -= 1;
        }
    }
    cout << tt << " " << sum << endl;
    return 0;
}