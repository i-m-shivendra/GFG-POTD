class Solution {
   private:
    pair<int,int> getTimeInSeconds(string timeInString) {
        vector<int> currTime;
        stringstream ss(timeInString);
        string token;
        while(getline(ss, token, ':')) {
            currTime.push_back(stoi(token));
        }
        
        int currTimeInSeconds = (currTime[0] * 60 * 60) + (currTime[1] * 60) + currTime[2];
        return {currTimeInSeconds - 86400, currTimeInSeconds};
    }
    
    int getMinTimeDiff(pair<int,int> &a, pair<int,int> &b) {
        return min({
            abs(a.first - b.first),
            abs(a.first - b.second),
            abs(a.second - b.first),
            abs(a.second - b.second)
        });
    }
    
    // maxTimeValue = 86400
  public:
    int minDifference(vector<string> &arr) {
        int n = arr.size();
        vector<pair<int,int>> timesInSeconds;
        for(auto &timeInString: arr) {
            pair<int,int> currTimePair = getTimeInSeconds(timeInString);
            timesInSeconds.push_back(currTimePair);
        }
        
        sort(timesInSeconds.begin(), timesInSeconds.end());
        
        int minTimeDiff = getMinTimeDiff(timesInSeconds[0], timesInSeconds[n-1]);
        for(int i = 0; i < n-1; i++) {
            int currMinTimeDiff = getMinTimeDiff(timesInSeconds[i], timesInSeconds[i+1]);
            minTimeDiff = min(minTimeDiff, currMinTimeDiff);
        }
        
        return minTimeDiff;
    }
};
