#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        int n=INT_MIN;
        for(auto a:arr){
            int i=abs(a-x);
            n=max(i,n);
        }
        vector<vector<int>> temp(n+1);
        for(int i=0;i<arr.size();i++){
            int diff=abs(x-arr[i]);
            temp[diff].push_back(arr[i]);
        }
        int k=0;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                arr[k]=temp[i][j];
                k++;
            }
        }
        
    }
};
