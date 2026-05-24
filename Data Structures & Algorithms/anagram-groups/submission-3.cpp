#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    return hashTable(strs);
  }

  // Time: O(m*nlog(n))
  // Space: O(m*n)
  vector<vector<string>> sorting(vector<string> &strs) {
    unordered_map<string, vector<string>> anagramMap;
    for (const auto &s : strs) {
      string sortedS{s};
      sort(sortedS.begin(), sortedS.end());
      anagramMap[sortedS].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &pair : anagramMap) {
      result.push_back(pair.second);
    }

    return result;
  }


  vector<vector<string>> hashTable(vector<string> &strs) {
    unordered_map<string, vector<string>> anagramMap;
    for (const auto& s : strs) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string key = to_string(count[0]);
        for (int i{1}; i < count.size(); ++i) {
                key += ',' + to_string(count[i]);
        }
        anagramMap[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &pair : anagramMap) {
      result.push_back(pair.second);
    }
    return result;
  }
};
