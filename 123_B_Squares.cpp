#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll a, b, x1, y1, x2, y2, count = 0;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &x1, &y1, &x2, &y2);
	if(x2 > x1)
	{
		for(ll i = x1 + 1; i < x2; i++)
		{
			if((abs(i + y1)) % (2 * a) == 0 || (abs(i - y1)) % (2 * b) == 0)
			{
				count++;
			}
		}
	}
	else if(x1 > x2)
	{
		for(ll i = x1 + 1; i > x2; i--)
		{
			if((abs(i + y1)) % (2 * a) == 0 || (abs(i - y1)) % (2 * b) == 0)
			{
				count++;
			}
		}
	}
	if(y2 > y1)
	{
		for(ll i = y1 + 1; i < y2; i++)
		{
			if((abs(x2 + i)) % (2 * a) == 0 || ((abs(x2 - i)) % (2 * b) == 0 && x2 != i))
			{
				//printf("%lld %lld\n", x2, i);
				count++;
			}
		}
	}
	else if(y1 > y2)
	{
		for(ll i = y1 + 1; i > y2; i--)
		{
			if((abs(x2 + i)) % (2 * a) == 0 || (abs(x2 - i)) % (2 * b) == 0)
			{
				count++;
			}
		}
	}
	printf("%lld\n", count);
	return 0;
}