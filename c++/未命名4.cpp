#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
class Game_2048
{
public:
    Game_2048();
    ~Game_2048();
    void introduction();
    bool judgeOver();                            //�ж���Ϸ�Ƿ����
    void reSize();
    void printBoard();                          //��ӡ����
    void getRand();                              //���������������2��4��
    void slide();                                //����
private:
    int m=4, n=4;
    char op;                                   //�û�����
    vector< vector<int> >     board;                                //����
    vector<int>  row;
    bool judgeInsert(int x,int y);
    bool judgeSlide();                               //�ж��Ƿ��ܻ�������δд�꣩
    void copyBoard(vector< vector<int> > &newBoard,vector< vector<int> > &board);
    void inputOp();
    char getOp();                            //���ز�����

    bool judgeLeftSlide(bool mark=true);
    void leftSlide();                            //�󻬶�

    bool judgeRightSlide(bool mark = true);
    void rightSlide();

    bool judgeUpSlide(bool mark = true);
    void upSlide();

    bool judgeDownSlide(bool mark = true);
    void downSlide();

    void reStart();
    void enlarge();                             //��ֵ�������
};

int main()
{
    Game_2048 NB;
    NB.introduction();
    NB.getRand();
    NB.printBoard();
    while (!NB.judgeOver())
    {
        NB.slide();
        NB.getRand();
        NB.printBoard();
    } 
    cout << "��Ϸ����������\n";
    system("pause");
    return 0;

}

void Game_2048::introduction()
{
    cout << "����һ��2048��Ϸ,�������£�\n";
    cout << "�ϻ���W��\n�»���S��\n�󻮣�A��\n�һ���D��\n�˳���Q��\n���¿�ʼ��R��\n�������´β�����\n";
}

void Game_2048::slide()
{
    inputOp();
    switch (getOp())
    {
    case 'a':
    case 'A':
        if (judgeLeftSlide())
            do
                leftSlide();
            while (judgeLeftSlide(false));
        else
        {
            cout << "�޷��󻬶��������ԣ�����\n";
            slide();
        }
        break;
    case 'd':
    case 'D':
        if (judgeRightSlide())
            do
                rightSlide();
        while (judgeRightSlide(false));        
        else
        {
            cout << "�޷��һ����������ԣ�����\n";
            slide();
        }
        break;
    case 'w':
    case 'W':
        if(judgeUpSlide())
            do
            upSlide();
        while (judgeUpSlide(false));
        else
        {
            cout << "�޷��ϻ����������ԣ�����\n";
            slide();
        }
        break;
    case 's':
    case 'S':
        if(judgeDownSlide())
            do    
                downSlide();
            while (judgeDownSlide(false));
        else
        {
            cout << "�޷��»����������ԣ�����\n";
            slide();
        }
        break;
    case 'p':
    case 'P':
        enlarge();
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 'r':
    case 'R':
        reStart();
        break;
    default:
        cout << "���������Ϊ�ͷ����������һ������\n";
        break;
    }
}


void Game_2048::reStart()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
}

void Game_2048::enlarge()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            board[i][j] *= 2;
        }
}


char Game_2048::getOp()
{
    return op;
}

void Game_2048::upSlide()
{
    for (int j = 0; j < n; j++)
        for (int i = m - 1; i > 0; i--) {                              //n-1!!
            if (board[i][j] != 0 && board[i - 1][j] == 0)            //�ƶ�
            {
                    board[i - 1][j] = board[i][j];
                    board[i][j] = 0;
            }
        }
    for (int j = 0; j < n; j++)
        for (int i = m - 1; i > 0; i--) {
            if (board[i][j] != 0 && board[i-1][j] == board[i][j])  //����
            {
                board[i-1][j] += board[i][j];
                board[i][j] = 0;
            }
        }
}

bool Game_2048::judgeUpSlide(bool mark)
{
    if (mark)
    {
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j > 0; j--)
            {
                if (board[i][j] == 0)
                return true;
            }
    }
    for (int j = 0; j < n; j++)
        for (int i = m - 1; i > 0; i--) {                              //n-1!!
            if (board[i][j] != 0 && board[i - 1][j] == 0)            //�ƶ�
                return true;
            if (board[i][j] != 0 && board[i - 1][j] == board[i][j])  //����
                return true;
        }
    return false;
}

bool Game_2048::judgeDownSlide(bool mark)
{
    if (mark) {
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j > 0; j--)
                {
                    if (board[i][j] == 0)
                        return true;
                }
        
    }
    for (int j = 0; j < n; j++)
                for (int i = 0; i < m - 1; i++) {                              //n-1!!
                    if (board[i][j] != 0 && board[i + 1][j] == 0)            //�ƶ�
                        return true;
                    if (board[i][j] != 0 && board[i + 1][j] == board[i][j])  //����
                        return true;

                }
    return false;
}

