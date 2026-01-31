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
        int n;
        string s;
        cin>>n>>s;

        vector<int> ans(n, 0);

        int res = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '1') {
                ans[i] = 1;
            // res += 1; 
        }
        }

        int a =0;

        for(int i = 0;i < n;i++){
            if(ans[i] == 1) continue;
             bool left  = (i > 0 && ans[i-1]);
            bool right = (i+1 < n && ans[i+1]);
             if(!left && !right){
                 if(i+1 < n && !ans[i+1] && (i+2 >= n || !ans[i+2])){
                    ans[i+1] = 1;
                    // a++;

                } 
                else {
                    ans[i] = 1;
                    // a++;
                }
            }           

    }

    for(auto i:ans){
        res += i;
    }
    cout<<res<<endl;
    
}
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/