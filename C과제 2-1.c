#include <stdio.h>

int mulitply_poly(int A[], int B[], int C[], int n1, int n2);
int input_poly(int A[], int end);
void poly_exam(int A[], int B[], int* n1_p, int* n2_p);

int main(void)
{
	int arrA[10];
	int arrB[10];
	int arrC[19];
	int p; //단순한 증가 연산을 위한 변수
	int n1 = 0; //arrA[] 다항식의 최대 차수 n1
	int n2 = 0; //arrB[] 다항식의 최대 차수 n2
	int* p_n1 = &n1; //n1을 가리키는 포인터 변수
	int* p_n2 = &n2; //n2를 가리키는 포인터 변수

	printf("다항식 두 개를 한 행으로 입력하시오 : ");

	poly_exam(arrA, arrB, p_n1, p_n2); //poly_exam 함수를 통해 arrA[]와 arrB[]를 완성한 후 두 다항식의 계수 범위를 확인한다.

	/*
	배열로 표현된, 두 다항식 arrA와 arrB를 곱한 다항식 arrC[]를 출력한다.
	*/
	printf("결과 다항식 : ");
	for (p = 0; p < mulitply_poly(arrA, arrB, arrC, *p_n1, *p_n2); p++)
	{
		printf("%d ", arrC[p]);
	}

	return 0;
}

/*
함수 이름 : multiply_poly
기능 : 인자로 전달된 배열로 표현된 두 다항식의 곱을 또다른 배열에 저장한다.
인자 : int A[] : 배열로 표현된 첫 번째 다항식
	   int B[] : 배열로 표현된 두 번째 다항식
	   int C[] : 두 다항식의 곱을 저장할 배열
	   int n1 : arrA[] 다항식의 최대 차수 n1
	   int n2 : arrB[] 다항식의 최대 차수 n2
반환값 : C[] 다항식의 최대 차수
작성 날짜 : 2019/11/13
작성자 : 금예인
*/
int mulitply_poly(int A[], int B[], int C[], int n1, int n2)
{
	int m; //C[] 다항식의 차수를 나타낼 변수 m
	int c; //C[] 다항식의 계수를 계산하기 위한 변수 c

	/*
	A[]와 B[]의 배열 요소를 이용해 C[] 다항식의 계수를 계산한 뒤, 값을 저장한다.
	*/
	for (m = 0; m <= n1 + n2; m++)
	{
		int total = 0;
		for (c = 0; c <= m; c++)
		{
			total += A[c] * B[m - c];
		}
		C[m] = total;

	}

	return n1 + n2 + 1; //C[] 다항식의 최대 차수를 반환
}

/*
함수 이름 : input_poly
기능 : 다항식을 입력 받아 poly[] 배열 요소에 저장한다.
인자 : int poly[] : 다항식을 저장할 배열
	   int end : 다항식의 끝을 나타내는 정수
반환값 : 입력 받은 다항식의 최대 차수
작성 날짜 : 2019/11/13
작성자 : 금예인
*/
int input_poly(int poly[], int end)
{
	int num; //입력 받은 정수
	int i;
	int high_n = 0; //입력 받은 다항식의 최대 차수를 나타낼 변수 high_n

	/*
	다항식을 입력 받아 poly[] 배열 요소에 저장한다.
	이때, 입력 받은 정수가 end와 일치한다면 남은 배열 요소에 0을 저장한다.
	*/
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &num);

		if (num == end) //입력 받은 정수가 end와 일치하는 경우
		{
			high_n = i - 1; //다항식의 최대 차수는 i-1
			for (; i < 10; i++)
			{
				poly[i] = 0; //남은 배열 요소에 0을 저장
			}
		}
		else //입력 받은 정수가 end와 일치하지 않는 경우
		{
			poly[i] = num; //입력 받은 정수를 poly[]의 배열 요소에 저장
		}
	}

	return high_n; //입력 받은 다항식의 최대 차수 반환
}

/*
함수 이름 : poly_exam
기능 : 배열을 입력 받고, 배열로 표현된 두 다항식의 계수들이 -99~99 범위 조건을 만족하는지 확인한다.
인자 : int A[] : 첫 번째 다항식
	   int B[] : 두 번째 다항식
	   int* n1_p : 첫 번째 다항식 최대 차수값의 주소
	   int* n2_p : 두 번째 다항식 최대 차수값의 주소
반환값 : -
작성 날짜 : 2019/11/13
작성자 : 금예인
*/
void poly_exam(int A[], int B[], int* n1_p, int* n2_p)
{
	int j;

	*n1_p = input_poly(A, -100); //input_poly 함수를 통해 배열로 표현된 다항식 A를 완성한다.
	*n2_p = input_poly(B, -1000); //input_poly 함수를 통해 배열로 표현된 다항식 B를 완성한다.

	/*
	두 다항식의 모든 계수가 -99~99 범위 조건을 만족하는지 확인한다.
	*/
	for (j = 0; j < 10; j++)
	{
		if (A[j] < -99 || A[j]>99 || B[j] < -99 || B[j]>99) //조건을 만족하지 않을 경우
		{
			printf("처음부터 다시 입력하시오 : "); //화면에 재입력 문구를 출력한다.
			for (j = 0; j < 10; j++) //재입력을 위해 A[]와 B[]의 모든 배열 요소에 0을 저장한다.
			{
				A[j] = 0;
				B[j] = 0;
			}
			poly_exam(A, B, n1_p, n2_p); //poly_exam 함수를 다시 실행한다.
		}
	}

}