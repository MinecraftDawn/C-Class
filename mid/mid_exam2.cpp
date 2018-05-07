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
				 << _cScore << "\t\t";
		}
		
	private:
		int _number;
		
		int _eScore;
		
		int _cScore;
		
		char _name[11];
};

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
			
			setStu(_people,stu);
			
			_people++;
		}
		
		void showCl(){
			cout << "班級名稱： "  << getName() << endl;
			
			cout << "座號" 		<< "\t\t"
				 << "姓名"		<< "\t\t"
				 << "英文分數"  << "\t\t"
				 << "中文分數"  << "\t\t" << endl; 
				 
			for(int i=0 ;i<_people ;i++){
				_stu[i].showSt();
				cout << endl;
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
						cout << "新增學生資料執行中" << endl;
						break;
						
					case 2://search
						cout << "查詢學生資料執行中" << endl; 
						break;
						
					case 3://print
						cout << "列印學生資料執行中" << endl; 
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
};

void MENU(){
	menu myMenu;
	myMenu.run();
}

int main(){
	MENU();
	system("pause");
	return 0;
}
