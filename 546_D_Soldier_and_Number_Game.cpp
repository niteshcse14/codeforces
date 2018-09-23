#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000001;
#define ll long long int
int arr[MAX];
ll ans[MAX];
void init()
{
	for(int i = 0; i < MAX; i++)
	{
		arr[i] = MAX + 1;
	}
	for(int i = 2; i < MAX; i++)
	{
		if(arr[i] == MAX + 1)
		{
			arr[i] = 1;
			for(int j = 2 * i; j < MAX; j += i)
			{
				arr[j] = min(i, arr[j]);
			}
		}
	}
	arr[1] = 1;
	/*
	for(int i = 2; i < 31; i++)
	{
		printf("%d %d\n", i, arr[i]);
	}
	printf("\n");
	*/
}
int PF(int N)
{
	ll ans = 1, x = arr[N];
	while(x != 1)
	{
		N /= x;
		ans++;
		x = arr[N];
	}
	return ans;
}
int main()
{
	init();
	ans[0] = 0;
	ans[1] = 1;
	for(int i = 2 ; i < MAX; i++)
	{
		ans[i] += PF(i);
		ans[i] += ans[i - 1];
	}
	int T, a, b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &a, &b);
		printf("%lld\n", ans[a] - ans[b]);
	}
	return 0;
}