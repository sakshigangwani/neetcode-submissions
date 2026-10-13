class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int longest = 0;
        for(auto num : nums){
            st.insert(num);
        }

        for(auto num : st){
            if(st.find(num - 1) == st.end()){
                int current = num;
                int count = 1;
                while(st.find(current + 1) != st.end()){
                    current++;
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};
