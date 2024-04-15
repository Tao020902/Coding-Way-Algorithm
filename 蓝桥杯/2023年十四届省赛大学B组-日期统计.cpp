#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class solution{
public:
    vector<int>path; int sum = 0;
    unordered_set <int> date;
    bool test(vector<int>path){
        int year = 1000 * path[0] + 100 * path[1] + 10 * path[2] + path[3];
        int month = path[4] * 10 + path[5]; int day = path[6] * 10 + path[7];
        if(year != 2023) return false;
        if(month > 12 || month < 1) return false;
        if(day <= 0) return false;
        if(month == 2 && day > 28) return false;
        if(month < 8 && month % 2 == 1 && day > 31) return false;
        if(month < 8 && month % 2 == 0 && day > 30) return false;
        if(month >= 8 && month % 2 == 1 && day > 30) return false;
        if(month >= 8 && month % 2 == 0 && day > 31) return false;
        return true;
    }
    void backtracing(vector<int>s,int startIndex){
        if(path.size() == 8){
            if(test(path) == true){
                int data = 10000000 * path[0] + 1000000 * path[1] + 100000 * path[2] + path[3] * 10000 + path[4] * 1000 + path[5] * 100 +path[6] * 10 + path[7];
                cout<<data<<endl;
                date.insert((data));
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(path.size() == 0 && s[i] != 2) continue;
            if(path.size() == 1 && s[i] != 0) continue;
            if(path.size() == 2 && s[i] != 2) continue;
            if(path.size() == 3 && s[i] != 3) continue;
            if(path.size() == 4 && s[i] > 1) continue;
            if(path.size() == 6 && s[i] > 3) continue;
            path.push_back(s[i]);
            backtracing(s,i+1);
            path.pop_back();
        }
    }
    int findingdate(vector<int>nums){
        backtracing(nums,0);
        sum = date.size();
        return sum;
    }
};
int main()
{

    //int numbers[100] = {5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,5,9,5,0,3,8,7,5,8,1,5,8,6,1,8,3,0,3,7,9,2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3};
    int numbers[100];
    for(int i = 0; i < 100; i++){
        cin>>numbers[i];
    }
    vector<int>nums;
    for(int i = 0; i < 100; i++){
        nums.push_back(numbers[i]);
    }
    solution s1;
    int result = s1.findingdate(nums);
    cout<<result<<endl;
    return 0;
}


