class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& m) {
        int n = m.size();
        int r = m[0].size();
        pre.resize(n,vector<int>(r,0));

        for(int i=0;i<n;i++){
            for(int j=0; j<r; j++){
                int sum = m[i][j];
                if( i > 0)
                    sum += pre[i-1][j];
                if( j > 0)
                    sum += pre[i][j-1];
                if( i > 0 && j > 0)
                    sum -= pre[i-1][j-1];

                pre[i][j] = sum;
            }
        }
        for (const auto &row : pre) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        cout << "pre[" << r2 << "][" << c2 << "] = " << pre[r2][c2] << '\n';
        cout << "pre[" << r2 << "][" << c1 << "] = " << pre[r2][c1] << '\n';
        cout << "pre[" << r1 << "][" << c2 << "] = " << pre[r1][c2] << '\n';
        int ans = pre[r2][c2];
        if( c1 > 0)
            ans -= pre[r2][c1-1];
        if( r1 > 0)
            ans -= pre[r1-1][c2];
        if(r1 > 0 && c1 > 0)
            ans += pre[r1-1][c1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */