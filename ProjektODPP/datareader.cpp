#include "datareader.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

DataReader::DataReader() {
    iloscZadan = 0;
    iloscStanowisk = 4;
    iloscMaszyn = 2;
    iloscOperacji = 0;
    Czasy = vector <double>(iloscOperacji, 0);
    Klient = vector <string>(iloscZadan,"Klient");
    Numer_Klienta = vector <int>(iloscZadan, 0);
}
DataReader::~DataReader() {


}

bool DataReader::Odczyt_Pliku(string nazwa_pliku) {
    Linie_In.clear();
    Klient.clear();
    Numer_Klienta.clear();
    Czasy.clear();

    ifstream plik;
    plik.open(nazwa_pliku);
    if (!plik.good()) {
        cerr << "Brak pliku" << nazwa_pliku << endl;
        return false;
    }
    string temp;
    getline(plik, temp);
    int number_of_lines = 0;
    //    cout << temp << endl;
    int i = 0;
    char temp1;
    int Nowe_Zadanie;
    while (getline(plik, temp, ';')) {
        if (!plik.eof()) {
            int numer, czas;

            string nazwa;

            plik >> numer;
            plik >> temp1;
            getline(plik, nazwa, ';');
            Klient.push_back(nazwa);
            Numer_Klienta.push_back(numer);
            vector <string> linia;
            Nowe_Zadanie = number_of_lines + 1;
            auto s1 = to_string(Nowe_Zadanie);
            auto s2 = to_string(numer);
            linia.push_back(s1);
            linia.push_back(s2);
            linia.push_back(nazwa);

            for (int j = 0; j < iloscStanowisk; j++) {
                plik >> czas;
                //                cout << "Czas" << endl;
                Czasy.push_back(czas);
                auto s3 = to_string(czas);
                linia.push_back(s3);
                if (j != iloscStanowisk - 1)
                    plik >> temp1;
            }

            Linie_In.push_back(linia);

            ++number_of_lines;
        }
        iloscZadan = number_of_lines;
    }

    plik.clear();
    plik.close();
    return true;
    //
    //FlowProblem flowProblem(lZadan, lStanowisk, LMaszyn, czasy);
    //return flowProblem;
}

bool DataReader::Dodaj_Rekord(string nazwa_pliku, int NumerKlienta, string NazwaKlienta, int Czas1, int Czas2, int Czas3, int Czas4) {

    ofstream plik_zap;
    plik_zap.open(nazwa_pliku.c_str(), ios::app);
    if (!plik_zap.is_open()) {
        cerr << "Brak pliku \n" << endl;
        return false;
    }
    int Nowe_Zadanie = iloscZadan + 1;
    plik_zap << Nowe_Zadanie;
    plik_zap << ";";
    plik_zap << NumerKlienta;
    plik_zap << ";";
    plik_zap << NazwaKlienta;
    plik_zap << ";";
    plik_zap << Czas1;
    plik_zap << ";";
    plik_zap << Czas2;
    plik_zap << ";";
    plik_zap << Czas3;
    plik_zap << ";";
    plik_zap << Czas4;
    plik_zap << endl;
    iloscZadan++;
    plik_zap.close();

    Czasy.push_back(Czas1);
    Czasy.push_back(Czas2);
    Czasy.push_back(Czas3);
    Czasy.push_back(Czas4);
    Klient.push_back(NazwaKlienta);
    Numer_Klienta.push_back(NumerKlienta);

    vector <string> linia;
    auto s1 = to_string(Nowe_Zadanie);
    auto s2 = to_string(NumerKlienta);

    auto s3 = to_string(Czas1);
    auto s4 = to_string(Czas2);
    auto s5 = to_string(Czas3);
    auto s6 = to_string(Czas4);
    linia.push_back(s1);
    linia.push_back(s2);
    linia.push_back(NazwaKlienta);
    linia.push_back(s3);
    linia.push_back(s4);
    linia.push_back(s5);
    linia.push_back(s6);

    Linie_In.push_back(linia);


    return true;
}

bool DataReader::Formatowanie(string nazwa_pliku, vector <unsigned int> Permutacje) {
    ofstream plik_zap;
    plik_zap.open(nazwa_pliku.c_str());
    if (!plik_zap.is_open()) {
        cerr << "Brak pliku \n" << endl;
        return false;
    }

    plik_zap << iloscZadan << " " << iloscStanowisk << " " << iloscMaszyn << endl;

    for (int i = 0; i < Czasy.size(); i++) {
        plik_zap << Czasy.at(i) << " ";
    }

    plik_zap << endl;

    for (int i = 0; i < Permutacje.size(); i++) {
        plik_zap << Permutacje.at(i) << " ";
    }

    plik_zap << endl;
    return true;
}

