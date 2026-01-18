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

        vector<pair<int,int>> v;
        v.reserve(n);

        for(int i = 0; i < n; i++){
            int a; 
            cin >> a;
            v.push_back({a, i});
        }

        if(n <= 1){
            cout << "YES\n";
            continue;
        }

        sort(v.begin(), v.end());

        bool flag = true;
        int s = v[0].second % 2;

        for(int i = 1; i < n; i++){
            if(v[i].second % 2 == s){
                flag = false;
                break;
            }
            s = v[i].second % 2;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/