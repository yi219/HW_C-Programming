#include <stdio.h>
int main(void)
{
	int input; //input이라는 정수형 변수를 선언한다.
	int num; //num이라는 정수형 변수를 선언한다.
	int i; //i라는 정수형 변수를 선언한다.
	int line; //line이라는 정수형 변수를 선언한다.
	int j; //j라는 정수형 변수를 선언한다.
	int k; //k라는 정수형 변수를 선언한다.

	//키보드로부터 한 정수를 입력받아 input 변수에 저장한다.
	printf("정수를 입력하시오 : "); //화면에 "정수를 입력하시오 : "를 출력한다.
	scanf_s("%d", &input); //사용자로부터 정수를 입력받아 input 변수에 저장한다.

	//input의 값을 num 변수에 저장한다.
	num = input;

	/*줄이 바뀔 때 *이 하나씩 줄어가는 과정을 출력하기 위해 num과 감소 연산자, i와 증가 연산자를 사용한다.
	for문을 중첩시켜 *이 의도한 바와 같이 출력되게 한다.*/
	for (; num > 0; num--) //for문을 통해 아래 내용을 반복한다.
	{
		for (i = 0; i < num; i++) //for문을 통해 아래 내용을 반복한다.
		{
			printf("*"); //화면에 "*"를 출력한다.
		}
		printf("\n"); //화면의 줄을 띄운다.
	}

	//두 번째 문제로 넘어가기 전 행을 바꾼다.
	printf("\n \n");

	/*의도한 바와 같이 *를 출력하기 위해 for문의 중첩을 사용한다.
	또한 행과 열에 따라 달라지는 결과를 if else문을 사용해 출력한다.*/
	for (line = 0; line < input; line++) //for문을 통해 아래 내용을 반복한다.
	{
		if (line == 0 || line == input - 1) //if, else문을 통해 line 값에 따라 달라지는 경우를 구분한다. 
		{
			for (j = 0; j < input; j++) //for문을 통해 아래 내용을 반복한다.
				printf("*"); //화면에 "*"를 출력한다.
			printf("\n"); //화면의 줄을 띄운다.
		}
		else
		{
			for (k = 0; k < input; k++) //for문을 통해 아래 내용을 반복한다.
			{
				if (k == 0 || k == 1 || k == input - 2 || k == input - 1) //if, else문을 통해 k 값에 따라 달라지는 경우를 구분한다. 
					printf("*"); //화면에 "*"를 출력한다.
				else
					printf(" "); // 화면에 " "를 출력한다.
			}
			printf("\n"); //화면의 줄을 띄운다.
		}

	}

	return 0;
}