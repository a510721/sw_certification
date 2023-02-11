#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int R,C;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

char MAP[11][11];
int VISTED[11][11][11][11] = {0, };
int RX, RY;
int BX, BY;

void input()
{
    //cin>>R>>C;//세로, 가로 

    // R = 5; C = 5;
    // MAP[1][1] = '#'; MAP[1][2] = '#'; MAP[1][3] = '#'; MAP[1][4] = '#'; MAP[1][5] = '#';
    // MAP[2][1] = '#'; MAP[2][2] = '.'; MAP[2][3] = '.'; MAP[2][4] = 'B'; MAP[2][5] = '#';
    // MAP[3][1] = '#'; MAP[3][2] = '.'; MAP[3][3] = '#'; MAP[3][4] = '.'; MAP[3][5] = '#';
    // MAP[4][1] = '#'; MAP[4][2] = 'R'; MAP[4][3] = 'O'; MAP[4][4] = '.'; MAP[4][5] = '#';
    // MAP[5][1] = '#'; MAP[5][2] = '#'; MAP[5][3] = '#'; MAP[5][4] = '#'; MAP[5][5] = '#';


    // R = 7; C = 7;
    // MAP[1][1] = '#'; MAP[1][2] = '#'; MAP[1][3] = '#'; MAP[1][4] = '#'; MAP[1][5] = '#'; MAP[1][6] = '#'; MAP[1][7] = '#';
    // MAP[2][1] = '#'; MAP[2][2] = '.'; MAP[2][3] = '.'; MAP[2][4] = '.'; MAP[2][5] = 'R'; MAP[2][6] = 'B'; MAP[2][7] = '#';
    // MAP[3][1] = '#'; MAP[3][2] = '.'; MAP[3][3] = '#'; MAP[3][4] = '#'; MAP[3][5] = '#'; MAP[3][6] = '#'; MAP[3][7] = '#';
    // MAP[4][1] = '#'; MAP[4][2] = '.'; MAP[4][3] = '.'; MAP[4][4] = '.'; MAP[4][5] = '.'; MAP[4][6] = '.'; MAP[4][7] = '#';
    // MAP[5][1] = '#'; MAP[5][2] = '#'; MAP[5][3] = '#'; MAP[5][4] = '#'; MAP[5][5] = '#'; MAP[5][6] = '.'; MAP[5][7] = '#';
    // MAP[6][1] = '#'; MAP[6][2] = 'O'; MAP[6][3] = '.'; MAP[6][4] = '.'; MAP[6][5] = '.'; MAP[6][6] = '.'; MAP[6][7] = '#';
    // MAP[7][1] = '#'; MAP[7][2] = '#'; MAP[7][3] = '#'; MAP[7][4] = '#'; MAP[7][5] = '#'; MAP[7][6] = '#'; MAP[7][7] = '#';


    //  R = 3; C = 5;
    //  MAP[1][1] = '#'; MAP[1][2] = '#'; MAP[1][3] = '#'; MAP[1][4] = '#'; MAP[1][5] = '#'; 
    //  MAP[2][1] = '#'; MAP[2][2] = 'O'; MAP[2][3] = 'B'; MAP[2][4] = 'R'; MAP[2][5] = '#'; 
    //  MAP[3][1] = '#'; MAP[3][2] = '#'; MAP[3][3] = '#'; MAP[3][4] = '#'; MAP[3][5] = '#';

    cin>>R>>C;//세로, 가로 
    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            cin>>MAP[r][c];

            if( MAP[r][c] == 'R'){
                RX = c;
                RY = r;
                MAP[r][c] == '.';
            } 

            if( MAP[r][c] == 'B'){
                BX = c;
                BY = r;
                MAP[r][c] == '.';
            } 
            
        }
    }

    //cout<<RX<<" "<<RY<<" "<<BX<<" "<<BY<< endl;

}

int search(int y, int x, int ny, int nx, int& distance, int color) //0=RED, 1=BLUE
{
    
    int ty = y + ny;
    int tx = x + nx;

    while(1)
    {
        if( MAP[ty][tx] == '#'){
            if(color==0){
               RY = ty - ny;
               RX = tx - nx;
            }
            else if(color == 1){
               BY = ty - ny;
               BX = tx - nx;
            }
            return 0;
        } 

        if( MAP[ty][tx] == 'O'){
            if(color==0){
               //RY = ty;
               //RX = tx;
               return 1;
            }
            else if(color == 1){
               //BY = ty;
               //BX = tx;
               return -1;
            }
        } 

        ty += ny;
        tx += nx;
        distance += 1;
    }
    return 0;
}

void solve()
{

    std::queue< tuple<int, int, int, int, int> > q; 
    q.push( make_tuple(RY, RX, BY, BX, 1));
    VISTED[RY][RX][BY][BX] = 1;

    //cout<<RY<<" "<<RX<<" "<<BY<<" "<<BX;

    while( !q.empty() )
    {
        tuple<int, int, int, int, int> t  = q.front();
        int red_y = get<0>(t);
        int red_x = get<1>(t);
        int blue_y = get<2>(t);
        int blue_x = get<3>(t);
        int cnt = get<4>(t);

        if(cnt>10){ 
            cout<<"-1";
            return;
        }
        q.pop();

        for(int n=0; n<4; n++){

            int rd = 0, bd = 0;
            int red_ret = search(red_y, red_x, dy[n], dx[n], rd, 0); //red
            int blue_ret = search(blue_y, blue_x, dy[n], dx[n], bd, 1);//blue

            if(RY == BY && RX == BX){
            
                if(rd>bd){ RX -= dx[n], RY -= dy[n]; }
                else{ BX -= dx[n], BY -= dy[n]; }
            
            }else{

                if( red_ret == 1 && blue_ret != -1){
                    cout<<cnt<<endl;
                    return;
                }else if( red_ret != 1 && blue_ret == -1 ){
                    continue;
                }else if( red_ret == 1 && blue_ret == -1){
                    continue;
                    // if(rd>bd){ 
                    //     continue; 
                    // }
                    // else{                     
                    //     cout<<cnt<<endl;
                    //     return;
                    //}
                }

            }

            //cout<<RX<<" "<<RY<<" "<<BX<<" "<<BY<< endl;
            if( VISTED[RY][RX][BY][BX] == 1) continue;
            q.push( make_tuple(RY, RX, BY, BX, cnt+1));
            VISTED[RY][RX][BY][BX] = 1;

        }

    }

    cout<<"-1";

}

int main()
{
    input();
    solve();
    return 0;
}