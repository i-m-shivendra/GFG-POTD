class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        for(int i=0;i<mat.size();i++){
            bool can=true;
            for(int j=0;j<mat[0].size();j++){
                if(i==j)continue;
                if(mat[i][j]==1)can=false;
            }
            if(can==false )continue;
            for(int k=0;k<mat.size();k++){
                if(i==k)continue;
                if(mat[k][i]==0)can=false;
            }
            if(can)return i;
        }
        return -1;
    }
};