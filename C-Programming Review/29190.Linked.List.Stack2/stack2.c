#include <stdio.h>
#include <stdlib.h>

struct item
{
    int data;
    struct item *next;
};

void insert(struct item **s, int n)
{
    struct item *pAlloc;
    pAlloc = (struct item*)malloc(sizeof(struct item));  //pAlloc = malloc으로 할당
    pAlloc->data = n;  //n값을 넣고
    pAlloc->next = *s;  //연결. 1회차: 주소 0
    *s = pAlloc; // 1회차: [처음 넣은 n을 포함하는 구조체]를 가리킴.
}

// is_empty 함수는 스택이 비어있으면 1을, 아니면 0을 돌려준다.
int is_empty(struct item *pStack)
{
    if (pStack == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// top 함수는 가장 위에 있는 항목 값을 돌려준다.
int top(struct item *pStack)
{
    return pStack->data;
}

// pop함수는 가장 위의 항목을 없앤다.
void pop(struct item **s)
{
    // 1-1. 비어있어서 pop()할 항목이 없는 경우
    if (*s == 0)
    {
        printf("pop()할 항목이 없습니다.");
    }
    // 1-2. 채워져있어 pop()할 항목이 있는 경우
    else
    {
        // 2. Free 시킬 임시 포인터 pFree를 만들어, Stack Top을 가리켜 붙잡아둔다.
        struct item *pFree = 0;
        pFree = (struct item*)malloc(sizeof(struct item));
        pFree = *s;

        // 3. pStack이 Stack Top 한 칸 밑의 구조체를 가리키게 한다.
        (*s) = (*s)->next;

        // 4. Free 시켜준다.
        free(pFree);
    }
}

int main()
{
    struct item * pStack = 0; // 지역변수, 빈 스택으로 초기화
    int value; // 스택에 넣을 정수data값

    while ( scanf("%d", &value) == 1)
    {
        insert(&pStack, value);
    }

    while ( ! is_empty(pStack) )
    {
        printf("stack top is %d\n", top(pStack));
        pop(&pStack);
    }
}
