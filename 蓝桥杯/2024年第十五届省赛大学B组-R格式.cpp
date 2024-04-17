# include <iostream>
using namespace std;
int main(){
    // 小蓝最近在研究一种浮点数的表示方法:R 格式。对于一个大于 0 的浮点数 d，可以用 R 格式的整数来表示。
    // 给定一个转换参数 n，将浮点数转换为 R 格式整数的做法是:
    //1. 将浮点数乘以 2^n;
    //2. 四舍五入到最接近的整数。
    double d;
    int n;
    cin>>n;
    cin>>d;
    long long ans = round(d * pow(2,n));
    cout<<ans;
    return 0;
}