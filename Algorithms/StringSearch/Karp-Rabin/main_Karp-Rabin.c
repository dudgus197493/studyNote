#include<stdio.h>
#include<stdlib.h>



int main(int argc, char** argv) {
    char* FilePath;
    char* Pattern;
    char buffer[500];

    FilePath = argv[1];
    Pattern = argv[2];

    FILE* fp;
    fp = fopen(FilePath, "r");

    if (fp == NULL) {
        printf("%s ���� �б⿡ ����\n", FilePath);
        return;
    }

    while (fgets(buffer, 500, fp) != NULL) {
    }
}