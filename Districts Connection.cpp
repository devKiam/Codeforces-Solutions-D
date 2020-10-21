#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
 
    ll t; cin>>t;
 
    while(t--)
    {
        ll n; cin>>n;
        vector<int> v;
        vector<int> connectedOrNot(n, 0);
        vector<int> adjList[n];
 
        for(int i=0; i<n; i++)
        {
            int x; cin>>x;
            v.push_back(x);
        }
 
        for(int i=0; i<v.size(); i++)
        {
            if(connectedOrNot[i]==1) continue;
 
            for(int j=0; j<v.size(); j++)
            {
                if(v[i] != v[j])
                {
                    adjList[i].push_back(j);
                    connectedOrNot[i] = 1;
                    connectedOrNot[j] = 1;
 
                    if(i>0) break;
                }
            }
        }
 
        int totalEdges = 0;
 
        for(int i=0; i<n; i++)
        {
            totalEdges += adjList[i].size();
        }
 
        if(totalEdges == n-1)
        {
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<adjList[i].size(); j++)
                {
                    cout<<i+1<<" "<<adjList[i][j] + 1<<endl;
                }
            }
 
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
