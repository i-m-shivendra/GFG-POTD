class Solution {
public:
    int countConsec(int n) {
         if(n < 1) return 0;
        int a = 0, b = 0;
        for(int i = 2; i <= n; i++)
        {
            int c = a + b + (1 << (i - 2));
            a = b;
            b = c;
        }
        return b;
    }
};
