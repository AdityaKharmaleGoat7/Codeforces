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
        vector<ll> arr(n), b;
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        b = arr;

        sort(b.begin(), b.end());

        if(b == arr){ 
        cout<<-1<<endl;
        continue;
        }

        ll mini = LLONG_MAX, maxi = LLONG_MIN;

        for(auto i:arr){
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
        
        ll ans = LLONG_MAX;

        for(int i = 0;i < n;i++){
            if(arr[i] != b[i]){
                ll cur = max(arr[i]-mini, maxi - arr[i]);
                ans = min(ans, cur);
            }
        }
        
        cout<<ans<<endl;




    }
    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/