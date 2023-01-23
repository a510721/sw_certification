#include <bits/stdc++.h>
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(0); \
    cout.tie(0)


   void search(int T, int sum, int& match)
{
    for(int n = 1; n<=3; n++){
        int tot = sum+n; 
        if(tot==T){ 
            match += 1; 
            return;
        }
        else if(tot<T){ search(T, tot, match); }
        else{ return; }
    }
    
}

int main()
{
    int T = 0;
    int test_case = 0;
    std::cin>>test_case;

    for (int i=0; i<test_case; ++i){
        int answer = 0;
        std::cin>>T;
        search(T, 0, answer);
        std::cout<<answer<<std::endl;
    }

    return 0;
}