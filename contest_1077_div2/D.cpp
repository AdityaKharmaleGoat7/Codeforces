/*
Author: Aditya Kharmale
*/
#include <bits/stdc++.h>
#define rep(i, a, b, r) for(int i = a; i < b; i += r)
#define ll long long
struct Prev {
    int pbx, pby;
    int pbit, qbit;
    bool ok = false;
};

const ll INF = (1LL<<62);

int gcd(int a, int b){
    while(a > 0){
        int rem = b%a;
        b = a;
        a = rem;        
    }

    return b;
}

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        ll bestCost = INF;
        int bestP = 0, bestQ = 0;

        auto relax = [&](int sx, int sy) {
             ll dp[33][2][2];
            static Prev pre[33][2][2];

            for (int i = 0; i < 33; i++)
                for (int bx = 0; bx < 2; bx++)
                    for (int by = 0; by < 2; by++) {
                        dp[i][bx][by] = INF;
                        pre[i][bx][by] = Prev{};
                    }

            dp[0][0][0] = 0;

            for (int bit = 0; bit <= 31; bit++) {
                int xb = (bit <= 30) ? ((x >> bit) & 1) : 0;
                int yb = (bit <= 30) ? ((y >> bit) & 1) : 0;

                for (int bx = 0; bx < 2; bx++) for (int by = 0; by < 2; by++) {
                    if (dp[bit][bx][by] == INF) continue;

                    for (int pbit : {0,1}) for (int qbit : {0,1}) {
                        if (pbit && qbit) continue;           
                        if (bit == 31 && (pbit || qbit)) continue; 
                         int A1 = (sx == 0) ? xb : pbit;
                        int B1 = (sx == 0) ? pbit : xb;

                        int v1 = A1 - B1 - bx;
                        int out1 = v1 & 1;
                        int nbx = (v1 < 0);

                         int A2 = (sy == 0) ? yb : qbit;
                        int B2 = (sy == 0) ? qbit : yb;

                        int v2 = A2 - B2 - by;
                        int out2 = v2 & 1;
                        int nby = (v2 < 0);

                        ll add = (ll)(out1 + out2) << bit;
                        ll nd = dp[bit][bx][by] + add;

                        if (nd < dp[bit+1][nbx][nby]) {
                            dp[bit+1][nbx][nby] = nd;
                            pre[bit+1][nbx][nby] = {bx, by, pbit, qbit, true};
                        }
                    }
                }
            }

            if (dp[32][0][0] >= bestCost) return; 

            // rebuild p,q
            int p = 0, q = 0;
            int bx = 0, by = 0;
            for (int bit = 31; bit >= 0; bit--) {
                auto st = pre[bit+1][bx][by];
                 if (st.pbit) p |= (1 << bit);
                if (st.qbit) q |= (1 << bit);
                bx = st.pbx;
                by = st.pby;
            }

            bestCost = dp[32][0][0];
            bestP = p; bestQ = q;
        };

         for (int sx = 0; sx <= 1; sx++)
            for (int sy = 0; sy <= 1; sy++)
                relax(sx, sy);

        cout << bestP << " " << bestQ << "\n";
    }
    
    
return 0;
}

/*
<< --> x.2^k
>> --> x/2^k

n | (1<<x) --> setting of the (x+1)th bit in 
*/