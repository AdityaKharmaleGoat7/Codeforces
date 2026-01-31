/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
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

        vector<vector<int>> arr(2, vector<int>(n));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        vector<int> mini1(n), maxi1(n), mini2(n), maxi2(n);

        int m = INT_MAX, M = INT_MIN;
        for(int i = 0; i < n; i++){
            m = min(m, arr[0][i]);
            M = max(M, arr[0][i]);
            mini1[i] = m;
            maxi1[i] = M;
        }

        m = INT_MAX; 
        M = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            m = min(m, arr[1][i]);
            M = max(M, arr[1][i]);
            mini2[i] = m;
            maxi2[i] = M;
        }

        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({
                min(mini1[i], mini2[i]),
                max(maxi1[i], maxi2[i])
            });
        }

        vector<int> ans(2*n + 2, INT_MAX);

        for(auto &p : vp){
            ans[p.first] = min(ans[p.first], p.second);
        }

        int cur = INT_MAX;
        for(int i = 2*n; i >= 1; i--){
            if(ans[i] != INT_MAX) cur = min(cur, ans[i]);
            ans[i] = cur;
        }

        ll res = 0;
        for(int i = 1; i <= 2*n; i++){
            if(ans[i] != INT_MAX){
                res += (2*n - ans[i] + 1);
            }
        }

        cout << res << '\n';
    }

    return 0;
}


/*
<< --> x.2^k
>> --> x/2^k
n | (1<<x) --> setting of the (x+1)th bit in 
*/