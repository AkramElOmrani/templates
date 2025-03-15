#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
 
int n, q;
vector<ll> tree, lazy, a;
 
void process(int node, int l, int r) {
	if(lazy[node] > 0) {
		tree[node] += (r - l + 1) * lazy[node];
		if(l != r) {
			for(int idx : {node * 2, node * 2 + 1}) {
				lazy[idx] += lazy[node];
			}
		}
	}
	lazy[node] = 0;
}
 
void build(int node, int l, int r) {
	if(l == r) {
		tree[node] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
 
void upd(int node, int l, int r, int low, int high, int v) {
	process(node, l, r);
	if(high < l || r < low) return;
	if(low <= l && r <= high) {
		lazy[node] += v;
		process(node, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	upd(node * 2, l, mid, low, high, v);
	upd(node * 2 + 1, mid + 1, r, low, high, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
 
ll query(int node, int l, int r, int pos) {
	process(node, l, r);
	if(pos < l || r < pos) return 0;
	if(l == r) return tree[node];
	int mid = (l + r) >> 1;
 
	return (ll)query(node * 2, l, mid, pos) + 
			query(node * 2 + 1, mid + 1, r, pos);
}
 
 
int main()
{
	ios
	cin >> n >> q;
	tree.resize(n * 4);
	lazy.resize(n * 4);
	a.resize(n);
	for(ll& x : a) {
		cin >> x;
	}
	build(1, 0, n - 1);
	// dbg(tree);
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int a, b, v; cin >> a >> b >> v; a--, b--;
			upd(1, 0, n - 1, a, b, v);
		}
		else {
			int k; cin >> k; k--;
			cout << query(1, 0, n - 1, k) << '\n';
		}
	}
}