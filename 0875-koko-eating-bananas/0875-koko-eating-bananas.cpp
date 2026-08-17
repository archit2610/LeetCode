class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int large = 0;

        for (int i = 0;i < piles.size(); ++i){
            if (large < piles[i])   large = piles[i];
        }

        int low = 1;
        int high = large;
        int k = 0;

        while (low <= high){
          long long int total = 0;
          int mid = low + (high - low)/2;

          for (int i = 0;i < piles.size();++i){
            total += piles[i]/mid;
            if (piles[i]%mid != 0)   total++;
          }

          if (total <= h){
             high = mid - 1;
            k = mid;
          }  

          else low = mid + 1;
        }
        return k;
    }
};