void Game_2048::downSlide()
{
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m - 1; i++) {                         
            if (board[i][j] != 0 && board[i + 1][j] == 0)            //�ƶ�
            {
                    board[i + 1][j] = board[i][j];
                    board[i][j] = 0;
            }
        }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m - 1; i++) {
            if (board[i][j] != 0 && board[i + 1][j] == board[i][j])  //����
            {
                board[i + 1][j] += board[i][j];
                board[i][j] = 0;
            }
        }
}


void Game_2048::rightSlide()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {                              //n-1!!
            if (board[i][j] != 0 && board[i][j + 1] == 0)            //�ƶ�
            {
                    board[i][j + 1] = board[i][j];
                    board[i][j] = 0;
            }
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] != 0 && board[i][j + 1] == board[i][j])  //����
            {
                board[i][j + 1] += board[i][j];
                board[i][j] = 0;
            }
        }
}

bool Game_2048::judgeRightSlide(bool mark )
{
    if (mark) {
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j > 0; j--)
            {
                if (board[i][j] == 0)
                    return true;
            }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {                              //n-1!!
            if (board[i][j] != 0 && board[i][j + 1] == board[i][j])  //����
                return true;
            if (board[i][j] != 0 && board[i][j + 1] == 0)
                return true;
        }
    return false;
}

void Game_2048::leftSlide()
{
    for (int i = 0; i < m; i++)
        for (int j = 1; j < n; j++) {                              //n-1!!
            if (board[i][j] != 0 && board[i][j - 1] == 0)            //�ƶ�
            {
                    board[i][j - 1] = board[i][j];
                    board[i][j] = 0;
            }
        }
    for (int i = 0; i < m; i++)
        for (int j = 1; j < n; j++) {
            if (board[i][j] != 0 && board[i][j - 1] == board[i][j])  //����
            {
                board[i][j - 1] += board[i][j];
                board[i][j] = 0;
            }
        }
}

bool Game_2048::judgeLeftSlide(bool mark)
{
    if (mark) {
        for (int i = 0; i < m; i++)
                for (int j = n - 1; j > 0; j--)
                {
                    if (board[i][j] == 0)
                        return true;
                }
    }
    for (int i = 0; i < m; i++)
        for (int j = n - 1; j > 0; j--) {                              //n-1!!
            if (board[i][j] != 0 && board[i][j - 1] == 0)            //�ƶ�
                return true;
            if (board[i][j] != 0 && board[i][j - 1] == board[i][j])  //����
                return true;
        }
    return false;
}

bool Game_2048::judgeOver()
{
    if (op == 'q' || op == 'Q')
        return true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2048)
            {
                printBoard();
                cout << "�����ִﵽ��2048����ϲ������\n";
                return true;
            }    
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
             if (board[i][j] == 0)
                return false;
        }
    if (judgeSlide())
        return false;
    else
    {
        cout << "�޷��ٻ���\n";
        return true;
    }
        
}

bool Game_2048::judgeSlide()
{
    vector< vector<int> >     copyBoard;                                //����
    vector<int>  copyRow;
    for (int i = 0; i < n; i++) {
        copyRow.push_back(0);
    }
    for (int i = 0; i < m; i++) {
        copyBoard.push_back(copyRow);
    }
    copyBoard = board;
    upSlide();
    downSlide();
    leftSlide();
    rightSlide();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0) {
                board = copyBoard;
                return true;
            }    
        }
    return false;
}

void Game_2048::copyBoard(vector< vector<int> >& newBoard, vector< vector<int> >&     board)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            newBoard[i][j] = board[i][j];
}

bool Game_2048::judgeInsert(int x,int y)
{
    if (board[x][y] == 0)
        return true;
    else
        return false;
}
void Game_2048::getRand()
{
    srand(time(0));
    int x, y,val;
    do
    {
        x = rand() % m;
        y = rand() % n;
    } while (!judgeInsert(x,y));
    val = (rand() % 2 + 1)*2;
    board[x][y] = val;

}

void Game_2048::inputOp()
{
    cin >> op;
}
void Game_2048::reSize()
{
    cout << "���������̴�Сm*n\n";
    cin >> m >> n;
    Game_2048();
}

Game_2048::~Game_2048()
{
}

Game_2048::Game_2048()
{
    for (int i = 0; i < n; i++){
        row.push_back(0);
    }
    for (int i = 0; i < m; i++){
        board.push_back(row);
    }
}
void Game_2048::printBoard()
{
    cout << "\n--------------\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
            if (j < n-1)
            {
                cout << "��";
            }
            if (j == n-1 && i < m-1)
            {
                cout << endl;
                int count = 0;
                while (count++ < n-1)
                {
                    cout << "|  ";
                }
                cout << "|" << endl;
            }
        }
    }

    cout << "\n--------------\n" ;
}

