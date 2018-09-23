#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long int
ll n, sum, pre_sum, post_sum;
ll inp[maxn], ans, pre[maxn];
map<ll, ll> mp;
ll solve() {
    ans = 0;
    pre_sum = 0;
    for (ll i = 0 ; i < n ; i++) {
        if (i == 0)
            pre[i] = inp[i];
        else pre[i] = pre[i - 1] + inp[i];
        //printf("%lld ", pre[i]);
    }
    //printf("\n");
    post_sum = 0;
    for (ll i=n-1; i >= 0; i--) {
        post_sum += inp[i];
        ll idx = lower_bound(pre, pre + i, post_sum) - pre;
        if (post_sum == pre[idx] && idx < i) {
            //printf("True At %lld\n", i);
            ans = max (ans, post_sum);
        }
    }
    return ans;
}
int main() {
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &inp[i]);
    printf("%lld\n", solve());
    return 0;
}