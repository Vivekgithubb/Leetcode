class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int xdis = abs(start[0]-target[0]);
        int ydis = abs(start[1]-target[1]);

        return (xdis+ydis) % 2 == 0;
    }
};