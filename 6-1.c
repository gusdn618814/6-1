#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    printf("배열 크기 N 입력: ");
    scanf("%d", &N);

    // 동적 할당
    int *arr = (int *)malloc(sizeof(int) * N);
    if (!arr) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 0~N 임의의 수로 채우기 → *(arr+i) 사용
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    // 1. 처음부터 끝까지 출력 → *(arr+i) 사용
    printf("\n[처음 → 끝]\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 2. 뒤에서부터 처음까지 출력 → *(arr+i) 사용
    printf("\n[끝 → 처음]\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 3. 총합, 최대값, 최소값 → *(arr+i) 사용
    int sum = 0;
    int max = *(arr + 0);
    int min = *(arr + 0);

    for (int i = 0; i < N; i++) {
        sum += *(arr + i);
        if (*(arr + i) > max) max = *(arr + i);
        if (*(arr + i) < min) min = *(arr + i);
    }

    printf("\n총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);
    return 0;
}
