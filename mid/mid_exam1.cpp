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
			setName("��@��");
			_people = 0;
		}
		
		void addPeo(){
			ST stu;
			
			int num;
			cout << "�п�J�Ӿǥͮy��" << endl;
			cin >> num;
			
			char name[11];
			cout << "�п�J�ӾǥͦW�r" << endl;
			cin.sync();
			cin.getline(name,11);
			
			int escore;
			cout << "�п�J�Ӿǥͭ^�妨�Z" << endl;
			cin >> escore;
			
			int cscore;
			cout << "�п�J�Ӿǥͤ��妨�Z" << endl;
			cin >> cscore;
			
			stu.setNum(num);
			stu.setName(name);
			stu.setEScore(escore);
			stu.setCScore(cscore);
			
			setStu(_people,stu);
			
			_people++;
		}
		
		void showCl(){
			cout << "�Z�ŦW�١G "  << getName() << endl;
			
			cout << "�y��" 		<< "\t\t"
				 << "�m�W"		<< "\t\t"
				 << "�^�����"  << "\t\t"
				 << "�������"  << "\t\t" << endl; 
				 
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
