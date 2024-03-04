#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Function to find first string number in the lines
int FindFirstStringNumber(std::string line, int position, std::string textNumbers[]){
    //make 2 integers
    int wordPosition;
    int index = 0;

    //for every word in the textNumbers array
    for(int i = 1; i < 10; i++){
        //find the first match of a text number
        wordPosition = line.find(textNumbers[i]);

        //if the index of the position of the word is less then position of the index of the first found number
        //so it knows the word comes before the first number
        if(wordPosition < position && wordPosition != std::string::npos){
            //set the position to the wordPosition
            position = wordPosition;

            //set the index to the index of the first word it finds
            index = i;
        }        
    }

    //return the index
    return index;
}

//Function to find first string number in the lines
int FindLastStringNumber(std::string line, int position, std::string textNumbers[]){
    //make 2 integers
    int wordPosition;
    int index = 0;

    //for every word in the textNumbers array
    for(int i = 1; i < 10; i++){
        //find the last match of a text number
        wordPosition = line.rfind(textNumbers[i]);

        //if the index of the position of the word is greater then position of the index of the first found number
        //so it knows the word comes after the last number
        if(wordPosition > position && wordPosition != std::string::npos){
            //set the position to the wordPosition
            position = wordPosition;

            //set the index to the index of the last word it finds
            index = i;
        }        
    }

    //return the index
    return index;
}


int main() {
    //create stream of file AOC1.txt
    std::ifstream file("input.txt");

    //create list to store all numbers
    std::vector<int> numberList;

    //create list to store all textnumbers
    //added nothing in element[0] so it starts at 1
    std::string textNumbers[] = {"nothing", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    //create strings for lines and currentnumber
    std::string line;
    std::string currentNum;

    //create int for position of the index
    int position;
    int currentWordNum;

    //if file is open
    if(file.is_open()){
        //getlines of file and store string in line
        while(getline(file, line)){

            //get index of first number
            position = line.find_first_of("123456789");

            //call function for finding first stringnumber and store it
            currentWordNum = FindFirstStringNumber(line, position, textNumbers);

            //if we found the first word number
            if(currentWordNum > 0){
                //add string number value to currentnumber
                currentNum += std::to_string(currentWordNum);

            }else{
                //else add the first number to the currentnum
                currentNum += line[position];
            }            

            //get index of last number
            position = line.find_last_of("123456789");

            //call function for finding last stringnumber and store it
            currentWordNum = FindLastStringNumber(line, position, textNumbers);

            //if we found the last word number
            if(currentWordNum > 0){
                //add string number value to currentnumber
                currentNum += std::to_string(currentWordNum);

            }else{
                //else add the last number to the currentnum
                currentNum += line[position];
            }     

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

    //Print out the final number
    std::cout << "final number: " << finalNumber;
    
    return 0;
}