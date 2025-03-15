#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gen(int a, int b) {return (ll)rng() % (b - a + 1) + a;}

vector<pair<int, int>> dir = {
	{0, -1}, {0, 1}, {-1, 0}, {1, 0}
};
signed main()
{
	ios
    
    vector<vector<int>> a(2, vector<int>(3));
    for(vector<int>& row : a) {
        for(int& x : row) {
            cin >> x;
        }
    }
    vector<vector<int>> goal = {
        {1, 2, 3}, {4, 5, 0}
    };
    set<vector<vector<int>>> vis;
    vector<vector<vector<int>>> cur;
    cur.push_back(a);
    vis.insert(a);
    int ans =0 ;
    auto inside = [&](int x, int y) -> bool {
    	return min(x, y) >= 0 && x < 2 && y < 3;
    };
    while(!cur.empty()) {
        int sz = cur.size();
        vector<vector<vector<int>>> new_cur;
        for(int i = 0; i < cur.size(); ++i) {
            vector<vector<int>> candidate = cur[i];
            if(candidate == goal) {
                cout << ans << '\n';
                return 0;
            }
            for(int i = 0; i < candidate.size(); ++i) {
                for(int j = 0; j < candidate[0].size(); ++j) {
                    if(candidate[i][j] == 0) {
                     	for(auto[x, y] : dir) {
                     		x += i;
                     		y += j;
                     		if(inside(x, y)) {
                     			swap(candidate[i][j], candidate[x][y]);
                     			if(!vis.count(candidate)) {
                     				new_cur.push_back(candidate);
                     				vis.insert(candidate);
                     			}
                     			swap(candidate[i][j], candidate[x][y]);
                     		}
                     	}
                    }
                }
            }
        }
        swap(cur, new_cur);
        ++ans;
    }
    cout << "-1\n";
}

