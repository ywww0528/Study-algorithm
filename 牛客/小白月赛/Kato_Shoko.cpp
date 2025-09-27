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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = "Kato_Shoko";
    map<char, int> mp1, mp2;
    for (auto it : ss)
        mp1[it]++;
    for (auto it : s)
        mp2[it]++;
    for (auto [a, b] : mp1)
    {
        if (mp2[a] < b)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << " ";
    cout << n - ss.size() << endl;
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
