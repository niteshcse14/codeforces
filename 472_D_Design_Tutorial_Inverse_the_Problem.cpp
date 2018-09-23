#include <bits/stdc++.h>
using namespace std;
int a[2001][2001];
int n,z;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		if(a[i][i])
			z=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){ 
			if(a[i][j]!=a[j][i]||(a[i][j]==0 && j!=i))
				z=1;
		}
	}
	for(int i=0;i<n;i++){
		int r=0;
		for(int j=0;j<n;j++)
			if(a[i][j]<a[i][r]&&i!=j)
				r=j;
		for(int j=0;j<n;j++)
			if(abs(a[i][j]-a[j][r])!=a[i][r]) 
				z=1;
	}
	printf("%s\n",z?"NO":"YES");
	return 0;
}