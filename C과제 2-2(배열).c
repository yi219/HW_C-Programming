#include <stdio.h>

//편의상 첫 번째 문자열을 전체 문자열, 두 번째 문자열을 부분 문자열이라 칭하겠습니다.

void change(int j, int length, char* sentence);
char input(char* ptr_sent);

int main(void)
{
	char sent[1000] = { 0 }; //전체 문자열의 배열을 선언한다.
	char first; //부분 문자열의 첫 번째 글자

	printf("전체 문자열을 입력하시오 : "); //화면에 '전체 문자열을 입력하시오 : '를 출력한다.
	gets(sent); //문자열을 받아 전체 문자열의 배열에 저장한다.

	/*
	부분 문자열의 첫 글자가 #이 아닌 경우, 프로그램을 반복한다.
	*/
	do
	{
		first = input(sent); //input 함수에 sent를 전달한다.
	} while (first != '#');

	return 0;
}

/*
함수 이름 : change
기능 : 인자로 전달된 정수로 배열 요소에 접근해, 저장된 값을 바꾼다. 이후 문자열을 출력한다.
인자 : int j : 전체 문자열 중 부분 문자열의 끝
	   int length : 부분 문자열의 길이
	   char* sentence : 전체 문자열의 주소
반환값 : -
작성 날짜 : 2019/11/13
작성자 : 금예인
*/
void change(int j, int length, char* sentence)
{
	int k; //값의 증가를 표현하기 위해 변수 k를 선언 (이는 함수 input의 k와 다르다.)

	/*
	length만큼 sentence 요소의 값을 변환한다.
	*/
	for (k = j - length; k < j; k++)
	{
		if (sentence[k] >= 65 && sentence[k] <= 90) //아스키코드를 이용해 소문자를 대문자로 변환한다.
		{
			sentence[k] += 32;
		}
		else if (sentence[k] <= 122 && sentence[k] >= 97) //아스키코드를 이용해 대문자를 소문자로 변환한다.
		{
			sentence[k] -= 32;
		}
	}

	printf("%s\n", sentence); //화면에 변환된 전체 문자열인 sentence를 출력한다.
	return;
}

/*
함수 이름 : input
기능 : 인자로 전달된 배열과 새롭게 받는 문자열을 비교하여 change 함수에 적절한 값을 전달한다.
인자 : char* ptr_sent : 전체 문자열의 주소
반환값 : 부분 문자열의 첫 번째 글자
작성 날짜 : 2019/11/13
작성자 : 금예인
*/
char input(char* ptr_sent)
{
	int i = 0; //길이 계산 시 값의 증가를 표현하기 위해 변수 i를 선언
	int j; //값의 증가를 표현하기 위해 변수 j를 선언 (ptr_sent 요소)
	int k; //값의 증가를 표현하기 위해 변수 k를 선언 (ptr_input 요소) (이는 함수 change의 k와 다르다.)
	int length = 0; //length 선언 - 부분 문자열의 길이 계산
	int p = 0; //전체 문자열 중, 부분 문자열의 첫 글자 포함 여부와 관련된 변수 p를 선언
	char input_chg[1000] = { 0 }; //부분 문자열의 배열을 선언한다.

	printf("대소문자를 변환할 문자열을 입력하시오 : ");
	gets(input_chg); //문자열을 받아 부분 문자열의 배열에 저장한다.

	if (input_chg[0] == '#') //부분 문자열의 첫 글자로 #이 입력된 경우, main 함수로 돌아가 프로그램을 종료한다.
	{
		return input_chg[0];
	}

	for (i = 0; i < 1000; i++) //for문을 사용해 부분 문자열의 길이를 계산한다.
	{
		if (input_chg[i] != 0)
		{
			length += 1;
		}
	}


	for (j = 0; j < 1000; j++) //for문을 사용해 전체 문자열에 부분 문자열의 첫 글자가 포함되는지 확인한다.
	{
		/*전체 문자열에 부분 문자열의 첫 글자가 포함될 경우,
		나머지 글자들의 포함 여부를 확인.*/
		if (ptr_sent[j] == input_chg[0])
		{
			int r = 0; //j의 증가 정도를 확인하기 위해 변수 r을 선언

			p += 1; //전체 문자열에 부분 문자열의 첫 글자가 포함될 경우, p의 값에 1을 더해준다.

			for (k = 0; k < length; k++) //부분 문자열의 길이만큼 전체 문자열의 요소와 부분 문자열의 요소가 같은지 확인한다.
			{
				if (ptr_sent[j] == input_chg[k]) //같다면, j와 r의 값에 1을 더해준다.
				{
					j++;
					r++;
				}
			}

			if (r == length) //j의 증가 정도인 r이 length와 같은 경우
			{
				change(j, length, ptr_sent); //change 함수에 j, length, ptr_sent(전체 문자열의 주소)를 전달한다.
				return input_chg[0]; //부분 문자열을 첫 번째 글자를 반환하며 input 함수를 빠져나간다.
			}
			else //j의 증가 정도인 r이 length와 다른 경우 
			{
				p -= 1; //p에 더해졌던 1을 다시 뺀다.
				j = j - r; //j의 값에서 r을 뺀다.
				continue; //for문의 조건 확인으로 되돌아간다.
			}
		}
	}

	if (p == 0) //부분 문자열의 첫 글자가 전체 문자열에 없을 경우
	{
		printf("결과 : %s을 찾을 수 없습니다.\n", input_chg); //(s: input_chg이 가리키는 문자열)
	}

	return input_chg[0]; //부분 문자열을 첫 번째 글자를 반환하며 input 함수를 빠져나간다.
}
