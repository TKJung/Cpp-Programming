/*
주어진 샘플 코드를 수정하여 포인터의 배열이 각각 정수 배열의
다섯개의 요소들을 가리키게 만들어 보라.
그 다음 정수 배열명을 쓰지 않고 포인터 배열을 이용하여 다섯개의 정수를 출력한다.
*/

#include <stdio.h>
int main()
{
    int arr[5] = {55, 22, 33, 44, 11};
    int *parr[5];  // 정수 포인터 5개로 구성된 배열이다.
    int i;

    for ( i=0; i < 5 ; i++)
    {
        // parr의 각 요소가 arr의 각 요소를 순서대로 가리키도록 만든다.
        parr[i] = &arr[i]; // 주소를 같게 만들어준다.
    }

    for (i=0; i < 5 ; i++)
    {
        // parr 배열을 이용하여 55 부터 11까지 현재 순서대로 출력하도록 만든다.
        // arr은 사용하지 않는다
        printf("%d ", *parr[i]);
    }
    return 0;
}