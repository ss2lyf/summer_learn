#include <iostream>
#include <cmath>
using namespace std;


int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month_r[12]={31,29,31,30,31,30,31,31,30,31,30,31};
void make_year_table(int *a ,int num)
{
    int i;
    for(i=1;i<num;i++)
    {
        if((i%100!=0&&i%4==0)||i%400==0)
        {
            a[i]=a[i-1]+366;

        }else{

        a[i]=a[i-1]+365;
        }
    }

}

int compute_data(int date,int * a)
{
 int i;
    int temp1,temp2,temp_year=0,temp_month=0;
    temp1=date/10000;
    temp_year=a[temp1];
   // cout<<endl<<temp_year<<endl;
    temp2=(date%10000)/100;


if((temp1%100!=0&&temp1%4==0)||temp1%400==0)
{
    for(i=0;i<temp2-1;i++)
    {
    temp_month+=month_r[i];
    }

}else{

 for(i=0;i<temp2-1;i++)
    {
    temp_month+=month[i];
    }

}
//cout<<endl<<temp_month<<endl;

return  temp_year+temp_month+date%100;

}
int main()
{
    int a[5000];
    int middle;
    make_year_table(a,5000);
    int date1,date2;


   while((cin >> date1)&&date1!=NULL)
   {

       middle=(abs(compute_data(date1, a)-compute_data(00000101,a)));
       middle=middle%7+1;

    cout << middle<< endl;
   }
    return 0;
}
