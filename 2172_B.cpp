/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>

using namespace std;
//   
//      0-3     4-5        6-10
//  (       )   ( ) (                 )
//      p1            p2      p3
// 0 --------------------------------- 10

int main(){
    
    int n, m, l, x, y; cin>>n>>m>>l>>x>>y;
    
    vector<pair<int,int>> st;
    vector<int> p;

    while(n--){
        int a, b; cin>>a>>b;
        st.push_back({a,b});
    }
    while(m--){
        int a; cin>>a;
        p.push_back(a);
    }


    return 0;
}
