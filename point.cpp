#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

struct Point {
	ll x, y;
	Point(ll x_, ll y_) {
		x = x_, y = y_;
	}
	Point() {
		cin >> x >> y;
	}
	Point get_vector(Point& p) {
		return Point{p.x - x, p.y - y};
	}
	bool cross(Point& p) {
		return p.x * y - p.y * x == 0;
	}
	void dbg_pt() {
		cout << make_pair(x, y) << '\n';
	}
};