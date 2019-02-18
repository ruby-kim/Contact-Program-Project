#include"my_define.h"

void delete_tel(struct student *p, int *n) //3. Delete
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