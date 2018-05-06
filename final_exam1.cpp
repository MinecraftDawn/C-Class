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

int main(){
	CL myClass;
	
	myClass.addPeo();
	myClass.addPeo();
	myClass.addPeo();
	myClass.addPeo();
	myClass.addPeo();
	
	myClass.showCl();
	
	system("pause");
	return 0;
}
