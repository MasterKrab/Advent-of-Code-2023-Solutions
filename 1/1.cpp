#include <bits/stdc++.h>

using namespace std;

int searchCalibrationValue(string text)
{
    string result;

    int left = 0;
    while (!isdigit(text[left]))
    {
        left++;
    }

    result += text[left];

    int right = text.size() - 1;
    while (!isdigit(text[right]))
    {
        right--;
    }

    result += text[right];

    return stoi(result);
}

int main()
{
    ifstream file("input-1.txt");

    if (!file.is_open())
    {
        cerr << "File could not be opened";
        return 1;
    }

    vector<string> texts;

    string text;
    while (getline(file, text))
    {
        texts.push_back(text);
    }

    file.close();

    long long sum = 0;

    for (string text : texts)
    {
        sum += searchCalibrationValue(text);
    }

    cout << sum << "\n";
}