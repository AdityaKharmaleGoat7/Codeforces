/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> deg(n, 0);
        vector<pair<int,int>> edges;
        edges.reserve(m);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            deg[x]++; deg[y]++;
            edges.push_back({x, y});
        }

        if (m % 2 == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;

         for (int i = 0; i < n; i++) {
            if (deg[i] % 2 == 1) {
                ans = min(ans, a[i]);
            }
        }

 
        for (auto [u, v] : edges) {
            if (deg[u] % 2 == 0 && deg[v] % 2 == 0) {
                ans = min(ans, a[u] + a[v]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
