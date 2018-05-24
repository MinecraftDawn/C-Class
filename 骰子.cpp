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
                return "����";
                break;

            case 1:
                return "���";
                break;

            case 2:
                return "����";
                break;

            case 3:
                return "�®�";
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
            cout << "[ĵ�i] ���μƦr�����D�I" << endl;
        }
    }

private://�ݩ�
    string _colorSt;
    int _color;
    int _number;
    bool _sended;
};

class PokerCards{
public:
    PokerCards(){

        Shuffle();

        for(int i =1;i<=52;i++){ //��l�ƥd��
            card[i] = PokerCard(i);
        }
    }

    void Shuffle(){
        for(int i =1;i<=52;i++){ //�^���d��
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

private://�ݩ�
    PokerCard card[53];
};

class Dice{
public:
    int getPoint(){
        return _point;
    }
    void setPoint(int point){
        if(point < 1 || point > 6){
            cout << "[ĵ�i]��l�I�Ʀ��~" << endl;
        }
        _point = point;
    }
    void randPoint(){
        _point = rand()%6 +1;
    }
private:
    int _point;
};

class IMenu{
public:
    IMenu(){
        _cpuWin = 0;
        _playerWin = 0;
    }

    void showRound(){
        cout << "�� " <<  getRound() << " �^�X\t"
             << "���a�ӳ� " << getPlayerWin()  << "\t"
             << "�q���ӳ�"  << getComputerWin() << endl;
    }

    void run();

protected:
    void showMenu();

    void srartGame();

    int getRound(){
        return _cpuWin + _playerWin;
    }

    int getComputerWin(){
        return _cpuWin;
    }

    int getPlayerWin(){
        return _playerWin;
    }

protected:
    int _select;
    int _cpuWin;
    int _playerWin;
    bool size;//True->�j , False->�p
};

class MenuPoker : virtual public IMenu{
public:

    void run(){
        do{
            showMenu();

            cin >> _select;

            if(_select < 1 || _select > 5){
                cout << "[ĵ�i] ��J���ƭȦ��~�A�Э��s��J" << endl;
                continue;
            }

            switch(_select){
                case 1://�~�P
                    cards.Shuffle();
                    break;

                case 2://��j
                    size = true;
                    srartGame();
                    break;

                case 3://��p
                    size = false;
                    srartGame();
                    break;

                case 4://����
                    showRound();
                    break;

                case 5://���}
                    break;
            }

        }while(_select != 5);
    }

private:
    void showMenu(){
        cout << "(1).�~�P"	<< endl
             << "(2).��j"	<< endl
             << "(3).��p"	<< endl
             << "(4).�ӳ�"	<< endl
             << "(5).���}"	<< endl
             << "�п�J��ܶ��ءH" 	<< endl;
    }

    void sendCard(){
        srand(time(NULL));

        int card;
        PokerCard *ptr;

        /***************************
        �o���a���
        ****************************/
        do{
            card = rand()%52+1;

            ptr = cards.getCard(card);

        }while( ptr->isSended());
        ptr->send();
        playerCard = *ptr;

        /***************************
        �o�q�����
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
            cout << "�S���ƺO�A�Ь~�P" << endl;
            return;
        }

        sendCard();

        cout << "���a��ơG " << playerCard.getColorSt() << playerCard.getNum() << endl
             << "�q����ơG " << cpuCard.getColorSt() << cpuCard.getNum() << endl;

        bool playerBig;

        playerBig = judgeSize(playerCard,cpuCard);

        if(size){
            if(playerBig){
                cout << "���a���" << endl;
                _playerWin++;
            }else{
                cout << "�q�����" << endl;
                _cpuWin++;
            }
        }else{
            if(!playerBig){
                cout << "���a���" << endl;
                _playerWin++;
            }else{
                cout << "�q�����" << endl;
                _cpuWin++;
            }
        }

        cout << endl;

    }

    bool judgeSize(PokerCard card1,PokerCard card2){//card1>card2 �|�^��True;
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
    PokerCards cards;
    PokerCard playerCard;
    PokerCard cpuCard;
};

class MenuDice : virtual public IMenu{
public:
    MenuDice(){
        srand(time(NULL));
        _round = 0;
    }

    void showMenu(){
        cout << "(1).����"	<< endl
             << "(2).��j"	<< endl
             << "(3).��p"	<< endl
             << "(4).�ӳ�"	<< endl
             << "(5).���}"	<< endl
             << "�п�J��ܶ��ءH" 	<< endl;
    }

    void run(){
        do{
            showMenu();

            cin >> _select;

            if(_select < 1 || _select > 5){
                cout << "[ĵ�i] ��J���ƭȦ��~�A�Э��s��J" << endl;
                continue;
            }

            switch(_select){
                case 1://�p����
                    showKnowledge();
                    break;

                case 2://��j
                    size = true;
                    srartGame();
                    break;

                case 3://��p
                    size = false;
                    srartGame();
                    break;

                case 4://����
                    showRound();
                    break;

                case 5://���}
                    break;
            }
        }while (_select != 5);
    }


private:
    void showKnowledge(){
        cout << "��l�ﭱ�[�_���I�ƦX��7��" << endl;
    }

    void srartGame(){
        throwDice();

        _round++;

        int Win = judgeSize(_plDice,_comDice);

        if(Win == 2){
            cout << "�����" << endl;
            return;
        }

        cout << "���a�I�ơG " << _plDice.getPoint() << "�I"<< endl
             << "�q���I�ơG " << _comDice.getPoint() << "�I"<< endl;

        if(size){//��j
            if(Win == 1){
                cout << "���a���" << endl;
                _playerWin++;
            }else if(Win == 3){
                cout << "�q�����" << endl;
                _cpuWin++;
            }
        }else{//��p
            if(Win == 3){
                cout << "���a���" << endl;
                _playerWin++;
            }else if(Win == 1){
                cout << "�q�����" << endl;
                _cpuWin++;
            }
        }
    }

    void throwDice(){
        _plDice.randPoint();
        _comDice.randPoint();
    }

    int judgeSize(Dice player,Dice computer){
        if(player.getPoint() > computer.getPoint()){
            return 1; //Player big
        }else if(player.getPoint() == computer.getPoint()){
            return 2; //Same size
        }else{
            return 3; //Computer big
        }


    }

    int getRound(){
        return _round;
    }

    void showRound(){
        cout << "�� " <<  getRound() << " �^�X\t"
             << "���a�ӳ� " << getPlayerWin()  << "\t"
             << "�q���ӳ�"  << getComputerWin() << endl;
    }
private:
    Dice _plDice;
    Dice _comDice;
    int _round;
};

int main(){
    MenuPoker p;
    MenuDice d;
    d.run();

}