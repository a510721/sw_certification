#include <bits/stdc++.h>
using namespace std;

int insert_energy[11][11];
int energy[11][11];
vector<int> tree[11][11];

int N = 0;
int M = 0;
int K = 0;
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };;


void input() {
  cin >> N >> M >> K;

  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      cin >> insert_energy[r][c];
      energy[r][c] = 5;
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    tree[a][b].push_back(c);
  }
}

void spring_sumer()
{

    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){

            if(tree[r][c].size()  == 0) continue;

            int Die_Tree_Energy = 0;
            vector<int> temp;
            sort(tree[r][c].begin(), tree[r][c].end());
            
            for(int k=0; k<tree[r][c].size(); k++){      

                int age = tree[r][c][k];
                if( energy[r][c] >= age){
                    energy[r][c] = energy[r][c]- age;
                    temp.push_back(age+1);
                }else{
                    Die_Tree_Energy +=  Die_Tree_Energy + age/2;
                }
            }//for(int nn=0; nn<tree[r][c].size(); nn++){
            

            tree[r][c].clear();
            for(int k = 0; k<temp.size(); k++){
                tree[r][c].push_back( temp[k]);
            }
            energy[r][c] =  energy[r][c]+Die_Tree_Energy;
            
        }
    }//for(int r=1; r<N; r++){

}

void fall()
{

    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){

             if(tree[r][c].size()== 0)continue;

            for(int k=0; k<tree[r][c].size(); k++){ 

                int age = tree[r][c][k];
                if(age%5 == 0 ){
                    for(int d = 0; d<8; d++){
                        int ny = r+dy[d];
                        int nx = c+dx[d];

                        if(nx >= 1 && nx<= N && ny>=1 && ny <= N){
                            tree[c][r].push_back(1);
                        }
                        
                    }

                }
            }

        }
    }

}

void winter()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            energy[i][j] = energy[i][j] + insert_energy[i][j];
        }
    }
}

void solve() {

  for (int n=0; n<K; n++) {
        spring_sumer();
        fall();
        winter();
  }
  
    int Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Answer = Answer + tree[i][j].size();
        }
    }
    cout<<Answer<<endl;

}

int main() {

  input();

  solve();

  return 0;
}
