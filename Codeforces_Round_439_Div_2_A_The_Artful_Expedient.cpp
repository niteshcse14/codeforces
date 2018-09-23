#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 2e6 + 5;
const ll MAX = 2005;
int visited[maxn];
ll a[MAX], b[MAX], n, cnt;
int main () {
	cnt = 0;
	memset (visited, false, sizeof (visited));
	scanf ("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf ("%lld", &a[i]);
		visited[a[i]] = true;
	}
	for (ll i = 0; i < n; ++i) {
		scanf ("%lld", &b[i]);
		visited[b[i]] = true;
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			ll temp = a[i] ^ b[j];
			if (temp > (ll)(2e6)) continue;
			if (visited[a[i] ^ b[j]]) {
				cnt++;
			}
		}
	}
	if (cnt & 1) {
		printf("Koyomi\n");
	}
	else {
		printf("Karen\n");
	}
	return 0;
}