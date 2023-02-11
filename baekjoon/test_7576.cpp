#include <bits/stdc++.h>
using namespace std;
int C; // 가로 C 
int R; // 세로 R
int Bin[1000][1000] = {0,};
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};

vector<pair<int,int>> init;

void input()
{

    // C = 2;
    // R = 2; 

    // C = 6;
    // R = 5; 

    // Bin[0][0] = 1;  Bin[0][1] =  0; Bin[0][2] = 0;  Bin[0][3] =  0; Bin[0][4] = 0;  Bin[0][5] =  0;
    // Bin[1][0] = -1;  Bin[1][1] =  -1; Bin[1][2] = -1;  Bin[1][3] =  -1; Bin[1][4] = -1;  Bin[1][5] =  -1;
    // Bin[2][0] = 0;  Bin[2][1] =  0; Bin[2][2] = 0;  Bin[2][3] =  0; Bin[2][4] = 0;  Bin[2][5] =  0;
    // Bin[3][0] = 0;  Bin[3][1] =  0; Bin[3][2] = 1;  Bin[3][3] =  0; Bin[3][4] = 0;  Bin[3][5] =  0;
    // Bin[4][0] = 0;  Bin[4][1] =  0; Bin[4][2] = 0;  Bin[4][3] =  0; Bin[4][4] = 0;  Bin[4][5] =  0;
    
    cin>>C>>R;

    
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            cin>> Bin[r][c];
        }
    }

}

void solve()
{
    queue<tuple<int,int,int>> q;

    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(Bin[r][c] == 1){
                q.push(make_tuple(r,c,0));
            }
        }
    }

    int yy = 0;
    int xx = 0;
    int day = 0;

    while(!q.empty()){
        tuple<int,int,int> info;
        info = q.front();
        q.pop();

        yy = get<0>(info);
        xx = get<1>(info);
        day = get<2>(info);

        for(int n=0; n<4; n++){
            int ny = yy + dy[n];
            int nx = xx + dx[n];

            if(ny<0 || ny>R-1) continue;
            if(nx<0 || nx>C-1) continue;

            if( Bin[ny][nx] == 0){
                Bin[ny][nx] = 1;
                q.push( make_tuple(ny, nx, day+1));
            }
            
        }

    }

    int flag = 1;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            //cout<<Bin[r][c]<<" ";
            if(Bin[r][c] == 0){
               flag = 0;
            }
        }
        //cout<<endl;
    }

    if(flag == 0){ cout<<"-1";}
    else{ cout<<day; }



}

int main()
{
    input();
    solve();

    return 0;
}

