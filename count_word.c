#include<stdio.h>
char str[100];

int isDigit(char ch) {
    if(ch >= '0' && ch <= '9') return 1;
    return 0;
}

int isChar(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return 1;
    return 0;
}

int isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
    return 0;
}

void count() {
    int nWord = 1, nLetter = 0, nDigit = 0, nOther = 0;
    for(int i = 0; str[i]; i++) {
        // word count
        if(str[i] == ' ' && (isChar(str[i+1]) || isDigit(str[i+1]))) {
            nWord++;
        }
        // letter count
        if(isChar(str[i])) {
            nLetter++;
        }
        // digit count
        if(isDigit(str[i])) {
            nDigit++;
        }

        // other characters count
        if(!isChar(str[i]) && !isDigit(str[i])) {
            nOther++;
        }
    }

    printf("\n\nNumbers of word: %d\n", nWord);
    printf("Numbers of letter: %d\n", nLetter);
    printf("Numbers of digit: %d\n", nDigit);
    printf("Numbers of other char: %d\n", nOther);
}

char letters[100], digits[100], others[100];
int letterIndex = 0, digitIndex = 0, otherIndex = 0;
char markLetter[300], markDigit[300], markOther[300];

void separate() {
    for(int i = 0; str[i]; i++) {
        int val = (int)str[i];
        // separate letter
        if(isChar(str[i]) && !markLetter[val]) {
            letters[letterIndex] = str[i];
            letters[letterIndex + 1] = ' ';
            letterIndex += 2;
            markLetter[val] = 1;
        }
        // separate digit
        if(isDigit(str[i]) && !markDigit[val]) {
            digits[digitIndex] = str[i];
            digits[digitIndex + 1] = ' ';
            digitIndex += 2;
            markDigit[val] = 1;
        }
        // separate other char
        if(!isChar(str[i]) && !isDigit(str[i]) && !markOther[val]) {
            others[otherIndex] = str[i];
            others[otherIndex + 1] = ' ';
            otherIndex += 2;
            markOther[val] = 1;
        }
    }

    letters[letterIndex] = '\0';
    digits[digitIndex] = '\0';
    others[otherIndex] = '\0';

    printf("\n\nSeparated letters : %s\n", letters);
    printf("Separated digits : %s\n",digits);
    printf("Separated others : %s\n",others);
}

int mark[200];
void countVowelConsonant() {
    int nVowel = 0, nConsonant = 0, vowelIndex = 0, consonantIndex = 0;
    char vowels[1000], consonants[1000];
    for(int i = 0; str[i]; i++) {
        int val = (int)str[i];
        if(isVowel(str[i])) {
            nVowel++;

            if(!mark[val]) {
                vowels[vowelIndex] = str[i];
                vowels[vowelIndex + 1] = ' ';
                vowelIndex += 2;
            }
        }
        else if(isChar(str[i])) {
            nConsonant++;

            if(!mark[val]) {
                consonants[consonantIndex] = str[i];
                consonants[consonantIndex + 1] = ' ';
                consonantIndex += 2;
            }
        }
        mark[val] = 1;
    }
    vowels[vowelIndex] = '\0';
    consonants[consonantIndex] = '\0';

    printf("\n\nNumbers of Vowels: %d\n", nVowel);
    printf("Numbers of Consonants: %d\n", nConsonant);
    printf("\nVowerls: %s\n", vowels);
    printf("Consonants: %s\n", consonants);
}

void startWithVowelCons() {
    int vowelIndex = 0, consonantIndex = 0;
    char vowels[1000], consonants[1000];

    for(int i = 0; str[i]; i++) {
        if(isVowel(str[i])) {
            while(str[i] != ' ' && str[i] != '\0') {
                vowels[vowelIndex++] = str[i++];
            }
            vowels[vowelIndex++] = ' ';
        } else if(isChar(str[i])) {
            while(str[i] != ' ' && str[i] != '\0') {
                consonants[consonantIndex++] = str[i++];
            }
            consonants[consonantIndex++] = ' ';
        }
    }
    vowels[vowelIndex] = '\0';
    consonants[consonantIndex] = '\0';

    printf("\n\nWords started with vowel : %s\n",vowels);
    printf("Words started with consonant : %s\n",consonants);
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf(" %[^\n]",str);
    count();
    separate();
    countVowelConsonant();
    startWithVowelCons();

    return 0;
}