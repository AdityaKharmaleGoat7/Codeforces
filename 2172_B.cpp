/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>

using namespace std;
//      0-3     4-5        6-10
//  (       )   ( ) (                 )
//      p1            p2      p3
// 0 --------------------------------- 10

/*
Constraint 
1≤n≤2×10e5
1≤m≤2×10e5
1≤ℓ≤10e9
1≤y<x≤10e6
0≤si<ti≤ℓ
0≤pi≤ℓ
*/

int main(){
    
    int n, m, l, x, y; cin>>n>>m>>l>>x>>y;
    
    // n == # of buses, m == # of people, l == total distance, x == bus speed, y == hoooman speed
    // y > x can be --> Can he catch multiple buses if so --> NOT TRUE
    // at max one bus --> speed of every bus is same


    vector<pair<int,int>> st;
    vector<int> p;
    int n1 = n, m1 = m;
    while(n1--){
        int a, b; cin>>a>>b;
        st.push_back({a,b});
    }
    while(m1--){
        int a; cin>>a;
        p.push_back(a);
    }

    sort(st.begin(), st.end());
    // sort(p.begin(), p.end());

    vector<float> res;

for(int i = 0;i < m; i++){
    float r = float(l - p[i])/float(y);   

    for(int j = 0; j < n; j++){
        if(p[i] < st[j].first)     
            break;
        
        if(p[i] >= st[j].second){
            continue;
        }

        float val = float(st[j].second - st[j].first) / float(x);
        r = min(r, val + float(l-st[j].second)/float(y));  
    }

    res.push_back(r);       
}

int o = 0;
while(m--){
    cout<<res[o]<<" ";
    o++;
}

cout<<endl;


    return 0;
}
