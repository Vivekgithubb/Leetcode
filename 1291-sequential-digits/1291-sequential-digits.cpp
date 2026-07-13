class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string l = to_string(low);
        string h = to_string(high);
        int lsize = l.length();
        int hsize = h.length();

        string v = "123456789";
        vector<int>ans;
        for(int i=lsize; i<= hsize ; i++){
            for(int start = 0 ; start + i <=9 ; start++){
                int num = stoi(v.substr(start,i));
                if(num <= high && num >= low)
                    ans.push_back(num);
            }
            
        }
        return ans;
    }
};