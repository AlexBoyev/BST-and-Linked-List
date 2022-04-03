/*
Alexander Boyev 314393158
Genady Yolgin 321983413
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
}node;

typedef struct queue {
	node* key;
	struct queue *next;
}queue;

node* link(int);										//allocate new node
void printmenu();										//print menu
node* Load_BST(node*);									//1
node* Insert_new_node(node*, int);						//2
node* Delete_node(node*,int);							//3
void Print_Levelorder(node*,int);						//4
void Print_Preorder(node*);								//5
void Print_Inorder(node*);								//6
void Print_Postorder(node*);							//7
node* BST_Search_Key(node*,int);						//8
node* Print_Tree_Minimum(node*);						//9
node* Print_Tree_Maximum(node*);						//10
node* Print_Tree_Successor_by_Key(node*,node*);			//11
node* Convert_to_preorder_doubly_link_list(node*);		//12
void exit_clean(node*);									//13
queue* Enqueue(queue*, node*);							//enqueue lvl order print help
node* Dequeue(queue*);									//dequeue lvl order print help
void cleanqueue(queue*);								//clean queue
void CleanDLL(node*);									//clean Doubly linked list
node *parent(node*,node*);								//parent function

int main() {
	
	int element = 0;
	node *root = NULL;
	int num = 0;
	int count = 0;
	int indicator = 0;
	node* mini, *maxi, *search, *find,*succesor;

	printf("\nWelcome!\n");

	while (num!=13) {

		printmenu();
		scanf("%d", &num);
		getchar();

		if (indicator == 1) {
			if (num != 1 && num != 13) {
				printf("\nBST is not valid anymore!\n");
				printf("Press 1 to reload or 13 to exit: \n");
			}

			while (num != 1 && num != 13) {
				scanf("%d", &num);
				getchar();
				if (num != 1 && num != 13)
					printf("Wrong input, try again: \n");
				else
					indicator = 0;
			}
			if (num == 1) {
				CleanDLL(root);
				root = NULL;
			}
		}
		
		switch (num) {
			case 1:
				if (root == NULL) {
					root = Load_BST(root);
				}
				else {
					exit_clean(root);
					root = NULL;
					root = Load_BST(root);
				}
				count = 11;
				num = 0;
				break;
			case 2:
				printf("\nEnter an element that you wish to insert: \n\n");
				scanf("%d", &element);
				getchar();
				if (root == NULL) {
					root = Insert_new_node(root, element);
				}
				else {
					Insert_new_node(root, element);
				}
				count += 1;
				num = 0;
				break;
			case 3:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nEnter an element that you wish to delete: \n\n");
					scanf("%d", &element);
					getchar();
					root = Delete_node(root, element);
					count -= 1;
				}
				num = 0;
				break;
			case 4:
				if (root == NULL) {
				printf("\nThe tree is empty,please load the tree.\n");
				}
				else {
					printf("\nprinting levelorder:\n\n");
					Print_Levelorder(root, count);
					printf("\n");
				}
				num = 0;
				break;
			case 5:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nprinting Preorder:\n\n");
					Print_Preorder(root);
					printf("\n");
				}
				num = 0;
				break;
			case 6:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nprinting Inorder: \n\n");
					Print_Inorder(root);
					printf("\n");
				}
				num = 0;
				break;
			case 7:
				
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nprinting Postorder: \n\n");
					Print_Postorder(root);
					printf("\n");
				}
				num = 0;
				break;
			case 8:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nEnter a key that you wish to search: \n\n");
					scanf("%d", &element);
					getchar();
					search = BST_Search_Key(root, element);
					if (search != NULL)
						printf("\nTrue\n");
					else
						printf("\nFalse\n");
					printf("\n");
				}
				num = 0;
				break;
			case 9:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					mini = Print_Tree_Minimum(root);
					printf("\nThe minimum key is: %d\n", mini->key);
				}
				num = 0;
				break;
			case 10:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					maxi = Print_Tree_Maximum(root);
					printf("\nThe maximum key is: %d\n", maxi->key);
				}
				num = 0;
				break;
			case 11:
				if (root == NULL) {
					printf("The tree is empty,please load the tree.\n");
				}
				else {
					printf("\nEnter tree successor key: \n\n");
					scanf("%d", &element);
					getchar();
					find = BST_Search_Key(root, element);
					succesor = Print_Tree_Successor_by_Key(root, find);
					if (succesor == NULL) {
						printf("\nTree successor doesnt exist!\n");
					}
					else {
						printf("\nThe succuessor of %d is %d.\n", element, succesor->key);
					}
				}
				num = 0;
				break;
			case 12:
				indicator = 1;
				if (root == NULL) {
					printf("\nThe tree is empty,please load the tree.\n");
				}
				else {
		
					root = Convert_to_preorder_doubly_link_list(root);
					
					node* temp = root;
					node *next = temp->right;
					printf("\nTesting doubly linked list: \n");
					printf("next is the 2nd key in the doubly linked list!\n");
					printf("1st key is: next->left %d \n",next->left->key);
					printf("2nd key is: %d \n", next->key);
					printf("3rd key is: next->right %d \n", next->right->key);
					printf("\n");
					printf("The whole doubly linked list is: \n\n");
					while (temp != NULL) {
						printf("%d<->", temp->key);
						temp = temp->right;
					}
					printf("\n");
				}
				num = 0;
				break;
			case 13:
				if (indicator == 1) {
					CleanDLL(root);
				}
				else {
					exit_clean(root);
				}
				printf("\nGoodbye!\n");
				break;
			default:
			   	printf("\nInvalid input, try again!\n");
				num = 0;
		}    
	}

	return 0;
}

void CleanDLL(node* root){
	if (root != NULL) {
		CleanDLL(root->right);
		free(root);
		root = NULL;
	}
}

node* link(int add) {
	node *temp = (node*)malloc(sizeof(node));
	temp->key = add;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printmenu() {
	
	printf("\npress 1 for Load BST.\n");
	printf("press 2 for Insert new node.\n");
	printf("press 3 for Delete node.\n");
	printf("press 4 for Print Levelorder.\n");
	printf("press 5 for Print Preorder.\n");
	printf("press 6 for Print Inorder.\n");
	printf("press 7 for Print Postorder.\n");
	printf("press 8 for BST - Search Key.\n");
	printf("press 9 for Print Tree - Minimum.\n");
	printf("press 10 for Print Tree - Maximum.\n");
	printf("press 11 for Print Tree - Successor by Key.\n");
	printf("press 12 for Convert to preorder doubly link list.\n");
	printf("press 13 for Exit.\n\n");
}

node* Load_BST(node* root){
	
	printf("\nThe tree is loaded!\n");
	
	root = Insert_new_node(root, 11);
	Insert_new_node(root, 19);
	Insert_new_node(root, 43);
	Insert_new_node(root, 49);
	Insert_new_node(root, 31);
	Insert_new_node(root, 17);
	Insert_new_node(root, 6);
	Insert_new_node(root, 8);
	Insert_new_node(root, 10);
	Insert_new_node(root, 4);
	Insert_new_node(root, 5);

	return root;
}

node* Insert_new_node(node* node, int add){
	
	if (node == NULL) {
		return link(add);
	}
	if (add < node->key)
		node->left = Insert_new_node(node->left, add);
	else if (add > node->key)
		node->right = Insert_new_node(node->right, add);

	return node;
}

node* Delete_node(node* root,int del){
	
	node* temp = BST_Search_Key(root, del);
	if (temp == NULL) {
		printf("\nThis element doesn't exist.\n");
		return root;
	}

	else if (root->right == NULL && root->left == NULL) {
		free(root);
		root = NULL;
		return root;
	}

	else if (temp->right == NULL && temp->left == NULL) {
			node* dad = parent(root, temp);
			if (dad->right == temp) {
				free(temp);
				dad->right = NULL;
				return root;
			}
			else if (dad->left == temp) {
				free(temp);
				dad->left = NULL;
				return root;
			}
	}
	else {
		node* dad = parent(root, temp);			// dad of element that we want to delete
		node* next = Print_Tree_Successor_by_Key(root,temp); // following of the element
		node* dadnext = parent(root, next);			// dad of the following element
		
		if (root == temp) {
			next->left = root->left;
			if (root->right != next) {
				next->right = root->right;
				if (dadnext->left == next) {
					dadnext->left = NULL; 
				}
				else if (dadnext->right == next) {
					dadnext->right = NULL;
				}	
			}
			free(temp);
			root = next;
			return root;
		}


		 if (next->right == NULL) {
			if (dad->right == temp)
				dad->right = next;
			else if (dad->left == temp) {
				dad->left = next;
				next->left = temp->left;
				next->right = temp->right;
				if (dadnext->right == next)
					dadnext->right = NULL;
				else if (dadnext->left == next)
					dadnext->left = NULL;
				free(temp);
				return root;
			}
			else {
				dad->left = next;
			}
			next->left = temp->left;
			if (temp->right != next) {
				next->right = temp->right;
			}
			if (dadnext->right == next) {
				dadnext->right = NULL;
			}
			else {
				dadnext->left = NULL;
			}
			free(temp);
			return root;
		}
		else {		        //next have right son
			if (dad->right == temp) {
				dad->right = next;
				if (temp->right == next) {
					next->left = temp->left;
					free(temp);
					return root;
				}
			}
			else if(dad->left == temp) {
				dad->left = next;
				next->left = temp->left;
				node* maxim = Print_Tree_Maximum(next);
				maxim->right = temp->right;
				if (dadnext->right == next)
					dadnext->right = NULL;
				else if (dadnext->left == next)
					dadnext->left = NULL;
				free(temp);
				return root;
			}
			else {
				dad->left = next;
				free(temp);
				return root;
			}
			
		if(!(temp->right == next || temp->left == next)) {
			node* maxim = Print_Tree_Maximum(next);
			maxim->right = temp->right;
			if (dadnext->right == next) {
				dadnext->right = NULL;
			}
			else
				dadnext->left = NULL;
		}
		free(temp);
		return root;
		}
	}
	return root;
}

void Print_Levelorder(node* root,int size){
	
	queue* enter=NULL;
	queue* temp = enter;
	node* t = root;
	
	
	while (size>0) {
		
		printf("%d-->", t->key);
		if(t->left != NULL)
			temp = Enqueue(temp, t->left);
		if (t->right != NULL)
			temp = Enqueue(temp, t->right);
		
		if (temp != NULL) {
			t = Dequeue(temp);
			temp = temp->next;
		}

		size -= 1;
	}

	cleanqueue(enter);
}

void Print_Preorder(node* root){
	
	if (root != NULL) {

		printf("%d-->", root->key);
		Print_Preorder(root->left);
		Print_Preorder(root->right);
	}
}

void Print_Inorder(node* root){
	
	if (root != NULL) {
		
		Print_Inorder(root->left);
		printf("%d-->",root->key);
		Print_Inorder(root->right);

	}
}

void Print_Postorder(node* root){
	
	if (root != NULL) {

		Print_Postorder(root->left);
		Print_Postorder(root->right);
		printf("%d-->", root->key);

	}
}

node* BST_Search_Key(node* root,int key){
	
	node* temp = root;
	while (temp != NULL) {
		if (temp->key == key)
			return temp;
		else if (key > temp->key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp = NULL;
}

node* Print_Tree_Minimum(node* root){
	node* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return  temp;
}

node* Print_Tree_Maximum(node* root){
	node* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

node* Print_Tree_Successor_by_Key(node* root,node* groot){
	node* dad = NULL;
	if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
		return dad;
	}
	else if (groot->right != NULL) {
		return Print_Tree_Minimum(groot->right);
	}
	else if (groot == Print_Tree_Maximum(root)) {
		return dad;
	}
	dad = parent(root,groot);
	if (dad->right != NULL) {
		while ((dad != NULL) && (dad->right->key == groot->key)) {
			groot = dad;
			dad = parent(root, groot);
		}
	}
	return dad;
}

node* parent(node* root,node* son) {
	node* dad = NULL;
	if( root->key == son->key ) {
		return dad;
	}
	dad = root;
	while (dad->right != NULL || dad->left != NULL) {
		if (dad->right != NULL)
			if (dad->right->key != son->key) {
				if (son->key > dad->key)
				dad = dad->right;
			}
			else break;
				
			
			if(dad->left != NULL)
				if (dad->left->key != son->key) {
					if (son->key < dad->key)
						dad = dad->left;
				}
				else break;
			}
	return dad;
}

node* Convert_to_preorder_doubly_link_list(node* root) {
	
	node *temp = root;
	node *prev = temp;
	node *max = NULL;
	if (temp->left != NULL) {
		max = temp->left;
		while (max->right != NULL) {
			max = max->right;
		}
		max->right = temp->right;
		temp->right = temp->left;
		temp->left = NULL;
	}
	temp = temp->right;
	while (temp != NULL) {
		if (temp->left == NULL) {
			temp->left = prev;
			temp = temp->right;
			prev = prev->right;
		}
		else {
			max = temp->left;
			while (max->right != NULL) {
				max = max->right;
			}
			max->right = temp->right;
			temp->right = temp->left;
			temp->left = prev;
			temp = temp->right;
			prev = prev->right;
		}
	}
	return root;
}

void exit_clean(node* root) {
	
	if (root != NULL) {
		exit_clean(root->left);
		exit_clean(root->right);
		free(root);
		root = NULL;
	}
}

void cleanqueue(queue* enter) {
	queue* temp = enter;
	while (temp != NULL) {
		temp = enter;
		enter = enter->next;
		free(temp);
	}
}

queue* Enqueue(queue* enter, node* add){
	queue* head = enter;
	
	if (enter == NULL) {
		enter = (queue*)malloc(sizeof(queue));
		enter->key = add;
		enter->next = NULL;
	}
	else {
		while (head->next != NULL) {
			head = head->next;
		}
		head->next = (queue*)malloc(sizeof(queue));
		head->next->key = add;
		head->next->next = NULL;
	}
	return enter;
}

node* Dequeue(queue *enter) {
	node* temp = enter->key;
	return temp;
}