#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
}Node;

int n;
Node* newNode(int key){
	Node *n=(Node*)malloc(sizeof(Node));
	if(!n){
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	n->key=key;
	n->left=n->right=NULL;
	return n;
}

int attach_to_immediate_child(Node *Node,int key){
	if(Node==NULL) return 0;  //nothing to attach to
	
	if(key<Node->key){
		if(Node->left==NULL){
			Node->left=newNode(key);
			return 2;  //attach to left
		}else{
			return -2;  //occupied
		}
	}
	else if(key>Node->key){
		if(Node->right==NULL){
			Node->right=newNode(key);
			return 2; //attach to right
		}else{
			return -2;// occupied
		}
	}else{
		//duplicate key:decide your policy(ignore here)
		return -3; //duplicate
	}
}
void insert(Node *root,int key){
	Node *current=root;
	while(1){
		int result=attach_to_immediate_child(current,key);
		
		if(result==1 || result==2){
			return;//attached successfully
		}
		else if(result==-1){
			current = current->left;
		}
		else if(result==-2){
			current=current->right;
		}
		else if(result=-3){
			printf("Duplicate key ignored: %d\n",key);
			return;
		}
	}
}
void inorder(Node *root){
	if(root == NULL) return;
	
	inorder(root->left);
	printf("%d",root->key);
	inorder(root->right);
}
void preorder(Node *root){
	if(root == NULL) return;
	
	preorder(root->left);
	printf("%d",root->key);
	preorder(root->right);
	
}
void postorder(Node *root){
	if(root == NULL) return;
	
	postorder(root->left);
	printf("%d",root->key);
	postorder(root->right);
	
}


int main(){
	int keys[]={10,20,30,40,50};
	int n=sizeof(keys)/sizeof(keys[0]);
	
	//first element becomes root
	Node *root=newNode(keys[0]);
	
	//insert remaining keys
	for(int i=1;i<n;i++){
		insert(root,keys[i]);
	}
	
	printf("Inorder traversal of BST:\n");
	inorder(root);
	printf("\n");

	printf("preorder traversal of BST:\n");
	preorder(root);
	printf("\n");
		  
	printf("postorder traversal of BST:\n");
	postorder(root);
	printf("\n");
		  
	return 0;
}