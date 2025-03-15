#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

int LOG;
int n;
vector<int> depth;
vector<vector<int>> adj;
vector<vector<int>> up;

void prepare() {
	
}

void build_lca(int a, int p = -1) {
	for(int v : adj[a]) {
		if(v == p) continue;
		up[v][0] = a;
		depth[v] = depth[a] + 1;
		for(int j = 1; j < LOG; ++j) {
			up[v][j] = up[ up[v][j - 1] ][j - 1];
		}
		build_lca(v, a);
	}
}

int kth_ancenstor(int a, int k) {
	for(int i = 0; i < LOG; ++i)
		if(k & (1 << i)) {
			a = up[a][i];
		}

	return a;
}

int lca(int a, int b) {
	if(depth[a] > depth[b]) {
		swap(a, b);
	}
	// a is the guy with the lesser depth
	b = kth_ancenstor(b, depth[b] - depth[a]);
	// dbg(a, b, depth[a], depth[b]);
	assert(depth[a] == depth[b]);
	if(a == b) {
		return a;
	}
	for(int i = LOG - 1; i >= 0; --i) {
		if(up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}

int dist(int a, int b) {
	return (depth[a] + depth[b]) - 2 * depth[lca(a, b)];
}


void test_case() {
	cin >> n;
	LOG = ceil(log2(n)) + 1;
	adj.resize(n);
	depth.resize(n);
	depth.clear();
	up = vector<vector<int>>(n, vector<int>(LOG));
	for(int i = 0; i < n; ++i) {
		adj[i].clear();
		depth[i] = 0;
		int m; cin >> m;
		for(int j = 0, u; j < m; ++j) {
			cin >> u; u--;
			adj[i].push_back(u);
		}
	}


	build_lca(0);
	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b; a--, b--;
		cout << dist(a, b) << '\n';
	}
}

int main()
{
	ios
	int t; cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case " << i << ":\n";
		test_case();
	}
}