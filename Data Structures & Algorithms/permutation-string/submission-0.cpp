class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Count characters in s1
        for (char c : s1) {
            need[c]++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {

            // Add current character
            window[s2[right]]++;

            // Keep window size equal to s1
            if (right - left + 1 > s1.size()) {
                window[s2[left]]--;

                if (window[s2[left]] == 0) {
                    window.erase(s2[left]);
                }

                left++;
            }

            // Check if current window is a permutation
            if (window == need) {
                return true;
            }
        }

        return false;
    }
};
