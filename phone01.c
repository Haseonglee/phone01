#include <stdio.h>

#include <string.h> 
//동적 메모리 할당은 힙에 저장
 
#define CAPACITY 100 //배열의 크기 
#define BUFFER_SIZE 20
//전역변수 ->deta section이라 불리는 메모리영역에 위치 
char *names[CAPACITY];//이름 저장  배열 인덱스를 이용하여 번호와 이름을 유지 
//캐릭터 포인터 타입의 배열 
//names 배열의 각 항에 이름 배열의(포인터)의 주소를 주어야함 
char *numbers[CAPACITY];//전화번호 저장 
//전화번호를 문자열로 다루는게 편함 

int n=0;

void add();
void find();
void status();
void remover(); 
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char command[BUFFER_SIZE];
	while(1){
		
		printf("명령을 입력하세요\n");//명령을 선택받음
		scanf("%s",command);
		
		if(strcmp(command,"add")==0)
		add();
		else if(strcmp(command,"find")==0)
		find();
		else if(strcmp(command,"status")==0)
		status();
		else if(strcmp(command,"delete")==0)
		remover();
		else if(strcmp(command,"exit")==0)
		break;
	}
	return 0;
}

void add(){
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	//스택(stack)에 위 치 
	printf("이름과 번호를 입력하세요\n"); 
	scanf("%s", buf1);
	scanf("%s", buf2);
	
	names[n]=strdup(buf1);
	numbers[n]=strdup(buf2);
	n++;
	/*strdup 는 string.h가 제공하므로 구현 할 필요 x
	배열을 만들고 매개변수로 받은 하나의 문자열을 거기에 복사하여 반환한다. 
	*/
	
	/*buf1은 스택에 할당된 메모리이므로 add함수가 return되고
	나면 소멸된다. 따라서 buf1에 저장된 문자열을 복제한 후
	배열 names[0]에 복제된 배열의 주소를 저장해야 한다. 복제된 배열은 
	strdup 함수 내에서 malloc으로 (heap에) 할당된 메모리이므로 
	add함수가 종료된 후에도 소멸하지 않는다.
	*/
	 
	printf("%s 는 성공적으로 추가되었습니다.\n",buf1);
}

void find(){
	char buf[BUFFER_SIZE];
	printf("찾을 이름을 입력하세요:\n"); 
	scanf("%s",buf);
	
	int i;
	for(i=0;i<n;i++){
		if(strcmp(buf,names[i])==0){
			printf("%s\n",numbers[i]);
			return ;
		}
	}
	printf("'%s' 는 존재하지 않습니다.\n",buf);
}

void status(){
	int i;
	for(i=0;i<n;i++){
		printf("%s  %s\n",names[i],numbers[i]);
	}
	printf("총 %d 명.\n",n);
}

void remover(){
	char buf[BUFFER_SIZE];
	printf("지울 이름을 입력하세요.\n"); 
	scanf("%s",buf);
	
	int i;
	for(i=0;i<n;i++){
		if(strcmp(buf,names[i])==0){
			names[i]=names[n-1];
			numbers[i]=numbers[n-1];
			n--;
			printf("'%s'는 성공적으로 삭제되었습니다.\n",buf);
			return ;
		}
	}
	printf("'%s'는 존재하지 않습니다.\n",buf);
}

