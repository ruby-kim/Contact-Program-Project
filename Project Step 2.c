#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char *name;
	char *call;
	char *birth;
}; //문제 조건에 맞는 구조체 선언

void insert(struct student *p, int *n); //1. Registration
void print_all(struct student *p, int n); //2. ShowAll
void delete_tel(struct student *p, int *n); //3. Delete
void find_by_birth(struct student *p, int n); //4. FindBirth
void free_all(struct student *p, int n); //5. Exit

int main()
{
	int n = 0, input, max_num, i;//총 인원을 받을 max_num, 현재 입력된 인원수 n, 입력숫자 input
	struct student *p; //동적할당으로 만들기 위해 포인터 구조체를 선언했습니다.
	printf("Max_num:"); //최대 입력 인원 수를
	scanf("%d", &max_num); //입력받아
	p = (struct student*)malloc(max_num * sizeof(struct student)); //그만큼 포인터 구조체를 동적할당해주고
	while (1)
	{
		//문제 조건에 맞는 메뉴가 계속 출력되게끔 while문 안에 작성하였습니다.
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
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
			free_all(p, n); //끝나면 함수를 이용해 지금까지 사용했던 메모리를 free해주고
			return 0; //끝내도록 만들었습니다
		}
	}
	return 0;
}

void insert(struct student *p, int *n) //1을 눌렀을 때
{
	char ar[101] = "";	//사용할 문자열배열 선언,
	int i, j; //for문에 사용하기 위한 i,j 선언
	struct student tmp; //이름을 사전순으로 정렬할 때 swap하기 위한 mp 선언
	int len; //문자열의 길이를 저장할 len 선언
	printf("Name:"); //이름 입력
	scanf("%s", ar); //ar에 이름을 저장하고
	len = strlen(ar); //ar의 길이를 재서
	p[*n].name = (char*)malloc((len + 1) * sizeof(char)); //해당 구조체 구역에 이름의 크기만큼 동적할당하여
	strcpy(p[*n].name, ar); //구조체에 넣었습니다.

	printf("Phone_number:"); //번호 입력
	scanf("%s", ar); //ar에 번호를 저장해
	len = strlen(ar); //ar의 길이를 재서
	p[*n].call = (char*)malloc((len + 1) * sizeof(char)); //해당 구조체 구역에 전화번호의 크기만큼 동적할당하여
	strcpy(p[*n].call, ar); //구조체에 넣었습니다.

	printf("Birth:"); //생일 입력
	scanf("%s", ar); //ar에 생일을 저장해
	len = strlen(ar); //ar의 길이를 재서
	p[*n].birth = (char*)malloc((len + 1) * sizeof(char)); //해당 구조체 구역에 생일의 크기만큼 동적할당하여
	strcpy(p[*n].birth, ar); //구조체에 넣었습니다.
	(*n)++; //인원이 추가되었기 때문에 전체 인원을 뜻하는 *n에 +1을 해주었습니다.

	for (i = 0; i < *n; i++) //이후 2중for문을 이용해
	{
		for (j = 0; j < *n - 1 - i; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name) > 0) //앞에 있는 이름이 사전순으로 뒤에 있어야 한다면
			{
				//해당 부분의 순서를 바꿔주었습니다.
				//이름 순서 변경
				len = strlen(p[j].name);
				tmp.name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.name, p[j].name);
				len = strlen(p[j + 1].name);
				p[j].name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].name, p[j + 1].name);
				len = strlen(tmp.name);
				p[j + 1].name = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].name, tmp.name);

				//번호 순서 변경
				len = strlen(p[j].call);
				tmp.call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.call, p[j].call);
				len = strlen(p[j + 1].call);
				p[j].call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].call, p[j + 1].call);
				len = strlen(tmp.call);
				p[j + 1].call = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].call, tmp.call);

				//생일 순서 변경
				len = strlen(p[j].birth);
				tmp.birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(tmp.birth, p[j].birth);
				len = strlen(p[j + 1].birth);
				p[j].birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j].birth, p[j + 1].birth);
				len = strlen(tmp.birth);
				p[j + 1].birth = (char*)malloc((len + 1) * sizeof(char));
				strcpy(p[j + 1].birth, tmp.birth);
			}
		}
	}
	printf("<<%d>>\n", *n); //마지막으로 현재 몇명이 저장되어 있는지 출력하도록 만들었습니다.
}

void print_all(struct student *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth); //n을 이용해 현재 저장된 인원을 출력하도록 만들었습니다.
}

void delete_tel(struct student *p, int *n)
{
	char ar[21] = ""; //이름을 저장할 문자열배열 ar선언
	int i, flag = -1; //for문에 이용할 i와 똑같은 이름이 있는지 판단하기 위한, 만약 있으면 그 인덱스 값을 저장할 flag선언
					  //처음부터 p를 돌렸을 때 같은 이름이 나올 수도 있기 때문에 flag의 초기값을 -1로 설정해주었습니다.
	int j = 0; //for문에 이용할 j선언 
	printf("Name:");
	scanf("%s", ar); //이름 입력

	for (i = 0; i < *n; i++)
	{
		if (strcmp(p[i].name, ar) == 0) //for문을 이용해 만약 p의 맴버의 이름이 ar과 같다면
		{
			flag = i; //그 인덱스 값을 flag에 저장하고
			break; //멈추기(문제 조건에서 동명이인은 없다고 했기에 바로 break를 걸어서 더욱 빠르게 돌아가도록 만들었습니다)
		}
	}
	if (flag != -1) //만약 flag가 -1이 아니라면, 즉 없애려는 이름이 있어 flag에 그 인덱스 값이 저장되면
	{
		for (i = 0; i < *n; i++) //처음부터 끝까지 돌려서
		{
			if (i == flag) //만약 저장한 인덱스 값에 도달하면
			{
				free(p[i].name); //해당 메모리를 해제해주고
				free(p[i].call);
				free(p[i].birth);
				for (j = i + 1; j < *n; j++) //그 다음부터 끝까지 있는 원소를 한칸씩 앞으로 당겨오도록 했습니다.
					p[j - 1] = p[j];
				break; //코드가 더 빠르게 돌아가도록 만들기 위해 break를 걸어주었습니다.
			}
		}
		(*n)--; //인원수가 한명 줄었기 때문에 전체 인원수-1을 해주었습니다.
	}
}

void find_by_birth(struct student *p, int n)
{
	int chk, in_bir; //p를 돌리면서 생일(달)을 정수로 저장할 chk, 입력받을 값 저장할 in_bir 선언
	int i, len;
	char ar[3] = ""; //p를 돌리면서 생일(달)을 문자열 형태로 저장할 ar 선언
	printf("Birth:");
	scanf("%d", &in_bir); //찾는 생일(달)을 입력해
	for (i = 0; i < n; i++)
	{
		len = strlen(p[i].birth);
		ar[0] = p[i].birth[len - 4]; //ar에 생일(달)을 문자 형태로 저장
		ar[1] = p[i].birth[len - 3];
		chk = atoi(ar); //atoi를 이용해 ar을 정수로 변환
		if (in_bir == chk) //만약 chk과 in_bir이 같으면 해당 값의 이름, 전화, 생일을 출력하도록 만들었습니다.
			printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	}
}

void free_all(struct student *p, int n)
{
	int i;
	for (i = 0; i < n; i++) //동적할당으로 받았기 때문에
	{
		free(p[i].name); //각각의 변수를 free해주었습니다.
		free(p[i].call);
		free(p[i].birth);
	}
	free(p); //구조체 또한 동적할당했기 때문에 free해주었습니다.
}