#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int is_anagram(char* _str1, char* _str2) {
    if(!_str1 || !_str2) return 0;
    size_t s1_len = strlen(_str1);
    if(s1_len != strlen(_str2)) return 0;

    char arr[256] = {0};
    for(size_t i = 0; i < s1_len; i++) {
        arr[_str1[i]]++;
        arr[_str2[i]]--;
    }

    for(size_t i = 0; i < 256; i++) {
        if(arr[i] != 0) return 0;
    }

    return 1;
}

int main(int _argc, char** _argv) {
    if(_argc != 3) {
        printf("Expected 2 arguments\n");
        return 1;
    }

    printf("%d\n", is_anagram(_argv[1], _argv[2]));
}
