#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int dp[3], t[3], d;

bool judge() {
    if (dp[0] != dp[1])
        return false;
    if (dp[0] != dp[2])
        return false;
    if (dp[1] != dp[2])
        return false;
    return true;
}

int minN() {
    int ans = 0;
    if (dp[1] < dp[ans])
        ans = 1;
    if (dp[2] < dp[ans])
        ans = 2;
    return ans;
}

int handle() {
    int i=0;
    while (!judge() && dp[0] <= d) {
        i = minN();
        dp[i] += t[i];
    }
    i = minN();
    dp[i] += t[i];
    while (!judge()) {
        i = minN();
        dp[i] += t[i];
    }
    i = (dp[0]-d);
    if (i > 21252)
        return i%21252;
    return i;
}

int main() {
    int step = 1;
    t[0] = 23, t[1] = 28, t[2] = 33;
    for (;cin>>dp[0]>>dp[1]>>dp[2]>>d && d!=-1; step++)
        cout<<"Case "<<step<<": the next triple peak occurs in "<<handle()<<" days. "<<endl;
    return 0;
}
