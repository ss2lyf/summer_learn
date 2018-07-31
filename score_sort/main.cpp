#include <iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    cin>>num;
    double f_part;
    double s_part;
    int middle;
    int middle2;
    double middle3;
    double * a=(double*)malloc(sizeof(double)*num);
    int i;
    for(i=0; i<num; i++)
    {
        cin>>f_part;
        cin>>s_part;
        a[i]=f_part/1000+s_part;
    }
    sort(a,a+num);

    for(i=0; i<num; i++)
    {
        middle=a[i];
        middle3=a[i]-middle;
        middle3=middle3*1000;
        cout<<middle3<<" "<<middle<<endl;
    }
    return 0;
}
