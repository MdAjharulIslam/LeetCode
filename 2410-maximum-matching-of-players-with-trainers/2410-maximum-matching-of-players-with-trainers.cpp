class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int count = 0;
        int i = 0, j = 0; // pointers for players and trainers

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // Match found
                count++;
                i++;
                j++;
            } else {
                // Try next trainer
                j++;
            }
        }
        return count;
    }
};