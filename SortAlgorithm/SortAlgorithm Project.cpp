/* 기초 프로젝트I
프로젝트명: SortAlgorithm Project
조 번호 : 5조
개발자 : 김성민, 이재문, 최준혁
개발 일자 : 18.05.04 ~ 18.06.04
프로그램 설명 : 삽입정렬,선택정렬,퀵정렬,히프정렬,셀정렬을 이용한 알고리즘 효율성 체크
화면버퍼 크기 :  120*9001
창크기 : 120*30
*/
#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x)        ((x-1)/2)
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환

typedef int element;

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int h = 0;
int s = 0;
long long cnt1 = 0; //비교
long long cnt2 = 0; //자리 교환
void gotoxy(int x, int y); // 초기화면_1
void prog(); //초기화면_2
void Testrandom(int arr[]); //테스트용 난수생성
void random(int arr[]); //난수 10만개 생성
void insertionsort(int arr[], int len); //삽입정렬
void selectionsort(int arr[], int len); //선택정렬
void intervalSort(element arr[], int begin, int end, int interval); //셀정렬 부분 집합
void intervalSort2(element arr[], int begin, int end, int interval); //셸정렬 부분 집합2
void shellionsort(int arr[], int  len); //셀 정렬
void InitHeap(int *base, int n); //히프초기화
void MakeHeap(int *base, int n); //히프생성
void HeapSort(int *base, int n); //히프정렬
int FindMaxIndex(int *base, int n, int now);//히프정렬 인덱스 검색
void ViewArr2(int *arr, int n); //히프정렬 테스트 출력2
void ViewArr(int *arr, int n); //히프정렬 테스트 출력1
void InitHeap2(int *base, int n);//히프정렬 본프로그램 용
void MakeHeap2(int *base, int n);//히프정렬 본프로그램 용
void HeapSort2(int *base, int n);//히프정렬 본프로그램 용
int FindMaxIndex2(int *base, int n, int now);//히프정렬 본프로그램 용
void quickSort(int left, int right, int* data);//퀵 정렬
void quickSort2(int left, int right, int* data);//퀵 정렬 본프로그램 용
void Testa(int arr[]);  //알고리즘 테스트

