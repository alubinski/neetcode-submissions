#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) { return hashTableSolution(s, t); }

  // Time complexity: O(nlog(n) + mlog(m))
  // Space complaxity: O(1) or O(n+m)
  bool sortingSolution(string s, string t) {
    if (s.length() != t.length())
      return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }

  // Time complexity: O(n + m)
  // Space complaxity: O(1), since we have at most 26 characters
  bool hashMapSolution(string s, string t) {
    if (s.length() != t.length())
      return false;

    unordered_map<char, int> countS;
    unordered_map<char, int> countT;

    for (int i{}; i < s.length(); ++i) {
      countS[s[i]]++;
      countT[t[i]]++;
    }
    return countS == countT;
  }

  // Time complexity: O(n + m)
  // Space complaxity: O(1), since we have at most 26 characters
  bool hashTableSolution(string s, string t) {
    if (s.length() != t.length())
      return false;

    vector<int> count(26, 0);

    for (int i{}; i < s.length(); ++i) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }

    for (auto val : count) {
      if (val != 0)
        return false;
    }
    return true;
  }
};
