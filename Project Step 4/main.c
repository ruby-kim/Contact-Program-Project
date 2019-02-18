#include"my_define.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n = 0, input, max_num, i;//총 인원을 받을 max_num, 현재 입력된 인원수 n, 입력숫자 input
	struct student *p; //동적할당으로 만들기 위해 포인터 구조체를 선언했습니다.
	FILE *fp = NULL; //안전하게 처음에는 NULL로 값을 지정해주었습니다.
	printf("Max_num:"); //최대 입력 인원 수를
	scanf("%d", &max_num); //입력받아
	p = (struct student*)malloc(max_num * sizeof(struct student)); //그만큼 포인터 구조체를 동적할당해주고
	while (1)
	{
		//문제 조건에 맞는 메뉴가 계속 출력되게끔 while문 안에 작성하였습니다.
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &input); //input에 값을 입력받아 1,2,3,4,5를 수행하는데
		switch (input)
		{
		case 1:
			if (max_num == n || n == 100) printf("OVERFLOW\n"); //만약 max_num과 n이 같으면 문제의 조건에서 벗어나기 때문에 overflow를 출력하도록,
			else insert(p, &n); //아니면 insert함수를 수행하도록 만들었습니다.
			break;
		case 2:
			print_all(p, n); //print_all함수를 수행하도록 만들었습니다.
			break;
		case 3:
			if (n == 0) printf("NO MEMBER\n"); //n=0, 즉 아무것도 입력되지 않았을 때 no member를 출력하도록,
			else delete_tel(p, &n); //아니면 delete를 하도록 만들었습니다.
			break;
		case 4:
			find_by_birth(p, n); //find_by_birth함수를 수행하도록 만들었습니다.
			break;
		case 5:
			register_from_file(p, fp, &n, max_num); //register_from_file함수를 수행하도록 만들었습니다.
			break;
		case 6:
			free_all(p, fp, n); //끝나면 함수를 이용해 입력된 자료를 텍스트에 저장 및 지금까지 사용했던 메모리를 free해주고
			return 0; //끝내도록 만들었습니다
		}
	}
	return 0;
}