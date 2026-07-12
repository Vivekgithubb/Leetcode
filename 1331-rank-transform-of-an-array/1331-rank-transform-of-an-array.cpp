class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        set<int>st;
        priority_queue<int>pq;
        vector<int>org = arr;
        sort(arr.begin(),arr.end());
        int n = arr.size();

        for(auto i : arr)
            st.insert(i);

        int ranks = st.size();
        for(auto s : st)
            pq.push(s);

        while(!pq.empty()){
            int el = pq.top();
            pq.pop();
            mp[el] = ranks;
            ranks--;
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<"-"<<mp[arr[i]]<<endl;
            int rank = mp[org[i]];
            org[i] = rank; 
        }

        return org;
    }
};