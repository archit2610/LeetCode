class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector <vector<int>> bucket(nums.size() + 1);
        for (int num:nums){
            freq[num]++;
        }
        
        for (auto& count:freq ){
            bucket[count.second].push_back(count.first);
        }

        vector<int> res;
        for (int i = bucket.size() - 1;i > 0;--i){
            for(int j : bucket[i]){
                res.push_back(j);
                if(res.size() == k){
                    return res;
                }
            }
        }

        return res;
    }
};