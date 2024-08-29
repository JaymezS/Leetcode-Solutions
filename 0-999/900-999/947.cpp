#include <bits/stdc++.h>


using namespace std;


int main() {




class FalseSolution {
public:
  int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    int c = 0;

    for (auto& stone: stones) {
      if (x.count(stone[0])) {
        x[stone[0]]++;
      } else {
        x[stone[0]] = 1;
      }

      if (y.count(stone[1])) {
        y[stone[1]]++;
      } else {
        y[stone[1]] = 1;
      }
    } 


    for (auto& stone: stones) {
      if (x[stone[0]] - 1 > 0 || y[stone[1]] - 1 > 0) {
        x[stone[0]]--;
        y[stone[1]]--;
        c++;
      }
    }  
    return c;
  }
};



class Disjoint{
    public:
    vector<int>size,parent;
    Disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    
    int findpar(int x){
        if(x==parent[x]) return x;
        return parent[x]=findpar(parent[x]);
    }

    void unionBySize(int u,int v){
        int up=findpar(u);
        int vp=findpar(v);

        if(up==vp) return;
        if(size[up]<size[vp]){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
    }
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int max_row=0;
        int max_col=0;

        for(auto it : stones){
            max_row=max(max_row,it[0]);
            max_col=max(max_col,it[1]);
        }

        Disjoint ds(max_row+max_col+1);

        unordered_map<int,int>mpp;

        for(auto it: stones){
            int nrow=it[0];
            int ncol=it[1]+max_row+1;

            ds.unionBySize(nrow,ncol);
            mpp[nrow]=1;
            mpp[ncol]=1;
        }

        int cnt=0;
        for(auto it : mpp){
            if(ds.findpar(it.first)==it.first)  {
                cnt++;
            }
        }


        return n-cnt;

    }
};



  return 0;
}