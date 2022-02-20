#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];

//Recursion
// int fun(int v[],int w[],int wt,int it)
// {
//     if(it==0 || wt==0)
//         return 0;
//     if(w[it-1] <=wt)
//         return max(v[it-1]+fun(v,w,wt-w[it-1],it-1) ,fun(v,w,wt,it-1));
//     else
//         return fun(v,w,wt,it-1);
// }

//Memoisation
// int fun(int v[],int w[],int wt,int it)
// {
//     if(it==0 || wt==0)
//         arr[it][wt]= 0;
//     if(arr[it][wt]!=-1)
//         return arr[it][wt];
//     if(w[it-1] <=wt)
//         return arr[it][wt]= max(v[it-1]+fun(v,w,wt-w[it-1],it-1) ,fun(v,w,wt,it-1));
//     else
//         return arr[it][wt]= fun(v,w,wt,it-1);
// }

//Top-down
// int fun(int v[], int w[], int wt, int it)
// {
//     for(int i=0;i<=it;i++)
//     {
//         for(int j=0;j<=wt;j++)
//         {
//             if(i==0 || j==0)
//                 arr[i][j]=0;
//         }
//     }
//     for(int i=1;i<=it;i++)
//     {
//         for(int j=1;j<=wt;j++)
//         {
//             if(w[i-1]<=j)
//                 arr[i][j]=max(v[i-1]+arr[i-1][j-w[i-1]], arr[i-1][j]);
//             else    
//                 arr[i][j]=arr[i-1][j];  
//         }
//     } 
//     return arr[it][wt];
// }

int main()  
{
    memset(arr,-1,sizeof(arr));
    int value[4]={60,100,120};
    int weight[4]={10,20,30};
    int max_wt=50;
    cout<<fun(value,weight,max_wt,4);
}
