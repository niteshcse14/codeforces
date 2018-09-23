#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
const int N = (1 << 22) + 5;
const int S = 2 * N;
int n,m,ans,topQ;
bool inp[N],vis[S];
int q[S];
/*
void solve(int x) {
	topQ = 0;
	q[topQ++] = x;
	vis[x] = 1;
	for (int i = 0; i < topQ; i++) {
		x = q[i];
		if (x < (1 << n)) {
			if (!vis[x + (1 << n)]) {
				vis[x + (1 << n)] = 1;
				q[topQ++] = x + (1 << n);
			}
		} else {
			int y = (1 << (n + 1)) - 1 - x;
			if (!vis[y] && inp[y]) {
				vis[y] = 1;
				q[topQ++] = y;
			}
			for (int j = 0; j < n; j++) {
				y = x | (1 << j);
				if (!vis[y]) {
					vis[y] = 1;
					q[topQ++] = y;
				}
			}
		}
	}
}
*/
void solve(int x){
	topQ=0;
	q[topQ++]=x;
	vis[x]=1;
	for(int i=0;i<topQ;++i){
		x=q[i];
		if(x<(1<<n)){
			if(!vis[x+(1<<n)]){
				vis[x+(1<<n)]=1;
				q[topQ++]=x+(1<<n);
			}
		}
		else{
			int y=(1<<(n+1))-1-x;
			if(!vis[y]&&inp[y]){
				vis[y]=1;
				q[topQ++]=y;
			}
			for(int j=0;j<n;++j){
				y=x|(1<<j);
				if(!vis[y]){
					vis[y]=1;
					q[topQ++]=y;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		inp[x] = 1;
	}
	for (int i = 0; i < (1 << n); i++) {
		if (inp[i] && !vis[i]) {
			solve(i);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}