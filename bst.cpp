#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node *root ,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searchBST(Node *root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}
void search(Node *root){
    int x;
    cout<<"Enter the key to search : ";
    cin>>x;
    if(searchBST(root,x)==NULL){
        cout<<"Key Doesn't Exists !!"<<endl;
    }else{
        cout<<"Key Exists !!"<<endl;
    }
}
Node* inorderSucc(Node *root){
    Node* c=root;
    while(c && c->left!=NULL){
        c=c->left;
    }
    return c;
}
Node* deleteBST(Node *root,int key){
    if(root==NULL){
        cout<<"Key "<<key<<" was not found in the BST."<<endl;
        return root;
    }
    if(key<root->data){
        root->left=deleteBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp=root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}

int main(){
    Node *root=NULL;
    //Insertion
    int i=1;
    while (i!=0)
    {
        cout<<"Enter a Node of BST : "<<endl;
        int f;
        cin>>f;
        if(root==NULL)
        {
        root=insertBST(root,f);
        }

        insertBST(root,f);
        cout<<"Do you want to continue(Yes->1,No->0)? : "<<endl;
        cin>>i;
    }
    i=1;
    while(i!=0){
        cout<<"Select Operations to Perform : "<<endl;
        cout<<"1)Search\n2)Delete\n3)InOrder Form\n0)Exit "<<endl;
        cout<<"Enter your choice : ";
        int choice;
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 0:
            i=0;
            break;
        case 1:
            search(root);
            cout<<endl;
            break;
        case 2:
            int del;
            cout<<"Enter a Key to Delete : ";
            cin>>del;
            root=deleteBST(root,del);
            cout<<endl;
            break;
        case 3:
            cout<<"Inorder Form : ";
            inorder(root);
            cout<<"\n"<<endl;
            break;
        default:
            cout<<"Invalid Choice!!\n"<<endl;
            break;
        }
    }
    return 0;
}
