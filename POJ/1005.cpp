#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

#define pi 3.1415926

double getR(int n) {
    double s = n*50.0;
    return sqrt(2*s/pi);
}

int getN(double x, double y) {
    int n = 1;
    double s = sqrt(x*x+y*y);
    for (; s>getR(n); n++);
    return n;
}

int main() {
    int i, n;
    double x, y;
    cin>>n;
    for (i=1; i<=n; i++) {
        cin>>x>>y;
        cout<<"Property "<<i<<": This property will begin eroding in year "<< getN(x, y) <<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
