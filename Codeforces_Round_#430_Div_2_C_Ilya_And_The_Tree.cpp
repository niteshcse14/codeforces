#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
vector < int > adj[maxn];
int arr[maxn];
int n;
int main(){
	int u, v;
	scanf("%d%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	return 0;
}