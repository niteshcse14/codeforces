#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	vector < int > num(6);
	int a[3], b[3];
	cin >> str;
	for(int i = 0; i < 6; ++i){
		num[i] = str[i] - '0';
	}
	vector<int> small(num.begin(), num.end() + 3);
	vector<int> big(num.begin() + 3, num.end());
	int sum1 = num[0] + num[1] + num[2];
	int sum2 = num[3] + num[4] + num[5];
	int diff = 0;
	diff = sum2 - sum1;
	if(diff < 0){
		small.swap(big);
		diff = 0 - diff;
	}
	vector < int > arr;
	arr.push_back(9 - small[0]);
	arr.push_back(9 - small[1]);
	arr.push_back(9 - small[2]);
	arr.push_back(big[0]);
	arr.push_back(big[1]);
	arr.push_back(big[2]);
	sort(arr.begin(), arr.end());
	if(diff == 0){
		printf("0\n");
	}
	else if(arr[5] >= diff){
		printf("1\n");
	}
	else if(arr[4] + arr[5] >= diff){
		printf("2\n");
	}
	else{
		printf("3\n");
	}
	return 0;
}