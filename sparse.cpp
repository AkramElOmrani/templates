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

struct Sparse {
	int n;
	int LOG;
	vector<vector<int>> table;
	Sparse(vector<int>& a) {
		n = a.size();
		LOG = (int)(log2(n)) + 1;
		table = vector<vector<int>>(n, vector<int>(LOG));
		for(int i = 0; i < n; ++i) {
			table[i][0] = a[i];
		}
		for(int j = 1; j < LOG; ++j) {
			for(int i = 0; i + (1 << j) <= n; ++i) {
				table[i][j] = __gcd(table[i][j - 1], table[(1 << (j - 1)) + i][j - 1]);
			}
		}
	}
	int get(int low, int high) {
		int sz = (high - low + 1);
		int l = log2(sz);
		return __gcd(table[low][l], table[high - (1 << l) + 1][l]);
	}
};

signed main()
{
	ios
	int n; cin >> n;
	vector<int> a(n); for(int& x : a) cin >> x;
	Sparse st(a);
	int j = 0;
	int ans = n + 1;
	for(int i = 0; i < n; ++i) {
		if(st.get(j, i) != 1) continue;
		while(j + 1 <= i && st.get(j + 1, i) == 1) {
			++j;
		}
		ans = min(ans, i - j + 1);
	}
	if(ans == n + 1) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
	}
}