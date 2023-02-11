#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int Arr[8];
bool Visited[8];
vector<int> v;

int N = 0;
void input()
{
    cin>>N;
    for(int n=0; n<N; n++){
        Arr[n] = n+1;
        Visited[n] = false;
    }

}

void print()
{
    for(int n=0; n<v.size(); n++){
        cout<<v[n]<<" ";
    }
    cout<<"\n";
}

void solve(int cnt)
{
    if(cnt == N){
        print();
        return;
    }


    for(int n=0; n<N; n++){
        if(Visited[n]==true) continue;

        Visited[n]= true;
        v.push_back(Arr[n]);
        solve(cnt+1);

        Visited[n]= false;
        v.pop_back();
    }

}

int main()
{
    input();
    solve(0);

    return 0;
}