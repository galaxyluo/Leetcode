#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for (vector<int> &a : A) {
            if (a[0] == 0) {
                for (int i = 0; i < n; i++) {
                    if (a[i] == 0) a[i] = 1;
                    else a[i] = 0;
                }
            }
        }
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << A[i][j];
			}
			cout << endl;
		}
        int res = 0;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 1) count++;
            }
            count = max(count, m - count);
            printf("%d\n", count);
            res += count * (1 << (n - j - 1));
            printf("res:%d\n", res);
        }
        return res;
    }
    
    
    int mmatrixScore(vector<vector<int>>& A) {
        for(vector<int> a : A) {
            if(a[0] == 0) {
                for(int i = 0; i < a.size(); i++) {
                    a[i] = a[i] == 0 ? 1 : 0;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < A[0].size(); i++) {
            int count = 0;
            for(int j = 0; j < A.size(); j++) {
                if(A[j][i] == 1) count++;
            }
            if(count <= A.size()/2) count = A.size()-count;
            res += count * pow(2, A[0].size()-i-1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int> > A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    printf("%d", s.matrixScore(A));
}
