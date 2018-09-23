//
//  main.cpp
//  leetcode contest weekly 103
//
//  Created by 张超 on 2018/9/23.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TopVotedCandidate {
public:
    vector<int> mp;
    vector<int> mt;
    
    TopVotedCandidate(vector<int> persons, vector<int> times): mp(persons), mt(times){
    }
    
    int q(int t) {
        int res[5001][2] = {0};  //0 for cont 1 for last time
        for (int i = 0; i < mt.size(); i++)
        {
            if (mt[i] <= t)
            {
                res[mp[i]][0]++;
                res[mp[i]][1] = (res[mp[i]][1] > mt[i]) ? res[mp[i]][1] : mt[i];
            }
            else
                break;
        }
        int residx = 0;
        int maxcnt = 0;
        int maxtime = 0;
        for (int i = 0; i < 5001; i++)
        {
            if(maxcnt < res[i][0])
            {
                maxcnt = res[i][0];
                maxtime = res[i][1];
                residx = i;
            }
            else if (maxcnt == res[i][0] && res[i][1] > maxtime)
            {
                maxtime = res[i][1];
                residx = i;
            }
            else
            {}
        }
        return residx;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> person = {0,1,1,0,0,1,0};
    vector<int> time = {0,5,10,15,20,25,30};
    TopVotedCandidate a(person, time);
    cout << a.q(3);
    cout << a.q(12);
    cout << a.q(25);
    cout << a.q(15);
    return 0;
}
