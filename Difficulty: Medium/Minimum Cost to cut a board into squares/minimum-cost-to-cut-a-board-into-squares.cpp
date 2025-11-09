class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort both in descending order
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int horizontalPieces = 1, verticalPieces = 1;
        long long cost = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) {
                cost += (long long)x[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                cost += (long long)y[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        // remaining horizontal cuts
        while (i < x.size()) {
            cost += (long long)x[i] * verticalPieces;
            i++;
        }

        // remaining vertical cuts
        while (j < y.size()) {
            cost += (long long)y[j] * horizontalPieces;
            j++;
        }

        return (int)cost;
    }
};
