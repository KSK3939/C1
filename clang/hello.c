#include <stdio.h>

/**
 * for 반복문
 */

// 입력값 받는 버전
// int main()
// {
//     int i,j;
//     int a;
//     printf("최대 높이를 지정 : ");
//     scanf("%d", &a);
//     for(i=0;i<a;i++){
//         for(j=0;j<=i;j++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     for(i=a-1;i>0;i--){
//         for(j=0;j<i;j++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }

// for 하나로 묶은 버전
// int main()
// {
//     int i=0,j=0;
//     int count = 0;
//     for(;count<10;count++){
//         if(count<5){
//             for(j=0;j<=i;j++){
//             printf("*");
//         }
//         printf("\n");
//         i++;
//         }
//         else{
//             for(j=1;j<i;j++){
//             printf("*");
//         }
//         printf("\n");
//         i--;
//         }
//     }
//     return 0;
// }

// 쉽게 한 버전
// int main()
// {
//     int i,j;
//     for(i=0;i<5;i++){
//         for(j=0;j<=i;j++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     for(i=4;i>0;i--){
//         for(j=0;j<i;j++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }

//중첩

// int main()
// {
//     int i,j;
//     for(i=0;i<5;i++){
//         printf("외부 for 시작 %d \n",i);

//         for (j=0;j < 5; j++){
//             printf("내부 for 수행 %d \n",j);
//         }
//         printf("내부 끝 %d\n",i);
//     }
//     return 0;
// }

//  int main()
//  {
//     //for(;;); 무한반복
//     //for(;;){}
//     //while(1); 무한반복
    
//     int i,j;
//     for(i=0;i<5;i++){
//         printf("%d \n",i);
//     }
//     return 0;
//  }

/**
 * while 반복문
 */

// int main()
// {
//     int weight = 80;
//     int count = 0;

//     while(weight > 70){
//         printf("운동을 통해 체중 1kg 감소\n");
//         weight--;
//         count++;
//     }
//     printf("운동 종료 \n");
//     printf("운동한 날 : %d \n",count);

//     //while(1) : 무한반복

//     return 0;
// }

/**
 * 제어문
 */

// switch case문

// int main()
// {
//     int num;
//     printf("미세먼지 농도 선택\n");
//     printf("1 : 좋음\n2: 보통\n3: 나쁨\n4: 매우 나쁨\n");
//     scanf("%d",&num);
//     switch (num)
//     {
//     case 1:
//         printf("마스크 미착용\n");
//         break;
//     case 2:
//         printf("마스크 착용 권장\n");
//         break;
//     case 3:
//         printf("마스크 착용 강하게 권장\n");
//         break;
//     case 4:
//         printf("외출 자제\n");
//         break;
//     default:
//         printf("올바른 숫자를 입력하시오.\n");
//         break;
//     }
//     return 0;
// }

// int main()
// {
//     int pm;
//     printf("미세먼지 농도를 입력하시오 : ");
//     scanf("%d",&pm);

//     //중첩
//     if(pm > 0){
//         if(pm <= 30){
//             printf("미세먼지 농도가 좋음이므로 마스크 미착용 \n");
//         }
//         else if(pm <= 80){
//             printf("미세먼지 농도가 보통이므로 마스크 착용 권장 \n");
//         }
//         else{
//             printf("미세먼지 농도가 나쁨이므로 외출 자제 \n");
//         }
//     }
//     else {
//         printf("입력값은 양수일 것 \n");
//     }
//     return 0;
// }

// int main()
// {
//     int num = 0;
    
//     printf("숫자 1개를 입력 \n");
//     scanf("%d",&num);
//     if (num <5){
//         printf("입력한 숫자는 5보다 작다. \n");
//     }
//     else if (num>5){
//         printf("입력한 숫자는 5보다 크다. \n");
//     }
//     else{
//         printf("입력한 숫자는 5와 같다. \n");
//     }
    
//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     double avg;

//     printf("정수 3개를 입력하십시오. \n");
//     scanf("%d %d %d",&a, &b, &c);
//     avg = (double)(a+b+c)/3; //형변환
//     printf("평균 : %f \n", avg);

//     return 0;
// }

//0000 0011 << 3 8bit -> 16bit 0000 0000 0000 0011

// int main()
// {
//     unsigned short data = 0x0000; // 0000 0000 0000 0000

//     unsigned short msk1 = 0xf000; // 1111 0000 0000 0000
//     unsigned short msk2 = 0x0f00; // 0000 1111 0000 0000
//     unsigned short msk3 = 0x00f0; // 0000 0000 1111 0000
//     unsigned short msk4 = 0x000f; // 0000 0000 0000 1111

