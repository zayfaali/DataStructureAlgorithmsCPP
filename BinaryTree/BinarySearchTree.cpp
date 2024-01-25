#include<iostream>
#include<queue>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL); // Separator of 1st Level

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //Previous Level Complete
            cout << endl;
			if(!q.empty()) { 
 			//queue still has some child ndoes
                q.push(NULL);     }      
				}
        
		else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);    }      
				}
    }    

}
void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

node* insertIntoBST(node* root, int d){
	//base case
	if(root == NULL){
		root = new node(d);
		return root;
	}
	
	if(d > root -> data){
		//Insert in the Right Side
		root -> right = insertIntoBST(root->right,d);
	}
	else {
		//Insert in the Left Side
		root -> left = insertIntoBST(root->left,d);
	}
	return root;	
}

void takeInput(node* &root){
	int data;
	cin>>data;
	
	while(data != -1){
		root = insertIntoBST(root,data);
		cin>>data;
	} 
}

node* minValue(node* root){
	node* temp = root;
	while (temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

node* maxValue(node* root){
	node* temp = root;
	while (temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

node* deleteFromBST(node* root, int key){
	if(root == NULL){
		return NULL;
	}
	if(root->data == key){
		// 0 Child
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}	
		// 1 Child
			// Left Child
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
			// Right Child
		if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		// 2 Child
		//2 cases: 1) Find the max value from left side and replace with deleted node
		// or     2) Find the min value from right side and replace with deleted node
		if(root->left != NULL && root->right != NULL){
			int min = minValue(root->right)->data;
			root->data= min;
			root->right = deleteFromBST(root->right, min);
			return root;
		}
		
	}
	else if (root->data > key){
		//Left Side
		root->left = deleteFromBST(root->left, key);
		return root;
	}
	else {
		//Right Side
		root->right = deleteFromBST(root->right, key);
		return root;
	}	
}

int main(){
	// 10 8 21 7 27 5 4 3 -1
	node* root = NULL;
	
	cout<<"Enter Data to Create BST"<<endl;
	takeInput(root);
	
	cout << "Inorder traversal is:  ";
    inorder(root); 

    cout << endl << "Preorder traversal is:  ";
    preorder(root); 

    cout << endl << "Postorder traversal is:  ";
    postorder(root); 
	
	cout<<endl<<"Printing the BST"<<endl;
	levelOrderTraversal(root);

	cout<<endl<<"Minimum Value of BST is: "<<minValue(root)->data<<endl;
	cout<<endl<<"Maximum Value of BST is: "<<maxValue(root)->data<<endl;
	
	root = deleteFromBST(root,7);
	cout<<endl<<"Printing the BST"<<endl;
	levelOrderTraversal(root);
	
	
	return 0;
	
}