#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class solution {
  public:
    vector<vector<string>> groupanagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> map;

      vector<vector<string>> ans;

      for (int i = 0; i < strs.size(); i++) {
        string key = strs[i];
        sort(key.begin(), key.end());
        map[key].push_back(strs[i]);
      }

      for (auto& pair : map) {
        ans.push_back(pair.second);
      }

      return ans;
    }
};

