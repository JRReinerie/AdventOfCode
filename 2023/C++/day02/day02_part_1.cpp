#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

std::string GetAllSets(std::string currentLine);

int main(){

    std::ifstream file("input.txt");

    std::vector<std::string> sets;

    std::string currentLine;
    std::string id;
    //int id = 1;

    if(file.is_open()){
        while(getline(file, currentLine)){
            
            GetAllSets(currentLine);

        }
    }


    return 0;
}

std::string GetAllSets(std::string currentLine){
    int position;
    int position2;
    std::string result;
    std::string result2;


    for(int i = 0; i < 5; i++){
        position = currentLine.find(": ");
        result = currentLine.substr(position);

        position2 = result.find("; ");
        result2 = result.substr(position2, position2);
        
    }

    std::cout << "position -> " << position2 << std::endl;
    std::cout << "substring -> " << result2 << std::endl;
    
}