// Querying the Document
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char**** get_document(char* text) {
    int p_count = 0;
    int s_count = 0;
    int w_count = 0;
    int sentences_per_paragraph[5];
    int words_per_sentence[5][1000];
    int chars_per_word[5][1000][1000];
    int last_word = 0;

    sentences_per_paragraph[0] = 0;
    words_per_sentence[0][0] = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            chars_per_word[p_count][s_count][w_count] = i - last_word;
            words_per_sentence[p_count][s_count]++;
            w_count++;
            last_word = i + 1;
        }
        if (text[i] == '.') {
            chars_per_word[p_count][s_count][w_count] = i - last_word;
            w_count = 0;
            sentences_per_paragraph[p_count]++;
            words_per_sentence[p_count][s_count]++;
            s_count++;
            chars_per_word[p_count][s_count][0] = 0;
            last_word = i + 1;
        }
        if (text[i] == '\n') {
            p_count++;
            s_count = 0;
            sentences_per_paragraph[p_count] = 0;
            words_per_sentence[p_count][0] = 0;
            last_word = i + 1;
        }
    }
    sentences_per_paragraph[p_count]++;
    p_count++;
    char ****document = malloc(sizeof(char***) * p_count);
    
    for (int p = 0; p < p_count; p++) {
        document[p] = malloc(sizeof(char**) * sentences_per_paragraph[p]);
        for (int s = 0; s < sentences_per_paragraph[p]; s++) {
            document[p][s] = malloc(sizeof(char*) * words_per_sentence[p][s]);
            for (int w = 0; w < words_per_sentence[p][s]; w++) {
                document[p][s][w] = malloc(sizeof(char) * chars_per_word[p][s][w] + 1);
                document[p][s][w][chars_per_word[p][s][w]] = '\0';
            }   
        }
    }
    int p = 0;
    int s = 0;
    int w = 0;
    last_word = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            document[p][s][w] = strncpy(document[p][s][w], text + last_word, i - last_word);
            document[p][s][w][i - last_word] = '\0';
            w++;
            last_word = i + 1;
        }
        if (text[i] == '.') {
            document[p][s][w] = strncpy(document[p][s][w], text + last_word, i - last_word);
            document[p][s][w][i - last_word] = '\0';
            w = 0;
            s++;
            last_word = i + 1;
        }
        if (text[i] == '\n') {
            s = 0;
            p++;
            last_word = i + 1;
        }
    }
    return document;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int w_count;
    scanf("%d", &w_count);
    for(int i = 0; i < w_count; i++){
        printf("%s", sentence[i]);
        if( i != w_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}