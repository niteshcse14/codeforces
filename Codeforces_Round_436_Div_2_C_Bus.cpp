#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a, b, f, F, k, journy, ans, cnt;
int main () {
	scanf ("%lld%lld%lld%lld", &a, &b, &f, &k);
	if (b >= k * a) {
		printf("0\n");
		return 0;
	}
	if (k == 1 && ((b < f ) || (b < (a - f)))) {
		printf("-1\n");
		return 0;
	}
	if ((b < 2 * (a - f)) && k > 1) {
		printf("-1\n");
		return 0;
	}
	if ((b < 2 * f ) && k > 2) {
		printf("-1\n");
		return 0;
	}
	F = b;
	b = b - f;
	ans = 0;
	journy = 0;
	for (int i = 1; i <= k + 5; ++i) {
		if (i & 1) {
			int temp = b - (a - f);
			if (journy == k - 1 && temp >= 0) {
				journy++;
				break;
			}
			b  -= 2 * (a - f);
			if (b < 0) {
				b = F;
				b -= 2 * (a - f);
				ans++;
			}
			journy++;
		}
		else {
			int temp = b - f;
			if (journy == k - 1 && temp >= 0) {
				journy++;
				break;
			}
			b -= 2 * f;
			if (b < 0) {
				ans++;
				b = F;
				b -= 2 * f;
			}
			journy++;
		}
		if (journy == k) {
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}