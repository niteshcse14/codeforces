#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n, k, sum, sz;
int ans[maxn];
struct node {
	int val, idx;
};
node inp[maxn], temp[maxn];
bool cmp(node a, node b) {
	if (a.val == b.val) 
		return a.idx < b.idx;
	return a.val > b.val;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &inp[i].val);
		temp[i].val = inp[i].val;
		temp[i].idx = inp[i].idx = i;
	}
	sort(temp, temp + n, cmp);
	for (int i =  0; i < k; ++i) {
		sum += temp[i].val;
		//
	}
	sz = 0;
	for (int i = 0; i < k; ++i)
		ans[sz++] = temp[i].idx;
	ans[sz++] = n - 1;
	sort(ans, ans + sz);
	printf("%d\n", sum);
	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}
	printf("%d ", ans[0] + 1);
	for (int i = 1; i < k - 1; ++i) {
		sum = ans[i] - ans[i - 1];
		printf("%d ", sum);
	}
	printf("%d\n", n - ans[k - 2] - 1);
	return 0;
}