#include <iostream>
#include <vector>
#include <algorithm>

struct Player {
    std::string name;
    int score;
};

void rankPlayers(std::vector<Player>& players) {
    std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });

    int position = 1;
    for (int i = 0; i < players.size(); ++i) {
        if (i > 0 && players[i].score != players[i-1].score) {
            position++;
        }
        std::cout << position << " " << players[i].name << " " << players[i].score << "\n";
    }
}

int main() {
    std::vector<Player> players = {
        {"Ivan", 85},
        {"Maria", 92},
        {"Petro", 78},
        {"Olena", 92},
        {"Andriy", 85},
        {"Mykola", 120}
    };

    rankPlayers(players);
}