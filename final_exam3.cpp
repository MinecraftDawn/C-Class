#include <iostream>
#include <cstring>

using namespace std;

class ST{
	
	public:
		int getNum(){
			return _number;
		}
		
		void setNum(int num){
			_number = num;
		}
		
		int getEScore(){
			return _eScore;
		}
		
		void setEScore(int score){
			_eScore = score;
		}
		
		int getCScore(){
			return _cScore;
		}
		
		void setCScore(int score){
			_cScore = score;
		}
		
		int getTotal(){
			return getEScore()+getCScore();
		}
		
		char *getName(){
			return _name;
		}
		
		void setName(char* name){
			strcpy(_name,name);
		}
		
		void showSt(){
			cout << _number << "\t\t"
				 << _name	<< "\t\t"
				 << _eScore << "\t\t\t"
				 << _cScore << "\t\t\t"
				 << getTotal() << endl;
		}
		
	private:
		int _number;
		
		int _eScore;
		
		int _cScore;
		
		char _name[11];
};

void swapST(ST &stu1,ST &stu2);

class CL{
	public:
		int getPeo(){
			return _people;
		}
		
		void setPeo(int peo){
			_people = peo;
		}
		
		char *getName(){
			return _CName;
		}
		
		void setName(char* name){
			strcpy(_CName,name);
		}
		
		ST getStu(int array){
			if(array <= 49)
			
				return _stu[array];
				
			else {
				cout << "error" << endl;
				
				return _stu[0];
			}
		}
		
		void setStu(int array,ST stu){
			if(array <= 49){
				_stu[array] = stu;
			} 
		}
		
		CL(){
			setName("資一甲");
			_people = 0;
		}
		
		void addPeo(){
			ST stu;
			
			int num;
			cout << "請輸入該學生座號" << endl;
			cin >> num;
			
			if(existNum(num)){
				cout << "[錯誤]座號重複" << endl;
				return; 
			}
			
			char name[11];
			cout << "請輸入該學生名字" << endl;
			cin.sync();
			cin.getline(name,11);
			
			int escore;
			cout << "請輸入該學生英文成績" << endl;
			cin >> escore;
			
			int cscore;
			cout << "請輸入該學生中文成績" << endl;
			cin >> cscore;
			
			stu.setNum(num);
			stu.setName(name);
			stu.setEScore(escore);
			stu.setCScore(cscore);
			
			setStu(getPeo(),stu);
			
			_people++;
		}
		
		void Search(char name[11]){
			bool nfind = true;
			
			for(int i=0 ;i<_people ;i++){
				
				if(! strcmp(_stu[i].getName(),name)){
					
					showCLTitle();
					_stu[i].showSt();
					
					nfind = false;
				
				}
			}
			if(nfind){
				cout << "查無此學生資料" << endl; 
			}
		}
		
		void BubbleSort(){
			if(_people<=1) return;
			
			for(int i=0;i<_people ;i++){
				
				for(int j=0 ;j<_people-1 ;j++){
					
					if(_stu[j].getTotal() < _stu[j+1].getTotal()){
						
						swapST(_stu[j],_stu[j+1]);
					}
				}
			}
		}
		
		void Print(){
			cout <<"班級名稱： " << getName() << endl
				 <<"班級人數： " << getPeo()  << " 人" << endl; 
			showCLTitle();
			
			BubbleSort();
			
			for(int i=0 ;i<_people ;i++){
				_stu[i].showSt();
			}
			
		}
		
		bool existNum(int num){
			for(int i=0 ;i<_people ;i++){
				
				if(_stu[i].getNum()==num)
					return true;
			}
			
			return false;
		}
		
		void showCLTitle(){
			cout << "座號" 		<< "\t\t"
				 << "姓名"		<< "\t\t"
				 << "英文分數"  << "\t\t"
				 << "中文分數"  << "\t\t"
				 << "總成績"    << endl;
		}
		
		void showCl(){
			cout << "班級名稱： "  << getName() << endl;
			
			showCLTitle();
				 
			for(int i=0 ;i<_people ;i++){
				_stu[i].showSt();
			}
		}
	
	private:
		int _people;
		
		char _CName[21];
		
		ST _stu[50];
};

class menu{
	public:
		void showMenu(){
			cout << "(1).新增學生資料"  << endl
				 << "(2).查詢資學生資料"<< endl
				 << "(3).列印學生成績單"<< endl
				 << "(4).離開"			<< endl
				 << "請輸入選擇項目？" 	<< endl; 
		}
		
		void run(){
			do{
				showMenu();
			
				cin >> func;
				
				if(func < 1 || func > 4){
					cout << "[警告] 輸入的數值有誤，請重新輸入" << endl;
					continue; 
				} 
				
				switch(func){
					case 1://add
						myClass.addPeo();
						break;
						
					case 2://search
						char name[11];
						cout << "請輸入該學生名字" << endl;
						cin.sync();
						cin.getline(name,11);
						
						myClass.Search(name);
						break;
						
					case 3://print
						myClass.Print();
						break;
						
					case 4://out
						cout << "正在離開本系統" << endl; 
						break;
				}
				cout << endl;
			}while(func!=4);
		}
		
	private:
		int func;
		CL  myClass;
};

void MENU(){
	menu myMenu;
	myMenu.run();
}

void swapST(ST &stu1,ST &stu2){
	ST stuTem;
	stuTem = stu1;
	stu1 = stu2;
	stu2 = stuTem;
}

int main(){
	MENU();
	return 0;
}
