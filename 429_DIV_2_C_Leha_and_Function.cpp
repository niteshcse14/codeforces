#include <bits/stdc++.h>
using namespace std;
int a[200000];
pair<int, int> b[200000];
int ans[200000];
int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + N, greater<int>());
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(b, b + N);
	for(int i = 0; i < N; i++)
	{
		ans[b[i].second] = a[i];
	}
	for(int i = 0; i < N; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}