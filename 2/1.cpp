#include <bits/stdc++.h>

using namespace std;

struct GameSet
{
    int red = 0;
    int blue = 0;
    int green = 0;
};

const map<string, string> GAME_SET_KEYS = {
    {"RED", "red"},
    {"BLUE", "blue"},
    {"GREEN", "green"}};

const map<string, int> MAX_BOXES = {
    {GAME_SET_KEYS.at("RED"), 12},
    {GAME_SET_KEYS.at("BLUE"), 14},
    {GAME_SET_KEYS.at("GREEN"), 13}};

GameSet processGameSet(string raw)
{
    GameSet gameSet;

    int index = 0;

    while (index < raw.size())
    {
        int currentIndex = raw.find(",", index);

        if (currentIndex == string::npos)
            currentIndex = raw.size();

        string rawBox = raw.substr(index, currentIndex - index);

        int spaceIndex = rawBox.find(" ");

        int boxes = stoi(rawBox.substr(0, spaceIndex));
        string color = rawBox.substr(spaceIndex + 1, rawBox.size() - spaceIndex);

        if (color == GAME_SET_KEYS.at("RED"))
        {
            gameSet.red = boxes;
        }
        else if (color == GAME_SET_KEYS.at("BLUE"))
        {
            gameSet.blue = boxes;
        }
        else if (color == GAME_SET_KEYS.at("GREEN"))
        {
            gameSet.green = boxes;
        }

        index = currentIndex + 2;
    }

    return gameSet;
}

bool isValidGame(vector<GameSet> sets)
{
    for (GameSet set : sets)
    {
        if (set.red > MAX_BOXES.at(GAME_SET_KEYS.at("RED")))
            return false;

        if (set.blue > MAX_BOXES.at(GAME_SET_KEYS.at("BLUE")))
            return false;

        if (set.green > MAX_BOXES.at(GAME_SET_KEYS.at("GREEN")))
            return false;
    }

    return true;
}

int main()
{
    ifstream file("input-1.txt");

    if (!file.is_open())
    {
        cerr << "File could not be opened";
        return 1;
    }

    vector<vector<GameSet>> games;

    string line;
    while (getline(file, line))
    {
        vector<GameSet> sets;

        int index = line.find(": ") + 2;

        while (index < line.size())
        {
            int currentIndex = line.find(";", index);

            if (currentIndex == string::npos)
                currentIndex = line.size();

            string rawSet = line.substr(index, currentIndex - index);

            sets.push_back(processGameSet(rawSet));

            index = currentIndex + 2;
        }

        games.push_back(sets);
    }

    file.close();

    int count = 0;

    for (int i = 0; i < games.size(); i++)
    {
        if (isValidGame(games[i]))
            count += i + 1;
    }

    cout << count << "\n";
}