/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>

using namespace std;

bool canMakeZero(int* arr, int idx, int n, int sum) {
    if (idx == n) return sum == 0;

    return canMakeZero(arr, idx + 1, n, sum + arr[idx]) ||
           canMakeZero(arr, idx + 1, n, sum - arr[idx]);
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
    int n;
    cin >> n;

    long long px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    // hypot returns the euclidean distance
    long double d = hypot((long double)(px - qx), (long double)(py - qy));

    long double L = 0.0L, R = 0.0L;

    for (int i = 0; i < n; i++) {
        long double a;
        cin >> a;      
        L = max({0.0L, L - a, a - R});
        R = R + a;
    }

    const long double EPS = 1e-12L;
    if (d + EPS >= L && d <= R + EPS) cout << "Yes\n";
    else cout << "No\n";
    }


return 0;
}