/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define rep(i, a, b, r) for(int i = a; i < b; i += r)
#define ll long long

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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n][n];

        rep(i, 0, n, 1){
            rep(j, 0, n, 1){
                cin>>arr[i][j];
            }
        }
        int ans = 0;

        rep(i, 0, n, 1){
            int sup = i;
            int mini = INT_MAX;
            rep(j, 0,n,1){
                mini = min(mini, arr[j][sup]);
                sup++;
            }
            if(mini < 0){
                ans += abs(mini);
            }
        }

        rep(j, 1, n, 1){
            int sup = j;
            int mini = INT_MAX;
            rep(i, 0,n,1){
                mini = min(mini, arr[sup][i]);
                sup++;
            }
            if(mini < 0){
                ans += abs(mini);
            }
        }

        cout<<ans<<endl;

    }

    
    
return 0;
}