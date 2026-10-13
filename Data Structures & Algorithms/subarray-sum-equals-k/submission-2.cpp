class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        int count = 0;
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        unordered_map<int,int> mp;
        for(int j = 0; j < n; j++){
            if(prefixSum[j] == k){
                count++;
            }

            int value = prefixSum[j] - k;

            if(mp.find(value) != mp.end()){
                count += mp[value];
            }

            if(mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]] = 0;
            }
            mp[prefixSum[j]]++;
        }

        return count;
    }
};