#include <bits/stdc++.h>
using namespace std;  
typedef long long LL;  
const int MAXN = 1e6 + 8;  
const LL INF = 2e9;  
  
int main()  
{  
    #ifdef LOCAL  
    freopen("c.txt", "r", stdin);  
    //freopen("c.out", "w", stdout);  
    int T = 4;  
    while(T--){  
    #endif // LOCAL  
    ios::sync_with_stdio(false); cin.tie(0);  
  
    LL n, m, ans = 0, cnt = 0;  
    cin >> n >> m;  
    if(m >= n){  
        cout << n << endl;  
        return 0;  
    }  
    ans = m; n -= m;  
    LL l = 0, r = INF, mid;  
    while(l + 1 < r){  
        mid = (l + r) / 2;  
        if((1ll + mid)*mid / 2 <= n){  
            cnt = max(cnt, mid);  
            l = mid;  
        }  
        else r = mid;  
    }  
  
    if((1ll + cnt)*cnt / 2 < n) cnt++;  
    //cout << cnt << endl;  
    ans += cnt;  
    cout << ans << endl;  
  
  
    #ifdef LOCAL  
    cout << endl;  
    }  
    #endif // LOCAL  
    return 0;  
}  