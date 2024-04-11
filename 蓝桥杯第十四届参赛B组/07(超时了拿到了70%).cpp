# include <iostream>
# include <string>
using namespace std;
int main(){
    int reducelength;
    cin>>reducelength;
    string initialstring;
    cin>>initialstring;
    char leftchar; char rightchar;
    cin>>leftchar; cin>> rightchar;
    int ans = 0;
    for(int i = 0; i <= initialstring.length() - reducelength; i++){
        if(initialstring[i] == leftchar){
            for (int j = i+reducelength-1; j < initialstring.length(); j++){
                if(initialstring[j] == rightchar){
//                    cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}