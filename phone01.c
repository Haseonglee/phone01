#include <stdio.h>

#include <string.h> 
//���� �޸� �Ҵ��� ���� ����
 
#define CAPACITY 100 //�迭�� ũ�� 
#define BUFFER_SIZE 20
//�������� ->deta section�̶� �Ҹ��� �޸𸮿����� ��ġ 
char *names[CAPACITY];//�̸� ����  �迭 �ε����� �̿��Ͽ� ��ȣ�� �̸��� ���� 
//ĳ���� ������ Ÿ���� �迭 
//names �迭�� �� �׿� �̸� �迭��(������)�� �ּҸ� �־���� 
char *numbers[CAPACITY];//��ȭ��ȣ ���� 
//��ȭ��ȣ�� ���ڿ��� �ٷ�°� ���� 

int n=0;

void add();
void find();
void status();
void remover(); 
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char command[BUFFER_SIZE];
	while(1){
		
		printf("����� �Է��ϼ���\n");//����� ���ù���
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
	//����(stack)�� �� ġ 
	printf("�̸��� ��ȣ�� �Է��ϼ���\n"); 
	scanf("%s", buf1);
	scanf("%s", buf2);
	
	names[n]=strdup(buf1);
	numbers[n]=strdup(buf2);
	n++;
	/*strdup �� string.h�� �����ϹǷ� ���� �� �ʿ� x
	�迭�� ����� �Ű������� ���� �ϳ��� ���ڿ��� �ű⿡ �����Ͽ� ��ȯ�Ѵ�. 
	*/
	
	/*buf1�� ���ÿ� �Ҵ�� �޸��̹Ƿ� add�Լ��� return�ǰ�
	���� �Ҹ�ȴ�. ���� buf1�� ����� ���ڿ��� ������ ��
	�迭 names[0]�� ������ �迭�� �ּҸ� �����ؾ� �Ѵ�. ������ �迭�� 
	strdup �Լ� ������ malloc���� (heap��) �Ҵ�� �޸��̹Ƿ� 
	add�Լ��� ����� �Ŀ��� �Ҹ����� �ʴ´�.
	*/
	 
	printf("%s �� ���������� �߰��Ǿ����ϴ�.\n",buf1);
}

void find(){
	char buf[BUFFER_SIZE];
	printf("ã�� �̸��� �Է��ϼ���:\n"); 
	scanf("%s",buf);
	
	int i;
	for(i=0;i<n;i++){
		if(strcmp(buf,names[i])==0){
			printf("%s\n",numbers[i]);
			return ;
		}
	}
	printf("'%s' �� �������� �ʽ��ϴ�.\n",buf);
}

void status(){
	int i;
	for(i=0;i<n;i++){
		printf("%s  %s\n",names[i],numbers[i]);
	}
	printf("�� %d ��.\n",n);
}

void remover(){
	char buf[BUFFER_SIZE];
	printf("���� �̸��� �Է��ϼ���.\n"); 
	scanf("%s",buf);
	
	int i;
	for(i=0;i<n;i++){
		if(strcmp(buf,names[i])==0){
			names[i]=names[n-1];
			numbers[i]=numbers[n-1];
			n--;
			printf("'%s'�� ���������� �����Ǿ����ϴ�.\n",buf);
			return ;
		}
	}
	printf("'%s'�� �������� �ʽ��ϴ�.\n",buf);
}

