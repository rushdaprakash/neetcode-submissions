class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // 1. Remove elements outside the window
            while (!dq.empty() && dq.front() < left) {
                dq.pop_front();
            }

            // 2. Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(right);

            // 4. If window has size k
            if (right - left + 1 == k) {

                // Front contains maximum
                ans.push_back(nums[dq.front()]);

                // Move window
                left++;
            }
        }

        return ans;
    }
};