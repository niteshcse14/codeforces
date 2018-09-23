#include <bits/stdc++.h>
using namespace std;
char a[100005], b[100005];
int n, ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i]; 
	for (int i = 1; i <= n; i++)
		if (b[i] == b[n + 1 - i])
			swap(b[i], a[n + 1 - i]), swap(a[i], b[i]);
	for (int i = 1; i <= n; i++)
		if (a[i] == b[n + 1 - i])
			swap(a[i], a[n + 1 - i]);
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int resp = 0;
	for (int i=0; i<n/2; i++){
		int j = n - (1 + i);
		if(b[i] == b[j]){
			if(a[i] != a[j]) resp++;
		}
		else {
			if(a[i] == b[i] && a[j] == b[j]) continue ;
			if(a[i] == b[j] && a[j] == b[i]) continue ;
			if((a[i] != b[i] && a[j] != b[j]) && (a[i] != b[j] && a[j] != b[i])) resp += 2;
			else resp += 1;
		}
	}
	if(n&1 && a[n/2] != b[n/2]) resp++; 
	cout << resp << endl;
}

*/