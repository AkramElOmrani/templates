#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

int binpow(int a, int b) {
	int result = 1;
	while(b) {
		if(b & 1) {
			result *= a;
		}
		a *= a;
		b >>= 1;
	}
	return result;
}

int binpow(int a, int b, int mod) {
	int result = 1;
	while(b) {
		if(b & 1) {
			(result *= a) %= mod;
		}
		(a *= a) %= mod;
		b >>= 1;
	}
	return result;
}


int main()
{
	ios
	int a, b; cin >> a >> b;
	cout << binpow(a, b) << '\n';
}