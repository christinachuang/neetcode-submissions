class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty())
            return 0;
        vector<pair<int, double>> rounds(position.size(), {0, 0});
        for(int i = 0; i < rounds.size(); i++)
            rounds[i] = {position[i], (target - position[i])/double(speed[i])};
        sort(rounds.begin(), rounds.end(), greater<pair<int, double>>());
        int fleet_count = 1;
        double curr_rounds = rounds[0].second;
        for(int i = 0; i < rounds.size(); i++){
            if(rounds[i].second <= curr_rounds)
                continue;
            fleet_count++;
            curr_rounds = rounds[i].second;
        }
        return fleet_count;
    }
};
