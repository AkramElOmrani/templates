#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << "[ " << #x << " ] : " << x

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
				table[i][j] = min(table[i][j - 1], table[(1 << (j - 1)) + i][j - 1]);
			}
		}
	}
	int get(int low, int high) {
		int sz = (high - low + 1);
		int l = log2(sz);
		return min(table[low][l], table[high - (1 << l) + 1][l]);
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
	Sparse st(a);
	const int LOG = (int)(log2(n)) + 1;
	vector<vector<int>> table(n, vector<int>(LOG));
	for(int i = 0; i < n; ++i) {
		table[i][0] = a[i];
	}
	for(int j = 1; j < LOG; ++j) {
		for(int i = 0; i + (1 << j) <= n; ++i) {
			table[i][j] = min(table[i][j - 1], table[(1 << (j - 1)) + i][j - 1]);
		}
	}
	auto get = [&](int low, int high) {
		int sz = (high - low + 1);
		int l = log2(sz);
		return min(table[low][l], table[high - (1 << l) + 1][l]);
	};
	// checking the build
	int q; cin >> q;
	while(q--) {
		int low, high; cin >> low >> high;
		cout << get(low, high) << '\n';
	}
}