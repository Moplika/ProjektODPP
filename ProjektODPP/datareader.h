#ifndef DATAREADER_H
#define DATAREADER_H

#include <string>
#include <vector>

class DataReader {
public:
    bool Dodaj_Rekord(std::string nazwa_pliku, int NumerKlienta, std::string NazwaKlienta, int Czas1, int Czas2, int Czas3, int Czas4);
    bool Odczyt_Pliku(std::string nazwa_pliku);
    bool Formatowanie(std::string nazwa_pliku, std::vector <unsigned int> Permutacje);
    bool Wyniki(std::string nazwa_pliku, std::vector <int>  Start, std::vector <int> Koniec, std::vector <unsigned int> Permutacje);
    bool Stworz_Wektor_In(std::string nazwa_pliku);
    bool Stworz_Wektor_Out(std::string nazwa_pliku);
    DataReader();
    ~DataReader();

private:

    int iloscZadan;
    int iloscStanowisk;
    int iloscMaszyn;
    int iloscOperacji;
    std::vector <double> Czasy;
    std::vector <std::string> Klient;
    std::vector <int> Numer_Klienta;
    std::vector < std::vector <std::string> > Linie_In;
    std::vector < std::vector <std::string> > Linie_Out;

};

#endif // DATAREADER_H