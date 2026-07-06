class Solution {
public:
    bool isPalindrome(string s) {
      s.erase(remove(s.begin(),s.end(),' '),s.end());
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      s.erase(
        remove_if(s.begin(), s.end(),
            [](unsigned char ch) {
                return !(isalnum(ch));
            }),
        s.end()
    );
    string r = s;
    for (int i = 0,j = s.length() - 1;i < s.length() && j >= 0;i++,j--) {
        if (s[i] != r[j]) return false;
    }
    return true;
    }
};