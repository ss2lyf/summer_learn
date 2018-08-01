#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



int main() {
    // your code goes here
    char ch1,ch2;
    string s;
    int n;
    int start,end;
    bool flag = false;
    while(cin >> n >> ch1 >> ch2)
    {
        if(flag)
        {
            cout << endl;
        }
        else
        {
            flag = true;
        }
        if(n == 1)
        {
            cout <<ch1 << endl;
            //cout << endl;
            continue;
        }
        if( ( (n + 1) / 2 & 1 ) == 0)
        {
            swap(ch1,ch2);
        }
        s = "";
        vector<string> vec;

        s.insert(0,n,ch1);
        //cout << s << endl;
        s[0] = ' ';
        s[n - 1] = ' ';
        vec.push_back(s);
        s[0] = ch1;
        s[n - 1] = ch1;

        start = 0;
        end = n - 1;
        for(int  i = 1;i < (n + 1) / 2;++i)  //前后是对称的，只要保存一半
        {
            ++start;
            --end;
            if(i & 1)   //区分不同的行
            {
                 for(int i = start;i <= end;++i)
                 {
                    s[i] = ch2;
                 }
            }
            else
            {
                 for(int i = start;i <= end;++i)
                 {
                    s[i] = ch1;
                 }
            }
            vec.push_back(s);
            //cout << "kk" << endl;
        }
        for(int i = 0;i < vec.size();++i)
        {
            cout << vec[i] << endl;
        }
        for(int i = vec.size() - 2;i >= 0;--i)
        {
            cout << vec[i] << endl;
        }

        //cout << endl;

    }

    return 0;
}
