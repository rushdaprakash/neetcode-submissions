class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> output;
        for(int c: nums){
            freq[c]++;
        }
        for (int i=0; i<k; i++){
            int maxfreq=0;
            int maxnum=0;
            for(auto& p: freq){
                if(p.second> maxfreq){
                    maxfreq= p.second;
                    maxnum=p.first;
                }
            }
            output.push_back(maxnum);
            freq.erase(maxnum);
        }
        return output;
    }
};
