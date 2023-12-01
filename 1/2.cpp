#include <bits/stdc++.h>

using namespace std;

const vector<string> WORD_DIGITS = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string searchDigit(string text, int index)
{
    if (isdigit(text[index]))
        return text.substr(index, 1);

    for (int i = 0; i < WORD_DIGITS.size(); i++)
    {
        if (text.substr(index, WORD_DIGITS[i].size()) == WORD_DIGITS[i])
        {
            return to_string(i + 1);
        }
    }

    // not found
    return "";
}

int searchCalibrationValue(string text)
{
    string a, b;

    int left = 0;
    while (a == "")
    {
        a = searchDigit(text, left);
        left++;
    }

    int right = text.size() - 1;
    while (b == "")
    {
        b = searchDigit(text, right);
        right--;
    }

    return stoi(a + b);
}

int main()
{
    ifstream file("input-2.txt");

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