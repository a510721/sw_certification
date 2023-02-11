#include <bits/stdc++.h>
using namespace std;

int N = 0;
int work[16] = {0,};
int salary[16] = {0,};

void input()
{
    // N = 7;
    // work[1] = 3;  salary[1] = 10;
    // work[2] = 5;  salary[2] = 20;
    // work[3] = 1;  salary[3] = 10;
    // work[4] = 1;  salary[4] = 20;
    // work[5] = 2;  salary[5] = 15;
    // work[6] = 4;  salary[6] = 40;
    // work[7] = 2;  salary[7] = 200;
    
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>work[i]>>salary[i]; 
    }

}

void solve()
{
    queue<pair<int,int>> q; // pos, salary

    for(int n=1; n<=N; n++){
        if(n+work[n]<=N+1){
            q.push(make_pair(n+work[n],salary[n]) );
            //cout<<n<<" "<<work[n]<<" "<<salary[n]<<endl;
        }
        //q.push(make_pair)
    }

    int max_salary = 0;
    while( !q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        int idx = v.first;
        int wage = v.second;

        if(wage>max_salary){
            max_salary = wage;
        }

        for(int n=idx; n<=N; n++){
            if(n+work[n]<=N+1){
                q.push(make_pair(n+work[n], wage+salary[n]) );
            }
        }
    }

    cout<<max_salary;

}

int main()
{
    input();
    solve();

    return 0;
}