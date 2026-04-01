class Twitter {
public:
    Twitter() {
        
    }
    vector<pair<int,pair<int,int>>> tweets;
    int k=1;
    map<pair<int,int>,int> m; //follower, followee

    void postTweet(int userId, int tweetId) {
        tweets.push_back({k,{userId,tweetId}});
        k++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        for(int i=tweets.size()-1; i>=0 && v.size()<10; i--){
            int user=tweets[i].second.first;
            if(user==userId || m[{userId,user}]>0){
                v.push_back(tweets[i].second.second);
            }
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        m[{followerId,followeeId}]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(m[{followerId,followeeId}]>0){
            m[{followerId,followeeId}]--;
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */