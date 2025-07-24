/* String utility functions for common string operations */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_length(const char *s) {
    return strlen(s);
}

void string_copy(char *dest, const char *src) {
    strcpy(dest, src);
}

int string_compare(const char *a, const char *b) {
    return strcmp(a, b);
}

void string_concat(char *dest, const char *src) {
    strcat(dest, src);
}

void string_reverse(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

void to_upper(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

void to_lower(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

int count_vowels(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (strchr("aeiouAEIOU", s[i])) {
            count++;
        }
    }
    return count;
}

int is_palindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left++] != s[right--]) {
            return 0;
        }
    }
    return 1;
}

int find_char(const char *s, char ch) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == ch) {
            return i;
        }
    }
    return -1;
}

void print_results() {
    char s[100] = "hello";
    printf("Length: %d\n", string_length(s));
    printf("Vowels: %d\n", count_vowels(s));
    printf("Is palindrome: %d\n", is_palindrome("level"));
}

int main() {
    print_results();
    return 0;
} 