class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int r = n - 1,l = 0;
        int area = 0;
        while(l < r){
            int res = (r-l)*min(height[l],height[r]);
            area = max(area,res);
            if (height[l] <= height[r]) l++;
            else r-- ;
        }
        return area; 
    }
};