/*메인 함수*/
int main()
{
	int Arr1[100000], Arr2[100000];
	int Testarr1[20], Testarr2[20];
	int num = 0, a, len, time = 0;

	clock_t start, end;
	Testrandom(Testarr1);

	prog();
	system("pause");
	while (num != 6) {
		s = 0;

		system("cls");
		printf("\n\t〓〓〓〓〓〓〓〓 SortAlgorithm Project 〓〓〓〓〓〓〓〓\n\n");
		printf("\t=======================================================\n");
		printf("\t1.삽입 정렬\n\n");
		printf("\t2.선택 정렬\n\n");
		printf("\t3.퀵 정렬\n\n");
		printf("\t4.히프 정렬\n\n");
		printf("\t5.셀 정렬\n\n");
		printf("\t6.프로그램 종료\n\n");
		printf("\t======================================================\n\n\t>");
		scanf_s("%d", &num);
		switch (num) {

		case 1: //삽입 정렬
			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓〓〓삽입 정렬〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("\t1.알고리즘 테스트\n\n\t2.본 프로그램\n\n\t>");
			scanf_s("%d", &a);
			if (a == 1) {
				len = 20;
				for (int i = 0; i < 20; i++) {
					Testarr2[i] = Testarr1[i];
				}
				Testa(Testarr2);
				insertionsort(Testarr2, len);
			}
			else if (a == 2) {
				len = 100000;
				for (int i = 0; i < 20; i++) {
					random(Arr1);
					for (int j = 0; j < 100000; j++) {
						Arr2[j] = Arr1[j];
					}
					start = clock();
					insertionsort(Arr2, len);
					end = clock();
					time = time + (end - start);
				}
				printf("\t정렬시간 : 평균 %d초 \n", (time / 1000) / 20);
				printf("\t자리교환 횟수 : 평균 %llu회 \t비교횟수 : 평균 %llu회 \n\n\t", cnt2 / 20, cnt1 / 20);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");
			}

			break;
		case 2: //선택 정렬
			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓〓〓선택 정렬〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("\t1.알고리즘 테스트\n\n\t2.본 프로그램\n\n\t>");
			scanf_s("%d", &a);
			if (a == 1) {
				len = 20;
				for (int i = 0; i < 20; i++) {
					Testarr2[i] = Testarr1[i];
				}
				Testa(Testarr2);
				selectionsort(Testarr2, len);
			}
			else if (a == 2) {
				len = 100000;
				for (int i = 0; i < 20; i++) {
					random(Arr1);
					for (int j = 0; j < 100000; j++) {
						Arr2[j] = Arr1[j];
					}
					start = clock();
					selectionsort(Arr2, len);
					end = clock();
					time = time + (end - start);
				}
				printf("\t정렬시간 : 평균 %d초 \n", (time / 1000) / 20);
				printf("\t자리교환 횟수 : 평균 %llu회 \t비교횟수 : 평균 %llu회 \n\n\t", cnt2 / 20, cnt1 / 20);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");

			}

			break;
		case 3: //퀵 정렬
			s = 0;
			h = 0;
			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓〓〓〓퀵 정렬〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("\t1.알고리즘 테스트\n\n\t2.본 프로그램\n\n\t>");
			scanf_s("%d", &a);
			if (a == 1) {
				len = 20;
				for (int i = 0; i < 20; i++) {
					Testarr2[i] = Testarr1[i];
				}
				Testa(Testarr2);
				system("cls");
				printf("\n\n\t〓〓〓〓〓〓〓초기값〓〓〓〓〓〓〓\n\t");
				for (int a = 0; a < len; a++)
					printf("%d ", Testarr2[a]);

				printf("\n\n\t");
				system("pause");
				quickSort(0, len - 1, Testarr2);
				system("cls");
				printf("\n\n\t※※※※※※※※※최종결과※※※※※※※※※\n\t");
				for (int a = 0; a < len; a++)
					printf("%d ", Testarr2[a]);
				printf("\n\n\t");
				printf("자리교환 횟수 : %llu회 \t비교횟수 : %llu회 \n\n\t", cnt2, cnt1);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");
			}
			else if (a == 2) {
				len = 100000;
				for (int i = 0; i < 20; i++) {
					random(Arr1);
					for (int j = 0; j < 100000; j++) {
						Arr2[j] = Arr1[j];
					}
					start = clock();
					quickSort2(0, len - 1, Arr2);
					end = clock();
					time = time + (end - start);
				}
				printf("\t정렬시간 : 평균 %lf초 \n", ((double)time / 1000.0) / 20.0);
				printf("\t자리교환 횟수 : 평균 %llu회 \t비교횟수 : 평균 %llu회 \n\n\t", cnt2 / 20, cnt1 / 20);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");
			}
			break;
		case 4: //히프 정렬
			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓〓〓히프 정렬〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("\t1.알고리즘 테스트\n\n\t2.본 프로그램\n\n\t>");
			scanf_s("%d", &a);
			if (a == 1) {
				len = 20;
				for (int i = 0; i < 20; i++) {
					Testarr2[i] = Testarr1[i];
				}
				Testa(Testarr2);
				system("cls");
				printf("\n\n\t〓〓〓〓〓〓〓초기값〓〓〓〓〓〓〓\n\t");
				for (int a = 0; a < len; a++)
					printf("%d ", Testarr2[a]);

				printf("\n\n\t");
				system("pause");
				system("cls");
				HeapSort(Testarr2, len);
				system("pause");
				system("cls");
				printf("\n\n\t※※※※※※※※※최종결과※※※※※※※※※\n\t");
				ViewArr(Testarr2, len);
				printf("\n\n\t");
				printf("자리교환 횟수 : %llu회 \t비교횟수 : %llu회 \n\n\t", cnt2, cnt1);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");

			}
			else if (a == 2) {
				len = 100000;
				for (int i = 0; i < 20; i++) {
					random(Arr1);
					for (int j = 0; j < 100000; j++) {
						Arr2[j] = Arr1[j];
					}
					start = clock();
					HeapSort2(Arr2, len);
					end = clock();
					time = time + (end - start);
				}
				printf("\t정렬시간 : 평균 %lf초 \n", ((double)time / 1000.0) / 20.0);
				printf("\t자리교환 횟수 : 평균 %llu회 \t비교횟수 : 평균 %llu회 \n\n\t", cnt2 / 20, cnt1 / 20);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");
			}
			break;
		case 5: //셀 정렬
			s = 0;
			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓〓〓셀 정렬〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
			printf("\t1.알고리즘 테스트\n\n\t2.본 프로그램\n\n\t>");
			scanf_s("%d", &a);
			if (a == 1) {
				len = 20;
				for (int i = 0; i < 20; i++) {
					Testarr2[i] = Testarr1[i];
				}
				Testa(Testarr2);
				shellionsort(Testarr2, len);
			}
			else if (a == 2) {
				len = 100000;
				for (int i = 0; i < 20; i++) {
					random(Arr1);
					for (int j = 0; j < 100000; j++) {
						Arr2[j] = Arr1[j];
					}
					start = clock();
					shellionsort(Arr2, len);
					end = clock();
					time = time + (end - start);
				}
				printf("\t정렬시간 : 평균 %lf초 \n", ((double)time / 1000.0) / 20.0);
				printf("\t자리교환 횟수 : 평균 %llu회 \t비교횟수 : 평균 %llu회 \n\n\t", cnt2 / 20, cnt1 / 20);
				cnt1 = 0, cnt2 = 0;
				time = 0;
				system("pause");
			}
			break;
		case 6:
			printf("\n\t프로그램을 종료합니다.\n\n\t");
			break;
		}
	}
	return 0;
}

