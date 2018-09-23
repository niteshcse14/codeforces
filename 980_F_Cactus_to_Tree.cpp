#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500000;
int n, m,dfs;
int L[N], Z[N], maxLen[N];
vector<pair<int,int>>g[N];
bool isBridge[2 * N],vis[N];
int low[N], idx[N], parent[N];
void markBridges(int u, int p) {
	low[u] = idx[u] = ++dfs;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i].first;
		if (idx[v] == 0) {
			markBridges(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > idx[u])
				isBridge[g[u][i].second] = true;
		}
		else if (v != p)
			low[u] = min(low[u], idx[v]);
	}
}
void solve(int cur) {
	queue<int> q;
	vector<int> nodesByDepth;
	q.push(cur);
	memset(vis, 0, sizeof(vis));
	vis[cur] = true;
	parent[cur] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		nodesByDepth.push_back(u);
		for (auto e : g[u]) {
			int v = e.first;
			if (vis[v])
				continue;
			vis[v] = true;
			parent[v] = u;
			q.push(v);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		int u = nodesByDepth[i];
		for (auto e : g[u]) {
			int v = e.first;
			if (parent[v] == u) {
				maxLen[u] = max(maxLen[u], 1 + maxLen[v]);
				if (isBridge[e.second])
					L[u] = max(L[u], 1 + maxLen[v]);
			}
		}
	}
}
vector<vector<int> > cycles;
int cycleIdx[N];
void findCycles(int u) {
	vis[u] = true;
	cycles.back().push_back(u);
	cycleIdx[u] = cycles.size() - 1;
	for (auto e : g[u])
		if (!isBridge[e.second] && !vis[e.first])
			findCycles(e.first);
}
void solveCycles(int u, int p, int upValue) {
	L[u] = max(L[u], upValue);
	vector<int> &cycle = cycles[cycleIdx[u]];
	int k = cycle.size();
	//printf("For %d\n",u);
	for (int it = 0; it < 2; ++it) {
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < 2 * k; ++i) {
			int d = 2 * k - i;
			while (!q.empty() && q.top().second - d > k / 2)
				q.pop();
			if (!q.empty())
				Z[cycle[i%k]] = max(Z[cycle[i%k]], q.top().first - d);
			q.push({ L[cycle[i%k]] + d,d });
			//printf("(%d %d %d %d)\n",d,L[cycle[i%k]],Z[cycle[i%k]],q.top().first);
		}
		for(int i=0;i<k;++i){
			//printf("(%d %d) ",Z[cycle[i]],L[cycle[i]]);
		}
		//printf("\n");
		reverse(cycle.begin(), cycle.end());
	}
	for (auto u : cycle) {
		int firstMax = 0, secondMax = 0;
		for (auto e : g[u]){
			if (e.first != p && isBridge[e.second]) {
				int v = e.first;
				if (secondMax < 1 + maxLen[v]) {
					secondMax = 1 + maxLen[v];
					if (firstMax < secondMax)
						swap(firstMax, secondMax);
				}
			}
		}
		for (auto e : g[u])
			if (e.first != p && isBridge[e.second]) {
				int v = e.first;
				int passValue = max(upValue, Z[u]);
				if (firstMax == 1 + maxLen[v])
					passValue = max(passValue, secondMax);
				else
					passValue = max(passValue, firstMax);
				solveCycles(v, u, passValue + 1);
			}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d%d", &u, &v);
		--u;--v;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	markBridges(0, -1);
	for (int i = 0; i < n; ++i)
		if (!vis[i]) {
			cycles.push_back(vector<int>());
			findCycles(i);
		}
	solve(0);
	solveCycles(0, -1, 0);
	for (int i = 0; i < n; ++i) {
		printf("%d ", max(L[i], Z[i]));
	}
	printf("\n");
	return 0;
}