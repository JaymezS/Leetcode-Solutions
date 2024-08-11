#include <bits/stdc++.h>

using namespace std;

int main(){
    class Solution {
    private:
        vector<int> X = {-1,0,1,0};
        vector<int> Y = {0,1,0,-1};
        vector<vector<int>> vis,low;
        int time;
        bool art=false;
        int n,m;
        bool isBoundary(int i,int j,int n,int m){
            return (i>=0 && j>=0 && i<n && j<m);
        }
        void isArti(int i,int j,int pi,int pj,vector<vector<int>> &grid){
            grid[i][j] = 0;
            int child = 0;
            low[i][j] = time;
            vis[i][j] = time;
            time++;

            for(int k=0;k<4; k++){
                int ii= i+X[k];
                int jj= j+Y[k];

                if(!isBoundary(ii,jj,n,m) || 
                  (ii==pi && jj==pj) || 
                  (grid[ii][jj] == 0 && vis[ii][jj] == 0)) continue;

                if(vis[ii][jj] ==  0){
                    child++;
                    isArti(ii,jj,i,j,grid);
                    low[i][j] = min(low[i][j],low[ii][jj]);
                    if(vis[i][j] <= low[ii][jj] && pi != -200 && pj != -200)
                        art = true;
                }else{
                    low[i][j] = min(low[i][j],vis[ii][jj]);
                }
            }
            if(pi == -200 && pj == -200 && child > 1) art = true;
        }
    public:
        int minDays(vector<vector<int>>& grid) {
            bool found = false;
            n= grid.size();
            m=grid[0].size();
            low = vector<vector<int>>(n,vector<int>(m,0));
            vis = vector<vector<int>>(n,vector<int>(m,0));
            time = 1;

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==1){
                        if(found) return 0;
                        found = true;
                        isArti(i,j,-200,-200,grid);
                    }
                }
            }
            if(time == 1) return 0;
            if(time == 2) return 1;

            if(art) return 1;
            else return 2;
        }
    };
  return 0;
}