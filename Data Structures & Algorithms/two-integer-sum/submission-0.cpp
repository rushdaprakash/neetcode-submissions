class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hm;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            hm[nums[i]]=i;
        } 
        for(int i=0; i< nums.size(); i++){
            int left= target- nums[i];
            if(hm.contains(left) && hm[left] != i) return {i, hm[left]};
        }
        return {};
    }
};
