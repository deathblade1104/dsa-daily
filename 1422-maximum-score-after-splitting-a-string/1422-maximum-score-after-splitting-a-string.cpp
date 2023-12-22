class Solution {
public:
    int maxScore(string s) {
         int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};