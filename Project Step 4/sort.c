#include"my_define.h"
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