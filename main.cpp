#include <iostream>
#include <vector>
#include "solve.h"

using namespace std;

#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)

#define MAX_N 12

int main()
{
    int n;
    cin >> n;
    if(n > MAX_N) return 1;
    vector<int> nums(n, 0);
    rep(i,n){
        cin >> nums[i];
    }
    int tar;
    cin >> tar;

    solve(nums, tar);
    
    return 0;
}


