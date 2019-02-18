#include"my_define.h"

void register_from_file(struct student *p, FILE *fp, int *n, int max_num) //5. RegFromFile
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