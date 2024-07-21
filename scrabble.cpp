#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int dlugosc(string litery)
{
    if (litery.length() % 2 == 0)
    {
        return litery.length() / 2;
    }
    else
    {
        return litery.length() / 2 + 1;
    }
}

bool canFormSubstring(string sub, string litery)
{
    unordered_map<char, int> letterCount;
    
    for (char c : litery)
    {
        letterCount[c]++;
    }
    
    for (char c : sub)
    {
        if (letterCount[c] > 0)
        {
            letterCount[c]--;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    string slowo;
    string litery;
    
    cin >> slowo;
    cin >> litery;
    
    int minLength = dlugosc(litery);
    
    int wynik=0;

    for (int len = minLength; len <= slowo.length(); len++) {
        for (int i = 0; i <= slowo.length() - len; i++) {
            string temp = slowo.substr(i, len);
            if (canFormSubstring(temp, litery)) {
                wynik++;
            }
        }
    }

    cout << wynik;
}
