/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define ll long long

#define rep(i, a, b, r) for(int i = a; i < b; i += r)

int gcd(int a, int b){

    while(a > 0){
        int rem = b%a;
        b = a;
        a = rem;        
    }

    return b;
}

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 3 == 1, 1, 1 ; 4 = 1, 1, 2 ; 5 = 1. 1. 3, 1, 2, 2   13 = 3 4 6   [13, 24]
    int t; cin>>t;

    while (t--)
    {
    
    int n, k; cin>>n>>k;
    
    vector<int>a(n),mp(n+1),p(n+1);

    rep(i, 0, n, 1) {
        cin>>a[i];
        mp[a[i]]++;
    }

    rep(i, 1, n+1, 1){
        p[i] = p[i-1] + mp[i];
    }
    int ans= 1;
        for(int g = 1; g <= n; g++){
            int idx = min(n, 4 * g - 1);
            int big = n - p[idx];

            int one = mp[g];
            int two = (2 * g <= n) ? mp[2 * g] : 0;
            int three = (3 * g <= n) ? mp[3 * g] : 0;

            if(big + one + two + three >= n - k){
                ans = g;
            }
        }
 

cout<<ans<<"\n";    
    }

return 0;
}

/*
k = 3
14 12 7 12 9 9

12 4 3 1 3 6 9 13

14 12 12 9 9 12 3 3 6 9 13
14 = 3 5 6
13 = 3 4 6

*/