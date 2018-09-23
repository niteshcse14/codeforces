#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector < pair < ll, ll > > arr;
ll n, a, b;
int main(){
	scanf("%lld", &n);
	for(ll i = 0; i < n; ++i){
		scanf("%lld %lld", &a, &b);
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end());
	ll last1 = -1, last2 = -1;
	for(ll i = 0; i < n; ++i){
		ll st = arr[i].first;
		ll fi = arr[i].second;
		if(last1 < st){
			last1 = fi;
		}
		else if(last2 < st){
			last2 = fi;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}