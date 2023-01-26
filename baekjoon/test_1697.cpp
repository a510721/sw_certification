#include <bits/stdc++.h>
using namespace std;
int N = 0;
int K = 0;

int K_MIN = 0;
int K_MAX = 100000;
int K_VISIT[100001] = {0,};

void input()
{
    //N = 5;
    //K = 17;
    cin>>N>>K;

}

void solve()
{
    queue<pair<int,int>> pos;//position, visit 
    pos.push(make_pair(N,0));
    K_VISIT[N] = 1;

    while(!pos.empty()){
        int x = pos.front().first;
        int cnt = pos.front().second;
        //cout<<x<<" "<<cnt<<endl;
        pos.pop();

        if( x == K){
            cout<<cnt;
            return;
        }

        int new_x = 0;
        new_x = x-1;
        if(new_x >= K_MIN && new_x<= K_MAX && K_VISIT[new_x]==0){
            K_VISIT[new_x] = 1;
            pos.push(make_pair(new_x,cnt+1));
        }

        new_x = x+1;
        if(new_x >= K_MIN && new_x<= K_MAX && K_VISIT[new_x]==0){
            K_VISIT[new_x] = 1;
            pos.push(make_pair(new_x,cnt+1));
        }

        new_x = x*2;
        if(new_x >= K_MIN && new_x<= K_MAX && K_VISIT[new_x]==0){
            K_VISIT[new_x] = 1;
            pos.push(make_pair(new_x,cnt+1));
        }
    }

}

int main()
{
    input();
    solve();

    return 0;
}