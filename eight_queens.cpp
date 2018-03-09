#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 8

int m[N+1][N+1];
vector<int> container;
typedef pair<int, int> P;

void addOne(int i, int j) {
    int a, b;
    for (a = 1; a<=N; a++)
        if (a!=i)
            m[a][j]++;
    for (b=1; b<=N; b++)
        if (b!=j)
            m[i][b]++;
    for (a=i-1, b=j-1; a>0 && b>0; a--, b--)
        m[a][b]++;
    for (a=i+1, b=j+1; a<=N && b<=N; a++, b++)
        m[a][b]++;
    for (a=i-1, b=j+1; a>0 && b<=N; a--, b++)
        m[a][b]++;
    for (a=i+1, b=j-1; a<=N && b>0; a++, b--)
        m[a][b]++;
    m[i][j]++;
}

void delH(int i, int j) {
    if (m[i][j] > 0)
        m[i][j]--;
}

void delOne(int i, int j) {
    int a, b;
    for (a = 1; a<=N; a++)
        if (a!=i)
            delH(a,j);
    for (b=1; b<=N; b++)
        if (b != j)
            delH(i,b);
    for (a=i-1, b=j-1; a>0 && b>0; a--, b--)
        delH(a,b);
    for (a=i+1, b=j+1; a<=N && b<=N; a++, b++)
        delH(a,b);
    for (a=i-1, b=j+1; a>0 && b<=N; a--, b++)
        delH(a,b);
    for (a=i+1, b=j-1; a<=N && b>0; a++, b--)
        delH(a,b);
    delH(i, j);
}

void solution() {
    int a, j, step = 0;
    bool direction = true; // true: forward, false: back
    stack<P> path;
    path.push(P(1, 1));
    addOne(1, 1);
    step = 1;
    do {
        P pre = path.top();
        a = pre.first;
        j = pre.second;
//        cout<<a<<", "<<j<<endl;
        if (a == N && direction) {
            container.push_back(step);
//            cout<<step<<endl;
            direction = false;
        }
        else {
            if (direction) {
                a = a+1;
                j = 1;
            }
            else {
                path.pop();
                delOne(a, j);
                step /= 10;
                j++;
            }
            for (; j<=N; j++) {
                if (!m[a][j]) {
                    path.push(P(a, j));
                    addOne(a, j);
                    step = step*10+j;
                    direction = true;
                    break;
                }
            }
            if (j > N) direction = false;
        }
    } while (!path.empty());
}

void dfs(int step, int i) {
    if (i>N) {
        container.push_back(step);
        return;
    }
    for (int j=1; j<=N; j++)
        if (!m[i][j]) {
            addOne(i, j);
            dfs(step*10+j, i+1);
            delOne(i, j);
        }
}

int main() {
//    dfs(0, 1);
    solution();
    for (int i=0; i<container.size(); i++)
        cout<<container[i]<<endl;
    cout<<container.size()<<endl;
    return 0;
}
