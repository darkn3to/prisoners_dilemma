#pragma once

#include <vector>
using namespace std;

class state {
    private: 
        vector<bool> p1, p2;
        int A_score, B_score;
    public: 
        state() : A_score(0), B_score(0) {}

};