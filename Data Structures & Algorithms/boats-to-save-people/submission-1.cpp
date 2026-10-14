class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int start = 0;
        int end = n - 1;
        int boats = 0;
        sort(people.begin(), people.end());
        while(start <= end){
            int sum = people[start] + people[end];
            if(sum <= limit){
                start++;
            }
            end--;
            boats++;
        }
        return boats;
    }
};