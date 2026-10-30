class Twitter {
public:
    int timer = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].push_back({timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        following[userId].insert(userId);

        for(auto user : following[userId]){
            if(tweets[user].empty()) continue;
            int index = tweets[user].size() - 1;
            auto [time, tweetId] = tweets[user][index];
            maxHeap.push({time, {user, index}});
        }

        vector<int> ans;
        while(!maxHeap.empty() && ans.size() < 10){
            auto top = maxHeap.top();
            maxHeap.pop();

            int time = top.first;
            int user = top.second.first;
            int index = top.second.second;

            ans.push_back(tweets[user][index].second);

            if(index > 0){
                int newIndex = index - 1;
                auto [time, tweetId] = tweets[user][newIndex];
                maxHeap.push({time, {user, newIndex}});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return;
        }
        following[followerId].erase(followeeId);
    }
};
