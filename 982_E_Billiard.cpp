#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,x,y,vx,vy;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void exgcd(int a,int b,ll&x,ll&y,int c){
	if(!b){
		x=c;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x,c);
	y-=a/b*x;
}
int main(){
	cin>>n>>m>>x>>y>>vx>>vy;
	if(!vx){
		if(!x||x==n)
			printf("%d %d",x,vy>0?m:0);
		else 
			printf("-1");
		return 0;
	}
	if(!vy){
		if(!y||y==m)
			printf("%d %d",vx>0?n:0,y);
		else 
			printf("-1");
		return 0;
	}
	int k1,k2;
	if(vx==1)
		k1=(n-x)%n;
	else 
		k1=x%n;
	if(vy==1)
		k2=(m-y)%m;
	else 
		k2=y%m;
	int g=gcd(n,m);
	if((k1-k2)%g){
		printf("-1");
		return 0;
	}
	ll xx,yy,s,lcm=1ll*n/g*m;
	exgcd(n,m,xx,yy,(k2-k1)/g);
	xx%=m/g;
	s=((xx*n+k1)%lcm+lcm)%lcm;
	xx=x+s*vx;
	yy=y+s*vy;
	printf("%lld %lld\n",(xx%(2*n)+2*n)%(2*n),(yy%(2*m)+2*m)%(2*m));
}