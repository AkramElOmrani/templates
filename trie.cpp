#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

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

const int N = 1.6e7 + 5;
const int siz = 2;

int rt, ncnt;
struct node {
    int ch[siz];
    int vis;
} trie[N];
inline bool check(int x) {
    if (!trie[0].vis) return 0;
    int p = rt;
    for (int i = 30; i >= 0; i--) {
        int j = ((x >> i) & 1);
        if (trie[p].ch[j] == -1 || !trie[trie[p].ch[j]].vis)
            return 0;
        p = trie[p].ch[j];
    }
    return 1;
}
inline void insert(int x) {
    if (check(x)) return ;
    int p = rt;
    trie[0].vis ++;
    for (int i = 30; i >= 0; i--) {
        int j = ((x >> i) & 1);
        if (trie[p].ch[j] == -1) {
            trie[p].ch[j] = ++ncnt;
            trie[ncnt].vis = 0;
            trie[ncnt].ch[0] = trie[ncnt].ch[1] = -1;
        }
        p = trie[p].ch[j];
        trie[p].vis ++;
    }
}
inline void del(int x) {
    if (!check(x)) return ;
    int p = rt;
    trie[0].vis --;
    for (int i = 30; i >= 0; i--) {
        int j = ((x >> i) & 1);
        p = trie[p].ch[j];
        trie[p].vis --;
    }
}
int dfs(int x) {
    int p = rt, ret = 0;
    for (int i = 30; i >= 0; i--) {
        int j = ((x >> i) & 1);
        if (trie[p].ch[j] != 0 && trie[trie[p].ch[j]].vis) {
            p = trie[p].ch[j];
        } else {
            ret |= (1 << i);
            p = trie[p].ch[j ^ 1];
        }
    }
    return ret;
}
void test_case() {
	
}

signed main()
{
	ios
	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
}