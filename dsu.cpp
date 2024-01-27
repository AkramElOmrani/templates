#include <bits/stdc++.h>
using namespace std;

struct Dsu {
	int n;
	vector<int> p, sz;
	int cc = 1;
	Dsu(int n) : n(n) {
		cc = n;
		p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0);
	}
	int find(int a) {
		return p[a] = (a == p[a] ? a : find(p[a]));
	}
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return false;
		if(sz[a] > sz[b]) swap(a, b);
		--cc;
		sz[b] += sz[a];
		p[a] = b;
		return true;
	}
};

// TODO : add Krushkal

int main()
{
	int n; cin >> n;
	Dsu d(n);
	d.unite(1, 2);
	cout << d.find(1) << ' ' << d.find(2) << '\n';
}