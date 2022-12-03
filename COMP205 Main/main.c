// Dorantes-Nikolaev, Bogdan Itsam
// 11/26/2022, COMP205-02 Systems Programming, HW1

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Defines
#define MAX_LEN 1000

// Function to get the frequency of one information and store it in the frequency array
void get_freq(char* sentence, const char* keyword, int* freq){
    // Get the length of the keyword
    int i, j, count;
    int len1 = strlen(sentence);
    int len2 = strlen(keyword);
    // Loop through the sentence
    count = 0;
    for (i=0; i<len1-len2; i++){
        for (j=0; j<len2; j++){
            if (sentence[i+j] != keyword[j]){
                break;
            }
        }
        // If the keyword is found, increase the count
        if (j == len2){
            count++;
            j = 0;
        }
    }
    // Store the count in the frequency array
    *freq = count;
}

// Function to get the frequency of all information and store in the frequency array
void collect_freq(char* sentence, char keywords[][100], int freq_keywords[]){
    int i;
    for (i=0; i<3; i++){
        get_freq(sentence, keywords[i], &freq_keywords[i]);
    }
}

// Function to collect the years found in the text
void get_years(char* word, int years[]){
    // Get the length of the word
    int i, j, count;
    int len1 = strlen(word);
    // Loop through the word
    count = 0;
    // Check if the word is a year
    for (i=0; i<len1-3; i++){
        for (j=0; j<4; j++){
            if (word[i+j] < '0' || word[i+j] > '9'){
                break;
            }
        }
        // If the word is a year, store it in the years array
        if (j == 4){
            // Convert the string to integer
            years[count] = atoi(&(word[i]));
            count++;
            j = 0;
        }
    }
    // Store the count in the frequency array
    years[count] = -1;
}

// Function to collect the years found in the text
int collect_years(char text[], int years[]){
    // Get the length of the text
    int i, j, count;
    int len = strlen(text);
    // Loop through the text
    count = 0;
    for (i=0; i<len; i++){
        if ((text[i] >= '0' && text[i] <= '9') || (text[i] == '-' && text[i+1] >= '0' && text[i+1] <= '9')){
            // Get the word
            for (j=i; j<len && ((text[j] >= '0' && text[j] <= '9') || text[j] == '-'); j++);
            char temp[j-i+1];
            // Copy the word to the temp array
            strncpy(temp, &text[i], j-i);
            // Add the null character to the end of the string
            temp[j-i] = '\0';
            // Get the years from the word
            get_years(temp, &years[count]);
            // Update the count
            count++;
            i = j;
        }
    }
    // Return the count
    return count;
}

// Function to get number of sentences and paragraphs
int collect_freq_par(char text[], char keywords[][100], int freq_keywords[]){
    // Get the length of the text
    int i, j, count1, count2;
    int len = strlen(text);
    int flag;
    // Loop through the text
    count1 = count2 = 0;
    flag = 0;
    // Loop through the text
    for (i=0; i<len; i++){
        // Check when a sentence ends
        if (text[i] == '.'){
            collect_freq(&text[flag], keywords, freq_keywords);
            flag = i+1;
            count1++;
        }
        // Check when a paragraph ends
        if (text[i] == '\n'){
            count2++;
        }
    }
    // Return the number of sentences and paragraphs
    return count2;
}

// Function to find the paragraph with the highest number of sentences
void find_par(int freq_par[], int n, int *max_par, int *max_count){
    int i;
    // Loop through the array
    *max_par = 0;
    *max_count = 0;
    for (i=0; i<n; i++){
        // Check if the current count is greater than the max count
        if (freq_par[i] > *max_count){
            *max_count = freq_par[i];
            *max_par = i;
        }
    }
}

// Main function
void main(){
    // Declare variables
    char file_name[50];
    char keywords[3][100];
    int freq_keywords[3];
    char text[MAX_LEN];
    int years[MAX_LEN];
    int freq_par[MAX_LEN];
    int n, max_par, max_count;
    int i;
    // Get the file name from the user
    printf("Enter file name: ");
    gets(file_name);
    // Get the information needed for the book (name, author, protagonist)
    printf("Enter keywords: \n");
    for (i=0; i<3; i++){
        gets(keywords[i]);
    }
    // Open the file
    FILE *fp = fopen(file_name, "r");
    // Check for file status
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    // Read the text from the file
    fgets(text, MAX_LEN, fp);
    // Get number of sentences and paragraphs
    n = collect_freq_par(text, keywords, freq_par);
    // Get the paragraph with the highest number of sentences
    find_par(freq_par, n, &max_par, &max_count);
    // Get the frequency of all information
    collect_freq(text, keywords, freq_keywords);
    // Get the years found in the text
    collect_years(text, years);
    // Print statistics
    // Loop through the number of paragraphs
    for (i=0; i<n; i++){
        printf("\nnum of sentences in this paragraph %d: %d", i, freq_par[i]);
    }
    // Paragraph with the highest number of sentences
    printf("\nparagraph %d", max_par, " has the highest number of sentences: %d", max_count);
    // Blank line
    printf("\n");
    // Number of first keyword
    printf("\nnum of %s: %d", keywords[0], freq_keywords[1]);
    // Number of second keyword
    printf("\nnum of %s: %d", keywords[1], freq_keywords[2]);
    // Number of third keyword
    printf("\nnum of %s: %d", keywords[2], freq_keywords[3]);
    // Print the years found in the text
    for (i=0; years[i] != -1; i++){
        printf("%d ", years[i]);
    }
    // Close the file
    fclose(fp);
}
//      C:/Users/bogdi/CLionProjects/untitled8/fahrenheit_451.txt