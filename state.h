#pragma once
#include <vector>
using namespace std;

class state {
    private: 
        vector<bool> p1, p2;
        string A_strat, B_strat; // to store the strategies employed by A and B.
        int A_sent, B_sent;      // to store the years of sentence for A and B. The person with more years of sentence loses.
    public: 
        state() : A_sent(0), B_sent(0) {}

        vector<bool> get_p1() {
            return p1;
        }
        vector<bool> get_p2() {
            return p2;
        }

        void set_p(bool p1, bool p2) {
            this->p1.push_back(p1);
            this->p2.push_back(p2);
        }

        void set_strat(const string &A_strat, const string &B_strat) {
            this->A_strat=A_strat;
            this->B_strat=B_strat;
        }

        inline int get_punish(char loser) {
            if (loser=='B') return this->B_sent;
            else return this->A_sent;
        }

        inline int get_score(char player) {
            if (player=='A') return this->A_sent;
            else return this->B_sent;
        }

        inline string strat_used(char winner) {
            if (winner=='A') return this->A_strat;
            else return this->B_strat;
        }

        char calc_scores() {
            for (int i=0; i<10; ++i) {
                if (this->p1[i]==true && this->p2[i]==true) {
                    this->A_sent+=4;
                    this->B_sent+=4;
                }
                else if (this->p1[i]==false && this->p2[i]==false) {
                    this->A_sent+=2;
                    this->B_sent+=2;
                }
                else if (this->p1[i]==true && this->p2[i]==false) {
                    this->A_sent+=5;
                    this->B_sent+=0;
                }
                else if (this->p1[i]==false && this->p2[i]==true) {
                    this->A_sent+=0;
                    this->B_sent+=5;
                }
            }
            if (this->A_sent > this->B_sent) return 'B';
            else if (this->A_sent < this->B_sent) return 'A';
            else return 'D';
        }
};