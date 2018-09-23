#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pr(x) cerr<<#x<<"="<<(x)<<endl
#define pri(x,lo) {cerr<<#x<<"={";for (int ol=0;ol<=lo;ol++)cerr<<x[ol]<<",";cerr<<"}"<<endl;}
#define inf 100000000
#define N 1000010
#define md 1000000007
int n,Q,prcnt,cnt,st[N],ed[N],prime[N],fa[N][20],dep[N],x[N],y[N],minn[10000100],vis[10001000],o,p,i;
ll ans[N];
vector<int> e[N],s[10000010],q[10000010];
ll qpow(ll x,ll y){ll ret=1;for (;y;y>>=1,x=x*x%md) if (y&1) ret=ret*x%md;return ret;}
struct BIT
{
	int c[N];
	void add(int x,int y) {
		while (x<=n) {
			c[x]+=y;
			x+=x&-x;
		}
	}
	int query(int x){
		int ret=0;
		while (x>0) {
			ret+=c[x];
			x-=x&-x;
		}
		return ret;
	}
}bit;
void dfs(int x){
	st[x]=++cnt;
	for (int i=1;i<=18;i++) 
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int y:e[x])
		if(y!=fa[x][0]) dep[y]=dep[x]+1,fa[y][0]=x,dfs(y);
	ed[x]=cnt;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) 
		swap(x,y);
	int d=dep[x]-dep[y];
	for (int i=0;i<=18;i++) 
		if(d&(1<<i)) 
			x=fa[x][i];
	if (x==y) 
		return x;
	for (int i=18;i>=0;i--) 
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void init(){
	for (i=2;i<=10000000;i++) {
		if (vis[i]==0) 
			prime[++prcnt]=i,minn[i]=i;
		for (int j=1;j<=prcnt;j++){
			int y=prime[j]*i;
			if (y>10000000) break;
			vis[y]=1;
			minn[y]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	for (i=1;i<n;i++){
		scanf("%d %d",&o,&p);
		e[o].pb(p);
		e[p].pb(o);
	}
	dfs(1);
	for (i=1;i<=n;i++) {
		scanf("%d",&o);
		while (o!=1){
			int now=1,p=minn[o];
			while (o%p==0) o/=p,now*=p,s[now].pb(i);
		}
	}
	scanf("%d",&Q);
	for (i=1;i<=Q;i++) {
		scanf("%d %d %d",&x[i],&y[i],&o);
		while (o!=1){
			int now=1,p=minn[o];
				while (o%p==0) {
				o/=p,now*=p;
				q[now].pb(i);
			}
		}
	}
	for (i=1;i<=Q;i++)
		ans[i]=1;
	for (i=1;i<=10000000;i++){
		if (s[i].empty()||q[i].empty())
			continue;
		//printf("true %d\n",i);
		for (int a:s[i]) {
			bit.add(st[a],1);
			bit.add(ed[a]+1,-1);
		}
		for (int a:q[i]) {
			int o=x[a],p=y[a],l=lca(o,p);
			int t=bit.query(st[o])+bit.query(st[p])-bit.query(st[l])-bit.query(st[fa[l][0]]);
			//printf("t %d %d\n",t,a);
			ans[a]=1ll*ans[a]*qpow(minn[i],t)%md;
		//	printf("ans[%d]+=%d^%d\n",a,minn[i],t);
		}
		//printf("\n");
		for (int a:s[i]){
			bit.add(st[a],-1);
			bit.add(ed[a]+1,1);
		}
	}
	for (i=1;i<=Q;i++) 
		printf("%lld\n",ans[i]);
}