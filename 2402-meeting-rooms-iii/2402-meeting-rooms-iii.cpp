class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> numMeeting(n, 0);
        vector<long long int> finishTime(n, 0);

        sort(meetings.begin(), meetings.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0];});

        long long lastStartedMeeting = 0;
        for (const auto& m : meetings)
        {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            vector<long long int>::iterator minIt;
            if (start > lastStartedMeeting) {
                minIt = std::find_if(finishTime.begin(), finishTime.end(),
                            [start](long long int time) { return time <= start; });

                if (minIt == finishTime.end())
                    minIt = min_element(finishTime.begin(), finishTime.end());
            }
            else {
                minIt = min_element(finishTime.begin(), finishTime.end());
            }
            
            const int minIndex = distance(finishTime.begin(), minIt);
            auto& minTime = *minIt;

            lastStartedMeeting = minTime;
            if (minTime > start)
                minTime += duration;
            else
                minTime = end;
            
            ++numMeeting[minIndex];
        }
        const auto maxIt = max_element(numMeeting.cbegin(), numMeeting.cend());
        return distance(numMeeting.cbegin(), maxIt);
    }
};