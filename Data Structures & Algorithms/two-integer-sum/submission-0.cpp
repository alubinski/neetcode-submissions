#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  // Time: O(n^2)
  // Space: O(1)
  vector<int> bruteForceSolution(vector<int> &nums, int target) {
    for (int i{}; i < nums.size(); ++i) {
      for (int j{i + 1}; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target)
          return {i, j};
      }
    }
    return {};
  }

  // Time: O(nlog(n))
  // Space: O(n)
  vector<int> sortingSolution(vector<int> &nums, int target) {
    vector<pair<int, int>> pairs;
    for (int i{}; i < nums.size(); ++i) {
      pairs.push_back({nums[i], i});
    }

    sort(pairs.begin(), pairs.end());

    int i{0}, j{(int)nums.size() - 1};
    while (i < j) {
      int curr{pairs[i].first + pairs[j].first};
      if (curr == target) {
        return {min(pairs[i].second, pairs[j].second),
                max(pairs[i].second, pairs[j].second)};
      } else if (curr < target) {
        i++;
      } else {
        j--;
      }
    }
    return {};
  }

  // Time: O(n)
  // Space: O(n)
  vector<int> hashMapTwoPass(vector<int> &nums, int target) {
    unordered_map<int, int> indices;
    for (int i{}; i < nums.size(); ++i) {
      indices[nums[i]] = i;
    }

    for (int i{}; i < nums.size(); ++i) {
      int diff{target - nums[i]};
      if (indices.count(diff) && indices[diff] != i) {
        return {i, indices[diff]};
      }
    }
    return {};
  }

  // Time: O(n)
  // Space: O(n)
  vector<int> hashMapOnePass(vector<int> &nums, int target) {
    unordered_map<int, int> prev;

    for (int i{}; i < nums.size(); ++i) {
      int diff{target - nums[i]};
      if (prev.find(diff) != prev.end()) {
        return {prev[diff], i};
      }
      prev.insert({nums[i], i});
    }
    return {};
  }
  vector<int> twoSum(vector<int> &nums, int target) {
    return hashMapOnePass(nums, target);
  }
};
