#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/**
 * Queue(큐)
 * FIFO(First Input First Output)
 * - 프린터의 대기열
 * - 운영체제에서 프로세스 스케쥴링
 */

// 큐의 크기
#define QUEUE_SIZE 5

// Queue의 구조체 정의
typedef struct
{
  int data[QUEUE_SIZE]; // 고정 크기의 정수형 배열(큐 데이터 저장소)
  int front; // 데이터를 꺼낼 위치 (가장 오래된 데이터)
  int rear; // 데이터를 넣을 위치 (다음 저장 위치)
}Queue;

// 큐 초기화
void initQueue(Queue *q)
{
  q->front = 0; // 처음에는 front도 0
  q->rear = 0; // rear도 처음에는 0 -> 큐가 비어있는 상태
}

// 비어있는지
bool isEmpty(Queue *q)
{
  // 프론트와 리어가 같으면 큐에 데이터가 없다
  return q->front == q->rear;
}

// 큐가 가득 차 있는지
bool isFull(Queue *q)
{
  return q->rear == QUEUE_SIZE; // rear값이 QUEUE_SIZE에 들어가면 배열의 끝
}

// 큐에 데이터 삽입
bool enqueue(Queue *q, int value)
{
  if(isFull(q)) // 큐가 가득 차 있으면 실패
  {
    printf("Queue is Full\n");
    return false;
  }
  // rear 위치에 데이터 저장 후에 rear 값 증가
  q->data[q->rear++] = value; // q->rear가 최우선 우선순위이기에 ++은 저장 후에 연산됨
  return true;
}

// 큐에서 데이터 제거 (dequeue)
bool dequeue(Queue *q, int *value)
{
  if(isEmpty(q)) // 큐가 비어있으면 실패
  {
    printf("Queue is Empty\n");
    return false;
  }
  // front 위치에서 데이터를 꺼내고 front 값을 증가
  *value = q->data[q->front++]; // 저장된 값 자체가 사라지진 않음
  return true;
}

// 큐 상태 출력 (프론트에서 리어 바로 직전까지)
void printQueue(Queue *q)
{
  printf("Queue = ");
  for(int i = q->front; i  < q->rear; i++)
  {
    printf("%d ",q->data[i]);
  }
  printf("\n");
}

int main()
{
  Queue q;
  initQueue(&q);

  // 데이터 삽입
  enqueue(&q, 10); // rear = 1
  enqueue(&q, 20); // rear = 2
  enqueue(&q, 30); // rear = 3
  printQueue(&q); // 10 20 30

  int value;
  dequeue(&q, &value); // 가장 앞에 있는 10 꺼냄, front = 1
  printf("Dequeue: %d \n", value); // 10
  printQueue(&q); // 20 30

  // 추가 삽입
  enqueue(&q, 40); // rear = 4
  enqueue(&q, 50); // rear = 5
  enqueue(&q, 60); // rear = 5이고 QUEUE_SIZE = 5이므로, Queue is Full 
  printQueue(&q); // 20 30 40 50, data = {10, 20, 30, 40, 50}
  // front = 1 이므로 20부터 출력함.
}
