#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int final =0;
        int n=mat.size();
        int m=mat[0].size();
        int maxsum=0;
         int actualsum=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                actualsum+=mat[i][j];
                sum+=mat[i][j];
            }
            maxsum=max(maxsum,sum);
        }
        
         for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
            }
            maxsum=max(maxsum,sum);
        }
        
        //than pure Mathematics
        //In beautiful matrix --> Total sum =(no. of row + no. of column)*maxsum
        //It's a square matri,x so no. of rows = the number of columns
        // Equation of beautiful matrix is
        // sum of row of beautiful matrix + sum of column of beautiful matrix=2*no. of row * maxsum
        //Now, the sum of all row elements and all column elements are same
        //so 2 * sum of all row elements = 2* total no. of row * maxsum
        // (Increment + sum of row of Actual matrix)=total no. of row * maxsum
        return (n*maxsum-actualsum);
    }
};
