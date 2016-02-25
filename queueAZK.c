/* a simple dynamic queue in C 
       
  functions: 
  - insert and remove element (no)
  - show the queue
  - free queue
  
  writer: Alexandre (azk4n) 	
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct NO{
	 int data;
	 struct NO *nxt;
 }no;
 
int size;
no *tmp = NULL;

int empty(no *queue){
	if(queue->nxt == NULL) return 1;
	else return 0;
}


void showQueue(no *queue){
	if(empty(queue)){
		printf("\nempty queue\n\n");
	}else{
		tmp = queue->nxt;
		printf("\n");
		while(tmp != NULL){
			printf("%d ", tmp->data);
			tmp = tmp->nxt;
		}printf("\nsize of queue: %d\n\n", size);
	}
}

void enqueue(no *queue){
	no *new = (no*) malloc(sizeof(no));
	new->nxt = NULL;
	printf("\ntake the new node: \n"); 
	scanf("%d", &new->data);
	printf("\n");
	if(empty(queue)){
		queue->nxt = new;
		size++;
	}else{
		tmp = queue->nxt;
		while(tmp->nxt != NULL){
			tmp = tmp->nxt; 
		}
		tmp->nxt = new;
		size++;
	}
}

no *dequeue(no *queue){
	if(empty(queue)){
		printf("\nempty queue\n\n");
		return NULL;
	}else{
		tmp = queue->nxt;
		queue->nxt = tmp->nxt; 
		size--;
		return tmp;
	}
}

void freeQueue(no *queue){
	if(empty(queue)){
		printf("\nempty queue\n\n");
	}else{
		no *nxtNode,
		   *actualNode;
		actualNode = queue->nxt;
		while(actualNode != NULL){
			nxtNode = actualNode->nxt;
			free(actualNode);
			actualNode = nxtNode;
		}
		printf("\nqueue clear\n\n");
	}
}
	
int main(){
	no *queue = (no*) malloc(sizeof(no));
	if(!queue){
		printf("no memory");
		exit(1);
	}else{
		queue->nxt = NULL;
		size = 0;
		int opt;
	
		do{	
			printf("0 -> quit\n");
			printf("1 -> show queue\n");
			printf("2 -> add node in queue\n");
			printf("3 -> remove node in queue\n");
			printf("4 -> free queue\n");
			printf("opt: "); scanf("%d", &opt);
		
			switch(opt){
				case 1:
					showQueue(queue);
					break;
				case 2:
					enqueue(queue);
					break;
				case 3:
					tmp = dequeue(queue);
					if(tmp != NULL)
						printf("\nelement removed: %d\n\n", tmp->data);
						break;
				case 4:
					freeQueue(queue);
					queue->nxt = NULL;
					size = 0;
					break;
				default:
					if(opt != 0) printf("\ninsert valid option!\n\n"); 
			 }	
		}while(opt != 0);
	}
	return 1;
}
	
