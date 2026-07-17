class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        int res = 0;
        for (int i = 0;i < position.size();++i){
             double time = (double)(target-position[i])/speed[i];
             cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());
        double fleetTime = 0;
        
        for(int i = position.size() - 1;i>=0;--i){
           double currentTime = cars[i].second;
            if (currentTime > fleetTime) {
                res++;
                fleetTime = currentTime;
            }

        }
        return res;
    }
};