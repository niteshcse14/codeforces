#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		int dp[N + 1];
		dp[1] = arr[0];
		dp[0] = 0;
		for(int i = 2; i <= N; i++)
		{
			dp[i] = max(dp[i - 2] + arr[i - 1], dp[i - 1]);
		}
		printf("%d\n", dp[N]);
	}
	return 0;
}