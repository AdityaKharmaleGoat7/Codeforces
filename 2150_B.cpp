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

    

    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/