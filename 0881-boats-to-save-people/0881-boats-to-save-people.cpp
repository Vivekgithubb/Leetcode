class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int j = people.size()-1;
        int i=0;
        int boat = 0;
        while( i <= j){
            int sum = 0;
            if( i == j){
                boat++;
                break;
            }
            if(people[i] + people[j] > limit){
                boat++;
                j--;
            }
            else {
                i++;
                j--;
                boat++;
            }
        }
        return boat;
    }
};