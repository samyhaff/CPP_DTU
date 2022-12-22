#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    if (t == nullptr) return;
    displayTeams(t->left);
    if (t->nodeType == team) cout << t->name << endl;
    displayTeams(t->right);
}

// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    if (t == nullptr or t->nodeType == team) return 0;
    return 1 + matches(t->left) + matches(t->right);
}

// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    if (t == nullptr) return "";
    if (t->nodeType == team) return t->name;
    if (t->result == leftWin) return winner(t->left);
    else return winner(t->right);
}

// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    if (t == nullptr || t->nodeType == team) return false;
    if ((t->result == leftWin && t->left->name == teamName)
        || (t->result == rightWin && t->right->name == teamName))
        return true;
    return wonAnyMatch(t->left, teamName) || wonAnyMatch(t->right, teamName);
}
