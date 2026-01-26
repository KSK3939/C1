#include "stdio.h"
#include "stdbool.h"

/**
 * Stack 구조
 * 후입선출(LIFO : Last Input First Output)
 * 마지막에 넣은 데이터가 제일 먼저 나오는 구조
 * - 함수가 호출될 때 현재 상태를 스택에 저장
 * - 브라우저에서 뒤로가기 화살표 누를 때
 * - 매직 더 개더링의 스택 생각하면 됨(나중에 쓴 주문부터 해결)
 */

// 스택의 크기를 5로 정의
#define STACK_SIZE 5

int stack[STACK_SIZE]; // 배열 선언(크기는 5)

// 스택의 가장 위를 가리키는 인덱스 변수
// -1 은 "스택이 비어있다"를 의미
int top = -1;

/**
 * 스택이 가득 차 있는지 확인하는 함수
 */

bool isFull()
{
  // top이 마지막 인덱스(4)와 같으면 가득 찬 상태
  return top == STACK_SIZE-1;
}

/**
 * 스택이 가득 차 있는지 확인
 */

bool isEmpty()
{
  // top이 -1이면 아무런 원소가 없음
  return top == -1;
}

/**
 * 스택에 값을 넣는 연산 (PUSH)
 */

void push(int value)
{
  if(isFull())
  {
    printf("스택이 가득 찼습니다.\n"); // 더 이상 삽입 불가
    return;
  }
  // top 값을 하나 올리고 해당 위치에 값을 저장
  top++;
  stack[top] = value;
  printf("PUSH : %d\n",value);
}

/**
 * 스택에서 값을 꺼내는 연산 (POP)
 */

void pop()
{
  if(isEmpty())
  {
    printf("스택이 비어 있습니다.\n"); // 꺼낼 것이 없음
    return -1;
  }
  // top 위치의 값을 저장한 후, top 감소
  int value = stack[top];
  top--;
  printf("POP : %d\n",value);
  return value;
}

/**
 * 스택의 가장 위에 있는값을 확인하는 함수(PEEK)
 */

int peek()
{
  if(isEmpty())
  {
    printf("스택이 비어 있습니다.\n"); // 꺼낼 것이 없음
    return -1;
  }
  return stack[top]; // top 위치 값을 반환
}

/**
 * 현재 스택의 모든 요소를 출력하는 함수
 */

void printStack()
{
  printf("스택 상태 [Bottom -> Top] : ");
  // 아래에서부터 top까지 순서대로 출력
  for(int i = 0; i <= top; i++)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main()
{
  // 스택에 값을 3개 넣을 예정
  push(10);
  push(20);
  push(30);

  // 현재 상태 출력
  printStack(); // 10 20 30 나옴

  // pop 연산 실행
  pop(); // 마지막인 30이 제거됨

  // 상태 다시 확인
  printStack(); // 10 20

  // 스택의 가장 위의 값을 확인
  printf("Top Element : %d\n", peek()); // 20

  return 0;
}
