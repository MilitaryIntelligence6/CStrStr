//
// Created by Administrator on 2020/12/03.
//
// !!!charset encoding == "GBK";(sorry about that "UTF-8" made console Garbled code)
//
// C99 标准;
// 编译环境 mingw-w64-8.1.0 i686 x86_64 posix dwarf
//


#include <stdio.h>
#include <string.h>
#include <windows.h>


/**
 * get Next 数组;
 * @param p
 * @param next
 */
void getNext(char* p, int* next);

/**
 * kmp 模式串匹配;
 * @param s
 * @param p
 * @param next
 * @return
 */
int kmp(char* s, char* p, int* next);

/**
 * 套皮;
 * @param _String
 * @param _SubString
 * @return
 */
int mystrstr(const char* _String, const char* _SubString);


int next[9999];


/**
 * get Next 数组;
 * @param p
 * @param next
 */
void getNext(char* p, int* next)
{
    int len = strlen(p);
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < len - 1)
    {
        if (k == -1 || p[k] == p[j])
        {
            k++;
            j++;
            next[j] = k;
        } else
        {
            k = next[k];
        }
    }
}


/**
 * kmp 模式串匹配;
 * @param s
 * @param p
 * @param next
 * @return
 */
int kmp(char* s, char* p, int* next)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        } else
        {
            //如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }

    }
    if (j >= pLen)
    {
        return (i - j);
    }
    return -1;
}


/**
 * 套皮;
 * @param _String
 * @param _SubString
 * @return
 */
int mystrstr(const char* _String, const char* _SubString)
{
    getNext(_SubString, next);

    return kmp(_String, _SubString, next);
}


int main()
{
    char s[30] = "hellofoobar";
    char p[10] = "foo";
    printf("\n s[] = %s", s);
    printf("\n p[] = %s", p);

    int n = mystrstr(s, p);

    switch (n)
    {
        case -1:
        {
            printf("\n\n没有匹配到模式串!\n\n");
            break;
        }

        default:
        {
            printf("\n\n匹配的位置为 %d\n\n", n);
            break;
        }
    }
    system("pause");
    return 0;
}
