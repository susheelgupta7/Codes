#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp(a,b) make_pair(a,b)
#define ll long long int
#define pb(a) push_back(a)
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,l,j,k,m,w,s1=0,s2=0;
        int ans[55];
        string s[55],length;
        cin>>length;
        l=length.size();
        s[0]=length;
        for(i=0;i<l;i++)
        ans[i]=0;
        for(i=1;i<l;i++)
        cin>>s[i];
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(s[i][j]=='N')           
                {
                    for(k=0;k<l;k++)
                    {
                        if(s[j][k]=='Y'&&s[i][k]=='Y') 
                        {
                            ans[j]++;
                            ans[i]++;
                            break;
                        }
                    }
                }
            }
        }
        for( i=0; i<l; i++ )
        {
            if(ans[i]>s1)
            {
                s1=ans[i];
                s2=i;
            }
        }
        cout<<s2<<" "<<s1<<endl;
    }
    return 0;
}