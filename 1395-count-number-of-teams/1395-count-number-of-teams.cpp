class Solution {
public:
     void update(vector<int>& segmentTree, int i, int ss, int se, int idx) {
        if (ss == se) segmentTree[i]++;
        else{
            int m = (ss + se)/2;
            if (idx <= m) update(segmentTree, 2 * i, ss, m, idx);
            else update(segmentTree, 2 * i + 1, m + 1, se, idx);
            segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
        }
    }

    int count(vector<int>& segmentTree, int i, int ss, int se, int left, int right) {
        if (left > se || right < ss) return 0;
        if (left <= ss && right >= se) return segmentTree[i];
        int mid = (ss+se)/2;
        return count(segmentTree, 2 * i, ss, mid, left, right) + count(segmentTree, 2 * i + 1, mid + 1, se, left, right);
    }

    int numTeams(vector<int>& rating) {
        int n=1e5 + 1;
        vector<int> ST_1(4*n);
        vector<int> ST_2(4*n);
        vector<int> A(rating.begin(),rating.end());
        //sort(A.begin(),A.end());
        for(int i=0;i<rating.size();i++){
            update(ST_2,1,0,n-1,rating[i]);
        }

        int teams=0;
        for(int i=0;i<rating.size();i++){
            int small_before = count(ST_1,1,0,n-1,0,rating[i]-1);
            int big_before = count(ST_1,1,0,n-1,rating[i]+1,n);
            int small_after = count(ST_2,1,0,n-1,0,rating[i]-1)-small_before;
            int big_after = count(ST_2,1,0,n-1,rating[i]+1,n)-big_before;
            teams += big_before*small_after + big_after*small_before;
            update(ST_1,1,0,n-1,rating[i]);
        }
        return teams;
    }
};