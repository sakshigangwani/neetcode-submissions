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

        vector<int> ans;
        for(int i = n; i >= 0 && ans.size() < k; i--){
            for(auto p : bucket[i]){
                ans.push_back(p);
                if(ans.size() == k) break;
            }
        }

        return ans;
    }
};
