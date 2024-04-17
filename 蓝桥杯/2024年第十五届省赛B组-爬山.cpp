# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
bool check(int magic_One, int magic_Two){
    if(magic_One == 0 && magic_Two == 0){
        return false;
    }
    return true;
}
int main(){
    // 小明这天在参加公司团建，团建项目是爬山。在 x 轴上从左到右一共有 n 座山，第 i 座山的高度为 h_i。
    // 他们需要从左到右依次爬过所有的山，需要花费的体力值为 S = Σni=1hi。
    //然而小明偷偷学了魔法，可以降低一些山的高度。他掌握两种魔法，第一种魔法可以将高度为 H 的山的高度变为 sqrt(H), 可以使用P次。
    //第二种魔法可以将高度为 H 的山的高度变为 H/2，可以使用 Q 次。并且对于每座山可以按任顺序多次释放这两种魔法。
    //小明想合理规划在哪些山使用魔法，使得爬山花费的体力值最少。请问最 优情况下需要花费的体力值是多少?
    int numbersOfMountain; int magic_One; int magic_Two;
    cin>>numbersOfMountain;
    cin>>magic_One;
    cin>>magic_Two;
    vector<int>mountain(numbersOfMountain);
    for(int i = 0; i < numbersOfMountain; i++){
        cin>>mountain[i];
    }
    sort(mountain.begin(), mountain.end());
    // int usage_magic_One = 0; int usage_magic_Two = 0;
    while(check(magic_One,magic_Two)){
        if(mountain[numbersOfMountain-1] > 2){
            if(magic_One != 0){
                mountain[numbersOfMountain-1] = sqrt(mountain[numbersOfMountain-1]);
                magic_One--;
            }
            else if(magic_One == 0 && magic_Two != 0){
                mountain[numbersOfMountain-1] /= 2;
                magic_Two--;
            }
        }
        if(mountain[numbersOfMountain-1] <= 2){
            if(magic_Two != 0){
                mountain[numbersOfMountain-1] = (mountain[numbersOfMountain-1]) / 2;
                magic_Two--;
            }
            else if(magic_Two == 0 && magic_One != 0){
                mountain[numbersOfMountain-1] = sqrt(mountain[numbersOfMountain-1]);
                magic_One--;
            }
        }
        sort(mountain.begin(),mountain.end());
    }
    int cost = 0;
    for(int i = 0; i < mountain.size(); i++){
        cost += mountain[i];
    }
    cout<<cost;
    return 0;
}
