class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);
        for(auto p : mp){
            int number = p.first;
            int count = p.second;
            bucket[count].push_back(number);
        }

        vector<int> ans;
        for(int i = n; i >= 0 && ans.size() < k; i--){
            for(auto a : bucket[i]){
                ans.push_back(a);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};
