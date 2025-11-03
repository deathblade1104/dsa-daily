class Twitter {
public:    
    struct mycomp
    {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            return a.second>b.second;
        }
    };

    int timer;
    unordered_map<int,unordered_set<int>>followdir;
    unordered_map<int,vector<pair<int,int>>>tweetdir;
    
    Twitter(){
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweetdir[userId].push_back({tweetId,timer++});
    }
    
    vector<int> getNewsFeed(int userId) {        
        followdir[userId].insert(userId);
        
        vector<int>ans;  
        priority_queue<pair<int,int>, vector<pair<int,int>> , mycomp>pq;
        
        
        for(auto&itr : followdir[userId])
        {
            int uid = itr,sz = tweetdir[uid].size();
            
            if(sz>10)
                sz=10;
            
            for(int i = tweetdir[uid].size()-1; i>=0 and sz>0; i--)
            {
                pq.push(tweetdir[uid][i]);
                sz--;
                
                if(pq.size()>10)
                    pq.pop();
            }
        }
    
        while(pq.size()>0)
        {
            
            auto p = pq.top();
            pq.pop();
            
            ans.push_back(p.first);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
     
    void follow(int followerId, int followeeId) {
        followdir[followerId].insert(followeeId);
    }
    
    
    void unfollow(int followerId, int followeeId) {
        
        if(followdir[followerId].count(followeeId)==1)
            followdir[followerId].erase(followeeId);    
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