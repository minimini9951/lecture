#include "q.h"

#define NULL ((void*)0) 

//문자열의 시작지점부터 끝지점까지 포인터를 증가시키면서 val과 일치하는 포인터를 리턴하는 함수
char const* find(char const* begin, char const* end, char val) {
    for (; begin != end; ++begin) {
        if (*begin == val) {
            return begin;
        }
    }
    return NULL;
}

char const* find_any(char const* begin, char const* end, char const* vals, int len) {
    for (; begin != end; ++begin) {
        for (const char* v = vals; v != vals + len; ++v) {
            if (*begin == *v) {
                return begin;
            }
        }
    }
    return NULL;
}

int count(char const* begin, char const* end, char val) {
    int cnt = 0;
    for (; begin != end; ++begin) {
        if (*begin == val) {
            ++cnt;
        }
    }
    return cnt;
}

int count_any(char const* begin, char const* end, char const* vals, int len) {
    int cnt = 0;
    for (; begin != end; ++begin) {
        for (const char* v = vals; v != vals + len; ++v) {
            if (*begin == *v) {
                ++cnt;
                break;
            }
        }
    }
    return cnt;
}

int compare(char const* begin1, char const* begin2, int len) {
    for (const char* end1 = begin1 + len, *end2 = begin2 + len; begin1 != end1 && begin2 != end2; ++begin1, ++begin2) {
        if (*begin1 < *begin2) {
            return -1;
        }
        else if (*begin1 > *begin2) {
            return 1;
        }
    }
    return 0;
}

void exchange(char* begin1, char* begin2, int len) {
    for (char* end1 = begin1 + len, *end2 = begin2 + len; begin1 != end1 && begin2 != end2; ++begin1, ++begin2) {
        char temp = *begin1;
        *begin1 = *begin2;
        *begin2 = temp;
    }
}

void copy(char* dst, char* src, int len) {
    if (dst < src) {
        for (char* end = src + len; src != end; ++src, ++dst) {
            *dst = *src;
        }
    }
    else if (dst > src) {
        dst += len;
        src += len;
        for (; len > 0; --len) {
            *(--dst) = *(--src);
        }
    }
}