/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--){
        ll n; cin>>n;
        ll arr[n];
        ll m = INT_MIN;

        for(int i = 0;i < n;i++){
            cin>>arr[i];
            m = max(m, arr[i]);
        }   

        ll sum = 0;

        for(int i = 0; i < n - 1; i++){
            sum += max(arr[i], arr[i + 1]);
        }

        sum += max(arr[n - 1], arr[0]);
        sum -= m;

        cout << sum << '\n';

    }

return 0;
}