#include <bits/stdc++.h>
using namespace std;
double r, d, n, x, y, sr;
int ans;
int main(){
	ans = 0;
	cin >> r >> d >> n;
	while(n--){
		cin >> x >> y >> sr;
		double dist = (double)sqrt(x * x + y * y);
		if((dist + sr) > r || (dist - sr) < (r - d)){
			continue;
		}
		double t = r - d;
		if(((dist + sr) <= r) && ((dist - sr) >= (r - d))){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}