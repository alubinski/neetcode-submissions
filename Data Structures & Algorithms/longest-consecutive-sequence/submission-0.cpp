class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int res{0};
    std::unordered_set<int> store(nums.begin(), nums.end());

    for (auto num : nums) {
      int streak{0}, curr = num;
      while (store.find(curr) != store.end()) {
        streak++;
        curr++;
      }
      res = max(res, streak);
    }
    return res;
  }
};
