#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 1000010
ll n;
ll inp[maxn];
int main() {
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i)
		scanf("%lld", &inp[i]);
	for (ll i = 0; i < n; ++i) {
		if (inp[i] % 2 == 0)
			printf("%lld ", inp[i] - 1);
		else printf("%lld ", inp[i]);
	}
	printf("\n");
	return 0;
}