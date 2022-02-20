#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
int p[100][100];
//recursive
int rec(string a,string b,int al,int bl,int count)
{
    if(al==0 || bl==0)
        return count;
    if(a[al-1]==b[bl-1])
        count= rec(a,b,al-1,bl-1,count+1);
    else 
        count= max(count,max(rec(a,b,al,bl-1,0), rec(a,b,al-1,bl,0))); 
    return count;
}
//Topdown
int fun(string a,string b,int al,int bl)
{
    int max=0;
    for(int i=0;i<=al;i++)
    {
        t[i][0]=0;
    }
    for(int j=0;j<=bl;j++)
    {
        t[0][j]=0;
    }
    for(int i=1;i<=al;i++)
    {
        for(int j=1;j<=bl;j++)
        {
            if(a[i-1]==b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
                if(t[i][j]>max)
                    max=t[i][j];
            }
            else 
                t[i][j]=0;
        }
    }
    return max;
}

//Printing Longest common substring
string  print(string a,string b,int al,int bl)
{
    string ans="";
    int ti,tj,max_len=0;
    for (int i = 0; i <= al; i++)
    {
        p[i][0]=0;
    }
    for (int i = 0; i <= bl; i++)
    {
        p[0][i]=0;
    }
    for(int i=1;i<=al;i++)
    {
        for(int j=1;j<=bl;j++)
        {
            if(a[i-1]==b[j-1])
            {
                p[i][j]=1+p[i-1][j-1];
                if(max_len < p[i][j] )
                {
                    max_len=p[i][j];
                    ti=i;
                    tj=j;
                }
            }
            else 
                p[i][j]=0;
        }
    }
    // for(int i=0;i<=al;i++)
    // {
    //     for(int j=0;j<=bl;j++)
    //     {
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"ti="<<ti<<" " <<"tj="<<tj;
    int it=ti-p[ti][tj]; //position first char in a string of longest common substring
    for(int i=it;i<it+p[ti][tj];i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
    
}

int main()
{
    memset(t,-1,sizeof(t));
    memset(p,-1,sizeof(p));
    string a="abcdell";
    string b="kabclll";
    cout<<rec(a,b,7,7,0)<<" "<<fun(a,b,7,7)<<endl;
    cout<<print(a,b,7,7); //print longest common substring 
    return 0;
}
