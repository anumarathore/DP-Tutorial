#include <bits/stdc++.h>
using namespace std;
int n;
int comp(int index,int a[])
{
    int ans=1,i;
    vector<int>v;
    vector<int>::iterator temp;
    v.push_back(a[index]);
    for(i=index+1;i<index+n;i++)
    {
        if(a[i]<v[0])
            v[0]=a[index];
        else if(a[i]>v[v.size()-1])
        {
            ans++;
            v.push_back(a[i]);
        }
 
        else
        {
            temp=upper_bound(v.begin(),v.end(),a[i]);
            *temp=a[i];
        }
    }
    return ans;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
 
    while(t--)
    {
        scanf("%d",&n);
        int a[2*n],l=0;
        vector<pair<int,int> >c(n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
            c[i].first=a[i];
            c[i].second=i;
        }
        sort(c.begin(),c.end());
        for(i=0;i<min(37,n);i++)
        {
            l=max(l,comp(c[i].second,a));
        }
        printf("%d\n",l);
    }
    return 0;
}