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


template<typename T>
struct Segtree {
	int n;
	vector<T> tree;
	T neut = 0;
	template<typename M>
	Segtree(vector<M>& a, T neu) : neut(neu) {
		n = a.size();
		tree.resize(n * 4);
		build(1, 0, n - 1, a);
	}	
	Segtree(int n_, T neu) : n(n_), neut(neu) {
		tree.resize(n * 4);
	}
	T merge(T a, T b) {
		return a + b;
	}
	template<typename M>
	void build(int node, int l, int r, vector<M>& a) {
		if(l == r) {
			tree[node] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(node * 2, l, mid, a);
		build(node * 2 + 1, mid + 1, r, a);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
	T query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
	T query(int node, int l, int r, int low, int high) {
		if(high < l || r < low) return neut;
		if(low <= l && r <= high) {
			return tree[node];
		}
		int mid = (l + r) / 2;
		return merge(query(node * 2, l, mid, low, high),
			query(node * 2 + 1, mid + 1, r, low, high));
	}
	template<typename M>
	void upd(int pos, M v) {
		upd(1, 0, n - 1, pos, v);
	}
	template<typename M>
	void upd(int node, int l, int r, int pos, M v) {
		if(pos < l || r < pos) return;
		if(l == r) {
			tree[node] = v;
			return;
		}
		int mid = (l + r) / 2;
		upd(node * 2, l, mid, pos, v);
		upd(node * 2 + 1, mid + 1, r, pos, v);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
};

int main()
{
	ios
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int& x : a) {
		cin >> x;
	}
	Segtree<ll> sg(a, 0);
	while(q--) {
		int type; cin >> type;
		if(type == 2) {
			int low, high; cin >> low >> high; low--, high--;
			cout << sg.query(low, high) << '\n';
		} else if(type == 1) {
			int k, v; cin >> k >> v; --k;
			sg.upd(k, v);
		}
	}
}