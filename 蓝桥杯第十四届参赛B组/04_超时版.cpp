# include <iostream>
# include <vector>
using namespace std;
class Solution{
public:
    vector<int>path; vector<vector<int> >result;
    void tracebacking(int numbers_plane, vector<int>& usage){
        if(path.size() == numbers_plane){
            result.push_back((path));
            return;
        }
        for(int i = 0 ; i < numbers_plane; i++){
            if(usage[i] == 1) continue;
            path.push_back(i);
            usage[i] = 1;
            tracebacking(numbers_plane,usage);
            path.pop_back();
            usage[i] = 0;
        }
    }
    bool valid(vector<int>sequence,vector<vector<int>>details,int time){
        for(int i = 1; i < sequence.size(); i++){
            // cout<<time<<" ";
            // cout<<details[sequence[i]][0]<<endl;
            if(time <= details[sequence[i]][0]) time =  details[sequence[i]][0] + details[sequence[i]][2];
            else if(time > details[sequence[i]][0] && time <= details[sequence[i]][0] + details[sequence[i]][1]){
                time +=  details[sequence[i]][1];
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool airplanelanding_valid(vector<vector<int>>details){
        vector<int> usage(details.size(),0);
        tracebacking(details.size(),usage);
//        for(int i = 0; i < result.size(); i++){
//            for(int j = 0; j < result[0].size(); j++){
//                cout<<result[i][j];
//            }
//            cout<<" ";
//        }
        for(int x = 0; x < result.size(); x++){
            int time = details[result[x][0]][2] + details[result[x][0]][0];
            // cout<<time<<endl;
            if(valid(result[x],details,time)) return true;
        }
        path.clear();
        result.clear();
        return false;
    }
};
int main(){
    int numbers_group;
    cin>>numbers_group;
    while(numbers_group--){
        int numbers_plane;
        cin>>numbers_plane;
        if(numbers_plane == 1) cout<<"YES"<<endl;
        else{
            vector<vector<int>>details(numbers_plane,vector<int>(3));
            for(int j = 0; j < numbers_plane; j++){
                cin>>details[j][0] >> details[j][1] >>details[j][2];
            }
            Solution s1;
            if(s1.airplanelanding_valid(details)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}