class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> set;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            // If duplicate exists, shrink window
            while (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }

            // Add current character
            set.insert(s[right]);

            // Update answer
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};