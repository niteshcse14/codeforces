#include <bits/stdc++.h>
using namespace std;
int n, a, data, sum1, sum2;
int cnt[500];
int main () {
	sum1 = sum2 = 0;
	memset (cnt, 0, sizeof(cnt));
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &data);
		if (cnt[data] == 0) {
			a++;
		}
		cnt[data]++;
	}
	if (a != 2) {
		printf("NO\n");
		return 0;
	}
	a = 1;
	for (int i = 1; i <= 200; ++i) {
		if (cnt[i] > 0) {
			if (a & 1) {
				sum1 += cnt[i];
			}
			else {
				sum2 += cnt[i];
			}
			a++;
		}
	}
	a--;
	if (sum1 == sum2 && a % 2 == 0) {
		printf("YES\n");
		a = 0;
		for (int i = 1; i <= 200 && a < 2; ++i) {
			if (cnt[i] > 0) {
				printf("%d ", i);
				a++;
			}
		}
		printf("\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}