#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define INF 1000000021
#define MOD 1000000007
#define pb push_back
#define sqr(a) (a)*(a)
#define M(a, b) make_pair(a,b)
#define F first
#define S second
#define all(x) (x.begin(), x.end())
#define deb(x) cerr << #x << " = " << x << '\n'
#define N 222222

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ld pi = 2 * acos(0.0);
template<class T> bool umin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
template<class T> bool umax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T, class TT> bool pal(T a, TT n){int k=0;for(int i=0;i<=n/2;i++){if(a[i]!=a[n-i-1]){k=1;break;}}return k?0:1;}

//int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

vi v[N], a;
int id[N], s[N];

void dfs(int u, int e)
{
  a.pb(u);
  id[u] = a.size()-1;
  s[u] = 1;
  for(auto it : v[u])
  {
    if(it != e)
      dfs(it, u),
      s[u] += s[it];
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 2; i <= n; i ++)
  {
    int x;
    cin >> x;
    v[i].pb(x);
    v[x].pb(i);
  }
  dfs(1, 0);
  while(m --)
  {
    int x, y;
    cin >> x >> y;
    if(y > s[x])
      cout << -1 << '\n';
    else
    cout << a[y-1+id[x]] << '\n';
  }
  return 0;
}