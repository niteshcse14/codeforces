#include <bits/stdc++.h>
using namespace std;
const int INF = 1234567890;
int main()
{
	int N, M, x, y, L1 = -INF, R1 = INF, L2 = -INF, R2 = INF;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		L1 = max(L1, x);
		R1 = min(R1, y);
	}
	cin>>M;
	int c, d;
	for(int i = 0; i < M; i++)
	{
		cin >> x >> y;
		L2 = max(L2, x);
		R2 = min(R2, y);
	}
	cout<<max(max(L2 - R1, L1 - R2), 0)<<"\n";	
	return 0;
}
//Anton_and_Classes.cpp