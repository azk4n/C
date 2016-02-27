/* a simple linked list in C
 
 * functions: remove/insert on head/end 
 * 			  show list 
 * 			  erase list (free)

  writer: azk4n

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int data;
	struct NO *next;
}no;

// global vars
int size; 
no *tmp = NULL;
// ----------

void startList(no *list){ 
	list->next = NULL;
	size = 0;
}

int testEmpty(no *list){
	if(list->next == NULL) return 1;
	else return 0;
}

no *malloking(){ 
	no *new = (no *) malloc(sizeof(no));
	if(!new){
		 printf("no memory\n");
		 return NULL;
	}else{
		printf("\ntake the nem element: ");
		scanf("%d", &new->data); 
		printf("\n");
		return new;
	}
}

void insertOnEnd(no *list){
	no *new = malloking();
	new->next = NULL;
	if(testEmpty(list)){
		list->next = new; 
	}else{
		tmp = list->next;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}tmp->next = new; 	
	}size++;
}

void insertOnHead(no *list){
	no *new = malloking();
	no *oldHead = list->next;
	
	list->next = new; 
	new->next = oldHead;
	size++;
}

no *removeOnEnd(no *list){
	if(testEmpty(list)){
		printf ("\n\nempty list\n\n");
		return NULL;
	}else{
		no *last = list->next,
			*llast = list;
		while(last->next != NULL){
			llast = last;
			last = last->next;
		}
		llast->next = NULL;
		size--;
		return last;
	}   

}

no *removeOnHead(no *list){
	if(testEmpty(list)){ 
		printf("\n\nempty list\n\n"); 
		return NULL;
	}else{
		tmp = list->next;
	    list->next = tmp->next;
		size--;
		return tmp;
	}
}
		
void showList(no *list){
	if(testEmpty(list)){ 
		printf("\n\nempty list\n\n"); 
		return; 
	}
	tmp = list->next; 
	system("clear");
	while(tmp != NULL){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void freeList(no *list){
	 if(!testEmpty(list)){
		 no *nextNo,
			*actualNo;
		actualNo = list->next;
		while(actualNo != NULL){
		  nextNo = actualNo->next;
		  free(actualNo);
		  actualNo = nextNo;
	  }
  }
}

int main(){
	
	no *list = (no*) malloc(sizeof(list));
	if(!list) printf("\n\nno memory\n\n");
	else startList(list);
		
		int opt;
		do{
		printf("0 -> quit\n");
		printf("1 -> insert on the end\n");
		printf("2 -> insert on the head\n");
		printf("3 -> show the list\n");
		printf("4 -> remove on the end\n");
		printf("5 -> remove on the head\n");
		printf("6 -> free the list\n");
		printf("opt: "); scanf("%d", &opt);
		
		switch(opt){
			case 1:
				insertOnEnd(list);
				break;
			case 2: 
				insertOnHead(list);
				break;
			case 3:
				showList(list);
				break;
			case 4:
			    tmp = removeOnEnd(list);
			    if(tmp != NULL){
			    printf("\nelement removed: %d\n\n", tmp->data);
			    free(tmp);
			   } break;
			
			case 5:
				tmp = removeOnHead(list);
			    if(tmp != NULL){
			    printf("\nelement removed: %d\n\n", tmp->data);
			    free(tmp);
			    }break;
			case 6:
				freeList(list);
				startList(list);
				break;
				default:
				if(opt != 0) printf("take valid option\n\n");
				
		}
	}while(opt != 0);
	
		return 0;
	}
