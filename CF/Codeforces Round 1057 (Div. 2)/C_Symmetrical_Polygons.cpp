#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cstring>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        vector<int> b(a.begin(), a.begin() + i);
        int S = accumulate(b.begin(), b.end(), 0);
        map<int, int> freq;
        for (int x : b)
        {
            freq[x]++;
        }
        vector<int> O;
        for (auto &p : freq)
        {
            if (p.second % 2 == 1)
            {
                O.push_back(p.first);
            }
        }
        int K = O.size();

        if (i - K >= 3)
        {
            int T0 = S;
            for (int x : O)
            {
                T0 -= x;
            }
            int M0 = 0;
            for (auto &p : freq)
            {
                if (p.second >= 2)
                {
                    if (p.first > M0)
                    {
                        M0 = p.first;
                    }
                }
            }
            if (T0 > 0 && M0 < T0 / 2.0)
            {
                ans = max(ans, T0);
            }
        }

        if ((K >= 1 && i - K + 1 >= 3) || (K == 0 && i - 1 >= 3))
        {
            int T1;
            if (K == 0)
            {
                T1 = S - b[0];
            }
            else
            {
                int sum_O = accumulate(O.begin(), O.end(), 0);
                T1 = S - sum_O + *max_element(O.begin(), O.end());
            }
            int M1 = b[i - 1];
            if (T1 > 0 && M1 < T1 / 2.0)
            {
                ans = max(ans, T1);
            }
        }

        if (K == 0 || K == 2)
        {
            if (i >= 3)
            {
                int T2 = S;
                int M2 = b[i - 1];
                if (M2 < T2 / 2.0)
                {
                    ans = max(ans, T2);
                }
            }
        }
        else if (K == 1)
        {
            if (i - 1 >= 3)
            {
                int T2 = S - b[0];
                int M2 = b[i - 1];
                if (M2 < T2 / 2.0)
                {
                    ans = max(ans, T2);
                }
            }
        }
        else
        {
            if (i - K >= 3)
            {
                int T2A = S;
                for (int x : O)
                {
                    T2A -= x;
                }
                int M2A = 0;
                for (auto &p : freq)
                {
                    if (p.second >= 2)
                    {
                        if (p.first > M2A)
                        {
                            M2A = p.first;
                        }
                    }
                }
                if (T2A > 0 && M2A < T2A / 2.0)
                {
                    ans = max(ans, T2A);
                }
            }
            if (i - K + 2 >= 3)
            {
                sort(O.begin(), O.end());
                int sum_small = 0;
                for (int j = 0; j < K - 2; j++)
                {
                    sum_small += O[j];
                }
                int T2B = S - sum_small;
                int M2B = b[i - 1];
                if (T2B > 0 && M2B < T2B / 2.0)
                {
                    ans = max(ans, T2B);
                }
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
