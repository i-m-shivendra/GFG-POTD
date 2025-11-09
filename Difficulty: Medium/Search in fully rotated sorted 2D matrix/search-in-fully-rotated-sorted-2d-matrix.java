class Solution {
      public boolean searchMatrix(int[][] mat, int x) {
        // code here
        int n = mat.length;
        int m = mat[0].length;
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] > mat[i][m-1]){
                if(linear(mat,i,x,m-1)) return true;
            } 
            else{
                if(x <= mat[i][m-1] && x >= mat[i][0]){
                    if(binary(mat,i,x,m-1)) return true;
                }
            }
        }
        return false;
    }
    private boolean linear(int[][] mat, int row, int key, int ei){
        for(int k : mat[row]) if(k == key) return true;
        
        return false;
    }
    private boolean binary(int[][] mat, int row, int key, int ei){
        int si = 0;
        while(si <= ei){
            int mid = si + (ei-si)/2;
            if(mat[row][mid] == key) return true;
            else if(mat[row][mid] > key) ei = mid-1;
            else si = mid+1;
        }
        return false;
    }
}