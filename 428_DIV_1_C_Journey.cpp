#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int sum = 0;
double dfs(int curr, int prev)
{
	double sum = 0;
	vector<int>::iterator itr;
	for(itr = adj[curr].begin(); itr != adj[curr].end(); itr++)
	{
		if(*itr != prev)
		{
			sum += dfs(*itr, curr) + 1;
		}
	}
	//cout << curr << "   " << sum << "  return  " << ((sum != 0) ? sum / (adj[curr].size() - (prev != -1)) : 0) <<"\n";
	return (sum != 0) ? sum / (adj[curr].size() - (prev != -1)) : 0;
}
int main()
{
	int N, u, v;
	scanf("%d", &N);
	for(int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%f\n", dfs(1, -1));
	return 0;
}