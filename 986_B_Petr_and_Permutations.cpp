#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,cnt=0;
	scanf("%d",&n);
	if(n<=5)
		printf("Petr\n");
	else{
		for(int i=1;i<=n;i++)
			scanf("%d",&x),cnt+=(i==x);
		printf("%s\n",(cnt>2)?"Petr":"Um_nik");
	}
	return 0;
}