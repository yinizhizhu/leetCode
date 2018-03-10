#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int solution(double dis) {
    int n = 2;
    for (;dis > 0; n++)
        dis -= (1.0/n);
    return (n-2);
}

int main() {
    double dis;
    for (cin>>dis; dis!=0.0; cin>>dis)
        cout<<solution(dis)<<" card(s)"<<endl;
    return 0;
}
