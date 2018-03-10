#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    double m, sum = 0;
    for (int i=0; i<12 && cin>>m; i++)
        sum+= m;
    printf("$%.2f\n", sum/12);
    return 0;
}
