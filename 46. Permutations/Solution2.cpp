#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int>> res;
	    permuteRecursive(num, 0, res);
	    return res;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int>& num, int begin, vector<vector<int>>& res)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    res.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, res);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};