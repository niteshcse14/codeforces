#include <bits/stdc++.h>
using namespace std;
int n, ans, sum;
char str[1000];
int cnt[26];
bool flag;
int main () {
	bool found = false;
	ans = 0;
	memset (cnt, 0, sizeof(cnt));
	scanf ("%d%s", &n, str);
	for (int i = 0; i < n; ++i) {
		if ((int)(str[i]) < 91) {
			continue;
		}
		found = true;
		for (int j = i + 1; j < n; ++j) {
			if ((int)(str[j]) < 91) {
				break;
			}
			found = true;
			flag = true;
			memset (cnt, 0, sizeof(cnt));
			sum = 0;
			for (int k = i; k <= j && flag; ++k) {
				if ((int)(str[k]) < 91) {
					flag = false;
				}
				else {
					if (cnt[str[k] - 'a'] == 0) {
						sum++;
					}
					cnt[str[k] - 'a']++;
				}
			}
			if (sum > 1 && flag) {
				//printf("%d  %d\n", i, j);
				ans = max (ans, sum);
			}
		}
	}
	if (ans == 0) {
		printf("%d\n", found ? 1 : 0);
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}