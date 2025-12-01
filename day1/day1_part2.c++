#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int ktoi(const std::string &komanda){
    return std::stoi(komanda.substr(1));
}


int manuelno_prolazenje(int pocetak, char smjer, int korak){
    int brojac = 0;
    int pozicija = pocetak;

    for(int i = 0; i<korak; i++){
        if(smjer == 'L'){
            pozicija = (pozicija - 1 + 100)%100;
        }
        else{
            pozicija = (pozicija + 1) % 100;
        }
        if(pozicija == 0) brojac++;
    }

    return brojac;
}

int main(){

    std::ifstream file("input.txt");
    if(!file.is_open()){
        std::cout<<"greska u otvaranju fajla";
        return 0;
    }

    std::string input, linija;

    while(std::getline(file, linija)){
        input += linija;
    }

    file.close();

    std::regex komanda_regex("(L\\d{1,3}|R\\d{1,3})");

    std::sregex_iterator it(input.begin(), input.end(), komanda_regex);
    std::sregex_iterator end;

    int lozinka = 0;
    int pozicija = 50;


    while(it != end){
        std::string komanda = it->str();
        int korak = ktoi(komanda);

        lozinka += manuelno_prolazenje(pozicija, komanda[0], korak);

        if(komanda[0] == 'L') pozicija = (pozicija - korak % 100 + 100) % 100;
        else pozicija = (pozicija + korak % 100) % 100;

        it++;
    }

    std::cout<<"lozinka: "<<lozinka;

    return 0;
}