#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, sum;
int cnt[maxn], arr[maxn], mis[maxn];
bool visited[maxn];
int main  () {
	memset (visited, false, sizeof (visited));
	memset (cnt, 0, sizeof(cnt));
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &arr[i]);
		cnt[arr[i]]++;
	}
	int SIZE = 0, sum = 0, options = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 0) {
			mis[SIZE++] = i;
		}
		else {
			options += cnt[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] >= 2) {
			cnt[i]--;
			sum += cnt[i];
		}
	}
	int j = 0, SS = SIZE;
	for (int i = 1; i <= n; ++i) {
		if (cnt[arr[i]] > 0 && j < SIZE) {
			if ((sum - SS) <= 0) {
				arr[i] = mis[j++];
				cnt[arr[i]]--;
				SS--;
			}
			else if (mis[j] < arr[i]) {
				arr[i] = mis[j++];
				cnt[arr[i]]--;
			}
			sum--;
		}
	}
	printf("%d\n", SIZE);
	for (int i = 1; i<= n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}