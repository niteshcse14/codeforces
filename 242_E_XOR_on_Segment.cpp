#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100010
ll t,n,x,L,R,sum,q,type;
ll st[4*maxn][22],lazy[4*maxn][22];
void update(ll si,ll ss,ll se,ll bit){
	ll interval=se-ss+1,mid=(ss+se)>>1;
	if(lazy[si][bit]){
		st[si][bit]=interval-st[si][bit];
		if(ss!=se){
			lazy[2*si][bit]^=1;
			lazy[2*si+1][bit]^=1;
		}
		lazy[si][bit]=0;
	}
	if(ss>R||se<L)return;
	if(ss>=L&&R>=se){
		lazy[si][bit]=1;
		if(lazy[si][bit]){
			st[si][bit]=interval-st[si][bit];
			if(ss!=se){
				lazy[2*si][bit]^=1;
				lazy[2*si+1][bit]^=1;
			}
			lazy[si][bit]=0;
		}
		return;
	}
	update(2*si,ss,mid,bit);
	update(2*si+1,mid+1,se,bit);
	st[si][bit]=st[2*si][bit]+st[2*si+1][bit];
}
ll query(ll si,ll ss,ll se,ll bit){
	ll interval=se-ss+1,mid=(ss+se)>>1;
	if(lazy[si][bit]){
		st[si][bit]=interval-st[si][bit];
		if(ss!=se){
			lazy[2*si][bit]^=1;
			lazy[2*si+1][bit]^=1;
		}
		lazy[si][bit]=0;
	}
	if(R<ss||se<L)return 0;
	if(L<=ss&&R>=se)return st[si][bit];
	return query(2*si,ss,mid,bit)+query(2*si+1,mid+1,se,bit);
}
int main(){
	scanf("%lld",&n);
	for(ll i=0;i<n;++i){
		scanf("%lld",&x);
		L=R=i;
		for(ll j=0;j<21;++j)
			if((1<<j)&x)update(1,0,n-1,j);
	}
	scanf("%lld",&q);
	while(q--){
		scanf("%lld%lld%lld",&type,&L,&R);
		L--, R--;
		if(type==1){
			sum=0;
			for(ll i=0;i<21;++i)
				sum+=query(1,0,n-1,i)*(1<<i);
			printf("%lld\n",sum);
		}
		else{
			scanf("%lld",&x);
			for(ll i=0;i<21;++i)
				if((1<<i)&x)update(1,0,n-1,i);
		}
	}
	return 0;
}