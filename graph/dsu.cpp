#include<bits/stdc++.h>
using namespace std;
int parent[1001];
int sz[1001];
void make_parent(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    return v;
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b)
{
int x=find_set(a);
int y=find_set(b);
if(sz[y]>sz[x])
swap(x,y);
parent[y]=x;
sz[x]+=sz[y];
}
int amin()
{

}