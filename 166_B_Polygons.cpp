#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 101000
struct point{
	ll x,y;
}ar[maxn],b;
ll n,m,ans=0;
ll cross_product(point p,point q,point r){
	return ((q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x));
}
int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;++i)
		scanf("%lld%lld",&ar[i].x,&ar[i].y);
	scanf("%lld",&m);
	for(int i=0;i<m;++i){
		scanf("%lld%lld",&b.x,&b.y);
		int l=1,r=n-1,mid,res=1;
		while(l<=r){
			mid=(l+r)>>1;
			if(cross_product(ar[0],b,ar[mid])>0)
				l=mid+1;
			else{
				res=mid;
				r=mid-1;
			}
		}
		if(res==1||(cross_product(ar[0],b,ar[n-1])==0))
			continue;
		if(cross_product(ar[res],b,ar[res-1])<0)
			ans++;
	}
	if(ans==m)printf("YES\n");
	else printf("NO\n");
	return 0;
}