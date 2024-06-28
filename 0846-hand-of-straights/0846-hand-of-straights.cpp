class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)return false;
        unordered_map<int,int>m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            if(m[hand[i]] == 0)continue;
            for(int k=0; k< groupSize;k++){
                if(m[hand[i] + k] == 0)return false;
                m[hand[i] + k]--;
            }
        }
        return true;
    }
};