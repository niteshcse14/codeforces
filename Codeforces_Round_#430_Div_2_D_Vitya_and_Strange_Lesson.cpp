#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e5 + 5;
int arr[maxn];
int cnt[maxn];
int not_avail[maxn];
int n, m, x;
int main(){
	scnaf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
		cnt[arr[i]] = 1;
	}
	sort(arr, arr + n);
	while(m--){
		scanf("%d", &x);
		if(arr[0] != 0 && cnt[x] == 0){
			printf("0\n");
			continue;
		}
	}
	return 0;
}