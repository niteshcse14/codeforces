#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXK = 13;
const ll max_n = 1e5 + 100;
ll n, k;
ll a[max_n];
ll fen[MAXK][max_n];
ll get(ll t, ll x){
  ll ret = 0;
  for (; x; x -= x & (-x))
    ret += fen[t][x];
  return  ret;
}
void add(ll t, ll x, ll val){
  for (x++; x < max_n; x += x & (-x))
    fen[t][x] += val;
}
int main()
{
    cin >> n >> k;  
    k++;
    for (ll i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    add(1, a[0], 1);
    for (ll i = 1; i < n; i++)
    {
        ll x = a[i];
        add(1, x, 1);
        for (ll j = 1; j < k; j++)
        {
            ll y = get(j, x);
            add(j + 1, x, y);
        }
    }
    cout << get(k, max_n) << endl;
    return 0;
}