#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        
        // Ants moving left: distance to 0
        for(int pos : left) {
            lastMoment = max(lastMoment, pos);
        }
        
        // Ants moving right: distance to n
        for(int pos : right) {
            lastMoment = max(lastMoment, n - pos);
        }
        
        return lastMoment;
    }
};
