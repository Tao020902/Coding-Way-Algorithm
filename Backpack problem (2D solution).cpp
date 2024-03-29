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
				if(weight[i] > j){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] =  max(dp[i-1][j], (value[i] +dp[i-1][j-weight[i]]));
					maxvalue = max(maxvalue, dp[i][j]);
				}    
            }
        }
		return  maxvalue;
    }
};
int main(){
    int numberOfitem;
    int capacity;
    cin>>numberOfitem;
	cin>>capacity;
	cout<<endl;
    vector<int>weight(numberOfitem);
    vector<int>value(numberOfitem);
    for(int i = 0; i < numberOfitem; i++){
        cin>>weight[i];
    }
    cout<<endl;
    for(int i = 0; i < numberOfitem; i++){
        cin>>value[i];
    }
    cout<<endl;
    Solution s1;
    int maxvalueOfBage_answer = s1.maxvalueOfBage(numberOfitem,capacity,weight,value);
    cout<<maxvalueOfBage_answer<<endl;
    return 0;
}