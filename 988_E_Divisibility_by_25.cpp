#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
void solve(string s,string p){
	int count=0;
	int t1=s.rfind(p[1]);
	int t2=(p[0]==p[1])?s.rfind(p[0],t1-1):s.rfind(p[0]);
	if(t1==-1||t2==-1)
		return;
	for(int i=t1;i<s.size()-1;i++)
		swap(s[i],s[i+1]),count++;
	t2=s.rfind(p[0],s.size()-2);
	for(int i=t2;i<s.size()-2;i++)
		swap(s[i],s[i+1]),count++;
	int z,tmp;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			z=i;
			break;
		}
	}
	tmp=count;
	if(z>=1&&s.size()-2>z)
		tmp=count+z;
	else if(z>=1&&s.size()-2<=z)
		tmp=INT_MAX;
	ans=min(ans,tmp);
}
int main(){
	string s;
	cin>>s;
	solve(s,"00");
	solve(s,"25");
	solve(s,"50");
	solve(s,"75");
	printf("%d\n",(ans==INT_MAX)?-1:ans);
	return 0;
}