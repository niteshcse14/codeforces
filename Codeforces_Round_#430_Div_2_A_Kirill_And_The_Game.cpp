#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll l, r, x, y, k;
int main(){
	scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k);
	bool flag = false;
	for(ll i = x; i <= y; ++i){
		ll t = i * k;
		if(t >= l && r >= t){
			flag = true;
			break;
		}
	}
	if(flag){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}