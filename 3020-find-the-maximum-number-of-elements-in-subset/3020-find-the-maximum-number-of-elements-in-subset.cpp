class Solution {
public:
    int maximumLength(vector<int>& nums) {
        set<int>st;
        unordered_map<int,int>mp;
        for(auto n : nums )
            mp[n]++; 

        int count = 1;
        for(auto &[i , freq] : mp){
            if(st.count(i)) continue;
            if(freq == 1 ) continue;

            int curCount = 0;
            if(i == 1) {
                if(freq %2 == 0 ) curCount += freq-1;
                else curCount += freq;
                count = max(count,curCount);
                continue;
            }

            curCount = 2;
            int p = 2;
            long long val = 1LL*i*i;
            //if next val is not found
            if(mp.find(val) == mp.end()) curCount-=1;
            
            //next power found
            while(mp.find(val) != mp.end()){
                if(mp[val] >= 2){
                    curCount += 2;
                }
                else {
                    curCount+=1;
                    break;
                }


                //i^8 = (i^4)^2 = i * i (since ^2 is just sqaure)
                if(val > 1e9){
                    curCount -=1;
                    break;
                }
                val *= val;
          
                //when nextPower is not there just remove 1 count cause single element in middle and exit 
                if(mp.find(val) == mp.end()){
                    curCount -= 1;
                    break;
                }
                //adding to set to prevent re checking
                st.insert(val);
            }
            count = max(count,curCount);
        }

        return count;
    }
};