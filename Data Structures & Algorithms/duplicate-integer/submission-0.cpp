#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // Time complexity: O(n^2)
  // Space complexity: O(1)
  bool bruteForceSolution(vector<int> &nums) {
    for (int i{}; i < nums.size(); ++i) {
      for (int j{i + 1}; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) {
          return true;
        }
      }
    }
    return false;
  }

  // Time complexity: O(nlog(n))
  // Space complexity: O(1) or O(n) depending on sorting algorithm
  bool sortingSolution(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i{1}; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }

  // Time complexity: O(n)
  // Space complexity: O(n)
  bool hashSetSolution(vector<int> &nums) {
    unordered_set<int> seen;
    for (auto num : nums) {
      if (seen.count(num))
        return true;
      seen.insert(num);
    }
    return false;
  }

  // Time complexity: O(n)
  // Space complexity: O(n)
  bool hashSetLengthSolution(vector<int> &nums) {
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
  }

  bool hasDuplicate(vector<int> &nums) { return hashSetLengthSolution(nums); }
};
