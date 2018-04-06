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
新增串列 
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
 新增串列並排列 
*******************************/
Node *ADappendSort(Node *node,int data=0){
	if(node==NULL){//若串列為空，則新增第一個頭，並設定其值 
		node = new Node;
		node->setData(data);
		node->setPtr(NULL);
		return node;
	}
	
	Node *temPtr = node;
	
	if(node->getDate() > data){ //插入最前方 
		Node *t = new Node;
		t->setData(data);
		t->setPtr(node);
		node=t;
		return node;
	}

	while(temPtr){
		if(temPtr->getDate() == data){
				cout << "錯誤！已存在該資料，無法新增" << endl;
				return node;
		}
		
		if(temPtr->getPtr()){//若輸入值介於串列中間
			if(temPtr->getDate()<data && temPtr->getPtr()->getDate()>data){
				Node *t = new Node;
				t->setData(data);
				t->setPtr(temPtr->getPtr());
				temPtr->setPtr(t);
				return node;
			}
		}else if(!temPtr->getPtr()){//若輸入值大於整個串列(已到串列尾端)
			temPtr->setPtr(new Node);
			temPtr = temPtr->getPtr();
			temPtr->setData(data);
			return node;
		}

		temPtr = temPtr->getPtr();
	}

}
/*******************************
新增至串列頭 
*******************************/
Node *ADappendHead(Node *node,int data=0){
	if(node==NULL){//若串列為空，則新增第一個頭，並設定其值 
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
新增至串列尾 
*******************************/ 
Node *ADappendTail(Node *node,int data=0){
	if(node==NULL){//若串列為空，則新增第一個頭，並設定其值 
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
顯示串列數值 
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
查詢資料 
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
	if(find)cout << "找到了！ " <<  data << " 位於串列中第 " << i << " 個位置"<<endl;
	else cout <<"查無此節點"<<endl;  
}
	
/***************************
刪除資料 
***************************/
Node *delList(Node *node,int data){
	Node *temPtr = node;
	
	if(node==NULL){//串列為空 
		cout << "空串列，無法刪除" << endl; 
		return node;
	}
	
	//刪除頭 
	if(temPtr->getDate() == data){
		node = temPtr->getPtr();
		delete temPtr;
		return node;
	}
	
	while(temPtr->getPtr()){
		if(temPtr->getPtr()->getDate()==data){
			Node *delPtr = temPtr->getPtr();
			
			if(delPtr->getPtr()){//在串列中間 
				temPtr->setPtr(delPtr->getPtr());
				
			}else{//在串列尾端 
				temPtr->setPtr(0);
			}
			delete delPtr;
			
			return node;
			
		}
		temPtr = temPtr->getPtr();	
	}
	
}

/***************************
主程式 
***************************/
int main(){
	Node *listSort = NULL;
	Node *listHead = NULL;
	Node *listTail = NULL;
	
	int data=0;
	int func=1;
	while(func!=5){
		//輸入想選取的功能
		cout << "請輸入想選取的功\能" << endl
			 << "1. 新增資料" << endl
			 << "2. 刪除資料" << endl
			 << "3. 查詢資料" << endl
			 << "4. 列印資料" << endl
			 << "5. 離開系統" << endl << endl;
		cin >> func;
		
		switch (func){
			case 1://新增資料 
				cout << "請輸入新加入的串列值" << endl;
				cin >> data;
				listSort = ADappendSort(listSort,data);
				//listHead = ADappendHead(listHead,data);
				//listTail = ADappendTail(listTail,data);
				break;
				
			case 2://刪除資料
				cout << "請輸入想刪除的串列值" << endl;
				cin >> data; 
				listSort = delList(listSort,data);
				break;
			
			case 3://查詢資料 
				cout << "請輸入想查詢的串列值" << endl;
				cin >> data; 
				linerSearch(listSort,data);
				break;
				
			case 4://列印資料 
				cout << "連接並且排序：  ";showNode(listSort);
				//cout << "連接串列頭部：  ";showNode(listHead);
				//cout << "連接串列尾端：  ";showNode(listTail);
				break;
				
			case 5://離開
				break; 
		}
	
	cout << "離開";
		
	}
	
}

