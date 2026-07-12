class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n > m) return "";

        vector<int> freq(128,0),window(128,0);

        for (char ch: t)    freq[ch]++;
        int req = 0;
        for (int x: freq)    if (x > 0)  req++;

        int l = 0,have = 0,min_length = INT_MAX,start = 0;
        for(int r = 0;r < s.size();r++){
            char c = s[r];
            window[c]++;
            if (freq[c] > 0 && freq[c] == window[c])   have++;
            while (have == req) {
                if (r - l + 1 < min_length){
                    min_length = r - l + 1;
                    start = l;
                }

                char left = s[l];
                window[left]--;

                if (freq[left] > 0 && window[left] < freq[left])    have--;

                l++;

            }
        }
        return min_length == INT_MAX ? "" : s.substr(start, min_length);
    }
};