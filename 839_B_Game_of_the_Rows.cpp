#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int arr[K];
	for(int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
	}
	int total = 4 * N, sum = 0;
	for(int i = 0; i < K; i++)
	{
		sum += arr[i] / 2 + arr[i] % 2;
	}
	if(sum > total)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}