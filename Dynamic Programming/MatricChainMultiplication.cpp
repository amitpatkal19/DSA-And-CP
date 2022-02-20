#include<bits/stdc++.h>
using namespace std;
int mem[100][100];
//recursive...
int solve(int a[], int i, int j)
{
    if(i>=j)
        return 0;
    int min=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = solve(a,i,k) + solve(a,k+1,j) + a[i-1]*a[k]*a[j];
        if(min>temp)
            min=temp;
    }
    return min;
}
//memoization
int memo(int a[], int i, int j)
{
    if(i>=j)
        return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];
    int min=INT_MAX;
    int temp1,temp2;
    for(int k=i;k<j;k++)
    {
        int temp = solve(a,i,k) + solve(a,k+1,j) + a[i-1]*a[k]*a[j];
        if(min>temp)
            min=temp;
    }
    return mem[i][j]=min;
}
int main()
{
    memset(mem,-1,sizeof(mem));
    int a[5]={1,2,3,4,3};
    cout<<solve(a,1,4)<<" "<<memo(a,1,4);
}