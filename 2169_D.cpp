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

bool rem(int z, int x, int y, int k){

    while(x--){
        z = z-z/y;
    }

    return (z>=k);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int x, y, k; cin>>x>>y>>k;


        int l = 1, r = 10e12, ans = 10e12;

        if(!rem(r, x, y, k)) cout<<-1<<endl;

        else{

        while(l <= r){
            int mid = l + (r-l)/2;

            if(rem(mid, x, y, k)){
                ans = min(mid, ans);
                r = mid-1;
            }
            else l = mid+1;

        }

        cout << (ans > 1000000000000 ? -1 : ans) << "\n";
        
        }

    }
    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/