#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
ll n, m, k;
const int N = 1e5 + 10;
struct node
{
    ll h, a, b, c, d, e, w, en;
} AA[N], BB[N];
queue<int> q1, q2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> AA[i].h >> AA[i].a >> AA[i].b >> AA[i].c >> AA[i].d >> AA[i].e >> AA[i].w;
        AA[i].en = 0;
        q1.push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> BB[i].h >> BB[i].a >> BB[i].b >> BB[i].c >> BB[i].d >> BB[i].e >> BB[i].w;
        BB[i].en = 0;
        q2.push(i);
    }
    int flag = 0;
    for (int i = 1; i <= k; i++)
    {
        int dex1 = q1.front();
        int dex2 = q2.front();
        // A攻击
        ll k1, k2, k3;
        k1 = max((ll)0, AA[dex1].a - BB[dex2].c);
        k2 = max((ll)0, AA[dex1].b - BB[dex2].d);
        if (AA[dex1].en >= AA[dex1].e)
        {
            k3 = AA[dex1].w;
        }
        else
            k3 = 0;
        if (k3 > k1 && k3 > k2)
        {
            BB[dex2].h -= k3;
            AA[dex1].en -= AA[dex1].e;
        }
        else
        {
            BB[dex2].h -= max(k1, k2);
            AA[dex1].en += 1;
        }
        if (BB[dex2].h <= 0)
        {
            q2.pop();
            if (q2.empty())
            {
                cout << "Alice" << endl;
                flag = 1;
                break;
            }
            dex2 = q2.front();
        }
        q1.push(q1.front());
        q1.pop();
        dex1 = q1.front();
        // B攻击
        k1 = max((ll)0, BB[dex2].a - AA[dex1].c);
        k2 = max((ll)0, BB[dex2].b - AA[dex1].d);
        if (BB[dex2].en >= BB[dex2].e)
        {
            k3 = BB[dex2].w;
        }
        else
            k3 = 0;
        if (k3 > k1 && k3 > k2)
        {
            AA[dex1].h -= k3;
            BB[dex2].en -= BB[dex2].e;
        }
        else
        {
            AA[dex1].h -= max(k1, k2);
            BB[dex2].en += 1;
        }
        if (AA[dex1].h <= 0)
        {
            ;
            q1.pop();
            if (q1.empty())
            {
                cout << "Bob" << endl;
                flag = 1;
                break;
            }
            dex1 = q1.front();
        }
        q2.push(q2.front());
        q2.pop();
        dex2 = q2.front();
    }
    if (flag == 0)
    {
        cout << "Draw" << endl;
    }
    return 0;
}