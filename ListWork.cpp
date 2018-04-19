#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
	Node(char name[100]="",int data=0){
		setData(data);
		setName(name);
		setPtr(NULL);
	}
	
	int getDate(){
		return _data;
	}
	void setData(int data){
		_data = data;
	}
	
	char *getName(){
		return _name;
	}
	void setName(char *name){
		strcpy(_name,name);
	}
	
	Node *getPtr(){
		return _ptr;
	}
	void setPtr(Node *ptr){
		_ptr = ptr;
	}

	/*******************************
	 新增串列並排列 
	*******************************/
	void ADappendSort(int data,char name[]){
		Node *node = this;
		
		Node *temPtr = node;
		
		if(node->getDate() > data){ //插入最前方 
			Node *t = new Node;
			
			t->setData(this->getDate());
			t->setName(this->getName());
			t->setPtr(this->getPtr());
			
			this->setData(data);
			this->setPtr(t);
			this->setName(name);

			return;
		}
	
		while(temPtr){
			if(temPtr->getDate() == data){ 
					cout << "錯誤！已存在該資料，無法新增" << endl;
					return;
			}
			
			if(temPtr->getPtr()){//若輸入值介於串列中間
				if(temPtr->getDate()<data && temPtr->getPtr()->getDate()>data){
					Node *t = new Node;
					
					t->setData(data);
					t->setName(name);
					t->setPtr(temPtr->getPtr());
					
					temPtr->setPtr(t);

					return;
				}
			}else if(!temPtr->getPtr()){//若輸入值大於整個串列(已到串列尾端)
				temPtr->setPtr(new Node);
				temPtr = temPtr->getPtr();
				temPtr->setData(data);
				temPtr->setName(name);

				return;
			}
	
			temPtr = temPtr->getPtr();
		}
	
	}
	
	/*******************************
	顯示串列數值 
	*******************************/ 
	void showNode(){
		Node *temPtr = this;
		
		if(temPtr && !temPtr->getPtr()){//串列只有一個值 
			if(strlen(temPtr->getName())==0){
				cout << "End" << endl;
				
				return;
			}
				
				
		}
		
		while(temPtr){
			cout << temPtr->getDate() << ": " << temPtr->getName() << " -> ";
			temPtr = temPtr->getPtr();
		}
		cout << "End" << endl;
		
	}
	
	void linerSearch(int data){
		Node *temPtr = this;
		int i=0;
		bool find=false;
		
		if(temPtr==NULL || temPtr->getName()==""){
			cout <<"查無此節點"<<endl;
			return;
		}
		
		while(temPtr){
			i++;
			if(temPtr->getDate()==data){
				find = true;
				break;
			}
			temPtr = temPtr->getPtr();	
		}
		if(find)
		cout << "找到了！ " <<  data <<
		" 位於串列中第 " << i << " 個位置，名字為"<< temPtr->getName() << endl;
		 
		else cout <<"查無此節點"<<endl;  
	}
	
	/***************************
	刪除資料 
	***************************/
	void delList(int data){
		Node *temPtr = this;
		
		if(this==NULL){//串列為空 
			cout << "[Warnning]空串列，無法刪除" << endl;
			return;
		}
		
		//刪除頭
		if(temPtr->getDate() == data){
			if(temPtr->getPtr()){//串列有下一個 
				Node *delPtr = temPtr->getPtr();
				
				temPtr->setData(temPtr->getPtr()->getDate());
				
				temPtr->setName(temPtr->getPtr()->getName());
				
				temPtr->setPtr(temPtr->getPtr()->getPtr());
				
				delete delPtr;
				
				return;
			}else{
				temPtr->setData(0);
				
				temPtr->setName("");
				
				temPtr->setPtr(NULL);
				
				return;
			}
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
				
				return;
				
			}
			temPtr = temPtr->getPtr();	
		}
		cout << "[Warnning]查無此資料，因而無法刪除" << endl; 
		
	}
	
private:
	int _data;
	
	Node *_ptr;
	
	char _name[100];
};

class Menu{
	public:
		void run(){

			do{
				showMenu();
				cin >> func; 
				
				switch(func){
					case 1:
						addData();
						break;
						
					case 2:
						delData();
						break;
						
					case 3:
						Search();
						break;
						
					case 4:
						showNode();
				}
			}while(func!=5);
		}
		
		void showMenu(){
			cout << "請輸入想選取的功\能" << endl
			<< "1. 新增資料" << endl
			<< "2. 刪除資料" << endl
			<< "3. 查詢資料" << endl
			<< "4. 列印資料" << endl
			<< "5. 離開系統" << endl << endl;
		}
		
	private:
		int func;
		
		Node *myNode=NULL;
		
		void addData(){
			
			int data=0;
			char name[100];
			
			cout << "請輸入想新增的數值" << endl;
			cin >> data;
			cin.sync();//clear buffer
			cout << "請輸入想新增的名字" << endl;
			cin.getline(name,100);
			
			if(!myNode){
				myNode = new Node(name,data);
			} 
			else{
				myNode->ADappendSort(data,name);
			} 
			
		}
		
		void delData(){
			int data=0;
			cout << "請輸入想刪除的值" << endl;
			cin >> data;
			myNode->delList(data);
		}
		
		void Search(){
			int data=0;
			cout << "請輸入想查詢的值" << endl;
			cin >> data;
			myNode->linerSearch(data);
		}
		
		void showNode(){
			myNode->showNode();
		}
		
};

/***************************
主程式 
***************************/
int main(){
	Menu myMenu;
	myMenu.run();
}

