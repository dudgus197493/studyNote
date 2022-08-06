#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>




int BruteForce(char* text, int size, char* pattern, int patterns, int startIndex) {
    // text 문장 안에서 pattern 문자열을 검색해서
    int i = 1;
    int result = 0;
    for (i = startIndex; i < size; i++) {         // 문장이 끝날때까지 반복
        int noEqual = 0;
        for (int j = 0; j < patterns; j++) {
            if (text[i + j] != pattern[j]) {
                noEqual = 1;
                break;
            }
        }
        if (noEqual == 0) {
            /*printf("같은 패턴 문자열 위치 : %d\n", i);*/
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
        printf("%s 파일 읽기에 실패\n", FilePath);
        return;
    }

    int line = 0;
    while (fgets(buffer, 500, fp) != NULL) {
        int startIndex = 0;
        int ret = BruteForce(buffer, strlen(buffer), Pattern, strlen(Pattern), startIndex);
        if (ret == -1) {
            printf("%s문장\n pattern : %s, %d라인에 발견된 패턴이 없습니다.", buffer, Pattern, line++);
        }
        else {
            printf("%s문장 \n pattern: %s, %d라인의 ", buffer, Pattern, line++);
            while (1) {
                ret = BruteForce(buffer, strlen(buffer), Pattern, strlen(Pattern), startIndex);
                if (ret == -1) {
                    break;
                }
                printf("%d ", ret);
                startIndex += ret + 1;
            }
            printf("컬럼에 있습니다.\n");
        }
        printf("\n\n");
    }

    fclose(fp);

    return 0;
}
