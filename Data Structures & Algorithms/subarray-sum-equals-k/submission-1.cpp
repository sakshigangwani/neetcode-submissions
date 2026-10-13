class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(prefixSum[i] == k){
                count++;
            }

            int value = prefixSum[i] - k;

            if(mp.find(value) != mp.end()){
                count += mp[value];
            }

            if(mp.find(prefixSum[i]) == mp.end()){
                mp[prefixSum[i]] = 0;
            }
            mp[prefixSum[i]]++;
        }
        return count;
    }
};