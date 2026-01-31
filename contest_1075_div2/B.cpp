/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
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
        int n, x; cin>>n>>x;

        int a[n], b[n], c[n];

        for(int i = 0;i < n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }

        
            
    }


    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/