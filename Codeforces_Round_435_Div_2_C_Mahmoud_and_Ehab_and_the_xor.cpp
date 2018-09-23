#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
	scanf("%d%d", &n, &x);
	printf("YES\n");
	for (int i = 0; i < n - 1; ++i) {
		if (n & 1) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
	printf("%d\n", x);
	return 0;
}