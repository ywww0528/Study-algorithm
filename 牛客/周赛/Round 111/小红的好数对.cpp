```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int modInverse(int a, int m) {
    // 模 m 的逆元 (m=11 是质数，可以用快速幂)
    int res = 1, b = m-2;
    while(b){
        if(b&1) res = 1LL*res*a % m;
        a = 1LL*a*a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    // 预计算 10^len mod 11
    vector<int> pow10mod11(11);
    pow10mod11[0] = 1;
    for(int i=1;i<=10;i++) pow10mod11[i] = (pow10mod11[i-1]*10)%11;

    // cnt[r] = 数组中模 11 余数为 r 的数量
    vector<int> cnt(11,0);
    for(auto x: a){
        cnt[x%11]++;
    }

    long long ans=0;

    for(auto B: a){
        int rB = B % 11;
        int lenB = to_string(B).size();
        int p = pow10mod11[lenB % 10]; // 因为周期性，len取模10即可
        int invp = modInverse(p,11);
        int need = ( (11 - rB) % 11 * invp ) % 11;

        ans += cnt[need];

        // 不能和自己组成对
        if(B % 11 == need) ans--;
    }

    cout << ans << "\n";
    return 0;
}
```
