#include "dynamicArrays.h"
#include <stdlib.h>
#include "stdio.h"

// Allocates an array
// 사이즈를 받아와서 배열을 생성?
int* AllocateArray(int size)
{
    if (size <= 0) {
        size = 0;
    }
    int* NewArray = (int*)malloc(size * sizeof(int)); // 사이즈 X 정수형 크기(4bit) 로 동적배열
    if (NewArray)
    {
        for (int i = 0; i < size; i++) {
            NewArray[i] = 0;
        }
    }
    return NewArray; // 할당된 배열의 포인터 반환
}


// Allocates an array given the user the size
int* AllocateArrayUserSize(int* size) // 파라미터가 필요한가?
{
    printf("Enter the size ");
    scanf_s("%d", size);
    return AllocateArray(*size);
}

// Frees an array
void FreeArray(struct ARRAY *arr)
{
    free(arr->Pointer);
}

//Adds an element to the array. Grows if needed
void PushBack(struct ARRAY* arr, int value)
{
    int count = 0;

    // 현재 배열의 상태 확인 0 아니면 다른값
    for (int i = 0; i < arr->size; i++) {
        // arr->Pointer[i]
        // arr->Pointer + i
        if (arr->Pointer[i] != 0) {
            count++;
        }
        else if (arr->Pointer[i] == 0) {
            break;
        }
    }
    // 현재 배열이 꽉차있는지 확인
    if (arr->size <= 0) {
        free(arr->Pointer);
        arr->Pointer = AllocateArray(1);
        arr->size = 1;
    }
    if (count == arr->size) {
        // 현재 배열 크기의 두배인 새로운 배열 생성
        struct ARRAY arr2;
        arr2.Pointer = (int*)malloc((arr->size * 2) * sizeof(int));
        arr2.size = arr->size * 2;
        for (int i = 0; i < (arr->size * 2); i++) {
            arr2.Pointer[i] = 0;
        }
        // 원래 배열의 값을 새로운 배열에 입력
        for (int i = 0; i < arr->size; i++) {
            arr2.Pointer[i] = arr->Pointer[i];
        }
        // 원래 배열 주소 삭제
        free(arr->Pointer);
        // 새로운 배열에 값 입력
        arr->Pointer = arr2.Pointer;
        arr->size = arr2.size;
        arr->Pointer[count] = value;
        // 원래 포인터를 새 배열을 가르키게 변경
    }
    else {
        arr->Pointer[count] = value;
    }
}
