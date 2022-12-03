// Library functions to work on strings
#include <string.h>
// Library functions to work on files
#include <stdio.h>
// Library functions to work on memory
#include <stdlib.h>
// isdigit() function
#include <ctype.h>


// Gets the frequency of one information and stores in the frequency array
void get_freq(char* sentence, const char* keyword, int* freq){
    // Variable declarations and initializations
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    // Looping through the sentence
    while(sentence[i] != '\0'){
        // If the character is a space, then the count is reset
        if(sentence[i] == ' '){
            count = 0;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(sentence[i])){
            count = 0;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(sentence[i])){
            count++;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(count == strlen(keyword)){
            freq[k]++;
            count = 0;
        }
        // If the character is the same as the keyword, then the frequency is increased
        if(sentence[i] == keyword[j]){
            j++;
        }
        // If the character is not the same as the keyword, then the count is reset
        else{
            j = 0;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(j == strlen(keyword)){
            freq[k]++;
            j = 0;
        }
        // If the character is a space, then the count is reset
        if(sentence[i] == ' '){
            k++;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(sentence[i])){
            k++;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(sentence[i])){
            k++;
        }
        // Incrementing the index
        i++;
    }
}

// Gets the frequency of all information and stores in the frequency array
void collect_freq(char* sentence, char keywords[][100], int* freq_keywords[]){
    // Variable declarations and initializations
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    // Looping through the sentence
    while(sentence[i] != '\0'){
        // If the character is a space, then the count is reset
        if(sentence[i] == ' '){
            count = 0;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(sentence[i])){
            count = 0;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(sentence[i])){
            count++;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(count == strlen(keywords[j])){
            freq_keywords[j][k]++;
            count = 0;
        }
        // If the character is the same as the keyword, then the frequency is increased
        if(sentence[i] == keywords[j][k]){
            k++;
        }
        // If the character is not the same as the keyword, then the count is reset
        else{
            k = 0;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(k == strlen(keywords[j])){
            freq_keywords[j][k]++;
            k = 0;
        }
        // If the character is a space, then the count is reset
        if(sentence[i] == ' '){
            j++;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(sentence[i])){
            j++;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(sentence[i])){
            j++;
        }
        // Incrementing the index
        i++;
    }
}
// Collects the years found in the text
void get_years(char* word, int* years[]){
// Variable declarations and initializations
    int year = 0;
    int index = 0;
    // Looping through the word
    for(int i = 0; i < strlen(word); i++){
        // If the character is a digit, then the year is increased by the digit
        if(isdigit(word[i])){
            year = year * 10 + (word[i] - '0');
        }
        // If the character is not a digit, then the year is added to the array
        else{
            years[index] = year;
            index++;
            year = 0;
        }
    }
}

// Calls get_years for each word
int collect_years(char* txt[], int years[]){
    // Variable declarations and initializations
    int num_years = 0;
    // For loop to go through the words
    for(int i = 0; i < sizeof(txt)/sizeof(txt[0]); i++){
        // Calling get_years
        get_years(txt[i], years);
    }
    return num_years;
}

// Calls collect_few for 1 paragraph
int collect_freq_par(char text[], char keywords[][100], int freq_keywords[]){
    // Variable declarations and initializations
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    // Looping through the text
    while(text[i] != '\0'){
        // If the character is a space, then the count is reset
        if(text[i] == ' '){
            count = 0;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(text[i])){
            count = 0;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(text[i])){
            count++;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(count == strlen(keywords[j])){
            freq_keywords[j][k]++;
            count = 0;
        }
        // If the character is the same as the keyword, then the frequency is increased
        if(text[i] == keywords[j][k]){
            k++;
        }
        // If the character is not the same as the keyword, then the count is reset
        else{
            k = 0;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(k == strlen(keywords[j])){
            freq_keywords[j][k]++;
            k = 0;
        }
        // If the character is a space, then the count is reset
        if(text[i] == ' '){
            j++;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(text[i])){
            j++;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(text[i])){
            j++;
        }
        // Incrementing the index
        i++;
    }
}
// Get the number of paragraphs
int get_num_paragraphs(char* text){
    // Variable declarations and initializations
    int num_par = 0;
    int i = 0;
    // Looping through the text
    while(text[i] != '\0'){
        // If the character is a space, then the number of paragraphs is increased
        if(text[i] == ' '){
            num_par++;
        }
        // Incrementing the index
        i++;
    }
    return num_par;
}
// Gets the number of sentences
int get_num_sentences(char* text){
    // Variable declarations and initializations
    int num_sent = 0;
    int i = 0;
    // Looping through the text
    while(text[i] != '\0'){
        // If the character is a period, then the number of sentences is increased
        if(text[i] == '.'){
            num_sent++;
        }
        // Incrementing the index
        i++;
    }
    return num_sent;
}
// Ge the paraghraphs index with the most sentences
int get_index(char* text){
    // Variable declarations and initializations
    int num_sent = 0;
    int max_sent = 0;
    int index = 0;
    int i = 0;
    // Looping through the text
    while(text[i] != '\0'){
        // If the character is a space, then the number of sentences is increased
        if(text[i] == ' '){
            num_sent++;
        }
        // If the character is a period, then the number of sentences is increased
        if(text[i] == '.'){
            num_sent++;
        }
        // If the number of sentences is greater than the max number of sentences, then the max number of sentences is updated
        if(num_sent > max_sent){
            max_sent = num_sent;
            index = i;
        }
        // Incrementing the index
        i++;
    }
    return index;
}
// Gets the keywords frequency in the paragraph with the most sentences
int get_keywords(char* text, char keywords[][100], int freq_keywords[]){
    // Variable declarations and initializations
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    // Looping through the text
    while(text[i] != '\0'){
        // If the character is a space, then the count is reset
        if(text[i] == ' '){
            count = 0;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(text[i])){
            count = 0;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(text[i])){
            count++;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(count == strlen(keywords[j])){
            freq_keywords[j][k]++;
            count = 0;
        }
        // If the character is the same as the keyword, then the frequency is increased
        if(text[i] == keywords[j][k]){
            k++;
        }
        // If the character is not the same as the keyword, then the count is reset
        else{
            k = 0;
        }
        // If the count is equal to the length of the keyword, then the frequency is increased
        if(k == strlen(keywords[j])){
            freq_keywords[j][k]++;
            k = 0;
        }
        // If the character is a space, then the count is reset
        if(text[i] == ' '){
            j++;
        }
        // If the character is a digit, then the count is reset
        else if(isdigit(text[i])){
            j++;
        }
        // If the character is a letter, then the count is increased
        else if(isalpha(text[i])){
            j++;
        }
        // Incrementing the index
        i++;
    }
}

// Main function
void Main(){
    // Get the file name from the user
    char filename[100];
    printf("Enter the file name: ");
    fgets(filename, 100, stdin);
    // Get the information needed for the book (name, author, protagonist)
    char book_name[100];
    char author[100];
    char protagonist[100];
    fgets(book_name, 100, stdin);
    fgets(author, 100, stdin);
    fgets(protagonist, 100, stdin);
    // Make necessary checks for the file status
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("File not found");
        return;
    }
    // Texts shall be short: 1000 characters for containing the text and 50 characters for containing the file name
    char text[1000];
    char file_name[50];
    // Get the text from the file
    fgets(text, 1000, file);
    // Get the file name from the text
    fgets(file_name, 50, text);
    // Get the number of paragraphs
    int num_paragraphs = get_num_paragraphs(text);
    // Get the number of sentences
    int num_sentences = get_num_sentences(text);
    // Get the paragraphs index with the highest number of sentences
    int index = get_index(text);
    // Get information about the book and their frequencies
    char keywords[10][100];
    int freq_keywords[10][100];
    int num_keywords = get_keywords(text, keywords, freq_keywords);
    // Get the years found in the text
    int years[100];
    int num_years = collect_years(text, years);
}