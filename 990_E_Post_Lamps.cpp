#include<bits/stdc++.h>
#define ll long long
#define inf 9999999999999999ll
#define N 1000005
using namespace std;
int n,m,k,s[N],f[N];ll ans;
int main()
{
  	int x;
  	scanf("%d%d%d",&n,&m,&k);
  	for(int i=1;i<=m;i++)
  		scanf("%d",&x),s[x]=1;
  	if(s[0]){
  		printf("-1\n");
  		return 0;
  	}
  	for(int i=1;i<=n;i++){
    	if(!s[i])f[i]=i;
    	else f[i]=f[i-1];
    	//printf("%d %d\n",i,f[i]);
  	}
  	ans=inf;
  	for(int i=1;i<=k;i++){
  		scanf("%d",&x);
  		int flag=0;ll sum=0;
    	for(int j=0;j<n;j=f[j]+i,sum+=x){
      		if(f[j]+i<=j){
      			flag=1;
      			break;
      		}
      	}
    	if(!flag)
    		ans=min(ans,sum);
  	}
  	if(ans==inf)
  		printf("-1\n");
  	else
  		printf("%lld\n",ans);
  	return 0;
}