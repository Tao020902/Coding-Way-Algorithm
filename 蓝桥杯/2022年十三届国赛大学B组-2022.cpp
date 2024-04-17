#include <iostream>
using namespace std;
long long pd[2023][11]{1};
int main() {
    for (int i = 1; i <= 2022; i++)
        for (int j = 1; j <= 10; j++)
            if (i >= j) {
                pd[i][j] = pd[i - j][j] + pd[i - j][j - 1];
            }
    cout<<pd[2022][10];
}