#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char str[15];
int main() {
	scanf("%s", str);
	int cnt = 0, cnt1 = 0, n;
	n = strlen(str);
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == '0') {
			cnt++;
		}
		else {
			break;
		}
	}
	for (int i = strlen(str) - 1; i >= 0; --i) {
		if (str[i] == '0') {
			cnt1++;
		}
		else {
			break;
		}
	}
	//printf("%d  %d\n", cnt, cnt1);
	if (cnt > cnt1) {
		printf("NO\n");
	}
	else {
		bool flag = true;
		for (int i = cnt, j = n - cnt1 - 1; i < n && j >= 0; ++i, --j) {
			if (str[i] != str[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}