#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a, b;
bool a_flag, f_flag, t_flag;
int main () {
	a_flag = f_flag = t_flag = false;
	scanf ("%lld%lld", &a, &b);
	if (a == b) {
		printf("1\n");
		return 0;
	}
	if (a > b) {
		printf("0\n");
		return 0;
	}
	if ((b - a) >= 10) {
		printf("0\n");
		return 0;
	}
	ll res = 1;
	for (ll i = a + 1; i <= b; ++i) {
		res *= i;
		res %= 10;
	}
	printf("%d\n", res % 10);
	return 0;
}