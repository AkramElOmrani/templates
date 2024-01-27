#include <bits/stdc++.h>
using namespace std;

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


signed main()
{
	ios
	int n, q; cin >> n >> q;
	vector<int> lg(n + 1);
	for(int i = 2; i <= n; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	vector<int> a(n); for(int& x : a) cin >> x;
	const int LOG = lg[n] + 1;
	vector<vector<int>> sparse(n, vector<int>(LOG));
	for(int i = 0; i < n; ++i) {
		sparse[i][0] = a[i];
	}
	for(int j = 1; j < LOG; ++j) {
		for(int i = 0; i + (1 << j) <= n; ++i) {
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
		}
	}
	auto get = [&](int l, int r) -> int {
		int sz = lg[r - l + 1];
		if(sz == 0) return a[l];
		return min(sparse[l][sz], sparse[r - (1 << (sz)) + 1][sz]);
	};
	while(q--) {
		int l, r; cin >> l >> r; --r;
		cout << get(l, r) << '\n';
	}
}
