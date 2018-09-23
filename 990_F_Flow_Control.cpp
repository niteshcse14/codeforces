#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
const int N = 1000013;
int n, m;
pair<int, int> e[N];
int a[N], rk[N];
long long sum[N], ans[N];
int p[N];
int getP(int a){
	return (a == p[a] ? a : p[a] = getP(p[a]));
}
bool merge(int a, int b){
	a = getP(a);
	b = getP(b);
	if (a == b) return false;
	if (rk[a] > rk[b]) swap(a, b);
	p[a] = b;
	rk[b] += rk[a];
	return true;
}
bool used[N];
vector<int> g[N];
int h[N];
void dfs(int v, int p){
	sum[v] = a[v];
	for (auto u : g[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
			sum[v] += sum[u];
		}
	}
}
int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n) p[i] = i, rk[i] = 1;
	scanf("%d", &m);
	forn(i, m){
		int &v = e[i].first;
		int &u = e[i].second;
		scanf("%d%d", &v, &u);
		--v, --u;
		if (merge(v, u)){
			g[v].push_back(u);
			g[u].push_back(v);
			used[i] = true;
		}
	}
	long long tot = 0;
	forn(i, n) tot += a[i];
	if (tot != 0){
		puts("Impossible");
		return 0;
	}
	dfs(0, -1);
	/*
	for(int i=0;i<n;++i){
		printf("%d %lld\n",i,sum[i]);
	}
	*/
	puts("Possible");
	forn(i, m){
		if (used[i]){
			int v = e[i].first, u = e[i].second;
			if (h[v] < h[u])
				ans[i] = sum[u];
			else
				ans[i] = -sum[v];
		}
		printf("%lld\n", ans[i]);
	}
	return 0;
}