#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll N, cnt = 0, data;
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &data);
		if(data % 2 != 0)
		{
			cnt++;
		}
	}
	if(cnt > 0)
	{
		printf("First\n");
	}
	else
	{
		printf("Second\n");
	}
	return 0;
}