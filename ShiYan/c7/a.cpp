#include<iostream>
using namespace std;
// int main()
// {
// 	int tong[100]={0},num,n,i,max=0,flag=0,ans=0;
// 	cin>>n;//数据个数 
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>num;//输入的数据 
// 		tong[num]++;//统计每个数据的出现次数 
// 		if(num>max)
// 		{
// 			max=num;
// 		}
// 	}
// 	for(i=0;i<=max;i++)//每个数出现次数的比较，一定要注意是 i<=max
// 	{
// 		if(tong[i]>flag)
// 		{
// 			flag=tong[i]; 
// 			ans=i;//此时i为之前输入的数据 
// 		}
// 	}
// 	cout<<ans;
// 	return 0;
//  } 
 int main()
 {
     int n;
     scanf("%d",&n);
     int arr[n-1];
     int ay[10000] = {0};
     int temp = 0;
     int i = 0,j;
     int number1 = 0;
     for(i = 0;i < n;i ++)
     {
         scanf("%d",&arr[i]);
     }
     int *amax = (int*)malloc(sizeof(int));
     *amax = arr[0];
     for(i = 0;i < n;i ++)
     {
         if(*amax < arr[i])
             *amax = arr[i];
     }
     for (i = 0; i< n;i ++)
     {
         temp = arr[i];
        
         ay[temp] ++;
         }
         int *max = (int*)malloc(sizeof(int));        
         *max = ay[0];
       
     for(j = 0;j <= *amax;j ++)
     {
         if(*max < ay[j])
            {
                *max = ay[j];
              number1=j;
           }
 
     }
     printf("%d\n",number1);
    return 0;
 }
