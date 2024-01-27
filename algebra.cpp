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

// given f integrate between a and b with some partition n
double PI = acos(-1);
double integrate(function<double(double)> f, double a, double b, int n) {
	double sm = 0;
	double len = (double)(b - a) / n;
	for(int k = 0; k < n; ++k) {
		sm += f(a + len * k);
		// dbg(f(a + len * k))
	}
	return double(sm) * len;
}

/*double f(double x) {
	double sn = sin(x);
	double cs = cos(x);
	return sn * sn * sn * cs;
}*/

double f(double x) {
	double s = (x * x * x * cos(x / 2.0) + 1.0 / 2) * sqrt(4 - x * x);
	return s;
}

int main()
{
	ios
	double a = -2, b = 2;
	int n = 10000;

	cout << fixed << setprecision(20) << integrate(f, a, b, n) << '\n';
}