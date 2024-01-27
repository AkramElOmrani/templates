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

const int nax = 1e5 + 1;
vector<int> spf(nax, -1);

void init() {
	for(int i = 2; i < nax; ++i) {
		if(spf[i] != -1) continue;
		for(int j = i; j < nax; j += i) {
			if(spf[j] == -1) {
				spf[j] = i;
			}
		}
	}
}

vector<int> factorize(int n) {
	vector<int> f;
	while(n > 1) {
		f.push_back(spf[n]);
		n /= spf[n];
	}
	return f;
}
int f(int n) {
	if(n <= 1) return 1;
	return f(n - 1) * n;
}

signed main()
{
	ios
	init();
	dbg(factorize(561));
}