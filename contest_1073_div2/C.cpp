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
        string s;

        cin >> s;

        string tstr = s;
        sort(tstr.begin(), tstr.end());

        if(s == tstr){
            cout << "Bob\n";
            continue;
        }

        vector<int> idx;
        for(int i = 0; i < n; i++){
            if(s[i] != tstr[i]) idx.push_back(i + 1); 
        }

        cout << "Alice\n";
        cout << idx.size() << "\n";
        for(int i = 0; i < (int)idx.size(); i++){
            cout << idx[i] << (i + 1 == (int)idx.size() ? '\n' : ' ');
        }
    }

 
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/