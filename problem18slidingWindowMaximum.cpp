class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector <int> maxes;
    set <pair <int, int> > window;
        
    if(nums.empty() || nums.size() < k) {
      return maxes;
    }
        
    for(int i = 0; i != nums.size(); i++) {
      if(window.size() < k) {
	window.insert(make_pair(nums[i],i));
      } else {
	maxes.push_back(window.rbegin()->first);
	window.erase(make_pair(nums[i-k],i-k));
      }
      window.insert(make_pair(nums[i],i));
    }
        
    maxes.push_back(window.rbegin()->first);
        
    return maxes;
  }
};
