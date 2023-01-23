#include <bits/stdc++.h>
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0)

using namespace std;

int dx[4] = { 0, 1, 0, -1}; //북쪽, 동쪽, 남쪽, 서쪽
int dy[4] = {-1, 0, 1,  0};

void moveRobot(vector<vector<int>> &robot_map, int y, int x, int dir, int& clean)
{
   
    while(1){
        
       if( robot_map[y][x] == 0){
            robot_map[y][x] = 2;
            clean +=1;
            //cout<<clean<<" ";
       }    

        int d1 = robot_map[y-1][x];
        int d2 = robot_map[y][x+1];
        int d3 = robot_map[y+1][x];
        int d4 = robot_map[y][x-1];
        
        if(d1>0 && d2>0 && d3>0 && d4>0) {
            
            if( robot_map[y-dy[dir]][x-dx[dir]] == 1){ return; }
            else{ 
              y -= dy[dir];
              x -= dx[dir];
            }
        }else{

            //rotate
            if( dir == 0){ dir = 3; }
            else{ dir -= 1; }

            if (robot_map[y + dy[dir]][x + dx[dir]] == 0) {
              y += dy[dir];
              x += dx[dir];
			      }
        }

    }

}

void make_map(std::vector<std::vector<int>> &r_map)
{
    
    r_map[1][1] = 0;

}

int main()
{

  int kRow = 11; 
  int kCol = 10;
  
  int y = 7;
  int x = 4;
  int dir = 0;
  int clean = 0;

  cin >> kRow >> kCol >> y >> x >> dir;

  //map generation
  vector<vector<int>> robot_map(kRow,vector<int>(kCol,1));
  for (int r = 0; r < kRow; r++) {
    for (int c = 0; c < kCol; c++) {
        cin >> robot_map[r][c];
    }
  }

//   for (int r = 0; r < kRow; r++) {
//     for (int c = 0; c < kCol; c++) {
//         cout<< robot_map[r][c];
//     }
//     cout<<endl;
//   }
  moveRobot(robot_map, y, x, dir, clean);  

  cout<<clean;

  return 0;
}


// void make_map(std::vector<std::vector<int>> &r_map)
// {
    
//     r_map[1][1] = 0;

//     // for(int r = 0; r<r_map.size(); r++){
//     //     for(int c=0; c<r_map[r].size(); c++){
//     //         std::cout<<r_map[r][c];
//     //     }
//     //     std::cout<<std::endl;
//     // }

// }