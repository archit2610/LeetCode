class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        return false;

        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        for(int i = 0;i < s.length(); ++i){
            maps[s[i]]++;
            mapt[t[i]]++;
        }
        return maps == mapt;
    }
};