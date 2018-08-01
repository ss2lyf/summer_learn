#include <iostream>

using namespace std;

int main()
{

    int num;
    int middle;
  int i;
    while((cin>>num)&&num!=0)
    {


        int sum[101]={0};



        for(i=0;i<num;i++)
        {
         cin>>middle;
         sum[middle]++;
        }


        cin>>middle;

        cout<<sum[middle]<<endl;




    }


    cout << "Hello world!" << endl;
    return 0;
}
