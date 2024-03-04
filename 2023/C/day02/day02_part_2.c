#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE *file;
    file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Couldn't open file");
    }

    char buffer[1024];
    int gameId = 0;
    int maxR = 12, maxG = 13, maxB = 14;
    int sumOfGames;

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        ++gameId;

        char *currentToken = buffer;
        while(*currentToken++ != ':');
        currentToken = strtok(currentToken, ",;");

        bool gamePossible = true;

        int minRed = 0;
        int minGreen = 0;
        int minBlue = 0;
        
        while(currentToken){
            int quantity;
            char color[1024];

            if(sscanf(currentToken, "%d %s", &quantity, &color) == 2){

                if(strcmp(color, "red") == 0){
                    if(quantity > minRed){
                        minRed = quantity;
                    }
                }

                if(strcmp(color, "green") == 0){
                    if(quantity > minGreen){
                        minGreen = quantity;
                    }
                }
                
                if(strcmp(color, "blue") == 0){
                    if(quantity > minBlue){
                        minBlue = quantity;
                    }
                }
            }

            currentToken = strtok(NULL, ",;");
        }

        sumOfGames += minRed * minGreen * minBlue;
    }
    
    printf("resultof games-> %d\n", sumOfGames);
    fclose(file);

    return 0;
}