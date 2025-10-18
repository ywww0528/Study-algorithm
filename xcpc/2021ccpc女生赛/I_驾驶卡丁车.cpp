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
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
void solve()
{
    int n, m;
    cin >> n >> m;
    int pox, poy;
    vector<vector<char>> a(n + 1, vector<char>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '*')
            {
                pox = i;
                poy = j;
            }
        }
    }
    int k;
    cin >> k;
    int kk = k;
    int v = 0;
    int dir = 0;
    while (k--)
    {
        char ch;
        cin >> ch;
        if (ch == 'U')
        {
            v++;
        }
        else if (ch == 'D')
        {
            v = max(v - 1, 0LL);
        }
        else if (ch == 'L')
        {
            dir--;
            dir = (dir + 8) % 8;
        }
        else if (ch == 'R')
        {
            dir++;
            dir = (dir + 8) % 8;
        }
        for (int i = 1; i <= v; i++)
        {
            int xx = pox + dx[dir];
            int yy = poy + dy[dir];
            if (xx > n || xx < 1 || yy > m || yy < 1)
            {
                cout << "Crash!" << " ";
                v = 0;
                break;
            }
            if (a[xx][yy] == '#')
            {
                cout << "Crash!" << " ";
                v = 0;
                break;
            }
            if (dx[dir] != 0 && dy[dir] != 0)
            {
                if (a[xx][poy] == '#' && a[pox][yy] == '#')
                {
                    cout << "Crash!" << " ";
                    v = 0;
                    break;
                }
            }
            pox += dx[dir];
            poy += dy[dir];
        }
        cout << pox << " " << poy << endl;
    }
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
