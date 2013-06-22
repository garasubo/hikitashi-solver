
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
#include "solve.h"

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

static vector< map<pair<int,int>,string> >memo;
static int nums_size;

string itoa(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

string dp(Bunsu tar, int pos)
{
    cerr << tar.getBunshi() << "/" << tar.getBunbo() << " " << pos << endl;
    pair<int,int> tarp = pair<int,int>(tar.getBunshi(), tar.getBunbo());

    if(tar.getBunshi() > MAX_NUM || tar.getBunbo() > MAX_NUM
            || tar.getBunshi() < 0){
        return "";
    }
    if(pos>=(int)memo.size()) return "";
    if(memo[pos].find(tarp)!=memo[pos].end()){
        return memo[pos][tarp];
    }
    rep(i,nums_size) rep2(i,1,memo.size()){
        if((pos&i) > 0) continue;
        for(auto it=memo[i].begin();it!=memo[i].end();it++){
            if(it->first==tarp) return it->second;

            Bunsu btmp = Bunsu(it->first.first, it->first.second);

            string tmp;
            
            tmp = dp(tar - btmp, pos|i);
            if(tmp!=""){
                cerr << "hit" << endl;
                return (memo[pos|i][tarp]= "(" + tmp +"+"+it->second+")");
            }

            tmp = dp(tar / btmp, pos|i);
            if(tmp!=""){
                cerr << "hit" << endl;
                return (memo[pos|i][tarp] = tmp + "*" + (*it).second );
            }

            tmp = dp(tar * btmp, pos|i);
            if(tmp!=""){
                cerr << "hit" << endl;
                return (memo[pos|i][tarp] = tmp + "/" + (*it).second );
            }
        }
    }
    return (memo[pos][tarp]="");
}

void solve(vector<int> nums, int tar)
{
    memo.resize( 1 << nums.size(), map<pair<int,int>,string>() );
    rep(i,nums.size()){
        int tar = 1 << i;
        memo[tar][pair<int,int>(nums[i],1)] = itoa(nums[i]);
    }
    nums_size = nums.size();
    
    cout << dp(Bunsu(tar), 0) << endl;
}


