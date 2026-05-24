#include <vector>
using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> products(nums.size(), 1);
    int runningProduct{nums[0]};
    for (int i{1}; i < nums.size(); ++i) {
      products[i] = runningProduct;
      runningProduct *= nums[i];
    }

    int runningProductRight{nums[nums.size()-1]};
    for (int i{(int)nums.size() - 2}; i >= 0; --i) {
        products[i] *= runningProductRight;
        runningProductRight *= nums[i];
    }
    return products;
  }
};
