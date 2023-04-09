//사원번호가 0일 경우는 모두 제외하였습니다.
//각 함수로 전달된 구조체 배열의 인덱스값은 사번과 같도록 하였습니다.

#include <stdio.h>
#include <math.h>
#include <string.h>

void includeEmployee(struct program* ptr);
void search(struct program* address_arr, struct program** array_p);
void statistic(struct program* ptr);

struct program
{
	int empNum;
	char name[20];
	char part[20];
	int first;
	int second;
	double total;
};

int main(void)
{
	struct program arr[1000] = { 0, 0, 0, 0, 0, 0 }; //구조체 변수 배열 선언

	int num = 0; //1. 직원추가 2. 검색 3. 통계 4. 종료 중 입력된 번호
	int i = 0;
	struct program* ptr = arr; //구조체 배열을 가리키는 포인터 ptr
	struct program* array_p[1000] = { 0 }; //구조체 배열을 가리키는 포인터 배열 array

	for (i = 0; i < 1000; i++)
	{
		array_p[i] = &arr[i];
	}

	/*
	채점을 위한 세 직원의 정보
	*/
	arr[11].empNum = 11; strcpy(arr[11].name, "K.Han"); strcpy(arr[11].part, "Marketting"); arr[11].first = 90; arr[11].second = 80; arr[11].total = (double)(arr[11].first + arr[11].second) / 2;
	arr[12].empNum = 12; strcpy(arr[12].name, "A.Lee"); strcpy(arr[12].part, "Sales"); arr[12].first = 80; arr[12].second = 80; arr[12].total = (double)(arr[12].first + arr[12].second) / 2;
	arr[13].empNum = 13; strcpy(arr[13].name, "Y.Kim"); strcpy(arr[13].part, "Marketting"); arr[13].first = 90; arr[13].second = 70; arr[13].total = (double)(arr[13].first + arr[13].second) / 2;

	/*
	입력된 번호에 따라,
	적절한 함수를 실행한다.
	단, 4가 입력되면 프로그램을 종료하고,
	1, 2, 3, 4 이외의 수가 입력되면 재입력을 요구한다.
	*/
	while (1)
	{
		printf("1. 직원 추가\n2. 검색\n3. 통계\n4. 종료\n->번호를 선택하시오 : ");
		scanf("%d", &num);
		printf("\n");

		if (num == 1)
		{
			printf("1. 직원 추가\n");
			includeEmployee(ptr);
		}
		else if (num == 2)
		{
			printf("2. 검색\n");
			search(ptr, array_p);
		}
		else if (num == 3)
		{
			printf("3. 통계\n");
			statistic(ptr);
		}
		else if (num == 4)
		{
			printf("프로그램을 종료합니다.");
			return;
		}
		else
		{
			printf("- 다른 메뉴를 선택하세요 !\n");
		}
	}

	return 0;
}
/*
함수 이름 : includeEmployee
기능 : 인자로 전달된 구조체 배열 중 한 요소의 멤버에 값을 저장한다.
인자 : struct program* ptr : 메인 함수에서 선언한 구조체 배열의 주소
반환값 : -
작성 날짜 : 2019.12.02
작성자 : 금예인
*/
void includeEmployee(struct program* ptr)
{
	int num; //사번 num

	while (1)
	{
		num = 1000; //사번에 0~999가 아닌 수 1000을 저장한다.

		printf("사번 이름 부서 전반기점수 하반기점수를 입력하시오 : ");
		scanf_s("%d", &num); //배열 ptr의 인덱스값을 사번으로 하기 위해, 사번을 먼저 입력 받는다.

		/*
		입력 받은 사번을 바탕으로 구조체 배열에 접근해 멤버들의 값을 저장한다.
		*/
		if ((ptr + num)->empNum == 0)
		{
			(ptr + num)->empNum = num;
			scanf("%s", (ptr + num)->name);
			scanf("%s", (ptr + num)->part);
			scanf("%d", &((ptr + num)->first));
			scanf("%d", &((ptr + num)->second));
			(ptr + num)->total = (double)((ptr + num)->first + (ptr + num)->second) / 2;

			if (num == 0) //사원번호가 0일 경우, 재입력을 요구한 후 반복문을 탈출한다.
			{
				printf("- 사원번호 0은 존재하지 않습니다. 재입력하시오.\n");
				break;
			}

			printf("\n");

			return;
		}

		/*
		사원번호가 존재할 경우, 사용하지 않는 인덱스값 0의 멤버에 값을 저장한다.
		이후, 재입력을 요구한다.
		*/
		else if ((ptr + num)->empNum == num)
		{
			(ptr)->empNum = 0;
			scanf("%s", (ptr)->name);
			scanf("%s", (ptr)->part);
			scanf("%d", &((ptr)->first));
			scanf("%d", &((ptr)->second));
			(ptr)->total = (double)((ptr)->first + (ptr)->second) / 2;
			printf(" - 이미 존재하는 사번입니다. 재입력하시오\n");
		}

	}

	includeEmployee(ptr); //사원번호가 0일 경우 반복문을 탈출하고도 재입력이 가능하도록 함수를 다시 실행한다.

}

