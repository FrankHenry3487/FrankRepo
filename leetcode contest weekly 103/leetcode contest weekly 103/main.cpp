//
//  main.cpp
//  leetcode contest weekly 103
//
//  Created by 张超 on 2018/9/23.
//  Copyright © 2018年 张超. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TopVotedCandidate {
public:
    vector<int> winner;
    vector<int> mt;
    
    TopVotedCandidate(vector<int> persons, vector<int> times): mt(times){
        winner.resize(mt.size());
        vector<int> cnt;
        cnt.resize(mt.size(), 0);
        int win_cnt = 0;
        
        //计算获胜者
        for (int i = 0; i < mt.size(); i++) {
            if (win_cnt <= ++cnt[persons[i]]) {
                winner[i] = persons[i];
                win_cnt = cnt[persons[i]];
            } else {
                winner[i] = winner[i - 1];
            }
        }
    }
    
    int q(int t) {
        return winner[upper_bound(mt.begin(), mt.end(), t) - mt.begin() - 1];
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
