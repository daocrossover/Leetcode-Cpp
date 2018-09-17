// Description:
// Design a simplified version of Twitter where users can post tweets,
// follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed.
// Your design should support the following methods:

// 1. postTweet(userId, tweetId): Compose a new tweet.
// 2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed.
// Each item in the news feed must be posted by users who the user followed or by the user herself.
// Tweets must be ordered from most recent to least recent.
// 3. follow(followerId, followeeId): Follower follows a followee.
// 4. unfollow(followerId, followeeId): Follower unfollows a followee.

// Example:
// Twitter twitter = new Twitter();
// User 1 posts a new tweet (id = 5).
// twitter.postTweet(1, 5);
// User 1's news feed should return a list with 1 tweet id -> [5].
// twitter.getNewsFeed(1);
// User 1 follows user 2.
// twitter.follow(1, 2);
// User 2 posts a new tweet (id = 6).
// twitter.postTweet(2, 6);
// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.getNewsFeed(1);
// User 1 unfollows user 2.
// twitter.unfollow(1, 2);
// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
// twitter.getNewsFeed(1);

#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

class Twitter {
    int order;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        order = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(order, tweetId));
        order--;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<pair<int, int>> newsFeed = tweets[userId];
        for (auto v : following[userId]) {
            newsFeed.insert(newsFeed.end(),tweets[v].begin(),tweets[v].end());
        }
        sort(newsFeed.begin(), newsFeed.end());
        int count = 0;
        vector<pair<int, int>>::iterator it;
        for (it = newsFeed.begin(); it != newsFeed.end(); ++it) {
            if (count == 10) break;
            res.push_back(it->second);
            count++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
         following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */