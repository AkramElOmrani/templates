#include <bits/stdc++.h>
using namespace std;

mt19937_64 mrand(random_device{}()); 
#define ll long long int
#define int ll

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	vector<int> h(n + 1), a(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i) {
		h[i] = mrand();
	}
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[i] = a[i - 1] + h[x];
	}
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		b[i] = b[i - 1] + h[x];
	}
	while(q--) {
		int l, r, L, R; cin >> l >> r >> L >> R;
		cout << (a[r] - a[l - 1] == b[R] - b[L - 1] ? "Yes\n" : "No\n");
	}
}