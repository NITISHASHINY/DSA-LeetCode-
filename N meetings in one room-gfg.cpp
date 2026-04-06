#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {

        // total number of meetings
        int n = start.size();

        // storing arrays in pairs in a vector called meetings
        vector<pair<int,int>> meetings;

        for(int i = 0; i < n; i++){
            // push end first so sorting happens by end time
            meetings.push_back({end[i], start[i]});
        }

        // sort meetings based on end time
        sort(meetings.begin(), meetings.end());

        int count = 1;

        // when the last meeting ended
        int lastEnd = meetings[0].first;

        for(int i = 1; i < n; i++){
            // if current meeting starts after previous meeting ends
            if(meetings[i].second > lastEnd){
                count++;
                lastEnd = meetings[i].first;
            }
        }

        return count;