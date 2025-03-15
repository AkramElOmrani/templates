#include <bits/stdc++.h>
using namespace std;
const int md = 1e9+7;
void solve() {
    int n, d, k;cin >> n >> d >> k;
    if(d == 1){
        while(n--) cout << "0 ";
        cout << '\n';
        return;
    }
    int dp[k+1][n+1];
    for(int i = 0;i <= n;i++) dp[0][i] = i;
    for(int ik = 1;ik <= k;ik++){
        dp[ik][0] = 0;
        for(int i = 1;i <=)
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while(t--) solve();
}