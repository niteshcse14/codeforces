#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e3 + 5;
typedef struct node {
	int start;
	int end;
	int profit;
} node;
node qu[maxn];
int n, a, b, c, res, len;
int ans[maxn];
bool cmp(node a, node b) {
	return (a.end < b.end);
}
int solve (int tm, int i, int SIZE) {
	if (i == n) {
		return 0;
	}
	if ((tm + qu[i].start) > qu[i].end) {
		return solve(tm, i + 1, SIZE);
	}
	return max (qu[i].profit + solve(qu[i].start + tm, i + 1, SIZE + 1), solve(tm, i + 1, SIZE));
	ans[SIZE] = i + 1;
	len = max (len, SIZE);
	//return result;
}
int main () {
	len = 0;
	memset (ans, 0, sizeof(ans));
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d%d%d", &a, &b, &c);
		qu[i].start = a;
		qu[i].end = b;
		qu[i].profit = c;
	}
	sort (qu, qu + n, cmp);
	res = solve(0, 0, 0);
	printf("%d\n", res);
	printf("%d\n", len);
	for (int i = 0; i < len; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}