#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gen(int a, int b) {return (ll)rng() % (b - a + 1) + a;}
 
const int MOD = 1e9 + 7;
 
 
int binp(int a, int b, int mod) {
	ll cur = 1;
	while(b) {
		if(b & 1) {
			(cur *= a) %= mod;
		}
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return cur;
}
 
void test_case() {
	int a, b, c; cin >> a >> b >> c;
	b = binp(b, c, MOD - 1);
	cout << binp(a, b, MOD) << '\n';
}
 
int main()
{
	ios
	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
}