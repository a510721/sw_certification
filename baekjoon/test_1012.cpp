//유기농 배추
#include <bits/stdc++.h>
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0)

using namespace std;



struct position
{
    int x;
    int y;
};

void fill_area( std::array<std::array<int,50>, 50> &region )
{
    for(int n=0; n<region.size(); n++)
    {
         region[n].fill(0);     
    }
   
}

void fill_up(int x, int y, std::array<std::array<int,50>, 50>& r, std::stack<position>& next_pos){
    if(y<0) return;
    if(r[y][x] == 1){
        position p;
        p.x = x;
        p.y = y;
        next_pos.push(p);
    }
}

void fill_down(int x, int y, std::array<std::array<int,50>, 50>& r, std::stack<position>& next_pos){
    if(y>49) return;
    if(r[y][x] == 1){
        position p;
        p.x = x;
        p.y = y;
        next_pos.push(p);
    }
}

void fill_right(int x, int y, std::array<std::array<int,50>, 50>& r, std::stack<position>& next_pos){
    if(x>49) return;
    if(r[y][x] == 1){
        position p;
        p.x = x;
        p.y = y;
        next_pos.push(p);
    }
}


void fill_left(int x, int y, std::array<std::array<int,50>, 50>& r, std::stack<position>& next_pos){
    if(x<0) return;
    if(r[y][x] == 1){
        position p;
        p.x = x;
        p.y = y;
        next_pos.push(p);
    }
}

void fill_zero(int x, int y, std::array<std::array<int,50>, 50> &r, std::stack<position>& next_pos)
{

    r[y][x] = 0;
    
    fill_up(x, y-1, r, next_pos);
    fill_down(x, y+1, r, next_pos);
    fill_right(x+1, y, r, next_pos);
    fill_left(x-1, y, r, next_pos);

    while(!next_pos.empty()){
        position p = next_pos.top();
        next_pos.pop();

        fill_zero(p.x, p.y, r, next_pos);
    }

}

int main()
{
    int test_num = 0;
    int w = 0, h = 0, num = 0;
    cin>>test_num;

    for(int n=0; n<test_num; n++){

        cin>>w>>h>>num;

        std::array<std::array<int,50>, 50> area = {0,};
        fill_area(area);
        int x = 0, y = 0;
        for(int i=0; i<num; i++){
            cin>>x>>y;
            area[y][x] = 1;
        }

        int cnt = 0;
        for(int r=0; r<h; r++){
             for(int c=0; c<w; c++){
                 if( area[r][c] == 1){
                     std::stack<position> next;
                     fill_zero(c, r, area, next);
                     cnt++;
                 }
             }
         }        

         cout<<cnt<<endl;

    }

    return 0;
}


// int main()
// {
//     int test_num = 1;
//     int w = 10, h = 8, pos = 17;

//     std::array<std::array<int,50>, 50> area = {0,};

//     for(int n=0; n<test_num; n++){

//         fill_area(area);

//         set_area_test_case_1(area);

//         int cnt = 0;
//         for(int r=0; r<h; r++){
//             for(int c=0; c<w; c++){
//                 if( area[r][c] == 1){
//                     std::stack<position> next;
//                     fill_zero(c, r, area, next);
//                     cnt++;
//                 }
//             }
//         }        

//         cout<<cnt;

//     }//for(int n=0; n<test_num; n++){

//     return 0;
// }


// void set_area_test_case_1(std::array<std::array<int,50>, 50> &region)
// {
//     region[0][0] = 1;
//     region[0][1] = 1;
//     region[1][1] = 1;
//     region[2][4] = 1;
//     region[3][4] = 1;

//     region[5][4] = 1;
//     region[4][2] = 1;
//     region[4][3] = 1;
//     region[4][7] = 1;
//     region[4][8] = 1;

//     region[4][9] = 1;
//     region[5][7] = 1;
//     region[5][8] = 1;
//     region[5][9] = 1;
//     region[6][7] = 1;

//     region[6][8] = 1;
//     region[6][9] = 1;
// }