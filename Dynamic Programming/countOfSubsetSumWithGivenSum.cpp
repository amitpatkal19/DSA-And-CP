//how many sets with given sum
#include<bits/stdc++.h> 
using namespace std;
//recursion 
// bool fun(int a[], int sum , int l)
// {
//     if(sum==0)
//         return true;
//     if(l<0) return false;
//     if(sum>=a[l]) 
//         return fun(a,sum,l-1) + fun(a,sum-a[l],l-1);
//     else 
//         return fun(a,sum,l-1); 
// }
//memoization
int mem[1001][1001];
int fun(int a[],int sum,int l)
{
    
    if(sum==0)
        return 1;
    if(l<0) return 0;
    if(mem[sum][l]!=-1)
        return mem[sum][l];
    if(sum>=a[l]) 
        return mem[sum][l]=fun(a,sum,l-1) + fun(a,sum-a[l],l-1);
    else 
        return mem[sum][l]=fun(a,sum,l-1); 
}

//topdown
int func(int a[],int sum,int l)
{
    for(int i=0;i<=l;i++) mem[0][i]=1;
    for(int i=1;i<=sum;i++) mem[i][0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(i>=a[j-1]) 
                mem[i][j]=mem[i][j-1] + mem[i-a[j-1]][j-1];
            else 
                mem[i][j]=mem[i][j-1]; 
        }
    }
    return mem[sum][l];
}
int main()
{
    memset(mem,-1,sizeof(mem));
    int arr[5]={3,7,9,1,10};
    //for recursion and memoisation
    cout<<fun(arr,10,4);
    //for topdown
    cout<<func(arr,10,5); 
    
}