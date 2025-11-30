#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3];

    for(int i = 0;i < 3;i++){
        cin>>arr[i];
    }
    sort(arr, arr+3);
    int g,c,l;
    g = arr[0];
    c = arr[1];
    l = arr[2];

    int maxi = max(max(g,c),l);
    int mini = min(min(g,c),l);

    if(maxi-mini>=10){
        cout<<"check again"<<endl;
    }
    else{
        cout<<"final "<<arr[1]<<endl;
    }
     
    return 0;
}