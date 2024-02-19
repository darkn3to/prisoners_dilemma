#pragma once
#include "tabulate.hpp"
#include <cstdlib>
#include <ctime>
#include "strategies.h"
#include "state.h"
#include <iomanip>
using namespace tabulate;

vector<string> strat = {"tft"/*, "ftft"*/, "007", "johnwick", "switcheroo", "coop", "def", "gamble"};
unordered_map<string, strategy *> strat_map = {
    {"tft", new tft()},
    {"007", new agent007()},
    {"johnwick", new johnwick()},
    {"switcheroo", new switcheroo()},
    {"coop", new coop()},
    {"def", new def()}, 
    {"gamble", new gamble()}
};
Table tabs;

void ls () {
    cout << "Available strategies:" << endl;
    for (const auto &s:strat) cout << "\u2022" << s << endl; // bullet point
}

void play(const string &strat1, const string &strat2, int round) {
    // strategies have been fed, now use the given strategy to update scores.
    state game;
    if (strat_map.find(strat1) != strat_map.end() && strat_map.find(strat2) != strat_map.end()) {
        strategy* s1 = strat_map[strat1];
        strategy* s2 = strat_map[strat2];
        game.set_strat(strat1, strat2);
        for (int i=0; i<10; ++i) {
            bool A_move = s1->decide(game.get_p2());
            bool B_move = s2->decide(game.get_p1());
            game.set_p(A_move, B_move);
        }
        char winner=game.calc_scores();
        string round_str = to_string(round+1);
        string winner_str;
        if (winner == 'A') winner_str = "A";
        else if (winner == 'B') winner_str = "B";
        else winner_str = "Tie";
        string scoreA_str = to_string(game.get_score('A'));
        string scoreB_str = to_string(game.get_score('B'));
        tabs.add_row({round_str, winner_str, scoreA_str, scoreB_str, game.strat_used('A'), game.strat_used('B')});
        if (winner_str=="Tie") {
            tabs[round+1][1].format().font_color(Color::yellow);
            tabs[round+1][2].format().font_color(Color::yellow);
            tabs[round+1][3].format().font_color(Color::yellow);
        }
        else if (winner_str=="A") {
            tabs[round+1][1].format().font_color(Color::green);
            tabs[round+1][2].format().font_color(Color::green);
            tabs[round+1][3].format().font_color(Color::red);
        }
        else if (winner_str=="B") {
            tabs[round+1][1].format().font_color(Color::green);
            tabs[round+1][2].format().font_color(Color::red);
            tabs[round+1][3].format().font_color(Color::green);
        }
    }
    else {
        cout << "Invalid strategy. " << endl;
        return;
    }
}

void tournament() {
    srand(time(nullptr));
    tabs.add_row({"Round", "Winner", "A's YOS", "B's YOS", "A's Strategy", "B's Strategy"});
    tabs.format().font_align(FontAlign::center);
    tabs[0].format().font_style({FontStyle::bold}).font_background_color(Color::blue);
    tabs.format().width(15);
    for (int round=0; round<20; ++round) {
        int n=strat.size();
        /*                             //manual selection of strategies. later...
        string strat1, strat2;
        ls();
        cin << strat1 << strat2;
        */
        string strat1=strat[(rand()%n)];
        string strat2=strat[(rand()%n)];
        play(strat1, strat2, round);
    }
    cout << tabs << endl;
    cout << endl;
    cout << "Press any key to exit...";
    while (std::cin.get() != '\n') {}
}