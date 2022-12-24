#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << "[ " << #x << " ] : " << x

struct Segtree {
	int n;
	vector<int> tree;
	vector<int> lazy;
	void build(vector<int>& arr) {
		n = arr.size();
		tree.resize(n * 4);
		lazy.resize(n * 4);
		build(1, 0, n - 1, arr);
	}
	int query(int low, int high) {
		low--, high--;
		return query(1, 0, n - 1, low, high);
	}

	void prop(int idx, int low, int high) {
		if(lazy[idx] == 0) return;
		tree[idx] += (high - low + 1)*lazy[idx];

		if(low != high) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	int query(int idx, int min_low, int max_high, int low, int high) {
		if(max_high < low || min_low > high) return 0;
		prop(idx, min_low, max_high);
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
	void upd(int low, int high, int v) {
		low--, high--;
		return range_update(1, 0, n - 1, low, high, v);
	}
	void range_update(int idx, int min_low, int max_high, 
			int low, int high, int v) {
		prop(idx, min_low, max_high);
		
		if(min_low > high || max_high < low) return;
		if(min_low >= low && max_high <= high) {
			lazy[idx] = v;
			prop(idx, low, high);
			return;
		}
		int mid = (min_low + max_high) / 2;
		range_update(idx * 2, min_low, mid, low, high, v);
		range_update(idx * 2 + 1, mid + 1, max_high, low, high, v);
		tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
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
	Segtree sg;
	sg.build(a);
	while(q--) {
		int type; cin >> type;
		if(type == 2) {
			int low, high; cin >> low >> high;
			cout << sg.query(low, high) << '\n';
		}
		else {
			int low, high, v; cin >> low >> high >> v;
			sg.upd(low, high, v);
		}
	}
}