#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>




int BruteForce(char* text, int size, char* pattern, int patterns, int startIndex) {
    // text ���� �ȿ��� pattern ���ڿ��� �˻��ؼ�
    int i = 1;
    int result = 0;
    for (i = startIndex; i < size; i++) {         // ������ ���������� �ݺ�
        int noEqual = 0;
        for (int j = 0; j < patterns; j++) {
            if (text[i + j] != pattern[j]) {
                noEqual = 1;
                break;
            }
        }
        if (noEqual == 0) {
            /*printf("���� ���� ���ڿ� ��ġ : %d\n", i);*/
            return i;
        }
    }
    return -1;
}


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

    int line = 0;
    while (fgets(buffer, 500, fp) != NULL) {
        int startIndex = 0;
        int ret = BruteForce(buffer, strlen(buffer), Pattern, strlen(Pattern), startIndex);
        if (ret == -1) {
            printf("%s����\n pattern : %s, %d���ο� �߰ߵ� ������ �����ϴ�.", buffer, Pattern, line++);
        }
        else {
            printf("%s���� \n pattern: %s, %d������ ", buffer, Pattern, line++);
            while (1) {
                ret = BruteForce(buffer, strlen(buffer), Pattern, strlen(Pattern), startIndex);
                if (ret == -1) {
                    break;
                }
                printf("%d ", ret);
                startIndex += ret + 1;
            }
            printf("�÷��� �ֽ��ϴ�.\n");
        }
        printf("\n\n");
    }

    fclose(fp);

    return 0;
}
