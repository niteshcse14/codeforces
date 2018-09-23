#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll K, ans = 0;
class Tree
{
	ll V;
	list<ll> *adj;
public:
	Tree(ll V);
	void addEdge(ll u, ll v);
	void dfs(ll i, ll count, bool visited[]);
};
Tree::Tree(ll V)
{
	this->V = V;
	adj = new list<ll>[V];
}
void Tree::addEdge(ll u, ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Tree::dfs(ll i, ll count, bool visited[])
{
	if(count % K == 0)
	{
		ans++;
	}
	visited[i] = true;
	list<ll>::iterator itr;
	for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, count + 1, visited);
		}
	}
}
int main()
{
	ll V, u, v, n;
	cin >> V >> K;
	n = V - 1;
	Tree tree(V);
	bool visited[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	while(n--)
	{
		cin >> u >> v;
		tree.addEdge(u - 1, v - 1);
	}
	tree.dfs(0, 0, visited);
	cout << 2 * ans << "\n";
	return 0;
}