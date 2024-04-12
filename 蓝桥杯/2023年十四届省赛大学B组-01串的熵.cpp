#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double xiangnongxinxishang(double x, double N){
    double p1 = x/N; double p2 = 1 - x/N;
    return( -  p1 * log2(p1) * x - p2 * log2(p2) * (N-x));
};
int main()
{
    for(int i = 1; i <= 11666666; i++){ // 表示有几个0
        xiangnongxinxishang(i, 23333333);
        if(fabs(xiangnongxinxishang(i, 23333333) - 11625907.5798) < 1e-4) {
            cout << i << endl;
        }
    }
    // cout<<xiangnongxinxishang(1,23333333);
    return 0;
}