/*goto xy 함수 정의*/
void gotoxy(int x, int y) {

	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

/*프로그램 설명*/
void prog()
{
	int x = 36;
	int y = 2;
	gotoxy(20, 0);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	for (int i = 1; i < 33; i++) {
		gotoxy(20, i);
		printf("||");
		gotoxy(90, i);
		printf("||");
	}
	gotoxy(x, y);
	printf("〓〓〓〓〓 SortAlgorithm Project 〓〓〓〓〓");
	gotoxy(x, 4);
	printf("조 번호 : 5조");
	gotoxy(x, 6);
	printf("개발자 : 김성민, 이재문, 최준혁");
	gotoxy(x, 8);
	printf("개발 일자 : 18.05.04 ~ 18.06.04");
	gotoxy(x, 10);
	printf("〓〓〓〓프로그램 설명〓〓〓〓");
	gotoxy(x, 12);
	printf("1. 삽입 정렬");
	gotoxy(x, 14);
	printf("2. 선택 정렬");
	gotoxy(x, 16);
	printf("3. 퀵 정렬");
	gotoxy(x, 18);
	printf("4. 히프 정렬");
	gotoxy(x, 20);
	printf("5. 셀 정렬");
	gotoxy(x, 22);
	printf("〓〓〓〓〓기능 구현〓〓〓〓");
	gotoxy(x, 24);
	printf("- 1,2번 최준혁 ");
	gotoxy(x, 26);
	printf("- 3번 이재문");
	gotoxy(x, 28);
	printf("- 4,5번 김성민");
	gotoxy(x, 30);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(20, 32);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(x, 34);
}

/*테스트 난수*/
void Testrandom(int arr[]) {
	int temp = 0;
	srand((unsigned)time(NULL));         //srand로 초기화 (실행마다 같은 난수가 나오지 않게하기 위함)
	bool Check[201] = { false, };     /*생성된 번호가 중복인지 체크할 변수
									  Check라는 논리형 변수에 20만개의 fales 값을 넣어주고 하나의 난수를 받을때마다
									  해당하는 숫자의 배열에 true를 넣어 중복된 난수가 나오지 못하게한다.
									  */
	for (int i = 0; i<20; )              //난수가 20개 생성될 때까지 반복
	{
		int temp = ((rand() << 15) | rand()) % 200 + 1; //1~20 범위의 난수 생성

		if (Check[temp] == false)  //중복 여부 판단
		{
			Check[temp] = true;     //번호가 중복 생성되지 않게 값을 true로 변경
			arr[i] = temp;         //배열에 난수 저장
			i++;                    //if문 만족시 증감을 한다.(중복시 난수 재생성을 위함)
		}
	}
}

/*난수 뽑기*/
void random(int arr[]) {
	srand((unsigned)time(NULL));          //srand로 초기화 (실행마다 같은 난수가 나오지 않게하기 위함)
	int temp = 0;
	bool Check[200001] = { false, };     /*생성된 번호가 중복인지 체크할 변수(인덱스)
										 Check라는 논리 변수에 20만개의 fales 값을 넣어주고 하나의 난수를 받을때마다
										 해당하는 숫자의 배열에 true를 넣어 중복된 난수가 나오지 못하게한다.
										 */
	for (int i = 0; i<100000; )          //난수가 10만개 생성될 때까지 반복
	{
		int temp = ((rand() << 15) | rand()) % 200000 + 1;  //1~200000 범위의 난수 생성

		if (Check[temp] == false)  //중복 여부 판단
		{
			Check[temp] = true;     //번호가 중복 생성되지 않게 값을 true로 변경
			arr[i] = temp;          //배열에 난수 저장
			i++;					//if문 만족시에 증감을 한다.(중복시 난수 재생성을 위함)
		}
	}




}

/*삽입 정렬*/
void insertionsort(int arr[], int len) {
	int i, j, temp = 0, s = 1;
	if (len == 20) {
		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓초기배열〓〓〓〓〓〓〓\n\t");
		for (int s = 0; s < 20; s++) {
			printf("%d ", arr[s]);
		}
		printf("\n\n\t");
		system("pause");
		for (i = 1; i < len; i++)
		{
			temp = arr[i];


			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				cnt1++;//비교
				arr[j + 1] = arr[j];
				cnt2++;//자리교환
				s = 0;
			}
			if (1 != (j >= 0 && arr[j] > temp) && s != 0)
				cnt1++;

			arr[j + 1] = temp;



			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓%d번째〓〓〓〓〓〓〓\n\t", i);
			for (int a = 0; a < len; a++)
				printf("%d ", arr[a]);

			printf("\n\n\t");
			system("pause");
		}
		system("cls");
		printf("\n\n\t※※※※※※※※※최종결과※※※※※※※※※\n\t");
		for (i = 0; i < len; i++)
			printf("%d ", arr[i]);
		printf("\n\n\t");
		printf("자리교환 횟수 : %llu회 \t비교횟수 : %llu회 \n\n\t", cnt2, cnt1);
		cnt1 = 0, cnt2 = 0;
		system("pause");
	}
	else {
		for (i = 1; i < len; i++)
		{
			temp = arr[i];


			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				cnt1++;//비교
				arr[j + 1] = arr[j];
				cnt2++;//자리교환
				s = 0;
			}
			if (1 != (j >= 0 && arr[j] > temp) && s != 0)
				cnt1++;

			arr[j + 1] = temp;

		}
	}
}

