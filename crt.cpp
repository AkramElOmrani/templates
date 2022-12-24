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


// solving the system of congruences :
// x = a[i].first(a[i].second)

x = a1			 				 		[q1]
a2 = x1 + x2 * q1 				 		[q2]
x2 = (a2 - x1) * inv(q1) 		 		[q2]
a3 = x1 + x2 * q1 + x3 * q1 * q2 	 	[q3]
x3 = (a3 - x1 - x2 * q1) * inv(q1 * q2) [q3]

int crt(vector<pair<int, int>> a) {
	// note check that all a[i].second are pairwise coprimes
	int cur = 0;
	int n = a.size();
	int p = 1;
	int cur = 0;

	for(int i = 0; i < n; i++) {
		cur += (a[i].first % a[i].second);
		
	}
}

int main()
{
	ios
	int n; cin >> n;
	vector<pair<int, int>> v(n);

	for(auto&[x, y] : v) {
		cin >> x >> y;
		
	}
	cout << solve(v) << '\n';
}