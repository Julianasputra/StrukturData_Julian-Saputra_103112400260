#include <iostream>
#include <string>
#include <vector>

int main(){

    std::string kampus [] = {"universitas telkom","universitas indonesia","itb","ugm","universitas airlangga"};

    std::cout<<"daftar nama kampus :"<< std::endl;

    for(const std::string&namaKampus : kampus){
        std::cout<<"-"<<namaKampus<<std::endl;
    }
    return 0;
}