/*선택 정렬*/
void selectionsort(int arr[], int len) {
	int i, j, index, temp;
	if (len == 20) {
		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓초기배열〓〓〓〓〓〓〓\n\t");
		for (int s = 0; s < 20; s++) {
			printf("%d ", arr[s]);
		}
		printf("\n\n\t");
		system("pause");
		for (i = 0; i < len - 1; i++)
		{
			index = i;
			for (j = i + 1; j < len; j++)
			{
				if (arr[index] > arr[j])
				{
					index = j;

				}

				cnt1++; // 비교
			}

			if (arr[index]<arr[i])
				cnt2++; // 자리교환
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;



			system("cls");
			printf("\n\n\t〓〓〓〓〓〓〓%d번째〓〓〓〓〓〓〓\n\t", i + 1);
			for (int a = 0; a < len; a++)
				printf("%d ", arr[a]);
			printf("\n\n\t");
			system("pause");
		}
		system("cls");
		printf("\n\n\t※※※※※※※※※최종결과※※※※※※※※※\n\t");
		for (i = 0; i < len; i++)
			printf("%d ", arr[i]);
		printf("\n\n\t");
		printf("자리교환 횟수 : %llu회 \t비교횟수 : %llu회 \n\n\t", cnt2, cnt1);
		cnt1 = 0, cnt2 = 0;
		system("pause");
	}
	else {
		for (i = 0; i < len - 1; i++)
		{
			index = i;
			for (j = i + 1; j < len; j++)
			{
				if (arr[index] > arr[j])
				{
					index = j;
				}
				cnt1++; // 비교
			}
			if (arr[index]<arr[i])
				cnt2++; // 자리교환
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;

		}
	}
}

