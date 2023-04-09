//�����ȣ�� 0�� ���� ��� �����Ͽ����ϴ�.
//�� �Լ��� ���޵� ����ü �迭�� �ε������� ����� ������ �Ͽ����ϴ�.

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
	struct program arr[1000] = { 0, 0, 0, 0, 0, 0 }; //����ü ���� �迭 ����

	int num = 0; //1. �����߰� 2. �˻� 3. ��� 4. ���� �� �Էµ� ��ȣ
	int i = 0;
	struct program* ptr = arr; //����ü �迭�� ����Ű�� ������ ptr
	struct program* array_p[1000] = { 0 }; //����ü �迭�� ����Ű�� ������ �迭 array

	for (i = 0; i < 1000; i++)
	{
		array_p[i] = &arr[i];
	}

	/*
	ä���� ���� �� ������ ����
	*/
	arr[11].empNum = 11; strcpy(arr[11].name, "K.Han"); strcpy(arr[11].part, "Marketting"); arr[11].first = 90; arr[11].second = 80; arr[11].total = (double)(arr[11].first + arr[11].second) / 2;
	arr[12].empNum = 12; strcpy(arr[12].name, "A.Lee"); strcpy(arr[12].part, "Sales"); arr[12].first = 80; arr[12].second = 80; arr[12].total = (double)(arr[12].first + arr[12].second) / 2;
	arr[13].empNum = 13; strcpy(arr[13].name, "Y.Kim"); strcpy(arr[13].part, "Marketting"); arr[13].first = 90; arr[13].second = 70; arr[13].total = (double)(arr[13].first + arr[13].second) / 2;

	/*
	�Էµ� ��ȣ�� ����,
	������ �Լ��� �����Ѵ�.
	��, 4�� �ԷµǸ� ���α׷��� �����ϰ�,
	1, 2, 3, 4 �̿��� ���� �ԷµǸ� ���Է��� �䱸�Ѵ�.
	*/
	while (1)
	{
		printf("1. ���� �߰�\n2. �˻�\n3. ���\n4. ����\n->��ȣ�� �����Ͻÿ� : ");
		scanf("%d", &num);
		printf("\n");

		if (num == 1)
		{
			printf("1. ���� �߰�\n");
			includeEmployee(ptr);
		}
		else if (num == 2)
		{
			printf("2. �˻�\n");
			search(ptr, array_p);
		}
		else if (num == 3)
		{
			printf("3. ���\n");
			statistic(ptr);
		}
		else if (num == 4)
		{
			printf("���α׷��� �����մϴ�.");
			return;
		}
		else
		{
			printf("- �ٸ� �޴��� �����ϼ��� !\n");
		}
	}

	return 0;
}
/*
�Լ� �̸� : includeEmployee
��� : ���ڷ� ���޵� ����ü �迭 �� �� ����� ����� ���� �����Ѵ�.
���� : struct program* ptr : ���� �Լ����� ������ ����ü �迭�� �ּ�
��ȯ�� : -
�ۼ� ��¥ : 2019.12.02
�ۼ��� : �ݿ���
*/
void includeEmployee(struct program* ptr)
{
	int num; //��� num

	while (1)
	{
		num = 1000; //����� 0~999�� �ƴ� �� 1000�� �����Ѵ�.

		printf("��� �̸� �μ� ���ݱ����� �Ϲݱ������� �Է��Ͻÿ� : ");
		scanf_s("%d", &num); //�迭 ptr�� �ε������� ������� �ϱ� ����, ����� ���� �Է� �޴´�.

		/*
		�Է� ���� ����� �������� ����ü �迭�� ������ ������� ���� �����Ѵ�.
		*/
		if ((ptr + num)->empNum == 0)
		{
			(ptr + num)->empNum = num;
			scanf("%s", (ptr + num)->name);
			scanf("%s", (ptr + num)->part);
			scanf("%d", &((ptr + num)->first));
			scanf("%d", &((ptr + num)->second));
			(ptr + num)->total = (double)((ptr + num)->first + (ptr + num)->second) / 2;

			if (num == 0) //�����ȣ�� 0�� ���, ���Է��� �䱸�� �� �ݺ����� Ż���Ѵ�.
			{
				printf("- �����ȣ 0�� �������� �ʽ��ϴ�. ���Է��Ͻÿ�.\n");
				break;
			}

			printf("\n");

			return;
		}

		/*
		�����ȣ�� ������ ���, ������� �ʴ� �ε����� 0�� ����� ���� �����Ѵ�.
		����, ���Է��� �䱸�Ѵ�.
		*/
		else if ((ptr + num)->empNum == num)
		{
			(ptr)->empNum = 0;
			scanf("%s", (ptr)->name);
			scanf("%s", (ptr)->part);
			scanf("%d", &((ptr)->first));
			scanf("%d", &((ptr)->second));
			(ptr)->total = (double)((ptr)->first + (ptr)->second) / 2;
			printf(" - �̹� �����ϴ� ����Դϴ�. ���Է��Ͻÿ�\n");
		}

	}

	includeEmployee(ptr); //�����ȣ�� 0�� ��� �ݺ����� Ż���ϰ� ���Է��� �����ϵ��� �Լ��� �ٽ� �����Ѵ�.

}

