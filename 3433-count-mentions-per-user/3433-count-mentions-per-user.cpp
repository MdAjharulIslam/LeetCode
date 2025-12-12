class Solution {
public:
    static bool cmp(vector<string>& a, vector<string>& b)
    {
        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);

        if(t1 == t2)
        {
            return a[0] > b[0];
        }
        return t1 < t2;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> thresh(n, 0);
        vector<int> mentions(n, 0);

        sort(events.begin(), events.end(), cmp);

        for(auto& ev: events)
        {
            if(ev[0] == "OFFLINE")
            {
                int time = stoi(ev[1]);
                int id = stoi(ev[2]);
                thresh[id] = time+60;
            }
            else if(ev[0] == "MESSAGE")
            {
                int time = stoi(ev[1]);
                string mnt_string = ev[2];

                if(mnt_string == "ALL")
                {
                    for(int i=0; i<n; i++) mentions[i] += 1;
                }
                else if(mnt_string == "HERE")
                {
                    for(int i=0; i<n; i++)
                    {
                        if(thresh[i] <= time) mentions[i] += 1;
                    }
                }
                else
                {
                    stringstream ss(mnt_string);
                    string token;
                    while(ss >> token)
                    {
                        int id = stoi(token.substr(2));
                        mentions[id] +=1;
                    }
                }
            }
        }

        return mentions;
    }
};