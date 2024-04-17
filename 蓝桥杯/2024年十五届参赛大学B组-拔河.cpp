# include <iostream>
using namespace std;
int main(){
    int num; long long sum = 0;
    cin>>num;
    long long nums[num+1];
    for(int i = 0; i < num; i++){
        cin>>nums[i+1];
        sum += nums[i+1];
    }
    long long capacity;
    if(sum % 2 == 0) capacity = sum/2;
    else{
        capacity = sum/2 + 1;
    }
    long long dp[num+1][capacity+1];
    for(int i = 0; i < num+1; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < capacity+1; i++){
        dp[0][i] = 0;
    }
//    cout<<num+1<<endl;
//    cout<<capacity<<endl;
    for(int i = 1; i < num+1; i++){
        for(int j = 1; j < capacity+1; j++){
            if(nums[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-nums[i]] + nums[i],dp[i-1][j]);
            }
        }
    }
//    for(long long i  = 0; i < num+1; i++){
//        for(long long j = 0 ; j < capacity+1; j++){
//            cout<<dp[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    cout<<abs(sum - 2 * dp[num][capacity]);
    return 0;
}