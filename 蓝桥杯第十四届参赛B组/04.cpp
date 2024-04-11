#include <iostream>
#include <vector>
using namespace std;
struct plane_detail{
    int arrival_time;
    int holding_time;
    int landing_time;
}detail[10];

bool planelanding(int time, int plane_number, vector<int>& usage, int plane_number_choosen){
    if(plane_number_choosen == plane_number ){
        return true;
    }
    for(int i = 0 ; i < plane_number; i++){
        int time_tempt =  time;
        if(usage[i] == 1) continue;
        if(detail[i].arrival_time >= time){
            usage[i] = 1;
            plane_number_choosen++;
            time_tempt = detail[i].arrival_time + detail[i].landing_time;
        }
        else if(detail[i].arrival_time < time && detail[i].arrival_time + detail[i].holding_time >= time){
            usage[i] = 1;
            time_tempt =  time_tempt + detail[i].landing_time;
            plane_number_choosen++;
        }
        else if(detail[i].arrival_time < time && detail[i].arrival_time + detail[i].holding_time < time){
            continue;
        }
        if(planelanding(time_tempt,plane_number,usage,plane_number_choosen) == true){
            return true;
        }
        else{
            plane_number_choosen--;
            usage[i] = 0;
        }
    }
    return false;
}

int main(){
    int number_group; int plane_number;
    cin>>number_group;
    while(number_group--){
        cin>>plane_number;
        for(int i = 0; i < plane_number; i++){
            cin>>detail[i].arrival_time>>detail[i].holding_time>>detail[i].landing_time;
        }
        vector<int>usage(plane_number,0);
        if(planelanding(0,plane_number,usage,0)) {
            cout<<"YES" <<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
