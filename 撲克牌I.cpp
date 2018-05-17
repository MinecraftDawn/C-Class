#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>

using namespace std;

class PokerCard{
public:
	PokerCard(){}
	
	PokerCard(int num){
		numToPoker(num);
		_sended = false;
	}
	
	int getColor(){
		return _color;
	}
	
	string getColorSt(){
		switch(_color){
			case 0:
				return "梅花";
				break;
			
			case 1:
				return "方塊";
				break;
				
			case 2:
				return "紅心";
				break;
				
			case 3:
				return "黑桃";
				break;
				
			default:
				return "Error";
				break; 
		}
	}
	
	int getNum(){
		return _number;
	}
	
	bool isSended(){
		return _sended;
	}
	
	void send(){
		_sended = true;
	}
	
	void Recover(){
		_sended = false;
	}
	
private:
	void numToPoker(int num){
		_color = (num-1)/13;
		_number = (num-1)%13+1;
		
		if(_color > 4 || _number > 13 ||
		  (_color == 0 && _number == 0)){
			cout << "[警告] 花色或數字有問題！" << endl; 
		}
	}
		
private://屬性 
	string _colorSt;
	int _color;
	int _number;
	bool _sended;
};

class PokerCards{
public:
	PokerCards(){
		
		Shuffle();
		
		for(int i =1;i<=52;i++){ //初始化卡片
			card[i] = PokerCard(i);
		}
	}
	
	void Shuffle(){
		for(int i =1;i<=52;i++){ //回收卡片 
			card[i].Recover();
		}
	}
	
	PokerCard* getCard(int num){
		return &(card[num]);
	}
	
	bool checkHaveCard(){
		for(int i =1;i<=52;i++){ 
			if(! card[i].isSended())
				return true;
		}
		return false;
	}
	
private:	

private://屬性 
	PokerCard card[53];
};

class Menu{
public:
	void showRound(){
		cout << "第 " <<  getRound() << " 回合\t"
			 << "玩家勝場 " << getPlayerWin()  << "\t" 
			 << "電腦勝場"  << getComputerWin() << endl; 
	}
	
	void run(){
		do{
			showMenu();
			
			cin >> _select;
			
			if(_select < 1 || _select > 5){
				cout << "[警告] 輸入的數值有誤，請重新輸入" << endl;
				continue;
			}
			
			switch(_select){
				case 1://洗牌
					cards.Shuffle();
					break;
					
				case 2://比大
					size = true;
					srartGame();
					break;
					
				case 3://比小
					size = false;
					srartGame();
					break;
					
				case 4://場數
					showRound();
					break; 
					
				case 5://離開
					break; 
			}
			
		}while(_select != 5);
	}
	
private:
	void showMenu(){
		cout << "(1).洗牌"	<< endl
			 << "(2).比大"	<< endl
			 << "(3).比小"	<< endl
			 << "(4).勝場"	<< endl
			 << "(5).離開"	<< endl
			 << "請輸入選擇項目？" 	<< endl; 
	}
	
	int getRound(){
		return _cpuWin + _playerWin;
	}
	
	int getComputerWin(){
		return _cpuWin;
	}
	
	int getPlayerWin(){
		return _playerWin;
	}
	
	void sendCard(){
		srand(1);
		
		int card;
		PokerCard *ptr;
		
		/***************************
		發玩家手排 
		****************************/
		do{
			card = rand()%52+1;	
			
			ptr = cards.getCard(card);	
			
		}while( ptr->isSended());
		ptr->send();
		playerCard = *ptr;
		
		/***************************
		發電腦手排 
		****************************/
		do{
			card = rand()%52+1;
			
			ptr = cards.getCard(card);
			
		}while(ptr->isSended());
		ptr->send();
		cpuCard = *ptr;
				
	}
	
	void srartGame(){
		if(!cards.checkHaveCard()){
			cout << "沒有排摟，請洗牌" << endl;
			return; 
		}
		
		sendCard();
		
		cout << "玩家手排： " << playerCard.getColorSt() << playerCard.getNum() << endl
			 << "電腦手排： " << cpuCard.getColorSt() << cpuCard.getNum() << endl;
			
		bool playerBig;
		
		playerBig = judgeSize(playerCard,cpuCard);
		
		if(size){
			if(playerBig){
				cout << "玩家獲勝" << endl;
				_playerWin++;
			}else{
				cout << "電腦獲勝" << endl;
				_cpuWin++;
			}
		}else{
			if(!playerBig){
				cout << "玩家獲勝" << endl;
				_playerWin++;
			}else{
				cout << "電腦獲勝" << endl;
				_cpuWin++;
			}
		}
		
		cout << endl;
		
	}
	
	bool judgeSize(PokerCard card1,PokerCard card2){//card1>card2 會回傳True; 
		if(card1.getNum() == card2.getNum()){
			
			if(card1.getColor() > card2.getColor()){
				return true;
			}else{
				return false;
			}
			
		}else if(card1.getNum() > card2.getNum()){
			return true;
		}else if(card1.getNum() < card2.getNum()){
			return false;
		}
			
			
	}
	
private:
	int _select;
	int _cpuWin;
	int _playerWin;
	PokerCards cards;
	bool size;//True->大 , False->小 
	
	PokerCard playerCard;
	PokerCard cpuCard;
};



int main(){

	Menu w;
	w.run();

}