/*
�Լ� �̸� : search
��� : ���ڷ� ���޵� ����ü �迭�� ��ҵ��� ����� Ž����, ��� �Ǵ� �������� �˻��� ����� ����Ѵ�.
���� : struct program* address_arr : ���� �Լ����� ������ ����ü �迭�� �ּ�
	   struct program** array_p : ���� �Լ����� ������ ����ü �迭�� ����Ű�� ������ �迭�� �ּ�
��ȯ�� : -
�ۼ� ��¥ : 2019.12.02
�ۼ��� : �ݿ���
*/
void search(struct program* address_arr, struct program** array_p)
{
	int method; //1)��� 2)�μ� �� ������ ���
	int number; //���
	char partment[20]; //�μ�
	int i;
	int j;
	struct program* temp; //array_p�� ��Ұ� ����Ű�� ����ü �迭�� ��Ҹ� �����ϱ� ���� �ʿ��� ������ temp

	/*
	�μ� �Է��� ��� ���������� ����ؾ��ϹǷ� ���ο� ������ temp�� ���ڷ� ���޵� ������ �迭 array�� �̿��Ѵ�.
	���� total ���� ũ�⿡ ���� array_p�� ��Ұ� ����Ű�� ����ü �迭�� ��Ҹ� �����Ͽ���.
	�̶�, ����� �����ϴ� ��츸�� ������ ����
	array[i]->empNum != 0, array[j]->empNum != 0 ������ �����Ͽ���.
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

	printf("1)���     2)�μ�\n");
	printf("- �˻� ����� �����Ͻÿ�. : ");
	scanf_s("%d", &method);

	/*
	����� ������ ���
	*/
	if (method == 1)
	{
		while (1)
		{
			printf("- ����� �Է��Ͻÿ�. : ");
			scanf_s("%d", &number);

			if (number == 0) //��� 0�� �Էµ� ���, ���Է��� �䱸�Ѵ�.
			{
				printf("- �����ȣ 0�� �������� �ʽ��ϴ�. ���Է��Ͻÿ�.\n");
				continue;
			}
			else //0 �̿��� ����� �Էµ� ���, ��ġ�ϴ� ����� �˻��� ��� ������ ����Ѵ�.
			{
				for (i = 1; i < 1000; i++)
				{
					if ((address_arr + i)->empNum == number)
					{
						(address_arr + i)->total = (double)((address_arr + i)->first + (address_arr + i)->second) / 2;
						printf("���           �̸�           �μ�           ���ݱ�����     �Ϲݱ�����     ����\n");
						printf("%-14d %-14s %-14s %-14d %-14d %-14.1f\n\n", (address_arr + i)->empNum, (address_arr + i)->name, (address_arr + i)->part, (address_arr + i)->first, (address_arr + i)->second, (address_arr + i)->total);
						return;
					}
				}
			}

			/*
			����� �������� ���� ���, ���� �ݺ����� ���� i ���� 1000�� �ǹǷ�
			�̸� �̿��� "- �������� �ʴ� ����Դϴ�. ���Է��Ͻÿ�."�� ����Ѵ�.(���Է��� �䱸�Ѵ�.)
			*/
			if (i == 1000)
			{
				printf("- �������� �ʴ� ����Դϴ�. ���Է��Ͻÿ�.\n");
			}
		}

	}

	/*
	�μ��� ������ ���
	*/
	else if (method == 2)
	{
		while (1)
		{
			int k = 1;

			printf("- �μ��� �Է��Ͻÿ�. : ");
			scanf("%s", partment);

			/*
			�μ��� �������� ���� ���, �Ʒ� �ݺ����� ���� k ���� 1000�� �ǹǷ�
			�̸� �̿��� "- �������� �ʴ� �μ��Դϴ�. ���Է��Ͻÿ�."�� ����Ѵ�. (���Է��� �䱸�Ѵ�.)
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
				printf("- �������� �ʴ� �μ��Դϴ�. ���Է��Ͻÿ�.\n");
				continue;
			}

			/*
			�μ��� ������ ���,
			�� ���ڿ��� �����ϸ� 0�� ��ȯ�ϴ� �Լ� strcmp�� �����
			��� ������ ���������� ������ ����ü �迭�� ����Ű�� ������ �迭 array_p�� ����� ��� ������ ����Ѵ�.
			*/
			for (i = 1; i < 1000; i++)
			{
				if (strcmp(partment, array_p[i]->part) == 0)
				{
					printf("���           �̸�           �μ�           ���ݱ�����     �Ϲݱ�����     ����\n");
					printf("%-14d %-14s %-14s %-14d %-14d %-14.1f\n\n", array_p[i]->empNum, array_p[i]->name, array_p[i]->part, array_p[i]->first, array_p[i]->second, array_p[i]->total);
				}
			}
			return;
		}

	}

	/*
	1) ��� 2) �μ� �̿��� ���� ������ ���
	���Է��� �䱸�Ѵ�.
	*/
	else
	{
		printf("- �ٸ� �޴��� �����ϼ���!\n");
		search(address_arr, array_p);
	}



}

