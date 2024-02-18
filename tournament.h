#pragma once
#include "tabulate.hpp"
#include <cstdlib>
#include <ctime>
#include "strategies.h"
#include "state.h"
#include <iomanip>
using namespace tabulate;

vector<string> strat = {"tft"/*, "ftft"*/, "007", "johnwick", "switcheroo", "coop", "def"};
unordered_map<string, strategy *> strat_map = {
    {"tft", new tft()},
    {"007", new agent007()},
    {"johnwick", new johnwick()},
    {"switcheroo", new switcheroo()},
    {"coop", new coop()},
    {"def", new def()}
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
        /*cout << left << setw(10) << "Player" << setw(25) << "Years of Sentence" << setw(30) << "Strategy Used" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << setw(10) << "A" << setw(25) << game.get_winscore('A') << setw(30) << game.strat_used('A') << endl;
        cout << setw(10) << "B" << setw(25) << game.get_winscore('B') << setw(30) << game.strat_used('B') << endl;
        cout << "-------------------------------------------------------------" << endl;
        if (winner == 'A') {
            cout << "A won the game by capitalizing on B's decision, getting them punished with " << game.get_punish('B') << " years." << endl;
        } else if (winner == 'B') {
            cout << "B won the game by capitalizing on A's decision, getting them punished with " << game.get_punish('A') << " years." << endl;
        } else {
            cout << "It's a tie. Both players receive " << game.get_winscore('A') << " years of punishment." << endl;
        }
        cout << endl;
        cout << endl;*/
        string round_str = to_string(round+1);
        string winner_str;
        if (winner == 'A') winner_str = "A";
        else if (winner == 'B') winner_str = "B";
        else winner_str = "Tie";
        string scoreA_str = to_string(game.get_score('A'));
        string scoreB_str = to_string(game.get_score('B'));
        tabs.add_row({round_str, winner_str, scoreA_str, scoreB_str, game.strat_used('A'), game.strat_used('B')});
    }
    else {
        cout << "Invalid strategy. " << endl;
        return;
    }
}

void tournament() {
    srand(time(nullptr));
    tabs.add_row({"Round", "Winner", "Winner's YOS", "Loser's YOS", "A's Strategy", "B's Strategy"});
    tabs[0].format().font_style({FontStyle::bold}).font_background_color(Color::blue).font_align(FontAlign::center);
    tabs[0][0].format().font_color(Color::white);
    tabs[0][1].format().font_color(Color::white);
    tabs[0][2].format().font_color(Color::white);
    tabs[0][3].format().font_color(Color::white);
    tabs[0][4].format().font_color(Color::white);
    tabs[0][5].format().font_color(Color::white);
    tabs.column(0).format().width(15);
    tabs.column(1).format().width(15);
    tabs.column(2).format().width(15);
    tabs.column(3).format().width(15);
    tabs.column(4).format().width(15);
    tabs.column(5).format().width(15);
    tabs.format().font_align({FontAlign::center});
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