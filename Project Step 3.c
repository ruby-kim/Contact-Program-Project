#include<stdio.h> //헤더선언
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
void register_from_file(struct student *p, FILE *fp, int *n, int max_num);//5. RegFromFile
void sort(struct student *p, int *n); //이름을 사전순으로 정렬하는 함수
void free_all(struct student *p, FILE *fp, int n); //6. Exit

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

void insert(struct student *p, int *n) //1번
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

	sort(p, n); //정렬함수를 불러와 사전순으로 이름을 정리했습니다.
	printf("<<%d>>\n", *n); //마지막으로 현재 몇명이 저장되어 있는지 출력하도록 만들었습니다.
}

void print_all(struct student *p, int n) //2번
{
	int i;
	for (i = 0; i<n; i++)
		printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth); //n을 이용해 현재 저장된 인원을 출력하도록 만들었습니다.
}

void delete_tel(struct student *p, int *n) //3번
{
	char ar[21] = ""; //이름을 저장할 문자열배열 ar선언
	int i, flag = -1; //for문에 이용할 i와 똑같은 이름이 있는지 판단하기 위한, 만약 있으면 그 인덱스 값을 저장할 flag선언
					  //처음부터 p를 돌렸을 때 같은 이름이 나올 수도 있기 때문에 flag의 초기값을 -1로 설정해주었습니다.
	int j = 0; //for문에 이용할 j선언 
	printf("Name:");
	scanf("%s", ar); //이름 입력

	for (i = 0; i<*n; i++)
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

void find_by_birth(struct student *p, int n) //4번
{
	int chk, in_bir; //p를 돌리면서 생일(달)을 정수로 저장할 chk, 입력받을 값 저장할 in_bir 선언
	int i, len;
	char ar[3] = ""; //p를 돌리면서 생일(달)을 문자열 형태로 저장할 ar 선언
	printf("Birth:");
	scanf("%d", &in_bir); //찾는 생일(달)을 입력해
	for (i = 0; i<n; i++)
	{
		len = strlen(p[i].birth); //생일정보가 담긴 곳의 길이를 구해
		ar[0] = p[i].birth[len - 4]; //ar에 생일(달)을 문자 형태로 저장
		ar[1] = p[i].birth[len - 3];
		chk = atoi(ar); //atoi를 이용해 ar을 정수로 변환
		if (in_bir == chk) //만약 chk과 in_bir이 같으면 해당 값의 이름, 전화, 생일을 출력하도록 만들었습니다.
			printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	}
}
void register_from_file(struct student *p, FILE *fp, int *n, int max_num) //5번
{
	int i, j = 0, flag = 0, len; //for문을 돌릴 때 필요한 i,j, flag와 len
	int result = 0;//result
	char nick[201] = "", c[201] = "", b[201] = ""; //nick,c,b배열
	char save[200] = ""; //save배열을 선언하고
	fp = fopen("PHONE_BOOK.txt", "r"); //텍스트파일을 엽니다.
	fgets(save, 200, fp); //파일의 문자열을 받아옵니다.
						  //위에서 한번 한 이유는 feof의 오류를 방지하기 위해)

	while (!feof(fp)) //파일의 끝까지 돌리면서
	{
		if (strcmp(save, "") != 0) //만약 문자열에 무언가가 적혀있다면
		{
			if (*n == max_num) //만약 입력인원이 최대 입력 가능한 인원수라면
			{
				result = 2; //result를 2로 변경하고
				break; //멈춰줍니다.
			}
			else { //아니라면, 즉 현 입력 인원이 최대 입력 가능한 인원수보다 작다면
				len = strlen(save); //문자열의 길이를 구해
				save[len - 1] = '\0'; //인덱스 len-1부분을 NULL로 해줍니다.
									  //fgets를 사용할 경우 문자열에 개행문자+'\0'이 붙기 때문에, 개행문자 부분인 len-1부분을 널문자로 만들어주었습니다.
				for (i = 0; save[i]; i++) //save의 배열 값이 참일 때, 즉 공백문자 NULL이 나오기 전까지 돌리면서
				{
					if (save[i] != ' ' && flag == 0) //만약 save[i]의 값이 띄어쓰기가 아니고 flag가 0이면
					{
						nick[j] = save[i]; //nick배열에 저장합니다.
						j++; //다음 값을 위해 j에 1을 더해줍니다.
					}
					else if (save[i] != ' ' && flag == 1) //만약 save[i]의 값이 띄어쓰기가 아니고 flag가 1이면
					{
						c[j] = save[i]; //c배열에 저장합니다.
						j++; //다음 값을 위해 j에 1을 더해줍니다.
					}
					else if (save[i] != ' ' && flag == 2) //만약 save[i]의 값이 띄어쓰기가 아니고 flag가 2이면
					{
						b[j] = save[i]; //b배열에 저장합니다.
						j++; //다음 값을 위해 j에 1을 더해줍니다.
					}
					else //만약 띄어쓰기가 나왔다면,
					{
						if (flag == 0) //flag=0일때 이름에 값 저장
						{
							nick[j] = '\0'; //문자열을 끝을 지정하기 위해 NULL을 해주고,
							len = strlen(nick); //동적할당으로 입력해야하기 때문에 문자열의 길이를 먼저 구했습니다.
							p[(*n)].name = (char*)malloc((len + 1) * sizeof(char)); //문자열의 길이+1만큼 동적할당하여
							strcpy(p[(*n)].name, nick); //문자열을 넣어줍니다.
							flag++; //띄어쓰기 다음은 call에 관한 내용이기 때문에 flag에 변화를 줍니다.
						}
						else if (flag == 1) //flag=1일때 전화번호 값 저장
						{
							c[j] = '\0';//문자열을 끝을 지정하기 위해 NULL을 해주고,
							len = strlen(c);//동적할당으로 입력해야하기 때문에 문자열의 길이를 먼저 구했습니다.
							p[(*n)].call = (char*)malloc((len + 1) * sizeof(char)); //문자열의 길이+1만큼 동적할당하여
							strcpy(p[*n].call, c); //문자열을 넣어줍니다.
							flag++; //띄어쓰기 다음은 birth에 관한 내용이기 때문에 flag에 변화를 줍니다.
						}
						j = 0; //j를 재활용하기 위해 0으로 초기화시켜줍니다.
					}
				}
				if (flag == 2) //flag=2일때 생일 저장
				{
					b[8] = '\0';//문자열을 끝을 지정하기 위해 NULL을 해주고,
					len = strlen(b);//동적할당으로 입력해야하기 때문에 문자열의 길이를 먼저 구했습니다.
					p[*n].birth = (char*)malloc((len + 1) * sizeof(char)); //문자열의 길이+1만큼 동적할당하여
					strcpy(p[*n].birth, b); //문자열을 넣어줍니다.
					flag = 0; //생일 다음에는 새로운 문자열을 받아오기 때문에 0으로 정해줍니다.
					(*n)++; //총 인원이 증가했기 때문에 현재 인원수에 1을 더해줍니다.
					j = 0; //j를 재활용하기 위해 0으로 초기화시켜줍니다.
				}
			}
		}
		else break; //save에 아무것도 적혀있지 않다면 멈춥니다.
		fgets(save, 200, fp); //파일의 문자열을 받아옵니다.
	}
	fclose(fp); //파일을 닫고
	if (result == 1) printf("OVERFLOW\n"); //문제에서 하나씩 입력하는데, 넘치면 OVERFLOW를 출력하라고 했기 때문에 최대인원수까지 입력이 되었다면, 문자를 출력하고
	sort(p, n); //최대 인원수만큼 들어갔든 아니든 상관없이 정렬을 해야하기 때문에 sort함수를 불렀습니다.
}

void sort(struct student *p, int *n) //이름정렬(사전순)
{
	int i, j; //for문에서 사용할 i,j와
	int len; //동적할당에 사용할 변수 len 선언
	struct student tmp;
	for (i = 0; i<(*n); i++) //이후 2중for문을 이용해
	{
		for (j = 0; j<(*n) - 1 - i; j++)
		{
			if (strcmp(p[j].name, p[j + 1].name)>0) //앞에 있는 이름이 사전순으로 뒤에 있어야 한다면
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
}

void free_all(struct student *p, FILE *fp, int n) //6번
{
	int i; //for문을 돌리기 위해 사용할 변수 i 선언
	fp = fopen("PHONE_BOOK.txt", "w"); //텍스트 파일을 열어(없으면 만들고 열어)

	for (i = 0; i < n; i++)//파일에 그동안의 기록물들을 저장합니다.
		fprintf(fp, "%s %s %s\n", p[i].name, p[i].call, p[i].birth);
	fclose(fp); //파일을 닫은 이후
	for (i = 0; i < n; i++) //동적할당으로 받았기 때문에
	{
		free(p[i].name); //각각의 변수를 free해주었습니다.
		free(p[i].call);
		free(p[i].birth);
	}
	free(p); //구조체 또한 동적할당했기 때문에 free해주었습니다.
}