/*셀 정렬 부분집합*/
void intervalSort(element arr[], int begin, int end, int interval)
{
	int i, j, stop = 1, y = 1;
	int t, num, num1, b = interval;
	int len = end + 1;
	element item;
	for (i = begin + interval; i <= end; i = i + interval)
	{
		item = arr[i];
		for (j = i - interval; j >= begin && item < arr[j]; j = j - interval)
		{
			cnt1++;
			arr[j + interval] = arr[j];
			cnt2++;
			y = 0;
		}
		if (1 != (j >= begin && item < arr[j]) && y != 0)
			cnt1++;
		y = 1;
		arr[j + interval] = item;
		t = 0;
		num = len % b;
		num1 = len / b;
		if (num != 0)
			num1++;

		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓%d번째〓〓〓〓〓〓〓\n\t", ++s);
		for (int j = 0; j < num1; j++) {
			stop = 1;
			for (int a = 0; a < b&&stop != 0; a++) {
				printf("[ %d ]\t", arr[t]);
				t++;
				if (t == len)
					stop = 0;
			}

			printf("\n\t");

		}
		printf("\n\n\t");
		system("pause");

	}

}

/*셀 정렬 부분집합2*/
void intervalSort2(element arr[], int begin, int end, int interval)
{
	int i, j, y = 1;
	int len = end + 1;
	element item;
	for (i = begin + interval; i <= end; i = i + interval)
	{
		item = arr[i];
		for (j = i - interval; j >= begin && item < arr[j]; j = j - interval)
		{
			cnt1++;
			arr[j + interval] = arr[j];
			cnt2++;
			y = 0;
		}
		if (1 != (j >= begin && item < arr[j]) && y != 0)
			cnt1++;
		y = 1;
		arr[j + interval] = item;


	}

}

/*셀 정렬*/
void shellionsort(int arr[], int len)
{
	int i, interval, cnt = 0;
	int t = 0, b = 7, stop, num1 = 3;
	interval = len / 3 + 1;
	s = 0;
	if (len == 20)
	{
		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓초기값〓〓〓〓〓〓〓\n\t");
		for (int a = 0; a < len; a++)
			printf("%d ", arr[a]);

		printf("\n\n\t");
		system("pause");

		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓초기배열〓〓〓〓〓〓〓\n\t");
		for (int j = 0; j < num1; j++) {
			stop = 1;
			for (int a = 0; a < b&&stop != 0; a++) {
				printf("[ %d ]\t", arr[t]);
				t++;
				if (t == len)
					stop = 0;
			}

			printf("\n\t");

		}
		printf("\n\n\t");
		system("pause");


		while (interval >= 1)
		{
			for (i = 0; i < interval; i++)
			{

				intervalSort(arr, i, len - 1, interval);

			}

			interval = interval / 3 + 1;

			if (cnt != 0) {
				interval = 1;
				if (interval == 1 && cnt == 2)
					interval = 0;
				cnt++;
			}
			if (interval == 2)
				cnt++;





		}
		system("cls");
		printf("\n\n\t※※※※※※※※※최종결과※※※※※※※※※\n\t");
		for (i = 0; i < len; i++)
			printf("%d ", arr[i]);
		printf("\n\n\t");
		printf("자리교환 횟수 : %llu회 \t비교횟수 : %llu회 \n\n\t", cnt2, cnt1);
		cnt1 = 0, cnt2 = 0;
		system("pause");
	}
	else
	{
		while (interval >= 1)
		{
			for (i = 0; i < interval; i++)
			{

				intervalSort2(arr, i, len - 1, interval);

			}

			interval = interval / 3 + 1;

			if (cnt != 0) {
				interval = 1;
				if (interval == 1 && cnt == 2)
					interval = 0;
				cnt++;
			}
			if (interval == 2)
				cnt++;





		}
	}
}

