#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class strategy {
    public:
        virtual bool decide(const vector<bool> &opponent) = 0;
};

class tft : public strategy {              // an eye for an eye
    public:
        bool decide(const vector<bool> &opponent) override {
            if (opponent.size()==0) return true;
            else if (opponent.back()==false) return false;
            else return true;
        }
};

class johnwick : public strategy {         // holds grudges
    private:
        int flag=0;
    public:
        bool decide(const vector<bool> &opponent) override {
            if (flag==0) return true;
            else if (opponent.back()==false || flag==1) {
                flag=1;
                return false;
            }
            return true;
        }
};

class switcheroo : public strategy {          // does the opposite
    public: 
        bool decide(const vector<bool> &opponent) override {
            if (opponent.size()==0) return true;
            else if (opponent.back()==false) return true;
            else return false;
        }
};

class coop : public strategy {               // the altruist
    public:
        inline bool decide(const vector<bool> &opponent) override {
            return true;
        }
};

class def : public strategy {                // the backstabber
    public:
        inline bool decide(const vector<bool> &opponent) override {
            return false;
        }
};

class agent007 : public strategy {               // the cautious
    private:
        unordered_map<bool, int> m;
    public:
        bool decide(const vector<bool> &opponent) override {
            if (opponent.size()==0) return true;
            else {
                for (auto it : opponent) m[it]++;
                int t=m[true], f=m[false];
                return (t>=f)?true:false;
            }
        }
};

class random : public strategy {             // the gambler
    public:
        bool decide(const vector<bool> &opponent) override {
            return (rand()%2==0)?true:false;
        }
};

class ftft : public strategy {             // not decided yet

};