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


int LOG;
vector<vector<int>> up;

int kth_ancenstor(int a, int k) {
	for(int i = 0; i < LOG; ++i)
		if(k & (1LL << i)) {
			a = up[a][i];
		}

	return a;
}


signed main()
{
	ios
	int n, k; cin >> n >> k;
	LOG = 60;
	vector<int> par(n);
	for(int& x : par) cin >> x, --x;
	vector<int> a(n); for(int& x : a) cin >> x;
	up = vector<vector<int>> (n, vector<int>(LOG));
	for(int i = 0; i < n; ++i) {
		up[i][0] = par[i];
	}
	for(int j = 1; j < LOG; ++j) {
		for(int v = 0; v < n; ++v) {
			up[v][j] = up[ up[v][j - 1] ][j - 1];
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << a[kth_ancenstor(i, k)] << ' ';
	}
}