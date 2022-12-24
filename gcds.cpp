#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

int egcd(int a, int b, int& x, int& y) {
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

int mod_inv(int a, int b) {
	int x, y;
	int g = egcd(a, b, x, y);
	assert(g == 1);
	x = (x % b + b) % b;
	return x;
}

int main()
{
	ios
	cout << mod_inv(10, 7);
}