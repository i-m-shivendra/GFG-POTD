class Solution {
public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int maxTime = 0;

        for (int i = 0; i < mices.size(); i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }

        return maxTime;
    }
};
