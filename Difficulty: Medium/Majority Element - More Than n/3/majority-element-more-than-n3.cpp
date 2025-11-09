#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        int mini = int(n/3)+1;
        
        vector<int>v;
        
        int cnt1 = 0 , cnt2 = 0 , el1 = INT_MIN, el2 = INT_MIN;
        
        for(int i=0; i<n ; i++){
            if(cnt1==0 && el2!=arr[i]){
                cnt1++;
                el1= arr[i];
            }
            
            else if(cnt2==0 && el1!=arr[i]){
                cnt2++;
                el2= arr[i];
                
            }
            
            else if(arr[i]==el1){
                cnt1++;
            }
            
            else if(arr[i]==el2){
                cnt2++;
            }
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0,cnt2=0;
        
        for( int i=0; i<n ;i++){
            if(arr[i]==el1) cnt1++;
            if(arr[i]==el2) cnt2++;
        }
        
        if(cnt1>=mini){
            v.push_back(el1);
        }
        
        if(cnt2>=mini){
            v.push_back(el2);
        }
        
        sort(v.begin(),v.end());
        
        
        return v;
    }
};
