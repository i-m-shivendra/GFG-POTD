class Solution {
public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int,int> freq;
        for(int x : arr) freq[x]++;

        // max-heap: {frequency, value}
        priority_queue<pair<int,int>> pq;

        for(auto &p : freq) {
            pq.push({p.second, p.first});
        }

        vector<int> ans;

        while(k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
