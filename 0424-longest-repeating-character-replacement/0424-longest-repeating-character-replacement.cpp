class Solution {
public:
    int characterReplacement(string s, int k) {
      int l = 0;
      unordered_map<char,int> substring;
        int count = 0;
        int maxFreq = 0;
      for(int r = 0;r < s.length(); ++r){
        substring[s[r]]++;
        maxFreq = max(maxFreq, substring[s[r]]);
        if ((r-l + 1) - maxFreq <= k) count = max(count, r - l + 1);
        else {
            substring[s[l]]--;
            l++;
            }
      }  
      return count;
    }
};