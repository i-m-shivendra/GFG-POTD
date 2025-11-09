#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        // Standard Kadane's algorithm for non-circular max sum
        int max_kadane = kadane(arr);
        
        // Total sum of array
        int total = 0;
        for(int x : arr) total += x;
        
        // Invert array to find minimum subarray sum
        for(int &x : arr) x = -x;
        int max_inverse = kadane(arr); // this is actually -minSubarraySum
        
        int max_circular = total + max_inverse; // total - minSubarraySum
        
        // Handle all negative case
        if(max_circular == 0) return max_kadane;
        
        return max(max_kadane, max_circular);
    }
    
private:
    int kadane(const vector<int>& arr) {
        int max_ending = arr[0];
        int max_so_far = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            max_ending = max(arr[i], max_ending + arr[i]);
            max_so_far = max(max_so_far, max_ending);
        }
        return max_so_far;
    }
};
