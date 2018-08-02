#include <iostream>

using namespace std;

int main()
{
    int a,b,k;
    int middle;
    int i;
    while(true)
    {
middle=1;
        cin>>a>>b>>k;
        if(a==0&&b==0)
        {
            break;
        }
  for(i=0;i<k;i++)
  {
middle*=10;
  }

  if(a%middle==b%middle)
  {

      cout<<"-1";

  }else{

  cout<<a+b;
  }
  cout<<endl;
    }

    return 0;
}
