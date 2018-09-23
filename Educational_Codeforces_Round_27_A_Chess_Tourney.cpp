#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, data, sum = 0, sum2 = 0;
	scanf("%d", &N);
	int arr[2 * N];
	for(int i = 0; i < 2* N; ++i){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 2 * N);
	int cnt = 0, j = 2 * N - 1;
	for(int i = 0; i < N; ++i){
		if(arr[i] >= arr[j--]) cnt++;
	}
	if(cnt){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}