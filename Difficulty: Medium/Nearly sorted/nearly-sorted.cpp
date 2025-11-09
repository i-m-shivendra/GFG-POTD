class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = arr.size();
        int index = 0;

        // Insert first k+1 elements
        for(int i = 0; i < min(k+1, n); i++)
            pq.push(arr[i]);

        // Process the remaining elements
        for(int i = k+1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }

        // Extract remaining elements
        while(!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};
