#include <bits/stdc++.h>
using namespace std;
int mem[100][100];
int t[1001][1001];
int p[100][100];
//recursive
int rec(int a[],int b[],int al,int bl)
{
    if(al==0 || bl==0)
        return 0;
    if(a[al-1]==b[bl-1])
        return 1+rec(a,b,al-1,bl-1);
    else 
        return max(rec(a,b,al,bl-1), rec(a,b,al-1,bl)); 
}
//memoisation
int memo(int a[],int b[],int al,int bl)
{
    if(al==0 || bl==0)
        return 0;
    if(mem[al][bl]!=-1)
        return mem[al][bl];
    if(a[al-1]==b[bl-1])
        return mem[al][bl]=1+memo(a,b,al-1,bl-1);
    else 
        return mem[al][bl]=max(memo(a,b,al,bl-1), memo(a,b,al-1,bl)); 
}
//Topdown
int fun(int a[],int b[],int al,int bl)
{
    for(int i=0;i<=100;i++)
    {
        t[0][i]=0;
        t[i][0]=0;
    }
    for(int i=1;i<=al;i++)
    {
        for(int j=1;j<=bl;j++)
        {
            if(a[i-1]==b[j-1])
                t[i][j]=1+t[i-1][j-1];
            else 
                t[i][j]=max(t[i-1][j] , t[i][j-1]);
        }
    }
    return t[al][bl];
}
//Printing Longest common subsequence
vector<int> print(int a[],int b[],int al,int bl)
{
    vector<int> v;
    for(int i=0;i<=al;i++)
    {
          p[0][i]=0;
          p[i][0]=0;  
    }
    for(int i=1;i<=al;i++)
    {
        for(int j=0;j<=bl;j++)
        {
            if(a[i-1]==b[j-1])
                p[i][j]=1+p[i-1][j-1];
            else
                p[i][j]=max( p[i-1][j] , p[i][j-1]);
        }
    }
    //printing p matrix
    // for(int i=0;i<=al;i++)
    // {
    //     for(int j=0;j<=bl;j++)
    //     {
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int temp=p[al][bl],m=al, n=bl; 
    while(temp)
    {
        if(a[m-1]==b[n-1])
        {
            m--;
            n--;
            v.push_back(a[m]);
            temp=p[m][n];
        }
        else 
        {
            if(p[m-1][n]>p[m][n-1])
            {
                m--;
            }
            else
                n--;
        }
    }
    return v;
}
int main()
{
    memset(mem,-1,sizeof(mem));
    memset(t,-1,sizeof(t));
    memset(p,-1,sizeof(p));
    int a[5]={1,2,4,5,6};
    int b[5]={1,3,2,5,6};
    cout<<rec(a,b,5,5)<<" "<<memo(a,b,5,5)<<" "<< fun(a,b,5,5)<<endl;
    cout<<"Longest Common Subsequence--> ";
    vector<int> v=print(a,b,5,5);
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}
