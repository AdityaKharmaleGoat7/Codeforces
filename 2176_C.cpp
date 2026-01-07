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
        int n;
        cin >> n;
        vector<long long> e;
        long long o = -1;
        int oc = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0) e.push_back(x);
            else { o = max(o, x); oc++; }
        }

        sort(e.begin(), e.end(), greater<long long>());
        int ec = (int)e.size();

        vector<long long> p(ec + 1, 0);
        for (int i = 0; i < ec; i++) p[i + 1] = p[i] + e[i];

        for (int k = 1; k <= n; k++) {
            long long ans = 0;

            if (oc == 0) {
                ans = 0;
            } else {
                if (k - 1 <= ec) {
                    ans = o + p[k - 1];
                } else {
                    if ( ((k - 1) & 1) == (ec & 1) ) {
                        ans = o + p[ec];
                    } else {
                        if (ec >= 1 && (k - ec) <= (oc - 1)) {
                            ans = o + p[ec - 1];
                        } else {
                            ans = 0;
                        }
                    }
                }
            }

            cout << ans << (k == n ? '\n' : ' ');
        }
    }
    return 0;
}
