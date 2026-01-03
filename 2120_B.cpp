/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>

using namespace std;
int main(){

int t; cin>>t;

while(t--){

int n, s; cin>>n>>s;

int ans = 0;

while(n--){
    int dx, dy, x, y; cin>>dx>>dy>>x>>y;
    int slope = dy/dx;
    if((slope == -1 && (x + y - s == 0 ))|| (slope == 1 && (y - x == 0 ))) {ans++;}
}

cout<<ans<<endl;   

}

return 0;
}

// Could be a good problem if theta belongs to (0, 360)