#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int size, l_v, r_v;
int area[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void input()
{
    cin>>size>>l_v>>r_v;

    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            cin>>area[r][c];
        }
    }
}

bool isUnion(int y, int x)
{
    for(int i=0; i<4; i++){
        int nx = x+ dx[i];
        int ny = y+ dy[i];

        if(nx>=0 && ny>=0 && nx<size && ny<size){
            if((l_v<= abs(area[y][x]-area[ny][nx])) && 
               (r_v>= abs(area[y][x]-area[ny][nx]))){
                return true;
               }
        }//if(nx>=0 && ny>=0 && nx<size && ny<size){
    }//for(int i=0; i<4; i++){

    return false;
}

bool connect(int y, int x, int ny, int nx)
{
    if((l_v<= abs(area[y][x]-area[ny][nx])) && 
       (r_v>= abs(area[y][x]-area[ny][nx]))){
                return true;
    }
    return false;
}

void search(int r, int c)
{
   stack<pair<int, int>> st, memory_st;
   st.push(make_pair(r,c));
   memory_st.push(make_pair(r,c));

   visit[r][c] = 1;
   int sum = 0;
   int cnt = 0;

   while(!st.empty())
   {
     int y = st.top().first;
     int x = st.top().second;
     st.pop();

     sum += area[y][x];
     cnt += 1;

     for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if( nx<0 || ny<0 || nx>=size || ny>=size) continue;
        if( visit[ny][nx] != 0) continue;

        if( connect(y, x, ny, nx) == true){
            visit[ny][nx] = 1;
            st.push(make_pair(ny,nx));
            memory_st.push(make_pair(ny,nx));
        }

     }

   }

   int value = sum/cnt;

   while(!memory_st.empty())
   {
        int y = memory_st.top().first;
        int x = memory_st.top().second;
        memory_st.pop();
        area[y][x] = value;
   }
}

void solution()
{
    int day= 0;
    bool next = true;
    while(next)
    {
        memset(visit, 0x00, sizeof(visit));
        next = false;

        for(int r=0; r<size; r++){
            for(int c=0; c<size; c++){
            if( visit[r][c] == 0 && isUnion(r,c) == true){
                    search(r,c);
                    next = true;
                }
            }
        }

        if(next == true) day++;

    }
    cout<<day;
}

int main()
{
    input();
    solution();

    return 0;
}