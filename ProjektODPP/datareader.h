#ifndef DATAREADER_H
#define DATAREADER_H

#include <string>
#include <vector>

class DataReader {
public:
    DataReader();
    ~DataReader();

    bool Dodaj_Rekord(std::string nazwa_pliku, int NumerKlienta, std::string NazwaKlienta, int Czas1, int Czas2, int Czas3, int Czas4);
    void Nowy_Plik(std::string nazwa_pliku);
    bool Odczyt_Pliku(std::string nazwa_pliku);
    bool Formatowanie(std::string nazwa_pliku, std::vector <unsigned int> Permutacje);
    bool Wyniki(std::string nazwa_pliku, std::vector <double>  Start, std::vector <double> Koniec, std::vector <unsigned int> Permutacje);
    bool Stworz_Wektor_In(std::string nazwa_pliku);
    void Stworz_Wektor_Out(std::vector <double>  Start, std::vector <double> Koniec, std::vector <unsigned int> Permutacje);

    std::vector<std::vector<std::string>> getInputFileContents();
    std::vector<std::vector<std::string>> getOutputFileContents();
    unsigned int getTaskCount();
    std::vector<double> getTaskTimes();


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

    std::string toString(const double value, const int n = 6);

};

#endif // DATAREADER_H