/*
함수 이름 : search
기능 : 인자로 전달된 구조체 배열의 요소들의 멤버를 탐색해, 사번 또는 총점으로 검색한 결과를 출력한다.
인자 : struct program* address_arr : 메인 함수에서 선언한 구조체 배열의 주소
	   struct program** array_p : 메인 함수에서 선언한 구조체 배열을 가리키는 포인터 배열의 주소
반환값 : -
작성 날짜 : 2019.12.02
작성자 : 금예인
*/
void search(struct program* address_arr, struct program** array_p)
{
	int method; //1)사번 2)부서 중 선택한 방법
	int number; //사번
	char partment[20]; //부서
	int i;
	int j;
	struct program* temp; //array_p의 요소가 가리키는 구조체 배열의 요소를 변경하기 위해 필요한 포인터 temp

	/*
	부서 입력의 경우 총점순으로 출력해야하므로 새로운 포인터 temp와 인자로 전달된 포인터 배열 array를 이용한다.
	총점 total 값의 크기에 따라 array_p의 요소가 가리키는 구조체 배열의 요소를 변경하였다.
	이때, 사번이 존재하는 경우만을 따지기 위해
	array[i]->empNum != 0, array[j]->empNum != 0 문장을 삽입하였다.
	*/
	for (i = 1; i < 999; i++)
	{
		if (array_p[i]->empNum != 0)
		{
			for (j = i + 1; j < 1000; j++)
			{
				if (array_p[j]->empNum != 0)
				{
					if (array_p[i]->total < array_p[j]->total)
					{
						temp = array_p[j];
						array_p[j] = array_p[i];
						array_p[i] = temp;
					}
				}
			}
		}

	}

	printf("1)사번     2)부서\n");
	printf("- 검색 방법을 선택하시오. : ");
	scanf_s("%d", &method);

	/*
	사번을 선택한 경우
	*/
	if (method == 1)
	{
		while (1)
		{
			printf("- 사번을 입력하시오. : ");
			scanf_s("%d", &number);

			if (number == 0) //사번 0이 입력된 경우, 재입력을 요구한다.
			{
				printf("- 사원번호 0은 존재하지 않습니다. 재입력하시오.\n");
				continue;
			}
			else //0 이외의 사번이 입력된 경우, 일치하는 사번을 검색해 사원 정보를 출력한다.
			{
				for (i = 1; i < 1000; i++)
				{
					if ((address_arr + i)->empNum == number)
					{
						(address_arr + i)->total = (double)((address_arr + i)->first + (address_arr + i)->second) / 2;
						printf("사번           이름           부서           전반기점수     하반기점수     총점\n");
						printf("%-14d %-14s %-14s %-14d %-14d %-14.1f\n\n", (address_arr + i)->empNum, (address_arr + i)->name, (address_arr + i)->part, (address_arr + i)->first, (address_arr + i)->second, (address_arr + i)->total);
						return;
					}
				}
			}

			/*
			사번이 존재하지 않을 경우, 위의 반복문에 따라 i 값이 1000이 되므로
			이를 이용해 "- 존재하지 않는 사번입니다. 재입력하시오."를 출력한다.(재입력을 요구한다.)
			*/
			if (i == 1000)
			{
				printf("- 존재하지 않는 사번입니다. 재입력하시오.\n");
			}
		}

	}

	/*
	부서를 선택한 경우
	*/
	else if (method == 2)
	{
		while (1)
		{
			int k = 1;

			printf("- 부서를 입력하시오. : ");
			scanf("%s", partment);

			/*
			부서가 존재하지 않을 경우, 아래 반복문에 따라 k 값이 1000이 되므로
			이를 이용해 "- 존재하지 않는 부서입니다. 재입력하시오."를 출력한다. (재입력을 요구한다.)
			*/
			for (i = 1; i < 1000; i++)
			{
				if (strcmp(partment, array_p[i]->part) != 0)
				{
					k++;
				}
			}
			if (k == 1000)
			{
				printf("- 존재하지 않는 부서입니다. 재입력하시오.\n");
				continue;
			}

			/*
			부서가 존재할 경우,
			두 문자열이 동일하면 0을 반환하는 함수 strcmp를 사용해
			사원 정보를 총점순으로 나열한 구조체 배열을 가리키는 포인터 배열 array_p를 사용해 사원 정보를 출력한다.
			*/
			for (i = 1; i < 1000; i++)
			{
				if (strcmp(partment, array_p[i]->part) == 0)
				{
					printf("사번           이름           부서           전반기점수     하반기점수     총점\n");
					printf("%-14d %-14s %-14s %-14d %-14d %-14.1f\n\n", array_p[i]->empNum, array_p[i]->name, array_p[i]->part, array_p[i]->first, array_p[i]->second, array_p[i]->total);
				}
			}
			return;
		}

	}

	/*
	1) 사번 2) 부서 이외의 수를 선택한 경우
	재입력을 요구한다.
	*/
	else
	{
		printf("- 다른 메뉴를 선택하세요!\n");
		search(address_arr, array_p);
	}



}

