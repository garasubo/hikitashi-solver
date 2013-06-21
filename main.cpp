#include <queue>
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <math.h>
#include <list>
#include <set>

#define INF (1 << 29)
#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define squere(x) ((x)*(x))
#define EPS 1e-20

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

#define MAX_NUM 20000
#define MAX_N 12

static vector< map<int,string> > memo;
static int nums[MAX_N];
static int nums_size ;

string itoa(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

void memo_set(int pos, int num, string num_str){
    rep2(i,1,(1 << nums_size)){
        memo[pos|i][num] = num_str;
    }
}

void memo_set_disable(int pos, int num)
{
    rep2(i,1,(1 << nums_size)){
        memo[pos&i][num] = "-";
    }
}

string dp(int tar, int pos)
{
    cerr << tar << " " << pos << endl;
    if(tar < 0 || tar >= MAX_NUM || pos <= 0) return "-";
    if(memo[pos][tar]!=""){
        return memo[pos][tar];
    }

    
    rep(i,nums_size*2) rep2(j,1,(1 << nums_size)){
        if((pos|j) > pos || pos==j) continue;
        rep2(k,1,MAX_NUM){
            if(memo[j][k]=="" || memo[j][k]=="-") continue;
            
            // add 
            cerr << "add" << endl;
            string tmp = dp(tar-k, pos&j);
            if(tmp !="-"){
                memo_set(pos, tar, "(" + tmp + "+" + memo[j][k] + ")");
                goto dp_end;
            }
            
            // mult
            if(tar%k==0){
                cerr << "mult" << endl;
                tmp = dp(tar/k, pos&j);
                if(tmp !="-"){
                    memo_set(pos, tar, tmp + "*" + memo[j][k] );
                    goto dp_end;
                }
            }

            // div
            cerr << "div" << endl;
            tmp = dp(tar*k, pos&j);
            if(tmp !="-"){
                memo_set(pos, tar, tmp + "/" + memo[j][k]);
                goto dp_end;
            }
        }
    }
    
    memo[pos][tar]="-";
    dp_end:
    return memo[pos][tar];
}
int main()
{
    cin >> nums_size;
    if(nums_size > MAX_N) return 1;
    rep(i,nums_size){
        cin >> nums[i];
    }
    int tar;
    cin >> tar;
    
    memo.resize(1 << nums_size,vector<string>(MAX_NUM+10,""));
    rep(i,nums_size)
        memo_set((1 << nums_size) - 1 - (1 << i), nums[i],string(itoa(nums[i])));

    cerr << "start " << tar << " " << nums_size << endl;
    cout << dp(tar,(1 << nums_size) - 1) << endl;

    return 0;
}


