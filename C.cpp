#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

#define ll long long
#define int ll
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gen(int a, int b) {return (ll)rng() % (b - a + 1) + a;}


const int nax = 1e6 + 1;
int dp[nax];
int c(int n) {
	return n * (n - 1) / 2;
}
signed main()
{
	ios
	for(int i = n; i >= 1; --i) {
		dp[i] = c(n / i);
		for(int j = i + i; j <= n; j += i) {
			dp[i] -= dp[j];
		}
	}
	int n;
	while(cin >> n) {
		if(n == 0) break;
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += i * dp[i];
		}
		cout << ans << '\n';
	}
}