#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of Item:";
    cin>>n;
    int v[n],w[n];
    cout<<"Enter the value of all item:\n";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];

    }

    cout<<"Enter the weight of all item:\n";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];

    }
    int s;
    cout<<"Enter the size of knapsack: ";
    cin>>s;
    int dp[n+1][s+1];
    bool selected[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                selected[i][j]=false;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(w[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
                selected[i][j]=true;
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                selected[i][j]=true;
            }
        }
    }

    int i = n;
    int W=s;
    vector<int> selectedItems;
    while (i > 0 && W > 0) {
        if (selected[i][W]) {
            selectedItems.push_back(i - 1);
            W -= w[i - 1];
        } 
        i--;
    }
    reverse(selectedItems.begin(), selectedItems.end());


    cout<<"\n\nHere the table of all value :\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
    }
    cout<<"\nMaximum Value:"<<dp[n][s]<<endl;
    cout<<"Selecting items:";
    for(int i=0;i<selectedItems.size();i++)
    {
        cout<<selectedItems[i]<<" ";
    }

}



