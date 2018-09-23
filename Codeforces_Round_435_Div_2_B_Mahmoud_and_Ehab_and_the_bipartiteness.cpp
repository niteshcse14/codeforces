#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
int V, a, b;
vector < int > s1;
vector < int > s2;
vector < int > adj[maxn];
int visited[maxn];
int arr_s1[maxn];
int arr_s2[maxn];
ll sum;
int cnt;
void dfs(int u, int level) {
	visited[u] = 1;
	if (level % 2 == 0) {
		s2.push_back(u);
	}
	else {
		s1.push_back(u);
	}
	vector < int > :: iterator itr;
	for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
		if (visited[*itr] == 0) {
			dfs(*itr, level + 1);
		}
	}
}
int main() {
	scanf("%d", &V);
	for (int i = 0; i < V - 1; ++i) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	memset(arr_s1, 0, sizeof(arr_s1));
	memset(arr_s2, 0, sizeof(arr_s2));
	/*
	for (int i = 0; i < s1.size(); ++i) {
		printf("%d  ", s1[i]);
	}
	printf("\n");
	*/
	for (int i = 0; i < s2.size(); ++i) {
		arr_s2[s2[i]] = 1;
	}
	sum = 0;
	for (int i = 0; i < s1.size(); ++i) {
		cnt = 0;
		vector < int > :: iterator itr;
		for (itr = adj[s1[i]].begin(); itr != adj[s1[i]].end(); ++itr) {
			if (arr_s2[*itr] == 1) {
				cnt++;
			}
		}
		sum += s2.size() - cnt;
	}
	printf("%lld\n", sum);
	return 0;
}