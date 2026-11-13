class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> mp;

        for(int i = 1; i <= n; i++){
            mp[i] = false;
        }
        for(auto it : nums){
            mp[it] = true;
        }

        for(auto it : mp){
            if(it.second == false){
                return it.first;
            }
        }

        return n+1;
    }
};