//     printf("결과 1 : %#.4x \n",data | msk1);
//     printf("결과 2 : %#.4x \n",data | msk2);
//     printf("결과 3 : %#.4x \n",data | msk3);
//     printf("결과 4 : %#.4x \n",data | msk4);
    //특정 부분 변경 가능


    // // & 연산
    // unsigned short data = 0x5678; // 0101 0110 0111 1000

    // unsigned short msk1 = 0xf000; // 1111 0000 0000 0000
    // unsigned short msk2 = 0x0f00; // 0000 1111 0000 0000
    // unsigned short msk3 = 0x00f0; // 0000 0000 1111 0000
    // unsigned short msk4 = 0x000f; // 0000 0000 0000 1111

    // printf("결과 1 : %#.4x \n",data & msk1);
    // printf("결과 2 : %#.4x \n",data & msk2);
    // printf("결과 3 : %#.4x \n",data & msk3);
    // printf("결과 4 : %#.4x \n",data & msk4);
    // //특정 비트를 뽑아낼 수 있다

   //  return 0;
//}

/**
 * 비트 마스크
 * & 연산자는 특정비트 0으로 만듬
 * | 연산자는 특정비트 1로 만듬
 * ^ 연산자는 특정비트 반전
 */

// int main()
// {
//     unsigned char a;
//     a = 255;
//     printf("%d \n",a);
//     a = 256;
//     printf("%d \n",a);

//     return 0;
// }

/**
 * 조건 연산자
 * expression 1 ? expression 2 : expression 3
 * 만약 exp1이 참(true)면 exp2가 실행, 그렇지 않으면 exp3 실행
 * a = 1 , b = 0
 * a || b ? 1 : 2 1번이 실행
 */

// /**
//  * 카멜표기법
//  * int nameAge << 단어 2개를 연결 시 맨 앞에 오는 단어는 소문자로 시작, 뒤에 오는 단어는 대문자로 시작. (중요하진 않음)
//  */

// /**
//   * 파스칼 표기법
//   * int ManAge << 모든 단어를 대문자로 시작 (역시나 중요하진 않음)
//   */

// /**
//    * 스네이크 표기법
//    * int man_age << 단어 중간을 _ 로 연결 (이건 내가 많이 씀)
//    */

// /**
//  * 헝가리안 표기법
//  * 변수명 앞에 데이터명을 붙이는 방식
//  * char ch1, String strName; (이것도 내가 많이 씀) 
//  */

// //변수 초기화, 초기화 안하면 쓰레기(더미) 값
// int main()
// {
//     // int price;
//     // printf("%d \n",price);
//     // return 0;

//     // int amount = 0;
//     // int price = 0;
//     // int totalPrice = 0;

//     int amount = 0, price = 0, totalPrice = 0;

//     printf("amount = %d, price = %d \n",amount, price);
//     printf("수량 입력 : ");
//     scanf("%d",&amount);
//     printf("가격 입력 : ");
//     scanf("%d", &price);
//     printf("합계 : %dwon \n",amount*price);
//     return 0;
// }

// int main()
// {
//     char ch;
//     int num;
//     double x;

//     printf("char 형의 바이트 크기 : %d \n",sizeof(char));
//     printf("int 형의 바이트 크기 : %d \n",sizeof(int));
//     printf("double 형의 바이트 크기 : %d \n",sizeof(double));
    
//     printf("변수 ch의 바이트 크기 : %d \n",sizeof(ch));
//     printf("변수 num의 바이트 크기 : %d \n",sizeof(num));
//     printf("변수 x의 바이트 크기 : %d \n",sizeof(x));
//     return 0;
// }

// int main()
// {
//     char name[20];
//     int age;
//     char gender;

//     printf("이름, 나이, 성별(M/F)을 순서대로 입력하시오. \n");
//     scanf("%s %d %c",name, &age, &gender);
//     printf("이름 : %s\n나이 : %d\n성별 : %c\n",name, age, gender);
//     return 0;
// }


// int main()
// {
//     int num = 12345;
//     float x = 12.34567;
//     printf("%d \n",num);
//     printf("%d \n",num*10);
//     printf("%d \n",num*100);
//     printf("%d \n",num*1000);

//     printf("%8d \n",num);
//     printf("%8d \n",num*10);
//     printf("%8d \n",num*100);
//     printf("%8d \n",num*1000);
//     printf("%8d \n",num*100000);

//     printf("%08d \n",num);

//     printf("\n\n");
//     printf("%f \n",x);
//     printf("%.1f \n",x);
//     printf("%8.2f \n",x);


//     return 0;
// }

// int main()
// {
//     int num;
//     float x;
//     char c;

//     num = 123;
//     x = 1.23;
//     c = 'A';

//     // 서식지정자는 출력갓의 갯수와 반드시 같아야 함.
//     printf("%d, %X \n",num, num);
//     printf("%f, %e \n",x, x);
//     printf("%c \n",c);
//     return 0;
// }

// #include <stdio.h>

// void fun()
// {
//     printf("현재 함수 : %s \n",__FUNCTION__);
// }


// int main()
// {
    
// }


// #include <stdio.h>

// #define CLAC(x,y) (x+y)

// int main()
// {
//     printf("%d \n",CLAC(10,20));
// }

// //deinfe 연습
// #include <stdio.h> 

// #define APPLE 10 //int const
// #define NAME "사과" //sentence const

// int main(void)
// {
//     printf("%s %d \n",NAME, APPLE);
//     return 0;
// }