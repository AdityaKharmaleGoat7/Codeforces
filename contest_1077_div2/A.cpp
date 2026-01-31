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

     vector<int> ans;

     int l =1, r = n;
     for(int i=0;i < n;i++){
        if(i%2 ==0){
            ans.push_back(l++);
        }
        else{
            ans.push_back(r--);
        }
     }

    
     reverse(ans.begin(), ans.end());

     for(auto i:ans){
        cout<<i<<" ";
     }
     cout<<endl;
    }
    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/