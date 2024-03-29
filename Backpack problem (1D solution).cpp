# include <iostream>
# include <vector>
using namespace std;
class Solution{
public:
    int maxvalueOfBage(int numberOfitem, int capacity, vector<int>& weight, vector<int>& value) {
        int dp[capacity+1];
        for(int i = 0; i <= capacity; i++){
            dp[i] = 0;
        }
        for(int i = 1; i <= numberOfitem; i++){
            for(int j = capacity; j >= 1; j--) {
                if(weight[i-1] <= j){
                    dp[j] = max(dp[j], (value[i-1] + dp[j-weight[i-1]]));
                }
            }
        }
        return dp[capacity];
    }
};
int main(){
    int numberOfitem = 6;
    int capacity = 1;
    cin>>numberOfitem;
    cin>>capacity;
    vector<int>weight(numberOfitem);
    vector<int>value(numberOfitem);
    for(int i = 0; i < numberOfitem; i++){
        cin>>weight[i];
    }
    for(int i = 0; i < numberOfitem; i++){
        cin>>value[i];
    }
    Solution s1;
    int maxvalueOfBage_answer = s1.maxvalueOfBage(numberOfitem,capacity,weight,value);
    cout<<maxvalueOfBage_answer<<endl;
    return 0;
}