bool DataReader::Wyniki(string nazwa_pliku, std::vector<double> Start, std::vector<double> Koniec, vector <unsigned int> Permutacje) {

    ofstream plik_zap;
    plik_zap.open(nazwa_pliku.c_str());
    if (!plik_zap.is_open()) {
        cerr << "Brak pliku \n" << endl;
        return false;
    }
    plik_zap << "Nr Klienta;Nazwa Klienta;Nr Etapu;Wykonujaca Ekipa;Czas trwania etapu;Czas rozpoczęcia;Czas zakonczenia";
    plik_zap << endl;
    unsigned int Wykonujaca_Ekipa = 0;
    for (vector <unsigned int> ::iterator it = Permutacje.begin(); it != Permutacje.end(); it++) {

        if (*it != 0) {
            unsigned int Operacja = *it;
            unsigned int Zadanie = 0;
            unsigned int Etap = 0;
            unsigned int temp = Operacja % iloscStanowisk;
            if (temp != 0) {
                Zadanie = floor(Operacja / iloscStanowisk) + 1;
                Etap = Operacja - (iloscStanowisk*(Zadanie - 1));
            }
            else {
                Zadanie = Operacja / iloscStanowisk;
                Etap = iloscStanowisk;
            }
            plik_zap << Numer_Klienta.at(Zadanie-1) << ";" << Klient.at(Zadanie-1) << ";";
            plik_zap << Etap << ";" << Wykonujaca_Ekipa << ';';
            plik_zap << Czasy.at(Operacja - 1);
            plik_zap << ";" << Start.at(Operacja);
            plik_zap << ";"<< Koniec.at(Operacja) << endl;

        }
        else {
            plik_zap << endl;
            Wykonujaca_Ekipa++;

        }
    }
    plik_zap << endl;

    plik_zap.close();
    Stworz_Wektor_Out(Start, Koniec, Permutacje);
    return true;
}

bool DataReader::Stworz_Wektor_In(string nazwa_pliku) {
    Linie_In.clear();
    ifstream plik;
    plik.open(nazwa_pliku);
    if (!plik.good()) {
        cerr << "Brak pliku" << nazwa_pliku << endl;
        return false;
    }
    string temp;
    getline(plik, temp);


    string temp1;
    while (getline(plik, temp1, ';')) {
        if (!plik.eof()) {
            string temp2, Numer, Klient, C1, C2, C3, C4;
            //getline(plik, temp1, ';');
            getline(plik, Numer, ';');
            getline(plik, Klient, ';');
            getline(plik, C1, ';');
            getline(plik, C2, ';');
            getline(plik, C3, ';');
            getline(plik, C4, '\n');

            vector <string> linia;
            linia.push_back(temp1);
            linia.push_back(Numer);
            linia.push_back(Klient);
            linia.push_back(C1);
            linia.push_back(C2);
            linia.push_back(C3);
            linia.push_back(C4);

            Linie_In.push_back(linia);
        }
    }
    plik.close();
    return true;
}

void DataReader::Stworz_Wektor_Out(vector <double>  Start, vector <double> Koniec, vector <unsigned int> Permutacje) {
    Linie_Out.clear();
    unsigned int Wykonujaca_Ekipa = 0;
    unsigned int Numer = 0;
    string Klient_temp;
    unsigned int Ekipa = 0;
    double Czas, C1, C2;
    int precision = 0;

    for (vector <unsigned int> ::iterator it = Permutacje.begin(); it != Permutacje.end(); it++) {

        if (*it != 0) {
            unsigned int Operacja = *it;
            unsigned int Zadanie = 0;
            unsigned int Etap = 0;

            unsigned int temp = Operacja % iloscStanowisk;
            if (temp != 0) {
                Zadanie = floor(Operacja / iloscStanowisk) + 1;
                Etap = Operacja - (iloscStanowisk*(Zadanie - 1));
            }
            else {
                Zadanie = Operacja / iloscStanowisk;
                Etap = iloscStanowisk;
            }
            Numer = Numer_Klienta.at(Zadanie - 1);
            Klient_temp = Klient.at(Zadanie - 1);
            Ekipa = Wykonujaca_Ekipa;
            Czas = Czasy.at(Operacja - 1);
            C1 = Start.at(Operacja);
            C2 = Koniec.at(Operacja);

            vector <string> linia;
            auto s0 = to_string(Operacja);
            auto s1 = to_string(Numer);
            auto s2 = to_string(Etap);
            auto s3 = to_string(Ekipa);
            auto s4 = toString(Czas, precision);
            auto s5 = toString(C1, precision);
            auto s6 = toString(C2, precision);
            linia.push_back(s0);
            linia.push_back(s1);
            linia.push_back(Klient_temp);
            linia.push_back(s2);
            linia.push_back(s3);
            linia.push_back(s4);
            linia.push_back(s5);
            linia.push_back(s6);

            Linie_Out.push_back(linia);

        }
        else {
            Wykonujaca_Ekipa++;

        }

    }
}

void DataReader::Nowy_Plik(string nazwa_pliku) {
    Linie_In.clear();
    Klient.clear();
    Numer_Klienta.clear();
    Czasy.clear();
    ofstream plik_zap;
    plik_zap.open(nazwa_pliku, ios::out);
    plik_zap << "Nr zamowienia;Nr klienta;Nazwa klienta;Czas Etap 1;Czas Etap 2;Czas Etap 3;Czas Etap 4" << endl;
    plik_zap.close();
}


vector<vector<string>> DataReader::getInputFileContents() {
    return Linie_In;
}

vector<vector<string>> DataReader::getOutputFileContents() {
    return Linie_Out;
}

unsigned int DataReader::getTaskCount() {
    return iloscZadan;
}

vector<double> DataReader::getTaskTimes() {
    return Czasy;
}

std::string DataReader::toString(const double value, const int n) {
    std::ostringstream out;
    out << std::setprecision(n) << fixed << value;
    return out.str();
}
