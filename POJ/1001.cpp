#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct big {
    int bit;
    vector<int> num, ans;
    big(string& r) {
        stack<int> container, rever;
        int i = r.size()-1;
        num.clear();
        bit = 0;
        for (; ; i--) {
            if (r[i] == '0') {
                if (bit) {
                    container.push(0);
                    bit++;
                }
            }
            else if (r[i] == '.')
                break;
            else {
                container.push(r[i]-'0');
                bit++;
            }
        }
        for (--i; i>=0; i--)
            container.push(r[i]-'0');
        while (!container.top())
            container.pop();
        while (!container.empty()) {
            rever.push(container.top());
            container.pop();
        }
        while (!rever.empty()) {
            num.push_back(rever.top());
            rever.pop();
        }
    }
    void update(vector< vector<int> >& tmp) {
        int i, j, up, len = tmp.size();
        ans.clear();
        for (i=0; i<tmp[0].size(); i++)
            ans.push_back(tmp[0][i]);
        for (i=1; i<len; i++) {
            for (j=0, up=0; j<tmp[i].size() && j<ans.size(); j++) {
                up = up + tmp[i][j] + ans[j];
                ans[j] = up%10;
                up/=10;
            }
            for (; j<tmp[i].size(); j++) {
                up += tmp[i][j];
                ans.push_back(up%10);
                up/=10;
            }
            for (; j<ans.size(); j++) {
                up += ans[j];
                ans[j] = up%10;
                up/=10;
            }
            if (up)
                ans.push_back(up);
        }
    }
    void showTmp(vector< vector<int> >& tmp) {
        int i, j, len = tmp.size();
        cout<<"Tmp: \n";
        for (i=0; i<len; i++) {
            for (j=tmp[i].size()-1; j>=0; j--)
                cout<<tmp[i][j];
            cout<<endl;
        }
        showAns();
    }
    void multi() {
        int i, j, up, lenN = num.size(), lenA = ans.size();
        vector< vector<int> > tmp;
        vector<int> step;
        for (i=0; i<lenN; i++) {
            if (num[i]) {
                step.clear();
                for (j=0; j<i; j++)
                    step.push_back(0);
                for (j=0, up = 0; j<lenA; j++) {
                    up = up + ans[j]*num[i];
                    step.push_back(up%10);
                    up /= 10;
                }
                if (up)
                    step.push_back(up);
                tmp.push_back(step);
            }
        }
        update(tmp);
//        showTmp(tmp);
    }
    void power(int n) {
        bit *= n;
        ans.push_back(1);
        for (; n; n--)
            multi();
    }
    void show() {
        for (int i=num.size()-1; i>=0; i--)
            cout<<num[i];
        cout<<", "<<bit<<endl;
    }
    void showAns() {
        int i, len = ans.size();
        if (bit == 0) {
            for (i=len-1; i>=0; i--)
                cout<<ans[i];
        }
        else if (bit >= len) {
            cout<<".";
            for (i=bit-len; i; i--)
                cout<<'0';
            for (i=len-1; i>=0; i--)
                cout<<ans[i];
        }
        else {
            for (i=len-1, bit = len-bit; bit; i--, bit--)
                cout<<ans[i];
            cout<<'.';
            for (; i>=0; i--)
                cout<<ans[i];
        }
        cout<<endl;
    }
};


int main() {
    int n;
    string r;
    while (cin>>r>>n) {
        big a(r);
//        a.show();
        a.power(n);
        a.showAns();
    }
    return 0;
}

