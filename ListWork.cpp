#include <iostream>

using namespace std;

class Node{
public:
	Node(){
		setData(0);
		setPtr(NULL);
	}
	
	int getDate(){
		return _data;
	}
	int setData(int data){
		_data = data;
	}
	
	Node *getPtr(){
		return _ptr;
	}
	Node setPtr(Node *ptr){
		_ptr = ptr;
	}
	
private:
	int _data;
	Node *_ptr;
};

/**********************************
�s�W��C 
**********************************/
void append(Node *node,int data=0){
	
	Node *temPtr = node;
	while(temPtr->getPtr()){
		temPtr = temPtr->getPtr();
	}
	temPtr->setPtr(new Node);
	temPtr = temPtr->getPtr();
	temPtr->setData(data);
}

/*******************************
 �s�W��C�ñƦC 
*******************************/
Node *ADappendSort(Node *node,int data=0){
	if(node==NULL){//�Y��C���šA�h�s�W�Ĥ@���Y�A�ó]�w��� 
		node = new Node;
		node->setData(data);
		node->setPtr(NULL);
		return node;
	}
	
	Node *temPtr = node;
	
	if(node->getDate() > data){ //���J�̫e�� 
		Node *t = new Node;
		t->setData(data);
		t->setPtr(node);
		node=t;
		return node;
	}

	while(temPtr){
		if(temPtr->getDate() == data){
				cout << "���~�I�w�s�b�Ӹ�ơA�L�k�s�W" << endl;
				return node;
		}
		
		if(temPtr->getPtr()){//�Y��J�Ȥ����C����
			if(temPtr->getDate()<data && temPtr->getPtr()->getDate()>data){
				Node *t = new Node;
				t->setData(data);
				t->setPtr(temPtr->getPtr());
				temPtr->setPtr(t);
				return node;
			}
		}else if(!temPtr->getPtr()){//�Y��J�Ȥj���Ӧ�C(�w���C����)
			temPtr->setPtr(new Node);
			temPtr = temPtr->getPtr();
			temPtr->setData(data);
			return node;
		}

		temPtr = temPtr->getPtr();
	}

}
/*******************************
�s�W�ܦ�C�Y 
*******************************/
Node *ADappendHead(Node *node,int data=0){
	if(node==NULL){//�Y��C���šA�h�s�W�Ĥ@���Y�A�ó]�w��� 
		node = new Node;
		node->setData(data);
		node->setPtr(NULL);
		return node;
	}
	
	Node *tem = new Node;
	tem->setData(data);
	tem->setPtr(node);
	return tem;

}
/*******************************
�s�W�ܦ�C�� 
*******************************/ 
Node *ADappendTail(Node *node,int data=0){
	if(node==NULL){//�Y��C���šA�h�s�W�Ĥ@���Y�A�ó]�w��� 
		node = new Node;
		node->setData(data);
		node->setPtr(NULL);
		return node;
	}
	
	Node *tem = node;
	while(tem->getPtr()){
		tem = tem->getPtr();
	}
	
	tem->setPtr(new Node);
	tem = tem->getPtr();
	tem->setData(data);
	return node;
	
}

/*******************************
��ܦ�C�ƭ� 
*******************************/ 
void showNode(Node *node){
	
	Node *temPtr = node;
	while(temPtr){
		cout << temPtr->getDate() << " -> ";
		temPtr = temPtr->getPtr();
	}
	cout << "End" << endl;
	
}
/***************************
�d�߸�� 
***************************/
void linerSearch(Node *node,int data){
	Node *temPtr = node;
	int i=0;
	bool find=false;
	
	while(temPtr){
		i++;
		if(temPtr->getDate()==data){
			find = true;
			break;
		}
		temPtr = temPtr->getPtr();	
	}
	if(find)cout << "���F�I " <<  data << " ����C���� " << i << " �Ӧ�m"<<endl;
	else cout <<"�d�L���`�I"<<endl;  
}
	
/***************************
�R����� 
***************************/
Node *delList(Node *node,int data){
	Node *temPtr = node;
	
	if(node==NULL){//��C���� 
		cout << "�Ŧ�C�A�L�k�R��" << endl; 
		return node;
	}
	
	//�R���Y 
	if(temPtr->getDate() == data){
		node = temPtr->getPtr();
		delete temPtr;
		return node;
	}
	
	while(temPtr->getPtr()){
		if(temPtr->getPtr()->getDate()==data){
			Node *delPtr = temPtr->getPtr();
			
			if(delPtr->getPtr()){//�b��C���� 
				temPtr->setPtr(delPtr->getPtr());
				
			}else{//�b��C���� 
				temPtr->setPtr(0);
			}
			delete delPtr;
			
			return node;
			
		}
		temPtr = temPtr->getPtr();	
	}
	
}

/***************************
�D�{�� 
***************************/
int main(){
	Node *listSort = NULL;
	Node *listHead = NULL;
	Node *listTail = NULL;
	
	int data=0;
	int func=1;
	while(func!=5){
		//��J�Q������\��
		cout << "�п�J�Q������\\��" << endl
			 << "1. �s�W���" << endl
			 << "2. �R�����" << endl
			 << "3. �d�߸��" << endl
			 << "4. �C�L���" << endl
			 << "5. ���}�t��" << endl << endl;
		cin >> func;
		
		switch (func){
			case 1://�s�W��� 
				cout << "�п�J�s�[�J����C��" << endl;
				cin >> data;
				listSort = ADappendSort(listSort,data);
				//listHead = ADappendHead(listHead,data);
				//listTail = ADappendTail(listTail,data);
				break;
				
			case 2://�R�����
				cout << "�п�J�Q�R������C��" << endl;
				cin >> data; 
				listSort = delList(listSort,data);
				break;
			
			case 3://�d�߸�� 
				cout << "�п�J�Q�d�ߪ���C��" << endl;
				cin >> data; 
				linerSearch(listSort,data);
				break;
				
			case 4://�C�L��� 
				cout << "�s���åB�ƧǡG  ";showNode(listSort);
				//cout << "�s����C�Y���G  ";showNode(listHead);
				//cout << "�s����C���ݡG  ";showNode(listTail);
				break;
				
			case 5://���}
				break; 
		}
	
	cout << "���}";
		
	}
	
}

