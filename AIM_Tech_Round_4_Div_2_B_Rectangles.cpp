#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ans = 0;
ll n, m;
ll arr[55][55];
ll cnt_z, cnt_o;
int main(){
	scanf("%lld%lld", &n, &m);
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < m; ++j){
			scanf("%lld", &arr[i][j]);
		}
	}
	if(n == 1 && m == 1){
		printf("1\n");
		return 0;
	}
	for(ll i = 0; i < n; ++i){
		cnt_z = 0, cnt_o = 0;
		for(ll j = 0; j < m; ++j){
			if(arr[i][j] == 0){
				cnt_z++;
			}
			else if(arr[i][j] == 1){
				cnt_o++;
			}
		}
		if(cnt_o > 0){
			ans += (ll)pow(2, cnt_o) - 1;
		}
		if(cnt_z > 0){
			ans += (ll)pow(2, cnt_z) - 1;
		}
	}
	for(ll i = 0; i < m; ++i){
		cnt_z = 0, cnt_o = 0;
		for(ll j = 0; j < n; ++j){
			if(arr[j][i] == 0){
				cnt_z++;
			}
			else if(arr[j][i] == 1){
				cnt_o++;
			}
		}
		if(cnt_o > 0){
			ans += (ll)pow(2, cnt_o) - 1;
		}
		if(cnt_z > 0){
			ans += (ll)pow(2, cnt_z) - 1;
		}
	}
	printf("%lld\n", ans - n * m);
	return 0;
}