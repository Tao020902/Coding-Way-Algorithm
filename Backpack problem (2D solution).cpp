# include <iostream>
# include <vector>
using namespace std;

class Solution{
public:
    int maxvalueOfBage(int numberOfitem, int capacity, vector<int>& weight, vector<int>& value){
        int dp[numberOfitem+1][capacity+1];
		int maxvalue = 0;
		for(int i = 0; i <= capacity; i++){
			dp[0][i] = 0;
		}
		for(int i = 0; i <= numberOfitem; i++){
			dp[i][0] = 0;
		}
        for(int i = 1; i <= numberOfitem; i++){
            for(int j = 1; j <= capacity; j++){
				if(weight[i-1] > j){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] =  max(dp[i-1][j], (value[i-1] +dp[i-1][j-weight[i-1]]));
					
				}
            }
        }
		return  dp[numberOfitem][capacity];
    }
};
int main(){
    int numberOfitem;
    int capacity;
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
