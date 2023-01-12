class Twitter {
public:
        // Initialize your data structure here
    unordered_map<int,unordered_set<int>>mp;
    unordered_map<int,list<array<int,2>>>posts;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
    int timer;
    
    Twitter() {
        
        timer = 0;
        
        mp.clear();
        
        posts.clear();
        
        while(pq.size())
            pq.pop();
        
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timer++,tweetId});
        
        while(posts[userId].size()>10)
            posts[userId].pop_front();
            
        return;
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        
        mp[userId].insert(userId);
        
        for(auto&user : mp[userId]){
            for(array<int,2>&currPost : posts[user]){
                pq.push(currPost);
                
                if(pq.size()>10)
                    pq.pop();
            }
        }
        
        while(pq.size()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
        
        mp[followerId].insert(followeeId);
        
        return;
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId) {
        if(mp[followerId].count(followeeId) ==1){
            mp[followerId].erase(followeeId);
        }
        
        return;
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