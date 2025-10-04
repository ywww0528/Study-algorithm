#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m, k;
int ii[105], jj[105], op[105], a[105], b[105], d[105], v[105];
typedef long long ll;
ll mx = -1;
void dfs1(string s)
{
    // cout<<s<<endl;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (op[i] == 0)
        {
            if (a[i] * (s[ii[i] - 1] - '0') + b[i] * (s[jj[i] - 1] - '0') <= d[i])
            {
                sum += v[i];
            }
        }
        else if (op[i] == 1)
        {
            if (a[i] * (s[ii[i] - 1] - '0') + b[i] * (s[jj[i] - 1] - '0') >= d[i])
            {
                sum += v[i];
            }
        }
    }
    mx = max(sum, mx);
}
void dfs(int dex, string s)
{
    if (dex == n)
    {
        dfs1(s);
        return;
    }
    for (int i = 0; i <= k; i++)
    {
        dfs(dex + 1, s + to_string(i));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> ii[i] >> jj[i] >> op[i] >> a[i] >> b[i] >> d[i] >> v[i];
    }
    dfs(0, "");
    cout << mx << endl;
    return 0;
}