class Twitter {
public:
    unordered_map<int,  unordered_set<int>> usertofollowers;
    vector<pair<int, int>> posts;
    Twitter() {
        usertofollowers.clear();
        posts.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int i=posts.size()-1, co = 0;

        while(i>=0 && co<10){
            int uid = posts[i].first, tid = posts[i].second;
            if(uid==userId || usertofollowers[userId].find(uid)!=usertofollowers[userId].end()  ){
                ans.push_back(posts[i].second);
                co++;
            }
            
            i--; 
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        usertofollowers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usertofollowers[followerId].erase(followeeId);
    }
};
