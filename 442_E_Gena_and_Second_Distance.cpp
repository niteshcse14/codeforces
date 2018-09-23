#include<bits/stdc++.h>
using namespace std;
struct point{
	double x,y,l;
	point(double a=0.,double b=0.){
		x=a;
		y=b;
	}
}s[2][1010],p[1010];
int f,n;
bool operator<(point a,point b){return a.l>b.l;}
double dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void calc(point &q){
	int i;
	double f,s,t;
	f=s=2e13;
	for(i=1;i<=n;i++){
		t=dis(p[i],q);
		if(t<s)s=t;
		if(f>s)swap(f,s);
	}
	q.l=s;
}
int main(){
	int w,h,i,j,k,sp,c;
	double ans,dx,dy;
	scanf("%d%d%d",&w,&h,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&j,&k);
		p[i].x=j;
		p[i].y=k;
	}
	c=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			c++;
			s[0][c]=point(w*(i+.5)*.1,h*(j+.5)*.1);
			//cout << (w*(i+.5)*.1) << "\t" << (h*(j+.5)*.1) << "\n";
		}
	}
	sp=10;
	f=0;
	dx=w*.05;
	dy=h*.05;
	while(sp--){
		for(i=1;i<=c;i++)calc(s[f][i]);
		sort(s[f]+1,s[f]+c+1);
		ans=s[f][1].l;
		dx*=.1;
		dy*=.1;
		c=0;
		for(k=1;k<=10;k++){
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					c++;
					s[f^1][c]=point(s[f][k].x+dx*(i*2.-9.),s[f][k].y+dy*(j*2.-9.));
				}
			}
		}
		f^=1;
	}
	printf("%.12lf\n",sqrt(ans));
}