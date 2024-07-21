#include <iostream>

using namespace std;

int dlugosc(string litery)
{
    if (litery.length()%2==0)
    {
        return litery.length()/2;
    }
    else
    {
        return litery.length()/2 + 1;
    }
    
}

int main()
{
    string slowo;
    string litery;
    string temp;
    cin >> slowo;
    cin >> litery;
    dlugosc(litery);
    for (int i = 0; i < slowo.length()-dlugosc(litery)-1; i++)
    {
        
    }
    
}