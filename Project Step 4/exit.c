#include"my_define.h"

void free_all(struct student *p, FILE *fp, int n) //6. Exit
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