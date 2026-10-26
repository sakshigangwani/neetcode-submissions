class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);
        for(auto it : mp){
            int number = it.first;
            int counter = it.second;
            bucket[counter].push_back(number);
        }

        vector<int> ans;
        for(int i = n; i>=0 && ans.size() < k; i--){
            for(auto ptr : bucket[i]){
                ans.push_back(ptr);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};
