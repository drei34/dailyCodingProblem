class Solution {
public:
  void sortColors(vector<int>& nums) {
    int r = 0;
    int w = 0;
    int b = 0;
        
    for(int i = 0; i != nums.size(); i++) {
      if(nums[i] == 2) {
	b++;
      } else if(nums[i] == 1) {
	nums[b++] = 2;
	nums[w++] = 1;
      } else {
	nums[b++] = 2;
	nums[w++] = 1;
	nums[r++] = 0;
      }
    }
        
  }
};
