#include <stdio.h>
int main(void)
{
	int input, num; //input과 num 이라는 정수형 변수를 선언한다.
	int i = 1; //i라는 정수형 변수를 선언하고 초기화한다.
	int total = 1; //total이라는 정수형 변수를 선언하고 초기화한다.

	//한 정수를 입력 받아 input 변수에 저장한다.
	printf("정수를 입력하시오 : "); //화면에 "정수를 입력하시오 : "를 출력한다.
	scanf_s("%d", &input); //사용자로부터 정수를 입력 받아 input 변수에 저장한다.

	//printf 함수를 이용해 주어진 문장을 출력한다.
	printf("--%5----------------\n"); //화면에 "-- ----------------"를 출력하고 줄을 띄운다.
	printf("n%51부터 n까지의 곱\n"); //화면에 "n  1부터 n까지의 곱"를 출력하고 줄을 띄운다.
	printf("--%5----------------\n"); //화면에 "-- ----------------"를 출력하고 줄을 띄운다.

	/*줄의 수를 i와 증가 연산자를 통해 출력한다.
	1*2->1*2*3->1*2*3*4의 과정을 표현하기 위해 num과 증가 연산자를 사용한다.
	위 내용을 for문을 통해 반복한다.*/
	for (num = 1; num <= input; num++) //for문을 통해 아래 내용을 반복한다.
	{
		total = total * num; //total 변수에 total*num 값을 저장한다.
		printf("%d      %d\n", i, total); //화면에 "%d  %d\n"를 출력하고 줄을 띄운다. 이때 첫 번째 %d는 i에 저장된 값, 두 번째 %d는 total에 저장된 값이다.
		i++; //증가 연산자를 이용해 i값에 1을 더한다.
	}

	return 0;
}