/*히프 정렬*/
void HeapSort(int *base, int n)

{
	int a = 1;


	printf("\n\n\t〓〓〓〓〓〓〓초기 힙 생성과정〓〓〓〓〓〓〓\n\t\t");
	InitHeap(base, n);
	system("pause");
	system("cls");
	printf("\n\n\t〓〓〓〓〓〓〓정렬 과정〓〓〓〓〓〓〓\n");
	n--;

	SWAP(base[0], base[n]);
	cnt2++;


	while (n>1)

	{

		MakeHeap(base, n);
		printf("\t");
		ViewArr(base, n + 1);

		n--;

		SWAP(base[0], base[n]);
		cnt2++;
	}
	printf("\t");
	ViewArr(base, n + 1);
	printf("\t%2d\n\t", base[0]);

}

/*히프초기화*/
void InitHeap(int *base, int n)

{

	int pa = 0;

	int now;

	int i;

	for (i = 1; i<n; i++)//순차적으로 힙에 구성

	{

		now = i;

		while (now>0)//now의 인덱스가 0이 아니면(힙의 루트가 아니면)

		{

			pa = PARENT(now);//부모 인덱스 구함

			if (base[now] > base[pa])//부모보다 더 크면				
			{
				cnt1++;
				SWAP(base[now], base[pa]);//부모와 교환
				cnt2++;
				now = pa;//인덱스를 부모로 설정

			}

			else//아니면 자리를 찾은 것임
			{
				cnt1++;
				break;

			}

		}



	}ViewArr2(base, i);

}

/*히프생성*/
void MakeHeap(int *base, int n)
{
	int now = 0;
	int mp = 0;
	//루트에 있는 요소를 힙 트리에 맞게 자리를 찾는 과정

	while (LEFT_CHILD(now) < n)//왼쪽 자식이 있다면

	{
		int mp = FindMaxIndex(base, n, now);//now와 왼쪽, 오른쪽 자식 중에 큰 값의 위치 찾음
		if (mp == now)//mp와 now가 같으면
		{
			cnt1++;
			break;//자리를 찾은 것임
		}
		else
			cnt1++;
		SWAP(base[mp], base[now]);//now와 큰 값의 자리 교환
		cnt2++;
		now = mp;//큰 값의 위치를 now로 설정
	}
}

/*히프정렬 인덱스 검색*/
int FindMaxIndex(int *base, int n, int now)
{
	int lc = LEFT_CHILD(now);//왼쪽 자식
	int rc = RIGHT_CHILD(now);//오른쪽 자식

	if (rc >= n)//오른쪽 자식이 없을 때
	{
		cnt1++;
		if (base[now] < base[lc])
		{
			cnt1++;
			return lc;
		}
		cnt1++;
		return now;
	}
	else
		cnt1++;
	if (base[lc]<base[rc])
	{
		cnt1++;
		return rc;
	}

	return lc;
}

/*히프정렬 테스트 출력1*/
void ViewArr(int *arr, int n)

{

	int i = 0;

	for (i = 0; i<n; i++)

	{

		printf("%2d ", arr[i]);

	}

	printf("\n");



}

/*히프정렬 테스트 출력2*/
void ViewArr2(int *arr, int n) {

	int i = 0, j = 0, a = 1, b = 1;
	for (i = 1; i < 6; i++)
	{
		for (j = 0; j < 10 - b; j++)
			printf(" ");
		for (j = 0; j < 1 * b; j++) {
			if (a == n)
				break;
			printf("%3d", arr[a - 1]);
			a++;
		}
		b = b * 2;
		printf("\n\t\t");
	}


}

/*히프정렬 본프로그램 용*/
void HeapSort2(int *base, int n)
{
	int on = n;
	InitHeap2(base, n);
	n--;
	SWAP(base[0], base[n]);
	cnt2++;
	while (n>1)
	{
		MakeHeap2(base, n);
		n--;
		SWAP(base[0], base[n]);
		cnt2++;
	}
}

