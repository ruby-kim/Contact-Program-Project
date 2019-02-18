#include"my_define.h"

void print_all(struct student *p, int n) //2. ShowAll
{
	int i;
	for (i = 0; i<n; i++)
		printf("%s %s %s\n", p[i].name, p[i].call, p[i].birth); //n을 이용해 현재 저장된 인원을 출력하도록 만들었습니다.
}