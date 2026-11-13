class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto it : nums){
            st.insert(it);
        }

        int longest = 0;

        for(auto num : st){
            if(st.find(num - 1) == st.end()){
                int current = num;
                int length = 1;
                while(st.find(current + 1) != st.end()){
                    current = current + 1;
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
