class Solution {
public:
    int characterReplacement(string s, int k) {

        int count[26] = {0};

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            count[s[right] - 'A']++;

            // Highest frequency character in current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If too many replacements are needed
            while ((right - left + 1) - maxFreq > k) {

                count[s[left] - 'A']--;

                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
