#include<iostream>
#include<vector>

using namespace std;

void printvec(vector<vector<int>> &v)
{
    for(vector<int> &i:v)
    {
        for(int &j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void markzero(vector<vector<int>> &v,vector<pair<int,int>> &pos)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==0){
                pos.push_back({i,j});
            }
        }
    }
}
bool check(vector<vector<int>> &v,int i,int j,int p)
{
    bool temp = true;
    int n=v.size();
    
    for(int x=0;x<n;x++)
    {
        if(v[i][x]==p) temp=false;
    }
    for(int x=0;x<n;x++)
    {
        if(v[x][j]==p) temp=false;
    }
    int rowStart = (i / 3) * 3;
    int colStart = (j / 3) * 3;
    for (int x = rowStart; x < rowStart + 3; x++) {
        for (int y = colStart; y < colStart + 3; y++) {
            if (v[x][y] == p)
                return false;
        }
    }
    
    return temp;

}
bool rec(vector<vector<int>> &v, vector<pair<int,int>> &pos, int k)
{
    if(k == pos.size())
    return true;

    int i = pos[k].first;
    int j = pos[k].second;

    for(int p = 1; p <= 9; p++)
    {
        if(check(v, i, j, p))
        {
            v[i][j] = p;
            if(rec(v,pos, k + 1))
                return true;
            v[i][j] = 0; 
        }
    }
    
    return false;
}

void solvesuduko(vector<vector<int>> &v)
{
    vector<pair<int,int>> pos;
    markzero(v,pos);
    int k=0;
    printvec(v);
    bool result=rec(v,pos,k);
    if(result) 
    {
        printf("THE SOLUTION IS\n");
        printvec(v);
    }
    else printf("NO SOLUTION");
}
int main()
{
    vector<vector<int>> v ={
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    solvesuduko(v);
}