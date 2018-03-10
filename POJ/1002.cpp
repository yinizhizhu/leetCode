#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef map<string, int> H;
typedef H::iterator ITER;
typedef pair<string, int> P;

bool cmp(P& a, P& b) {
    return a.first < b.first;
}

string mapping(char a) {
    if (a >= '0' && a<= '9') {
        string str = "";
        str += a;
        return str;
    }
    if (a>='A' && a<='C')
        return "2";
    if (a>='D' && a<='F')
        return "3";
    if (a>='G' && a<='I')
        return "4";
    if (a>='J' && a<='L')
        return "5";
    if (a>='M' && a<='O')
        return "6";
    if (a>='P' && a<='S')
        return "7";
    if (a>='T' && a<='V')
        return "8";
    return "9";
}

void show(P& a) {
    int i=0;
    for (; i<3; i++)
        cout<<a.first[i];
    cout<<"-";
    for (; i<7; i++)
        cout<<a.first[i];
    cout<<" ";
    cout<<a.second<<endl;
}

int main() {
    int i, len, n;
    string step;
    ITER iter;
    string str;
    while (cin>>n) {
        H container;
        for (; n; n--) {
            cin>>str;
            len = str.size();
            for (i=0, step = ""; i<str.size(); i++)
                if (str[i] != '-')
                    step += mapping(str[i]);
            iter = container.find(step);
            if (iter == container.end())
                container[step] = 1;
            else
                iter->second++;
        }
        vector<P> ans;
        for (iter = container.begin(); iter!=container.end(); iter++)
            if (iter->second > 1)
                ans.push_back(P(iter->first, iter->second));
        len = ans.size();
        if (len) {
            sort(ans.begin(), ans.end(), cmp);
            for (i=0; i<len; i++)
                show(ans[i]);
        }
        else
            cout<<"No duplicates."<<endl;
    }
    return 0;
}
