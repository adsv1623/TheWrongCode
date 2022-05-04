class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // no. of pairs of sum k
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto x: nums){
            if(mp.find(k-x)!=mp.end() && mp[k-x]>0){
                mp[k-x]--;
                cnt++;
            }else{
                mp[x]++;
            }
        }
        return cnt;
    }
};