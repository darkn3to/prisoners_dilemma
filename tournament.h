#pragma once

#include <cstdlib>
#include <ctime>
#include "strategies.h"
#include "state.h"
#include <memory>

vector<string> strat = {"tft"/*, "ftft"*/, "007", "johnwick", "switcheroo", "coop", "def"};
unordered_map<string, strategy *> strat_map = {
    {"tft", new tft()},
    {"007", new agent007()},
    {"johnwick", new johnwick()},
    {"switcheroo", new switcheroo()},
    {"coop", new coop()},
    {"def", new def()}
};

void ls () {
    cout << "Available strategies:" << endl;
    for (const auto &s:strat) cout << L"\x2022" << s << endl; // bullet point
}

void play(const string &strat1, const string &strat2) {
    // strategies have been fed, now use the given strategy to update scores.
    state game;
    if (strat_map.find(strat1) != strat_map.end() && strat_map.find(strat2) != strat_map.end()) {
        strategy* s1 = strat_map[strat1];
        strategy* s2 = strat_map[strat2];
        
        /*bool A_move = s1->decide(game.p2);
        bool B_move = s2->decide(game.p1);*/
        s1->print();
        s2->print();
    }
    else {
        cout << "Invalid strategy. " << endl;
        return;
    }
    /*game.p1.push_back();   //idiota! do not try to access private members from outside the class
    game.p2.push_back();*/
}

void tournament() {
    srand(time(nullptr));
    for (int round=0; round<20; ++round) {
        int n=strat.size();
        /*                             //manual selection of strategies. later...
        string strat1, strat2;
        ls();
        cin << strat1 << strat2;
        */
        string strat1=strat[(rand()%n)];
        string strat2=strat[(rand()%n)];
        play(strat1, strat2);
    }
}
