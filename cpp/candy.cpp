class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        map<int, int> myMap;
        vector<int> give(n, 0);
        for (int i = 0; i < n; i++) {
            myMap.insert(pair(ratings[i], i));
        }
        int ans = 0;
        for (auto it = myMap.begin(); it != myMap.end(); it++)
        {
            int i = it->second;
            if (i == 0) {   
                int right = i + 1;
                if (ratings[i] > ratings[right]) {
                    give[i] = give[right] + 1;
                }
                else {
                    give[i] = 1;
                }
            }
            else if (i == n - 1) {
                int left = i - 1;
                if (ratings[i] > ratings[left]) {
                    give[i] = give[left] + 1;
                }
                else {
                    give[i] = 1;
                }
            }
            else {
                int left = i - 1;
                int right = i + 1;
                int tf = 0, tr = 0;
                if (ratings[i] > ratings[left]) {
                    tf = give[left] + 1;
                }
                if (ratings[i] > ratings[right]) {
                    tr = give[right] + 1;
                }
                give[i] = max(tf, tr);
                give[i] = max(give[i], 1);
            }
        }
        for (int i = 0; i < n; i++) {
            ans += give[i];
        }
        return ans;
    }
};