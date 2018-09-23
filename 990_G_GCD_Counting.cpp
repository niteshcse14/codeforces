#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int gi(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
const int N = 2e5+5;
int n,a[N],to[N<<1],nxt[N<<1],head[N],cnt,vis[N],tim,S;
vector<int>v[N];
long long F[N];
void link(int u,int v){
	to[++cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
}
void fact(int x,int id){
	for (int i=1;i*i<=x;++i)
		if (x%i==0){
			v[i].push_back(id);
			if (i*i!=x) v[x/i].push_back(id);
		}
		
}
void dfs(int u,int f){
	vis[u]=tim;
	++S;
	for (int e=head[u];e;e=nxt[e])
		if (to[e]!=f&&a[to[e]]%tim==0) dfs(to[e],u);
}
int main(){
	n=gi();
	for (int i=1;i<=n;++i){
		a[i]=gi();
		fact(a[i],i);
	}
	for (int i=1;i<n;++i){
		int u=gi(),v=gi();
		link(u,v),link(v,u);
	}
	for (tim=1;tim<=200000;++tim)
		for (int j=0,sz=v[tim].size();j<sz;++j)
			if (vis[v[tim][j]]!=tim){
				S=0;
				dfs(v[tim][j],0);
				F[tim]+=1ll*S*(S-1)/2+S;
			}
	for (int i=200000;i;--i)
		for (int j=i+i;j<=200000;j+=i)
			F[i]-=F[j];
	for (int i=1;i<=200000;++i)
		if (F[i]) printf("%d %I64d\n",i,F[i]);
	return 0;
}
/*
#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll ans[N];
int n, A[N];
map<int,ll> cnt[N];
vector<int> g[N];
void dfs(int u, int p=-1){
	cnt[u][A[u]]=1;
	ans[A[u]]++;
	for(int v:g[u])if(v!=p){
		dfs(v,u);
		//printf("for %d %d\n",u,v);
		int sum=0;
		for(auto p:cnt[v]){
			for(auto p2:cnt[u]){
				//sum++;
				//printf("(%d %d)\n",p.first,p2.first);
				ans[__gcd(p2.fst,p.fst)]+=p2.snd*p.snd;
			}
		}
		//printf("sum %d\n\n",sum);
		for(auto p:cnt[v])
			cnt[u][__gcd(p.fst,A[u])]+=p.snd;
		cnt[v].clear();// for memory limit exceeds
	}
}

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int x=0; x<n; x++)
		cin>>A[x];
	for(int x=0; x<n-1; x++){
		int u,v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	for(int x=1; x<N; x++)
		if(ans[x])cout<<x<<" "<<ans[x]<<"\n";
}
*/