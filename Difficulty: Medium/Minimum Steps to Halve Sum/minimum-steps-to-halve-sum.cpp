class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> q;
        double orgsum = 0;
        for(int i: arr){
            orgsum+=i;
            q.push(1.0*i);
        }
        double sum = orgsum;
        int steps = 0;
        while(sum>orgsum/2){
            double val = q.top();
            q.pop();
            sum-=val;
            sum+=val/2;
            q.push(val/2);
            steps++;
        }
        return steps;
    }
};
