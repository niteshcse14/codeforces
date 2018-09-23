#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> ans;
map<ll, ll> ANS;
ll N;
int main()
{
	for(ll i = 1; i < 11; i++)
	{
		ll total = 1 << i;
		for(ll n = 0; n < total; n++)
		{
			ll k = n;
			vector<ll> temp;
			for(ll ii = 0; ii < i; ii++)
			{
				if(k & 1)
				{
					temp.push_back(7);
				}
				else
				{
					temp.push_back(4);
				}
				k >>= 1;
			}
			ll sum = 0;
			ll tt = 1;
			for(int jj = 0; jj < temp.size(); jj++)
			{
				sum += tt * temp[jj];
				tt *= 10;
			}
			ans.push_back(sum);
		}
	}
	for(ll i = 0; i < ans.size(); i++)
	{
		ANS[ans[i]] = i + 1;
	}
	scanf("%lld", &N);
	printf("%lld\n", ANS[N]);
	return 0;
}