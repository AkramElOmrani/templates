#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
struct point {
    long long x, y;
    long long cross(const point& o) const {
        return x*o.y - y*o.x;
    }
};
long long que(bool st, vector<pair<char, long long>> d){
    point cur = {0, 0};
    vector<point> ps;
    int i = 0;
    for(int _ = 0;_ < d.size();_++){
        char c = d[_].first;
        long long l = d[_].second;
        i = (i+1)%d.size();
        char a = d[i].first;
        if(c == 'R'){
            if(st){
                if(a == 'U'){
                    st = false;
                    cur.x += l;
                    d[i].second--;
                } else {
                    st = true;
                    cur.x += l+1;
                }
            } else {
                if(a == 'U'){
                    st = true;
                    cur.x += l+1;
                } else {
                    st = false;
                    cur.x += l;
                    d[i].second--;
                }
            }
        } else if(c == 'L'){
            if(st){
                if(a == 'U'){
                    st = true;
                    cur.x -= l;
                    d[i].second--;
                } else {
                    st = false;
                    cur.x -= l+1;
                }
            } else {
                if(a == 'U'){
                    st = false;
                    cur.x -= l+1;
                } else {
                    st = true;
                    cur.x -= l;
                    d[i].second--;
                }
            }
        } else if(c == 'U'){
            if(st){
                if(a == 'R'){
                    st = false;
                    cur.y += l;
                    d[i].second--;
                } else {
                    st = true;
                    cur.y += l+1;
                }
            } else {
                if(a == 'R'){
                    st = true;
                    cur.y += l+1;
                } else {
                    st = false;
                    cur.y += l;
                    d[i].second--;
                }
            }
        } else {
            if(st){
                if(a == 'R'){
                    st = true;
                    cur.y -= l;
                    d[i].second--;
                } else {
                    st = false;
                    cur.y -= l+1;
                }
            } else {
                if(a == 'R'){
                    st = false;
                    cur.y -= l+1;
                } else {
                    st = true;
                    cur.y -= l;
                    d[i].second--;
                }
            }
        }
        ps.push_back(cur);
    }
    long long ans = 0;
    for(int i = 0;i < ps.size();i++){
        ans += ps[i].cross(ps[(i+1)%ps.size()]);
    }
    return ans < 0 ? -ans : ans;
}
void solve() {
    vector<point> p;
    char c;int l;
    vector<pair<char, long long>> d;
    while(cin >> c){
        cin >> l;
        if(!d.empty() && d.back().first == c) d.back().second+=l;
        else d.emplace_back(c, l);
    }
    if(d.size() == 1){
        cout << d.back().second << '\n';
        return;
    }
    if(d.back().first == d.front().first){
        d.front().second += d.back().second;
        d.pop_back();
    }
    if(d.size() == 1){
        cout << d.back().second << '\n';
        return;
    }
    d[0].second--;
    cout << max(que(false, d), que(true, d))/2 << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   solve();
}