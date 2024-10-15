#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if there are at least 2 arguments
int checkArguments(int numOfArguments) {
   if (numOfArguments >=2) {
    printf("Arguments: true\n");
   }
   else {
    printf("Arguments: false\n");
   }
    return 1; //Easy
}

//Function to check if the first file exists
int checkFileExists(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if(file != NULL) { 
        printf("File Exists: true\n");
        fclose(file); //Segmentation fault (core dumped) error - Outside Help
    }
    else{
        printf("File Exists: false\n");
    }
    return 2; // Not too hard
}

// Function to scan and print file names
int printFileNames(int numberOfFiles, char **fileNames) {
    for (int i = 0; i < numberOfFiles; i++) {
        printf("File Name: %s\n", fileNames[i]);
    }
    return 0; //Easy
}

//Function to read and print from file 2
int readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char line[256];
    if(file != NULL){
        while (fgets(line, 256, file)) { //Reads and prints each line from file 2 (Outside Help how to use fgets - Colab Log)
        line[strcspn(line, "\n")] = '\0'; //why is there a space between all the names  ---------------------------------------------- (Outside Help)
        printf("Name: %s\n", line); 
        }
    }
    else{
        return 0;
    }
    fclose(file);
    return 3; //A little hard
}

//Function to read and print only 6 >= character words
int extractSample(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char line[256];
    int lineNumber = 1;  // Starts counting from 1
    if(file != NULL){
        // Read each line from the file
        while (fgets(line, 256, file)) {
            line[strcspn(line, "\n")] = '\0';
            // Check if the line has 6 or more characters
            if (strlen(line) >= 6) { //how to use strlen ----------------------------------------------------------------- (Outside Help)
                printf("Sample %d: %s\n", lineNumber, line);
            }
        lineNumber++;
        }
    }
    else{
        return 0;
    }
    fclose(file);
    return 4; //Hardest Function
}

int main(int argc, char **argv) {
    int numOfArguments = argc - 1; // Skips file name (pandas.c) (Outside Help - Colab Log)
    char **cmdLineArguments = argv + 1; // Skips file name (pandas.c) (Outside Help - Colab Log)
    checkArguments(numOfArguments);
    checkFileExists(cmdLineArguments[0]);
    printFileNames(numOfArguments, cmdLineArguments);
    if (numOfArguments >= 2)
        readFile(cmdLineArguments[1]);
    if (numOfArguments >= 3)
        extractSample(cmdLineArguments[2]);
    return 0;
}