#include"my_define.h"

void insert(struct student *p, int *n) //1. Registration
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