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

    
    int t; 
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(n);
        int cnt0 = 0;

        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] == 0) cnt0++;
        }


        vector<int> vis(n + 2, 0);
        for(int i = 0; i < n; i++){
            if(v[i] <= n) vis[v[i]] = 1;
        }

        int mex = 0;
        while(mex <= n + 1 && vis[mex]) mex++;
        

        if(mex == 0){
            cout << "NO\n";
        }
        else if(mex == 1){
            if(cnt0 == 1) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/