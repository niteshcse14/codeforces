#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
typedef pair < int, int > PII;
vector <int> adj[MAX];
int path[MAX], dest;
bool visited[MAX];
int ans = INT_MAX;
void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printPath(int idx){
	int temp = 0;
	for(int i = 0; i < idx; ++i){
		temp ^= path[i];
	}
	printf("%d\n", temp);
	ans = min(temp, ans);
}
void dfs(int u, int idx){
	visited[u] = true;
	path[idx++] = u;
	if(u == dest){
		printPath(idx);
	}
	vector < int > :: iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		if(!visited[*itr]){
			dfs(*itr, idx);
		}
	}
	idx--;
	visited[u] = false;
}
int main(){
	memset(visited, false, sizeof(visited));
	int u, v, w, e;
	scanf("%d%d", &v, &e);
	dest = v - 1;
	for(int i = 0; i < e; ++i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	dfs(0, 0);
	return 0;
}