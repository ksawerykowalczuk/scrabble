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

int ilesiedaulozyc(string slowo, string litery, int indeks, int minLength)
{   
    bool czyznalazlem= false; 
    int licznik = 0;
    for (int i = indeks; i < slowo.length()-minLength; i++)
    {
        for (int j = 0; j < litery.length(); j++)
        {
            if (slowo[i] == litery[j])
            {
                litery[j] = ' ';
                licznik ++;
                czyznalazlem = true;
                break;
            }
            

        }
        if (!czyznalazlem)
        {
            break;
        }
        
    }
    
    return licznik;
}

int main()
{
    string slowo;
    string litery;

    cin >> slowo;
    cin >> litery;

    int minLength = dlugosc(litery);
    int wynik = 0;

    for (int i = 0; i <= slowo.length() - minLength; i++)
    {
        int temp = ilesiedaulozyc(slowo, litery, i, minLength);
        if (temp >= minLength)
        {
            wynik = wynik + temp -minLength +1;
        }
        
    }

    cout << wynik;
    return 0;
}