/*
�Լ� �̸� : statistic
��� : ���ڷ� ���޵� ����ü �迭�� ���� ��谪�� ����ϰ� ����Ѵ�.
���� : struct program* ptr : ���� �Լ����� ������ ����ü �迭�� �ּ�
��ȯ�� : -
�ۼ� ��¥ : 2019.12.02
�ۼ��� : �ݿ���
*/
void statistic(struct program* ptr)
{
	int i;
	int people = 0; //��� ��
	int total1 = 0; //���ݱ� ������ ��
	int total2 = 0; //�Ĺݱ� ������ ��
	double aver1; //���ݱ� ������ ���
	double aver2; //�Ĺݱ� ������ ���
	double standard1; //���ݱ� ������ ǥ������
	double standard2; //�Ĺݱ� ������ ǥ������
	double doubTot1 = 0; //(���ݱ� ���� - ���)^2�� ��
	double doubTot2 = 0; //(�Ĺݱ� ���� - ���)^2�� ��

	/*
	����� ���� ���Ƹ���.
	*/
	for (i = 1; i < 1000; i++)
	{
		if ((ptr + i)->empNum != 0)
		{
			people++;
		}
	}

	/*
	���ݱ� ������ ���� ����Ѵ�
	*/
	for (i = 1; i < 1000; i++)
	{
		total1 += (ptr + i)->first;
	}
	aver1 = total1 / people;

	/*
	�Ĺݱ� ������ ���� ����Ѵ�
	*/
	for (i = 1; i < 1000; i++)
	{
		total2 += ((ptr + i)->second);
	}
	aver2 = total2 / people;

	/*
	(���ݱ� ���� - ���)^2�� ���� ����ϰ�,
	���ݱ� ������ ǥ�������� ����Ѵ�.
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
	(�Ĺݱ� ���� - ���)^2�� ���� ����ϰ�,
	�Ĺݱ� ������ ǥ�������� ����Ѵ�.
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
	��谪���� ����Ѵ�.
	*/
	printf("���ݱ� -> ��� : %.1f ǥ������ : %.1f\n", aver1, standard1);
	printf("�Ϲݱ� -> ��� : %.1f ǥ������ : %.1f\n\n", aver2, standard2);
}
