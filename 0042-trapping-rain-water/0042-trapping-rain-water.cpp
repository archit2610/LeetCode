class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0,r = height.size() - 1;
        int leftMax = height[l],rightMax = height[r];
        int area = 0;
        while ( l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax,height[l]);
                if (leftMax - height[l] > 0) area += leftMax - height[l];
            }
            else {
                r--;
                rightMax = max(rightMax,height[r]);
                if (rightMax - height[r] > 0) area += rightMax - height[r];
            }
        }
    return area;
    }
};