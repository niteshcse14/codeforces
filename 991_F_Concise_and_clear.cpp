#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
long long p10[10];
map<long long, string> m;
set<long long> s[10];
 
template<class T> string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
 
int getlen(long long x) {
    int ans = 0;
    while (x) {
        x /= 10;
        ans++;
    }
    return max(ans, 1);
}
 
string get(long long x) {
    if (m.count(x))
        return m[x];
    return toString(x);
}
 
void relax(long long x, string str) {
    // obviously not optimal
    if (x > n || str.length() >= getlen(x))
        return;
 
    // already have better
    if (m.count(x) && m[x].length() <= str.length())
        return;
 
    s[m[x].length()].erase(x);
    m[x] = str;
    s[str.length()].insert(x);
}
 
void generatePowers() {
    for (long long x = 2; x * x <= n; x++) {
        long long c = x * x;
        int p = 2;
        while (c <= n) {
            string tmp = toString(x) + "^" + toString(p);
            relax(c, tmp);
            c *= x;
            p++;
        }
    }
}
 
void generatePowerAndPower(int maxlen) {
    for (int i = 1; i <= maxlen; i++)
        for (int j = i; i + j + 1 <= maxlen; j++)
            for (auto x : s[i])
                for (auto y : s[j])
                    relax(x * y, get(x) + "*" + get(y));
}
 
void generateSimpleAndPower(int maxlen) {
    for (int i = 1; i + 2 <= maxlen; i++)
        for (long long x = 1; x < p10[maxlen - 1 - i]; x++)
            for (long long y : s[i])
                relax(x * y, toString(x) + "*" + get(y));
}
 
void precalc() {
    generatePowers();
    generatePowerAndPower(7);
    generateSimpleAndPower(7);
}
 
string ans;
void relaxAns(string s) {
    if (ans.length() > s.length())
        ans = s;
}
 
void check2() {
    for (int i = 1; i * 2 + 1 < ans.length(); i++) {
        for (long long x = 1; x <= p10[i]; x++) {
            relaxAns(get(n - x) + "+" + get(x));
            if (n % x == 0)
                relaxAns(get(n / x) + "*" + get(x));
        }
        for (auto x : s[i]) {
            relaxAns(get(n - x) + "+" + get(x));
            if (n % x == 0)
                relaxAns(get(n / x) + "*" + get(x));
        }
    }
}
 
int main() {
    p10[0] = 1;
    for (int i = 1; i < 10; i++)
        p10[i] = 10 * p10[i - 1];
    cin >> n;
    precalc();
    ans = get(n);
    check2();
    cout << ans;
}