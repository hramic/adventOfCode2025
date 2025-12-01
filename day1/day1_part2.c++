#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int ktoi(const std::string &komanda){
    return std::stoi(komanda.substr(1));
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
        if(komanda[0] == 'R') pozicija = (pozicija + korak) % 100;
        else pozicija = (pozicija - korak + 100) % 100;
        if(pozicija == 0) lozinka++;
        it++;
    }

    std::cout<<"lozinka: "<<lozinka;

    return 0;
}