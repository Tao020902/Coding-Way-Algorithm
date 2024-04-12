#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution{
public:
    bool valid(int mid, int numbers, vector<vector<int> >record){
        for(int i = 0 ;i < numbers; i++){
            if(record[i][0] / mid > record[i][1]) return false;
        }
        return true;
    }
    int mineralcost_left(int numbers, vector<vector<int> >record) {
        int left = 1;
        int right = 0;
        for (int i = 0; i < numbers; i++) {
            right = max(right, record[i][0]);
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, numbers, record) == false) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
int main(){
    int numbers;
    cin>>numbers;
    vector<vector<int> >record(numbers,vector<int>(2));
    int right = INT_MAX;
    for(int i = 0; i <numbers; i++) {
        cin >> record[i][0] >> record[i][1];
        right = min(right,(record[i][0]/record[i][1]));
    }
    Solution s1;
    int left = s1.mineralcost_left(numbers,record);
    cout<<left<<" "<<right<<endl;
    return 0;
}