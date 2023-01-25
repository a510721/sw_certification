#include <bits/stdc++.h>

using namespace std;

int area[200][200] = {0,};
int visited[200][200][31] = {0,};//map[y][x],[2:horse, monkey][3:ability]
int W = 0;
int H = 0;
int K = 0;

int dy[4] = {-1, 0, 1,  0};
int dx[4] = { 0, 1, 0, -1};
int h_dy[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int h_dx[8] = {-1,  1, -2,  2, -2, 2, -1, 1};



void input()
{
    // K = 1;
    // W = 4;
    // H = 4;
    // area[0][0] = 0; area[0][1] = 0; area[0][2] = 0; area[0][3] = 0;
    // area[1][0] = 1; area[1][1] = 0; area[1][2] = 0; area[1][3] = 0;
    // area[2][0] = 0; area[2][1] = 0; area[2][2] = 1; area[2][3] = 0;
    // area[3][0] = 0; area[3][1] = 1; area[3][2] = 0; area[3][3] = 0;

    // K = 2;
    // W = 5;
    // H = 2;
    // area[0][0] = 0; area[0][1] = 0; area[0][2] = 1; area[0][3] = 1; area[0][4] = 0;
    // area[1][0] = 0; area[1][1] = 0; area[1][2] = 1; area[1][3] = 1; area[1][4] = 0;

    cin>>K;
    cin>>W;
    cin>>H;

    for(int r=0; r<H; r++){
        for(int c=0; c<W; c++){
            cin>>area[r][c];
        }
    }

}

void solve()
{
    queue<tuple<int,int,int,int>> monkey;//<y,x>, <cnt,ability>
    monkey.push(make_tuple(0,0,0,0));
    visited[0][0][0] = 1;

    while(!monkey.empty())
    {
        tuple<int,int,int,int> trace = monkey.front(); 
        monkey.pop();

        int y = get<0>(trace);
        int x = get<1>(trace);
        int cnt = get<2>(trace);
        int ability = get<3>(trace);

        if( W-1 == x && H-1 ==  y ){
            cout<<get<2>(trace);
            return;
        }

        //move horse
        if( ability<K ){
            for(int n=0; n<8; n++){
                int my = y+h_dy[n];
                int mx = x+h_dx[n];

                if(my>=0 && mx>=0 && mx<W && my<H)
                {
                    if( area[my][mx] == 0 && visited[my][mx][ability+1] == 0){

                        visited[my][mx][ability+1] = 1;
                        monkey.push(make_tuple(my,mx,cnt+1,ability+1));   
                    }
                }   
            }
        }

        //move monkey
        for(int n=0; n<4; n++){
            int my = y+dy[n];
            int mx = x+dx[n];

            if(my>=0 && mx>=0 && mx<W && my<H)
            {
                if( area[my][mx] == 0 && visited[my][mx][ability] == 0){
                    visited[my][mx][ability] = 1;
                    monkey.push(make_tuple(my,mx,cnt+1,ability));
                    
                }
            }   
        }


    }
    cout<<-1;

}

int main()
{
    input();
    solve();

    return 0;
}