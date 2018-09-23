#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 1000010
ll t, n, k;
ll inp[maxn];
struct node {
	ll rc, lc;
	node *left, *right;
	node() : lc(0), rc(0), left(NULL), right(NULL) {};
};
node *insert(node *root, ll val, ll level) {
	if (level == -1)
		return root;
	ll x = (val >> level) & 1;
	if (x) {
		root->rc++;
		if (!root->right)
			root->right = new node();
		root->right = insert(root->right, val, level - 1);
	}
	else {
		root->lc++;
		if (!root->left)
			root->left = new node();
		root->left = insert(root->left, val, level - 1);
	}
	return root;
}
ll query(node *root, ll pre, ll level) {
	if (level == -1 || root == NULL) return 0;
	ll x = (pre >> level) & 1;
	ll y = (k >> level) & 1;
	if (y) {
		if (x == 0) 
			return root->lc + query(root->right, pre, level - 1);
		else
			return root->rc + query(root->left, pre,level - 1);
	}
	else {
		if (x == 0) 
			return query(root->left, pre, level - 1);
		else
			return query(root->right, pre,level - 1);
	}
}
int main() {
	scanf("%lld%lld", &n, &k);
	for (ll i = 0; i < n; ++i) 
		scanf("%lld", &inp[i]);
	ll res = 0;
	ll pre = 0;
	node *root = new node();
	root = insert(root, 0, 31);
	for (ll i = 0; i < n; ++i) {
		pre ^= inp[i];
		res += query(root, pre, 31);
		root = insert(root, pre, 31);
	}
	printf("%lld\n", (n * (n + 1) / 2 - res));
	return 0;
}