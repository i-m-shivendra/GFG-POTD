#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> digits(arr.begin(), arr.end());
        
        // Digits NOT in arr[]
        vector<int> notInArr;
        for(int d = 0; d <= 9; d++) {
            if(digits.find(d) == digits.end()) notInArr.push_back(d);
        }
        
        int totalNdigit = 9 * pow(10, n-1); // Total n-digit numbers

        if(notInArr.empty()) return totalNdigit; // All digits are forbidden

        // Count of first digit choices (cannot be 0)
        int firstDigitChoices = 0;
        for(int d : notInArr) {
            if(d != 0) firstDigitChoices++;
        }
        
        int restDigitChoices = notInArr.size();

        long long noArrDigitNumbers = 0;
        if(firstDigitChoices > 0)
            noArrDigitNumbers = firstDigitChoices * pow(restDigitChoices, n-1);
        
        return totalNdigit - noArrDigitNumbers;
    }
};
