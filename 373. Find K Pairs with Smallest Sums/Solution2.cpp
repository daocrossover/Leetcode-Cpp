// O(klogk)
#include<vector>
#include<queue>
using namespace std;

class Solution {
typedef vector<int>::iterator it;
struct cmp{
    bool operator()(const pair<it,it>& a,const pair<it,it>& b){
        if(*(a.first) + *(a.second) == *(b.first) + *(b.second)) return *(a.first) > *(b.first);
        return *(a.first) + *(a.second) > *(b.first) + *(b.second);
    }
};
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<it,it>, vector<pair<it,it>>, cmp> q;
        vector<pair<int,int>> res;
        auto it_1 = nums1.begin(),it_2 = nums2.begin();
        if (it_1 == nums1.end() || it_2 == nums2.end()) return res;
        for (;it_1 != nums1.end(); ++it_1) q.push(make_pair(it_1, it_2)); 
        while (!q.empty() && k > 0){
            k--;
            pair<it,it> tmp = q.top();
            q.pop();
            res.push_back(make_pair(*(tmp.first), *(tmp.second)));
            if (++tmp.second == nums2.end()) continue;
            q.push(make_pair(tmp.first, tmp.second));
        }
        return res;
    }
};