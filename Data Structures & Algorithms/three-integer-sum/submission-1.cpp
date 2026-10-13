class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            set<int> hashset;
            for(int j = i + 1; j < n; j++){
                int value = -(nums[i] + nums[j]);
                if(hashset.find(value) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], value};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};