/*히프정렬 본프로그램 용*/
void InitHeap2(int *base, int n)
{
	int pa = 0;
	int now;
	int i;
	for (i = 1; i<n; i++)//순차적으로 힙에 구성
	{
		now = i;
		while (now>0)//now의 인덱스가 0이 아니면(힙의 루트가 아니면)
		{
			pa = PARENT(now);//부모 인덱스 구함
			if (base[now] > base[pa])//부모보다 더 크면				
			{
				cnt1++;
				SWAP(base[now], base[pa]);//부모와 교환
				cnt2++;
				now = pa;//인덱스를 부모로 설정

			}

			else//아니면 자리를 찾은 것임
			{
				cnt1++;
				break;

			}
		}
	}
}

/*히프정렬 본프로그램 용*/
void MakeHeap2(int *base, int n)
{
	int now = 0;
	int mp = 0;
	//루트에 있는 요소를 힙 트리에 맞게 자리를 찾는 과정
	while (LEFT_CHILD(now) < n)//왼쪽 자식이 있다면
	{
		int mp = FindMaxIndex2(base, n, now);//now와 왼쪽, 오른쪽 자식 중에 큰 값의 위치 찾음
		if (mp == now)//mp와 now가 같으면
		{
			cnt1++;
			break;//자리를 찾은 것임
		}
		else
			cnt1++;
		SWAP(base[mp], base[now]);//now와 큰 값의 자리 교환
		cnt2++;
		now = mp;//큰 값의 위치를 now로 설정
	}
}

/*히프정렬 본프로그램 용*/
int FindMaxIndex2(int *base, int n, int now)
{
	int lc = LEFT_CHILD(now);//왼쪽 자식
	int rc = RIGHT_CHILD(now);//오른쪽 자식
	if (rc >= n)//오른쪽 자식이 없을 때
	{
		cnt1++;
		if (base[now] < base[lc])
		{
			cnt1++;
			return lc;
		}
		cnt1++;
		return now;
	}
	else
		cnt1++;
	if (base[lc]<base[rc])
	{
		cnt1++;
		return rc;
	}
	return lc;
}

/* 알고리즘 테스트*/
void Testa(int arr[]) {
	int num = 0;
	while ((num != 1) & (num != 2)& (num != 3)) {
		system("cls");
		printf("\n\n\t1.1~20 오름차순으로 배열\n");
		printf("\n\t2.1~20 내림차순으로 배열\n");
		printf("\n\t3.난수로 배열\n\n\t");
		printf(">");
		scanf_s("%d", &num);

		switch (num) {
		case 1:
			for (int i = 0; i < 20; i++) {
				arr[i] = i + 1;
			}
			break;
		case 2:
			for (int i = 0; i < 20; i++) {
				arr[i] = 20 - i;
			}
			break;

		case 3:
			Testrandom(arr);
			break;
		}
	}
}

/*퀵 정렬*/
void quickSort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;
	if (left < right) {
		for (; i <= right; i++) {
			cnt1++;
			if (data[i] < data[pivot]) {
				cnt1++;
				j++;
				swap(&data[j], &data[i]);
				cnt2++;
			}
			else
				cnt1++;
		}
		system("cls");
		printf("\n\n\t〓〓〓〓〓〓〓%d번째〓〓〓〓〓〓〓\n\t", ++h);
		for (int a = 0; a < 20; a++)
			printf("%d ", data[a]);
		printf("\n\n\t");
		system("pause");
		swap(&data[left], &data[j]);
		//cnt2++;
		pivot = j;

		quickSort(left, pivot - 1, data);
		quickSort(pivot + 1, right, data);
	}
	else
		cnt1++;
}
/*퀵 정렬 본프로그램 용*/
void quickSort2(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {

		for (; i <= right; i++) {
			cnt1++;
			if (data[i] < data[pivot]) {
				cnt1++;
				j++;
				swap(&data[j], &data[i]);
				cnt2++;
			}
			else
				cnt1++;
		}

		swap(&data[left], &data[j]);
		//cnt2++;
		pivot = j;

		quickSort2(left, pivot - 1, data);
		quickSort2(pivot + 1, right, data);
	}
	else
		cnt1++;
}