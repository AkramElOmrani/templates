#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << "[ " << #x << " ] : " << x

struct Segtree {
	int n;
	vector<int> tree;
	Segtree(int n_) {
		n = n_;
		tree.resize(n * 4);
	}
	Segtree(vector<int>& a) {
		n = arr.size();
		tree.resize(n * 4);
		build(1, 0, n - 1, arr);
	}
	int query(int low, int high) {
		return query(1, 0, n - 1, low, high);
	}
	int query(int idx, int min_low, int max_high, int low, int high) {
		if(max_high < low || min_low > high) return 0;
		if(low <= min_low && max_high <= high) return tree[idx];

		int mid = (min_low + max_high) / 2;
		return merge(
			query(idx * 2, min_low, mid, low, high),
			query(idx * 2 + 1, mid + 1, max_high, low, high)
			);
	}
	int merge(int a, int b) {
		return a + b;
	}
	void build(int idx, int l, int r, vector<int>& arr) {
		if(l == r) {
			tree[idx] = arr[l];
			return;
		}
		int mid = (l + r) / 2;
		build(idx * 2, l, mid, arr);
		build(idx * 2 + 1, mid + 1, r, arr);
		tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
	}
	void upd(int node, int v) {
		return point_upd(1, 0, n - 1, node, v);
	}
	void point_upd(int idx, int min_low, int max_high, int node, int v) {
		if(node < min_low || max_high < node) return;
		if(min_low == max_high) {
			tree[idx] = v;
			return;
		}
		int mid = (min_low + max_high) / 2;
		point_upd(idx * 2, min_low, mid, node, v);
		point_upd(idx * 2 + 1, mid + 1, max_high, node, v);
		tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
	}
};


int main()
{
	ios
	int n; cin >> n;
	vector<int> a(n);
	for(int& x : a) {
		cin >> x;
	}
	Segtree sg;
	sg.build(a);
	int q; cin >> q;
	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int low, high; cin >> low >> high;
			cout << sg.query(low, high) << '\n';
		}
		else {
			int node, v; cin >> node >> v;
			sg.upd(node, v);
		}
	}
}