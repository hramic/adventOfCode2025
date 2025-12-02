#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

long int sum = 0;

bool check_if_invalid(long int id){

    std::string sid = std::to_string(id);
    if(sid.size()%2!=0) return false;

    size_t pola = sid.size()/2;

    return sid.substr(0, pola) == sid.substr(pola);
}


int main(){

    std::cout<<"radi li ovo";

    std::ifstream file("input.txt");

    std::stringstream buffer;
    buffer<<file.rdbuf();

    std::string content = buffer.str();
    file.close();

    std::stringstream ss(content);
    std::string substr;
    std::vector<std::string> IDs;

    while(std::getline(ss, substr, ',')){
        IDs.push_back(substr);
    }
    int suma = 0;
    for(int i = 0; i<IDs.size(); i++){
        size_t pozicija_ = IDs.at(i).find('-');
        if(IDs.at(i)[0] != '0'){
            long int prvi_u_nizu = std::stol(IDs.at(i).substr(0, pozicija_));
            long int zadnji_u_nizu = std::stol(IDs.at(i).substr(pozicija_ + 1));
            for(int j = prvi_u_nizu; j<=zadnji_u_nizu; j++){
                if(!check_if_invalid(j)) suma += j;
            }
        }
    }
    std::cout<<"suma invalidnih IDijeva: "<<suma;
    return 0;
}