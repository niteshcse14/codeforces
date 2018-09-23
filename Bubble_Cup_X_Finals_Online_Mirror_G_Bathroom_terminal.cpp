#include <bits/stdc++.h>
using namespace std;
map < string, int > mp, match_mp;
int n, m;
string str;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		cin >> str;
		mp.insert(make_pair(str, str.size()));
	}
	for(int i = 0; i < n; ++i){
		cin >> str;
		match_mp.insert(make_pair(str, str.size()));
	}
	for(int i = 0; i < match_mp.size(); ++i){
		for(int j = 0; j < mp.size(); ++j){
			//
		}
	}
	return 0;
}