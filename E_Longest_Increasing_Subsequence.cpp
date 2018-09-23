#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN];
int gaps[MAXN];
int main()
{
	int N, M, count = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] == -1)
		{
			count++;
		}
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &gaps[i]);
	}
	sort(gaps, gaps + M);
	if(count == 0)
	{
		for(int i = 0; i < N; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = N - 1; i >= 0; i--)
		{
			if(arr[i] == -1)
			{
				for(int j = M - 1; j >= 0; j--)
				{
					if(gaps[j] != -1 && gaps[j] > arr[i - 1] && gaps[i] < arr[i + 1] && (i - 1) >= 0 && (i + 1) <= (N - 1))
					{
						arr[i] = arr[j];
						gaps[j] = -1;
						break;
					}
				}
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(arr[i] == -1)
			{
				for(int j = 0; j < M; j++)
				{
					if(gaps[j] != -1 && gaps[j] >= arr[i])
					{
						arr[i] = arr[j];
						gaps[j] = -1;
						break;
					}
				}
			}
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}