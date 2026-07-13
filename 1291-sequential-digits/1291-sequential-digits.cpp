class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v = {1,2,3,4,5,6,7,8,9};
        int n = v.size();
        string l = to_string(low);
        string h = to_string(high);

        vector<int>ans;
        int lsize = l.length();
        int hsize = h.length();
        for(int i=lsize; i<= hsize ; i++){
            int k = 0;
            int j = 0;
            string str = "";
            while( k+i <= 9){
                while( (j-k) < i && j <= 8){
                    str +=(v[j]+'0');
                    j++;
                }
                int num = stoi(str);
                cout<<num<<"\n";
                if(num > high ) return ans;
                if(num >= low && num <= high)
                    ans.push_back(num);
                
                str.erase(0,1);
                k++;
            }
        }

        return ans;
    }
};