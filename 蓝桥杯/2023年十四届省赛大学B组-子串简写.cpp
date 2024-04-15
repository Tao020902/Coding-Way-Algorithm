# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main(){
    int reducelength;
    cin>>reducelength;
    string initialstring;
    cin>>initialstring;
    char leftchar; char rightchar;
    cin>>leftchar; cin>> rightchar;
    long long ans = 0;
///     时间复杂度为O(n^2)
//    for(int i = 0; i <= initialstring.length() - reducelength; i++){
//        if(initialstring[i] == leftchar){
//            for (int j = i+reducelength-1; j < initialstring.length(); j++){
//                if(initialstring[j] == rightchar){
//                    ans++;
//                }
//            }
//        }
//    }
// 时间复杂度为O(n)
    int sum_leftchar = 0;
    for(int i =0,j = reducelength-1; j < initialstring.length();i++,j++){
        if(initialstring[i] ==leftchar)  sum_leftchar++;
        if(initialstring[j] == rightchar) ans += sum_leftchar;
    }
    cout<<ans;
    return 0;
}
