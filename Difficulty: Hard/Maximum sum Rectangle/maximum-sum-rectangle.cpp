class Solution {
public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Fix the left boundary of the rectangle
        for (int left = 0; left < m; left++) {
            // Temporary array to store row sums between left and right columns
            vector<int> temp(n, 0);

            // Fix the right boundary of the rectangle
            for (int right = left; right < m; right++) {
                // Add current column to temp array
                for (int i = 0; i < n; i++) {
                    temp[i] += mat[i][right];
                }

                // Find the maximum sum subarray in temp using Kadane's algorithm
                int sum = kadane(temp);
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

private:
    int kadane(vector<int> &arr) {
        int maxSoFar = arr[0];
        int maxEndingHere = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
