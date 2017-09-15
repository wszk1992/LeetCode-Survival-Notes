class Twitter {
public:
    
    Twitter() {
    /** Initialize your data structure here. */    
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back(pair<int, int>(tweetId, time++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> news;
        vector<int> followees = userFollowees[userId];
        followees.push_back(userId);
        for(auto followee : followees) {
            int n = userTweets[followee].size();
            for(int i = 0; i < 10 && i < n; i++) {
                news.push_back(userTweets[followee][n - 1 - i]);
            }
        }
        sort(news.begin(), news.end(), compareTime);
        
        vector<int> res;
        for(int i = 0; i < news.size() && i < 10; i++) {
            res.push_back(news[i].first);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        //check if the follower follows himself/herself
        if(followerId == followeeId) {
            return;
        }
        //check if the follower has already followed the followee
        for(auto followee : userFollowees[followerId]) {
            if(followee == followeeId) {
                return;
            }
        }
        userFollowees[followerId].push_back(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        for(int i = 0; i < userFollowees[followerId].size(); i++) {
            if(userFollowees[followerId][i] == followeeId) {
                userFollowees[followerId].erase(userFollowees[followerId].begin() + i);
                break;
            }
        }
    }
private:
    static bool compareTime(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    // userId -> list{pair(tweetId, time)}
    unordered_map<int, vector<pair<int, int>>> userTweets;
    // userId -> list{followeeID}
    unordered_map<int, vector<int>> userFollowees;
    //time
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */