#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int n,l,r,x,mx,mn,ans,sum,cnt;
int inp[maxn];
int main(){
	ans=0;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for(int i=0;i<n;++i)scanf("%d",&inp[i]);
	for(int i=0;i<(1<<n);++i){
		sum=cnt=0;
		mx=INT_MIN;
		mn=INT_MAX;
		for(int j=0;j<n;++j){
			//printf("val %d\n",(i&(1<<j)));
			if((i&(1<<j))>0){
				cnt++;
				sum+=inp[j];
				mn=min(mn,inp[j]);
				mx=max(mx,inp[j]);
			}
		}
		//printf("%d %d %d %d\n",cnt,sum,mn,mx);
		if(cnt>=2&&(mx-mn)>=x&&sum>=l&&sum<=r)ans++;
	}
	printf("%d\n",ans);
	return 0;
}