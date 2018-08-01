#include <iostream>
#include <cmath>
using namespace std;


int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month_sum[14]={0};
int month_sum_r[14]={0};
string day_index[32]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
string month_index[13]={"00","01","02","03","04","05","06","07","08","09","10","11","12"};
void make_month_table(int *a,bool is_r)
{
    int i;
    a[1]=0;
    int num=13;
    for(i=2;i<=num;i++)
    {
        if(is_r&&i==3)
        {
            a[i]=a[i-1]+29;
        }else{

        a[i]=a[i-1]+month[i-2];
        }
    }
}

int main()
{


    bool is_r;
    int year,date;
    int i;

int day;
    make_month_table(month_sum_r,true);
     make_month_table(month_sum,false);
   while((cin >> year)&&year!=NULL)
   {
       cin>>date;
       is_r=((year%100!=0&&year%4==0)||year%400==0);
       if(is_r)
       {
           i=1;
           while(date>month_sum_r[i])
           {
               i++;
           }
           i--;
     day=date-month_sum_r[i];
       }else{

      i=1;

           while(date>month_sum[i])
           {
               i++;
           }
           i--;
     day=date-month_sum[i];
       }
        cout<<year<<"-"<<month_index[i]<<"-"<<day_index[day]<<endl;

   }

    return 0;
}
