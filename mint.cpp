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

template <int MOD=1000000007>
struct Modular {
	int value;
	static const int MOD_value = MOD;

	Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
	Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

	Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
	Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
	Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

	friend Modular mexp(Modular a, long long e) {
		Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
	}
	friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

	Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
	friend Modular operator+(Modular a, Modular const b) { return a += b; }
	friend Modular operator-(Modular a, Modular const b) { return a -= b; }
	friend Modular operator-(Modular const a) { return 0 - a; }
	friend Modular operator*(Modular a, Modular const b) { return a *= b; }
	friend Modular operator/(Modular a, Modular const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
	friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
	friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

const int mod = 1e9 + 7; // 998244353
using mint = Modular<mod>;

mint binpow(mint a, int b) {
	mint result = 1;
	while(b) {
		if(b & 1) {
			result *= a;
		}
		a *= a;
		b >>= 1;
	}
	return result;
}

vector<mint> fact = {1}, inv_fact = {1};
mint C(int n, int k) {
	if(k < 0) {
		return 0;
	}
	if(n < k) return 0;
	while(fact.size() <= n) {
		fact.push_back(fact.back() * (fact.size()));
		inv_fact.push_back(mint(1) / fact.back());
	}
	return fact[n] * inv_fact[n - k] * inv_fact[k]; 
}

mint A(int n, int k) {
	if(k < 0) {
		return 0;
	}
	if(n < k) return 0;
	while(fact.size() <= n) {
		fact.push_back(fact.back() * (fact.size()));
		inv_fact.push_back(mint(1) / fact.back());
	}
	return fact[n] * inv_fact[n - k]; 
}


mint f(int n) {
	while(fact.size() <= n) {
		fact.push_back(fact.back() * (fact.size()));
		inv_fact.push_back(mint(1) / fact.back());
	}
	return fact[n];
}

mint ifact(int n) {
	while(fact.size() <= n) {
		fact.push_back(fact.back() * (fact.size()));
		inv_fact.push_back(mint(1) / fact.back());
	}
	return inv_fact[n];
}

mint sb(int n, int k) {
	return C(n + k - 1, k - 1);
}


int main()
{
	ios
	for(int i = 0; i <= )
}
