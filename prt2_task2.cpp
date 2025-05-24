#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> scheduleTasks(vector<string>& tasks, int cooldown) {
    unordered_map<string, int> lastTime;
    int currentTime = 0;
    vector<string> result;

    for_each(tasks.begin(), tasks.end(), [&](const auto& task) {
        if (lastTime.count(task) && currentTime <= lastTime[task] + cooldown)
            {
            int waitTime = lastTime[task] + cooldown - currentTime + 1;
            while (waitTime-- > 0) {
                result.emplace_back("idle");
                currentTime++;
                }
            }
        result.push_back(task);
        lastTime[task] = currentTime;
        currentTime++;
    });

    return result;
}

int main() {
    vector<string> tasks = {"A", "B", "C", "D"};
    int cooldown = 2;
    vector<string> schedule = scheduleTasks(tasks, cooldown);
    for (int i = 0; i < schedule.size(); i++) {
        cout << schedule[i];
        if (i != schedule.size() - 1) cout << " -> ";
    }

    return 0;
}