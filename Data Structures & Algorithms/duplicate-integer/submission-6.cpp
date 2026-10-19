class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto it : nums){
            if(st.find(it) != st.end()){
                return true;
            }
            st.insert(it);
        }
        return false;
    }
};