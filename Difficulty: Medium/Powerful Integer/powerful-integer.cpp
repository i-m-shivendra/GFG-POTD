#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int> pq;
        for(int i=intervals.size()-1;i>=0;i--)
        {
            pq.push(intervals[i][0]);
            while(!pq.empty() && pq.top() > intervals[i][1])
                pq.pop();
            if(pq.size() == k)
                return intervals[i][1];
        }
        return -1;
    }
};
