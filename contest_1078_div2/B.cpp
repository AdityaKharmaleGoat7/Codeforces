/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b){
    while(a > 0){
        int rem = b%a;
        b = a;
        a = rem;        
    }

    return b;
}

using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int n,x,y; cin>>n>>x>>y;
        vector<int> arr(n);
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        int s = 0;

        for(auto i:arr){
            s += i/x;
        }
        int ans = LLONG_MIN;
        
        for(auto i:arr){
            ans = max(ans, i+y*(s-i/x));
        }

        cout<<ans<<"\n";
    }

    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/