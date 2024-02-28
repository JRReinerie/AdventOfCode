#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    //create stream of file AOC1.txt
    std::ifstream file("input.txt");

    //create list to store all numbers
    std::vector<int> numberList;

    //create strings for lines and currentnumber
    std::string line;
    std::string currentNum;

    //create int for position of the index
    int position;
    
    //if file is open
    if(file.is_open()){
        //getlines of file and store string in line
        while(getline(file, line)){

            //get index of first number
            position = line.find_first_of("123456789");

            //add the value of first number found to currentNumber as a string
            currentNum += line[position];

            //get index of last number
            position = line.find_last_of("123456789");

            //add the value of last number found to currentNumber as a string
            currentNum += line[position];

            //add the total vlaue of the numbers combined and converts it to integer
            //and pushes it into the array
            numberList.push_back(stoi(currentNum));

            //clear lines and numbers so its set to 0
            line.clear();
            currentNum.clear();
        }

        //properly close the file
        file.close();
    }

    //create variable for the final number
    int finalNumber = 0;

    //loops through the array numberList
    for(int i = 0; i < numberList.size(); i++){
        //sums up the values in array numberList and add it to finalNumber
        finalNumber += numberList.at(i);
    }

    //Print the outcome
    std::cout << "final number: " << finalNumber;
    
    return 0;
}