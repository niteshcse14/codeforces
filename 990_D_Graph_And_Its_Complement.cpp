#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int ar[2000][2000];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(min(a,b)>1){
		printf("NO\n");
		return 0;
	}
	if(a==1&&b==1){
		if(n==2||n==3){
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i=1;i<n;++i)
			ar[i][i-1]=ar[i-1][i]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				printf("%d",ar[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	int flag=0;
	if(a==1){
		swap(a,b);
		flag=1;
	}
	printf("YES\n");
	for(int i=1;i<=n-a;++i)
			ar[i][i-1]=ar[i-1][i]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%d",(i==j)?0:flag^ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}