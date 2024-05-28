#include "dynamicArrays.h"
#include <stdlib.h>
#include "stdio.h"

// Allocates an array
// ����� �޾ƿͼ� �迭�� ����?
int* AllocateArray(int size)
{
    if (size <= 0) {
        size = 0;
    }
    int* NewArray = (int*)malloc(size * sizeof(int)); // ������ X ������ ũ��(4bit) �� �����迭
    if (NewArray)
    {
        for (int i = 0; i < size; i++) {
            NewArray[i] = 0;
        }
    }
    return NewArray; // �Ҵ�� �迭�� ������ ��ȯ
}


// Allocates an array given the user the size
int* AllocateArrayUserSize(int* size) // �Ķ���Ͱ� �ʿ��Ѱ�?
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

    // ���� �迭�� ���� Ȯ�� 0 �ƴϸ� �ٸ���
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
    // ���� �迭�� �����ִ��� Ȯ��
    if (arr->size <= 0) {
        free(arr->Pointer);
        arr->Pointer = AllocateArray(1);
        arr->size = 1;
    }
    if (count == arr->size) {
        // ���� �迭 ũ���� �ι��� ���ο� �迭 ����
        struct ARRAY arr2;
        arr2.Pointer = (int*)malloc((arr->size * 2) * sizeof(int));
        arr2.size = arr->size * 2;
        for (int i = 0; i < (arr->size * 2); i++) {
            arr2.Pointer[i] = 0;
        }
        // ���� �迭�� ���� ���ο� �迭�� �Է�
        for (int i = 0; i < arr->size; i++) {
            arr2.Pointer[i] = arr->Pointer[i];
        }
        // ���� �迭 �ּ� ����
        free(arr->Pointer);
        // ���ο� �迭�� �� �Է�
        arr->Pointer = arr2.Pointer;
        arr->size = arr2.size;
        arr->Pointer[count] = value;
        // ���� �����͸� �� �迭�� ����Ű�� ����
    }
    else {
        arr->Pointer[count] = value;
    }
}
