/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define rep(i, a, b, r) for(int i = a; i < b; i += r)
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n; 
        cin >> n;

        vector<int> a(n);
        rep(i, 0, n, 1) cin >> a[i];

        int m = n / 2;  

        auto L = [&](int k, int c)->int{return (c == 0) ? a[k] : a[n - 1 - k];};

        auto R = [&](int k, int c)->int{return (c == 0) ? a[n - 1 - k] : a[k];};

        const int INF = 1e9;
        int dp[2] = {0, 0};

        for(int k = 0; k < m; k++){
            int ndp[2] = {INF, INF};

            for(int pc = 0; pc < 2; pc++){
            for(int cc = 0; cc < 2; cc++){
                int cost = dp[pc];

                if(k > 0){
                    cost += (L(k, cc) == L(k - 1, pc));
                    cost += (R(k, cc) == R(k - 1, pc));
                }

                if(n % 2 == 0 && k == m - 1){
                        cost += (L(k, cc) == R(k, cc));  
                    }

                    ndp[cc] = min(ndp[cc], cost);
                }
            }


            dp[0] = ndp[0];
            dp[1] = ndp[1];
        }

        int ans = min(dp[0], dp[1]);

        if(n % 2 == 1){
            int mid = a[m];
            int best = INF;
            for(int c = 0; c < 2; c++){
                int cost = dp[c];
            if(m > 0){
                cost += (L(m - 1, c) == mid);


                cost += (mid == R(m - 1, c));
            }
            best = min(best, cost);
        }
            ans = best;
        }

        cout << ans << "\n";
    }

    return 0;
}
