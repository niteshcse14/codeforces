#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long lld;
#define N 1000005
int main(){
    lld x,d;
    vector<lld> ans;
    cin>>x>>d;
    lld num = 1, cnt = 0;
    for(int i=60;i>=1;--i){
        if((x>>i)&1){
            //printf("set %d\n",i);
            for(int j=0;j<i;++j)
                ans.pb(num);
            cnt++;
            num+=(d+1);
        }
    }
    //printf("SIZE %d\n",cnt);
    while(cnt--) 
        ans.pb(num),num+=(d+1);
    if(x%2) ans.pb(num);
    cout<<(ans.size())<<endl;
    for(auto i:ans) cout<<i<<" ";
    printf("\n");
    return 0;
}