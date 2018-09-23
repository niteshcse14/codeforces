#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pb push_back
#define f first
#define s second
#define iPair pair <int, int>
int u, v, n, m, k, cnt;
int dist[maxn];
bool vis[maxn], ans[maxn];
vector <iPair> adj[maxn];
string res[maxn];
void dfs(int cur) {
    if (cur > n) {
        cnt++;
        for (int i = 1; i <= m; ++i)
            res[cnt] += '0' + ans[i];
        return;
    }
    for (auto i : adj[cur]) {
        if (cnt >= k) return;
        if (dist[cur] == dist[i.f] + 1) {
            ans[i.s] = true;
            dfs(cur + 1);
            ans[i.s] = false;
        }
    }
    if (cnt >= k) return;
}
void bfs(int cur) {
    queue <int> qu;
    qu.push(cur);
    dist[cur] = 0;
    vis[cur] = true;
    while (!qu.empty()) {
        u = qu.front();
        qu.pop();
        for (auto i : adj[u]) {
            if (!vis[i.f]) {
                vis[i.f] = true;
                qu.push(i.f);
                dist[i.f] = dist[u] + 1;
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    bfs(1);
    dfs(2);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        cout << res[i] << "\n";
    return 0;
}