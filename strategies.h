#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class strategy {
    public:
        virtual bool decide(const vector<bool> &opponent) = 0;
        virtual void print() = 0;
};

class tft : public strategy {              // an eye for an eye
    public:
        bool decide(const vector<bool> &opponent) override {
            if (opponent.size()==0) return true;
            else if (opponent.back()==false) return false;
            else return true;
        }
        void print() {
            cout << "tft" << endl;
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
        void print() {
            cout << "johnwick" << endl;
        }
};

class switcheroo : public strategy {          // does the opposite
    public: 
        bool decide(const vector<bool> &opponent) override {
            if (opponent.size()==0) return true;
            else if (opponent.back()==false) return true;
            else return false;
        }
        void print() {
            cout << "switcheroo" << endl;
        }
};

class coop : public strategy {               // the altruist
    public:
        bool decide(const vector<bool> &opponent) override {
            return true;
        }
        void print() {
            cout << "coop" << endl;
        }
};

class def : public strategy {                // the backstabber
    public:
        bool decide(const vector<bool> &opponent) override {
            return false;
        }
        void print() {
            cout << "def" << endl;
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
        void print() {
            cout << "007" << endl;
        }
};

class ftft : public strategy {             // not decided yet

};