#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, K, sum = 0;
	string str;
	cin >> N >> K >> str;
	int arr[26];
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < str.size(); i++)
	{
		arr[str[i] - 'a']++;
	}
	bool flag = true;
	for(int i = 0; i < 26; i++)
	{
		if(arr[i] > K)
		{
			flag = false;
		}
	}
	if(flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}