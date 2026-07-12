class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int count = 0;
        int stH = 0, endH = 0;
        int stM = 0, endM = 0;
        int stS = 0, endS = 0;
        string str1 = "";
        string str2 = "";
        for(auto s : startTime){
            if(s != ':')
                str1 += s;
            else{
                int val = stoi(str1);
                if(count == 0)
                    stH = val;
                else if (count == 1)
                    stM = val;
                str1= "";
                count+=1;
            }
        }
        stS = stoi(str1);

        count = 0;
        for(auto s : endTime){
            if(s != ':')
                str2 += s;
            else{
                int val = stoi(str2);
                if(count == 0)
                    endH = val;
                else if (count == 1)
                    endM = val;
                str2= "";
                count+=1;
            }
        }
        endS = stoi(str2);
        int start = stH*3600 + stM*60 + stS;
        int end = endH*3600 + endM*60 + endS;
        
        int total = abs(end - start) ;
        return total;
    }
};