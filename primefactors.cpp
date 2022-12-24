#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

const int nax = 1e6 + 1;
vector<int> prime(nax, true);

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

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void sieve() {
	prime[0] = prime[1] = false;
	for(int i = 2; i <= nax; ++i) {
		if(!prime[i]) continue;
		for(int j = i + i; j <= nax; j += i) {
			prime[j] = false;
		}
	}
}

map<int, int> primefactors(int n) {
	map<int, int> mp;
	if(prime[n]) {
		mp[n] = 1;
		return mp;
	}
	for(int i = 2; i <= n; ++i) {
		while(n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	return mp;
}

int indicatrice(int n) {
	map<int, int> mp = primefactors(n);
	int res = 1;
	for(auto& [a, b] : mp) {
		res *= binpow(a, b - 1) * (a - 1);
	}
	return res;
}

int phi(int n) 
{ 
	int result = n;  
	for(int p = 2; p * p <= n; ++p) 
	{
		if (n % p == 0)  
		{
			while (n % p == 0) 
				n /= p; 
			result -= result / p; 
		}
	}
	if (n > 1) {
		assert(prime[n]);
		result -= result / n; 
	}
	return result;
}

int main()
{
	ios
	sieve();
	ll ans = 0;
	for(int i = 0; i < nax; ++i) {
		if(prime[i]) {
			cout << i << '\n';
			++ans;
		}
	}
	cout << ans;
}