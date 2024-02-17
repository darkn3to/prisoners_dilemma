#include <cstdlib>
#include <ctime>
#include "state.h"
using namespace std;

vector<string> strat = {"tft", "ftft", "007", "johnwick", "switcheroo", "echo", "coop", "def"};

void ls () {
    cout << "Available strategies:" << endl;
    for (const auto &s:strat) cout << L"\x2022" << s << endl; // bullet point
}

void play(const string &strat1, const string &strat2) {
    // strategies have been fed, now use the given strategy to update scores.
    state game;

}

void tournament() {
    srand(time(nullptr));
    for (int round=0; round<20; ++round) {
        int n=strat.size();
        /*
        string strat1, strat2;
        ls();
        */
        string strat1=strat[(rand()%n)];
        string strat2=strat[(rand()%n)];
        play(strat1, strat2);
    }
}
