#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Read(vector<int> &numbers, string &str, int &num)
{
    for (int i = 0; i < (int)str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            numbers.push_back(0); // при пробеле, поймем, что началось новое число
        }
        else
        {
            numbers.back() *= 10;
            numbers.back() += str[i] - '0'; // добавили новую цифру числа
        }
    }

    num = numbers[0];
    numbers.erase(numbers.begin());
}

void Sort(vector<int>& numbers)
{
    sort(numbers.begin(), numbers.end(), greater<int>());

    vector<int> numbers2;
    int num_back = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (num_back == numbers[i])
        {

        }
        else
        {
            numbers2.push_back(numbers[i]);
        }
        num_back = numbers[i];
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num = 0;
    vector<int> numbers = {0};
    string str;

    cout << "Введите числа через пробел: ";
    getline(cin, str);
    Read(numbers, str, num);
    Sort(numbers);

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }

    return 0;
}