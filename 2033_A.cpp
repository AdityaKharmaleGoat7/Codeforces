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
    if(n%2 == 0){
        cout<<"Sakurako"<<endl;
    }
    else{
        cout<<"Kosuke"<<endl;

    }
}
    
    
return 0;
}