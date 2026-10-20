class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> st;

        for(auto num : nums){
            st.insert(num);
        }

        for(auto num : st){
            if(st.find(num-1) == st.end()){
                int current = num;
                int length = 1;
                while(st.find(current+1) != st.end()){
                    current++;
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
