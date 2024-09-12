/*
메모리 페이지 개수 등은 상수로 정의
파일로부터 참조된 페이지 번호들을 읽는다.
페이지 폴트 회수 출력
페이지 테이블은 구현할 필요 없음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PAGE_NUM 6 // 메모리 페이지 개수
#define MAXSIZE 3 // page frame

typedef struct PAGE
{
	int number; 
	struct PAGE *next;
	struct PAGE *prev;
}mypage;

void initlink(mypage* page)
{
	page->next = NULL;
	page->prev = NULL;
}

int lencheck(mypage* head)
{
	int count = 0;
	while (head->number != 999)
	{
		count++;
		head = head->next;
	}
	return count;
}

int main(void)
{
	int len = 0;
	char buffer[30] = {0, };
	int ref[30] = { 0, };
	int n = 0;
	mypage* mypages[PAGE_NUM];
	for (int i = 0; i < PAGE_NUM; i++) {
		mypages[i] = (mypage*)malloc(sizeof(mypage));
	}

	// 각 페이지들을 초기화
	mypages[0]->number = 0;
	initlink(mypages[0]);
	mypages[1]->number = 1;
	initlink(mypages[1]);
	mypages[2]->number = 2;
	initlink(mypages[2]);
	mypages[3]->number = 3;
	initlink(mypages[3]);
	mypages[4]->number = 4;
	initlink(mypages[4]);
	mypages[5]->number = 5;
	initlink(mypages[5]);

	// 이중 연결리스트를 위한 head와 tail
	mypage* head = (mypage*)malloc(sizeof(mypage));
	mypage* tail = (mypage*)malloc(sizeof(mypage));
	head->prev = head;
	head->next = tail;
	head->number = -1;
	tail->prev = head;
	tail->next = tail;
	tail->number = 999;

	// reference string을 txt파일에 저장 후 불러옴
	FILE* fp = fopen("file.txt", "r");   
	fgets(buffer, sizeof(buffer), fp);
	fclose(fp);

	for (int i = 0; i < sizeof(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\0')
		{
			ref[n] = buffer[i] - '0';
			n++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < PAGE_NUM; j++)
		{
			if (mypages[j]->number == ref[i])
			{
				// cache hit
				if (mypages[j]->next == NULL && mypages[j]->prev == NULL)
				{
					len = lencheck(head);
					if (len > MAXSIZE)
					{
						printf("page fault occur!!  page number %d's page!!\n", tail->prev->number);
						int a = tail->prev->number;
						tail->prev->prev->next = tail;
						tail->prev = tail->prev->prev;
						for (int k = 0; k < PAGE_NUM; k++)
						{
							if (mypages[k]->number == a)
							{
								initlink(mypages[k]);
							}
						}
					}
					mypages[j]->prev = head;
					mypages[j]->next = head->next;
					head->next->prev = mypages[j];
					head->next = mypages[j];
				}
				// cache miss
				else
				{
					if (head->next != mypages[j])
					{
						mypages[j]->prev->next = mypages[j]->next;
						mypages[j]->next->prev = mypages[j]->prev;

						mypages[j]->prev = head;
						mypages[j]->next = head->next;
						head->next->prev = mypages[j];
						head->next = mypages[j];
					}
				}
				printf("head : %d, tail : %d\n", head->next->number, tail->prev->number);
			}
		}
	}

	free(head);
	for (int i = 0; i < PAGE_NUM; i++) {
		free(mypages[i]);
	}
	return 0;
}