#include "datareader.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <list>
#include <string>
#include <cmath>


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
    ifstream plik;
    plik.open(nazwa_pliku);//.c_str());
    if (!plik.good()) {
        cerr << "Brak pliku " << nazwa_pliku << endl;
        return false;
    }
    string temp;
    getline(plik, temp);
    int number_of_lines = 0;
    cout << temp << endl;
    int i = 0;
    char temp1;
    while (getline(plik, temp, ';')) {
        if (!plik.eof()) {
            int numer, czas;
            string nazwa;

            plik >> numer;
            plik >> temp1;
            getline(plik, nazwa, ';');
            Klient.push_back(nazwa);
            Numer_Klienta.push_back(numer);

            for (int j = 0; j < iloscStanowisk; j++) {
                plik >> czas;
//                cout << "Czas" << endl;
                Czasy.push_back(czas);
                if (j != iloscStanowisk - 1)
                    plik >> temp1;
            }
            ++number_of_lines;
        }
        iloscZadan = number_of_lines;
    }
    plik.clear();
    plik.close();

    return true;
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
}

bool DataReader::Wyniki(string nazwa_pliku, vector <double>  Start, vector <double> Koniec, vector <unsigned int> Permutacje) {

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
            plik_zap << ";" << Start.at(Operacja-1);
            plik_zap << ";"<< Koniec.at(Operacja-1) << endl;

        }
        else {
            plik_zap << endl;
            Wykonujaca_Ekipa++;

        }
    }
    plik_zap << endl;

    plik_zap.close();
    return true;
}

bool DataReader::Stworz_Wektor_In(string nazwa_pliku) {
    ifstream plik;
    plik.open(nazwa_pliku);//.c_str());
    if (!plik.good()) {
        cerr << "Brak pliku " << nazwa_pliku << endl;
        return false;
    }
    string temp;
    getline(plik, temp);


    string temp1;
    while (getline(plik, temp1, ';')) {
        if (!plik.eof()) {
            string temp2, Numer, Klient, C1, C2, C3, C4;
            //getline(plik, temp2, ';');
            getline(plik, Numer, ';');
            getline(plik, Klient, ';');
            getline(plik, C1, ';');
            getline(plik, C2, ';');
            getline(plik, C3, ';');
            getline(plik, C4, '\n');

            vector <string> linia;
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

bool DataReader::Stworz_Wektor_Out(string nazwa_pliku) {
    ifstream plik;
    plik.open(nazwa_pliku);//.c_str());
    if (!plik.good()) {
        cerr << "Brak pliku " << nazwa_pliku << endl;
        return false;
    }
    string temp;
    getline(plik, temp);


    string temp1;
    int licznik = 0;;
    while (!plik.eof()) {

        string temp2, Numer, Klient, Etap, Ekipa, Czas, C1, C2;
        //getline(plik, temp2, ';');
        getline(plik, Numer, ';');
        if (!Numer.find("\n")) {
            Numer.erase(0, 1);
        }
        getline(plik, Klient, ';');
        getline(plik, Etap, ';');
        getline(plik, Ekipa, ';');
        getline(plik, Czas, ';');
        getline(plik, C1, ';');
        getline(plik, C2, '\n');

        vector <string> linia;
        linia.push_back(Numer);
        linia.push_back(Klient);
        linia.push_back(Etap);
        linia.push_back(Ekipa);
        linia.push_back(Czas);
        linia.push_back(C1);
        linia.push_back(C2);

        Linie_Out.push_back(linia);
    }

    Linie_Out.pop_back();

    plik.close();
    return true;


}

std::vector<std::vector<std::string>> DataReader::getInputFileContents() {
    return Linie_In;
}

std::vector<std::vector<std::string>> DataReader::getOutputFileContents() {
    return Linie_Out;
}

unsigned int DataReader::getTaskCount() {
    return iloscZadan;
}

std::vector<double> DataReader::getTaskTimes() {
    return Czasy;
}
