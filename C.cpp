#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

// C(n, k) = n! / (k! * (n - k)!)

#define int ll

vector<mint> fact = {1}, inv_fact = {1};
template<typename T>
mint C(T n, T k) {
	while(fact.size() <= n) {
		fact.push_back(fact.back() * (fact.size()));
		inv_fact.push_back(T(1) / fact.back());
	}
	return fact[n] * inv_fact[n - k] * inv_fact[k]; 
}


signed main()
{
	ios
	int x = calc(130, 5);
	int y = calc(63, 5);
	int z = calc(130 - 63, 5);
	dbg(x, y, z)
}
