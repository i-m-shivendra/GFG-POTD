#include <vector>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check first row
        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 0) firstRowZero = true;
        }
        
        // Check first column
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 0) firstColZero = true;
        }
        
        // Use first row and column as markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        // Set cells to zero using markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        // Update first row
        if(firstRowZero) {
            for(int j = 0; j < m; j++) mat[0][j] = 0;
        }
        
        // Update first column
        if(firstColZero) {
            for(int i = 0; i < n; i++) mat[i][0] = 0;
        }
    }
};
