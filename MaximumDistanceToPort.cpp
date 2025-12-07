/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>

using namespace std;
int main(){
int n, m, k; cin>>n>>m>>k;


// K --> total product type
vector<int> output(k, 0);
vector<int> an;

while(n--){
    int a; cin>>a;
    an.push_back(a);
}
unordered_map<int, vector<int>> mp;

while(m--){
    int a, b; cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
}

unordered_map<int, bool> visited;

visited[1] = true;
queue<int> q;
q.push(1);

unordered_map<int,int> dist;
dist[1] = 0;


while(!q.empty()){
    int node = q.front();
    q.pop();
    
    for(auto i:mp[node]){
        if(!visited[i]){
            dist[i] = dist[node] + 1;
            q.push(i);
            visited[i] = true;
        }
    }

}

for(int city = 1; city <= an.size(); city++){
    int product = an[city-1];
    output[product-1] = max(output[product-1], dist[city]);
}


for(auto i:output){
    cout<<i<<" ";
}
cout<<endl;


return 0;
}