/*
함수 이름 : statistic
기능 : 인자로 전달된 구조체 배열에 대한 통계값을 계산하고 출력한다.
인자 : struct program* ptr : 메인 함수에서 선언한 구조체 배열의 주소
반환값 : -
작성 날짜 : 2019.12.02
작성자 : 금예인
*/
void statistic(struct program* ptr)
{
	int i;
	int people = 0; //사원 수
	int total1 = 0; //전반기 점수의 합
	int total2 = 0; //후반기 점수의 합
	double aver1; //전반기 점수의 평균
	double aver2; //후반기 점수의 평균
	double standard1; //전반기 점수의 표준편차
	double standard2; //후반기 점수의 표준편차
	double doubTot1 = 0; //(전반기 점수 - 평균)^2의 합
	double doubTot2 = 0; //(후반기 점수 - 평균)^2의 합

	/*
	사원의 수를 세아린다.
	*/
	for (i = 1; i < 1000; i++)
	{
		if ((ptr + i)->empNum != 0)
		{
			people++;
		}
	}

	/*
	전반기 점수의 합을 계산한다
	*/
	for (i = 1; i < 1000; i++)
	{
		total1 += (ptr + i)->first;
	}
	aver1 = total1 / people;

	/*
	후반기 점수의 합을 계산한다
	*/
	for (i = 1; i < 1000; i++)
	{
		total2 += ((ptr + i)->second);
	}
	aver2 = total2 / people;

	/*
	(전반기 점수 - 평균)^2의 합을 계산하고,
	전반기 점수의 표준편차를 계산한다.
	*/
	for (i = 1; i < 1000; i++)
	{
		if ((ptr + i)->empNum != 0)
		{
			doubTot1 += (((ptr + i)->first) - aver1) * (((ptr + i)->first) - aver1);
		}
	}
	standard1 = sqrt(doubTot1 / people);

	/*
	(후반기 점수 - 평균)^2의 합을 계산하고,
	후반기 점수의 표준편차를 계산한다.
	*/
	for (i = 1; i < 100; i++)
	{
		if ((ptr + i)->empNum != 0)
		{
			doubTot2 += ((ptr + i)->second - aver2) * ((ptr + i)->second - aver2);
		}
	}
	standard2 = sqrt(doubTot2 / people);

	/*
	통계값들을 출력한다.
	*/
	printf("전반기 -> 평균 : %.1f 표준편차 : %.1f\n", aver1, standard1);
	printf("하반기 -> 평균 : %.1f 표준편차 : %.1f\n\n", aver2, standard2);
}
