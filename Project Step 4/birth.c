#include"my_define.h"

void find_by_birth(struct student *p, int n) //4. FindBirth
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