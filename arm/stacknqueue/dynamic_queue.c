#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 원형 큐 구조체 정의
typedef struct
{
    int *data;     // 데이터를 저장할 동적 배열
    int front;     // 데이터를 꺼낼 위치
    int rear;      // 데이터를 넣을 위치
    int size;      // 전체 큐 크기 (배열 크기)
} CircularQueue;

// 큐 생성 및 초기화 함수
CircularQueue *createQueue(int capacity)
{
    CircularQueue *q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->data = (int*)malloc(sizeof(int) * capacity);  // 배열 동적 할당
    q->front = 0;  // front와 rear를 같은 위치로 초기화
    q->rear = 0;
    q->size = capacity;  // 배열 크기 저장
    return q;
}

// 큐가 비어있는지 확인
bool isEmpty(CircularQueue *q)
{
    return q->front == q->rear;
}

// 큐가 가득 찼는지 확인
bool isFull(CircularQueue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

// 큐에 데이터 삽입 (Enqueue)
bool enqueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return false;
    }
    q->rear = (q->rear + 1) % q->size;  // rear를 한 칸 이동 (원형)
    q->data[q->rear] = value;           // 데이터 삽입
    return true;
}

// 큐에서 데이터 추출 (Dequeue)
bool dequeue(CircularQueue *q, int *value)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return false;
    }
    q->front = (q->front + 1) % q->size;  // front를 한 칸 이동 (원형)
    *value = q->data[q->front];           // 데이터 추출
    return true;
}

// 큐 내용 출력 (디버깅용)
void printQueue(CircularQueue *q)
{
    int i = (q->front + 1) % q->size;  // 첫 번째 요소 위치
    printf("Queue: ");
    while (i != (q->rear + 1) % q->size)
    {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// 큐 메모리 해제
void freeQueue(CircularQueue *q)
{
    free(q->data);  // 배열 해제
    free(q);        // 구조체 해제
}

// 메인 함수 (사용 예제)
int main()
{
    // 크기 6짜리 큐 생성 (실제 데이터는 최대 5개)
    CircularQueue *q = createQueue(6);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);  // Queue: 10 20 30 40 50

    int val;
    dequeue(q, &val);
    printf("Dequeued: %d\n", val);  // Dequeued: 10

    enqueue(q, 60);
    printQueue(q);  // Queue: 20 30 40 50 60

    // 큐가 가득 찼기 때문에 삽입 실패
    enqueue(q, 70);  // Queue is full!

    // 마무리: 메모리 해제
    freeQueue(q);
    return 0;
}
