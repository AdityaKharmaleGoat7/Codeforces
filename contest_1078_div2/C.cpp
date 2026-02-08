/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b){
    while(a > 0){
        int rem = b % a;
        b = a;
        a = rem;
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;

         vector<int> avail(n, 0);

        for (int row = 0; row < k; row++) {
            string s; 
            cin>>s;
            for (int i = 0; i < n; i++) {
                avail[i] |= (1u<<(s[i] - 'a'));
            }
        }

         vector<int> divs;
        for (int d = 1; (long long)d*d <= n; d++) {
            if (n % d == 0) {
                divs.push_back(d);
                if (d != n/d) divs.push_back(n/d);
            }
        }
        sort(divs.begin(), divs.end());

        string ans;

      const int al = (1<<26) - 1;

        for (auto d:divs) {
             vector<int> inter(d, al);

            for (int i = 0; i < n; i++) {
                inter[i % d] &= avail[i];
            }

            bool flag = true;
            for (int r = 0; r < d; r++) {
                if (inter[r] == 0) { flag = false; break; }
            }
            if (!flag) continue;
 
            string base(d, 'a');
            for (int r = 0; r < d; r++) {
                int bit = __builtin_ctz(inter[r]); 
                base[r] = char('a' + bit);
            }
 
            ans.resize(n);
            for (int i = 0; i < n; i++) {
                ans[i] = base[i % d];
            }
            break;  
        }

        cout << ans << "\n";
    }

    return 0;
}

/*
<< --> x * 2^k
>> --> x / 2^k

n | (1<<x) --> setting of the (x+1)th bit in
*/
