#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5 + 5;
int get_sum(int st[], int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss && qe >= se)
	{
		return st[si];
	}
	if(se < qs || ss > qe)
	{
		return 0;
	}
	int mid = ss + (se - ss) / 2;
	return get_sum(st, ss, mid, qs, qe, 2 * si + 1) + 
			get_sum(st, mid + 1, se, qs, qe, 2 * si + 2);
}
int seg_build(int st[], int arr[], int ss, int se, int si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se - ss) / 2;
	st[si] = seg_build(st, arr, ss, mid, 2 * si + 1) + 
				  seg_build(st, arr, mid + 1, se, 2 * si + 2);
	return st[si];
}
int main()
{
	int Q, N, a, b;
	string str;
	cin >> str >> Q;
	N = str.length();
	int open[N], close[N];
	memset(open, 0, sizeof(open));
	memset(close, 0, sizeof(close));
	for(int i = 0; i < N; i++)
	{
		if(str[i] == '(')
		{
			open[i] = 1;
		}
		else
		{
			close[i] = 1;
		}
	}
	int height = (int)ceil(log2(N));
	int size = 2 * (int)pow(2, height) - 1;
	int *open_st = new int[size];
	int *close_st = new int[size];
	seg_build(open_st, open, 0, N - 1, 0);
	seg_build(close_st, close, 0, N - 1, 0);
	for(int i = 0; i < size; i++)
	{
		printf("%d  ", open_st[i]);
	}
	printf("\n");
	for(int i = 0; i < size; i++)
	{
		printf("%d  ", close_st[i]);
	}
	printf("\n");
	while(Q--)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		int ans = get_sum(open_st, 0, N - 1, a, b, 0);
		int ans1 = get_sum(close_st, 0, N - 1, a, b, 0);
		printf("%d   %d\n", ans, ans1);
	}
	return 0;
}