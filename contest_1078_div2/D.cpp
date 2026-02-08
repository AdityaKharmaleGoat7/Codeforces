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

struct Parent {
    int pi, pj;       
    int pst;         
    char mv;        
    Parent(int _pi=-1,int _pj=-1,int _pst=-1,char _mv='?'):pi(_pi),pj(_pj),pst(_pst),mv(_mv){}
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

         vector<vector<int>> a(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }

         vector<vector<int>> colPref(n+1, vector<int>(m+1, 0));
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                colPref[i][j] = colPref[i-1][j] + a[i][j];
            }
        }

        int totalOnes = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                totalOnes += a[i][j];
            }
        }

        int target = totalOnes / 2;

         const int NEG = -(1LL<<60);
        const int INF = (1LL<<60);

        int H = n + 1, W = m + 1;

        vector<vector<int>> lo(H, vector<int>(W, NEG));  
        vector<vector<int>> hi(H, vector<int>(W, INF));  

        vector<vector<Parent>> parLo(H, vector<Parent>(W));
        vector<vector<Parent>> parHi(H, vector<Parent>(W));

        lo[0][0] = 0; 
        auto relax = [&](int ni, int nj, int newVal, int pi, int pj, int pst, char mv){
             if(newVal <= target && newVal > lo[ni][nj]){
                lo[ni][nj] = newVal;
                parLo[ni][nj] = Parent(pi, pj, pst, mv);
            }
             if(newVal >= target && newVal < hi[ni][nj]){
                hi[ni][nj] = newVal;
                parHi[ni][nj] = Parent(pi, pj, pst, mv);
            }
        };

         for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){

                 if(lo[i][j] != NEG){
                     if(j < m){
                        int gain = colPref[i][j+1];
                        relax(i, j+1, lo[i][j] + gain, i, j, 0, 'R');
                    }
                     if(i < n){
                        relax(i+1, j, lo[i][j], i, j, 0, 'D');
                    }
                }

                 if(hi[i][j] != INF){
                    if(j < m){
                        int gain = colPref[i][j+1];
                        relax(i, j+1, hi[i][j] + gain, i, j, 1, 'R');
                    }
                    if(i < n){
                        relax(i+1, j, hi[i][j], i, j, 1, 'D');
                    }
                }
            }
        }

         auto score = [&](int aOnes){
            return aOnes * (totalOnes - aOnes);
        };

        int bestState = -1;  
        int bestA = -1;
        long long bestScore = -1;

        if(lo[n][m] != NEG){
            bestA = lo[n][m];
            bestScore = score(bestA);
            bestState = 0;
        }
        if(hi[n][m] != INF){
            long long sc = score(hi[n][m]);
            if(sc > bestScore){
                bestScore = sc;
                bestA = hi[n][m];
                bestState = 1;
            }
        }

         string path;
        int ci = n, cj = m, cs = bestState;
        while(!(ci == 0 && cj == 0)){
            Parent p = (cs == 0 ? parLo[ci][cj] : parHi[ci][cj]);
            path.push_back(p.mv);
            ci = p.pi;
            cj = p.pj;
            cs = p.pst;
        }
        reverse(path.begin(), path.end());

        cout << bestScore << "\n";
        cout << path << "\n";
    }

    return 0;
}
