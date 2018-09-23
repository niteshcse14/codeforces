#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,k,res;
int main(){
	res =0;
	scanf("%llu%llu",&n,&k);
	res=(1LL<<int(log2l(n)+1))-1;
	printf("%llu\n",(k==1)?n:res);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
main(){
	__int64 n,k;
	cin>>n>>k;
	cout<<(k-1?(1LL<<int(log2l(n)+1))-1:n);
}
*/