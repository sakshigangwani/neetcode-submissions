class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        for(auto it : mp){
            int number = it.first;
            int count = it.second;
            bucket[count].push_back(number);
        }

        vector<int> result;

        for(int i = n; i >= 0 && result.size() < k; i--){
            for(auto it : bucket[i]){
                result.push_back(it);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};
