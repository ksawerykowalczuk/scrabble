#include <iostream>
#include <string>

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

bool czydasieulozyc(string sub, string litery)
{
    int letterCount[26] = {0};
    
    for (size_t i = 0; i < litery.length(); i++)
    {
        char c = litery[i];
        letterCount[c - 'a']++;
    }
    
    for (size_t i = 0; i < sub.length(); i++)
    {
        char c = sub[i];
        if (letterCount[c - 'a'] > 0)
        {
            letterCount[c - 'a']--;
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
    int wynik = 0;

    for (int len = minLength; len <= slowo.length(); len++) {
        for (int i = 0; i <= slowo.length() - len; i++) {
            string temp = slowo.substr(i, len);
            if (czydasieulozyc(temp, litery)) {
                wynik++;
            }
        }
    }

    cout << wynik;
    return 0;
}
