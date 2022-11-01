#include"Snake.h"

void Snake::Show_information(int& score,int& sleeptime)
{
    Pos(44, 4);
    cout << "�÷�: " << score<<"     ";//�ո�������λ��
    cout << "�ٶ�: "<<  sleeptime;
}

void Snake::overout(const int score)                    //��Ϸ������ʾ
{
    Pos(44, 14);
    cout << "��Ϸ����";
    Pos(44, 18);
    cout << "�÷֣�" << score;
}

void Snake::Gameover(int& score,int &x)                 //��Ϸ����ԭ�򼰵÷�
{
    //ײǽ
    if (snakepoint[0].x >= 100 || snakepoint[0].x < 22 || snakepoint[0].y >= 36 || snakepoint[0].y < 6)
    {
        system("cls");      //����
        Pos(44, 10);
        cout << "ײǽ����ͷ̫��";
        overout(score);
        score = 0;
        Sleep(3000);
        exit(0);            //�˳�
    }
    //ײ������
    for (int i = 1; i < snakepoint.size(); i++)
        if (snakepoint[0].x == snakepoint[i].x && snakepoint[0].y == snakepoint[i].y)
        {
            system("cls");  //����
            Pos(44, 10);
            cout << "ײ�����������϶���ʹ";
            overout(score);
            score = 0;
            Sleep(3000);
            exit(0);       //�˳�
        }
}

void Snake::Control(Snakepoint& nexthead)
{
    static char Direction = 'R';                //��̬������ֹ�ı��ƶ���������¸Ļ���������������Ϊ��ʼ������

    if (_kbhit())
    {
        char temp = _getch();                   //��ʱ����������������ֵ

        if ((temp == 'd') && Direction != 'L')
        {
            Direction = 'R';
        }
        else if ((temp == 'a') && Direction != 'R')
        {
            Direction = 'L';
        }
        else if ((temp == 'w') && Direction != 'D')
        {
            Direction = 'U';
        }
        else if ((temp == 's') && Direction != 'U')
        {
            Direction = 'D';
        }
    }

    switch (Direction)                          //����Direction��ֵ��ȷ���ߵ��ƶ�����
    {
    case 'R':
        nexthead.x = snakepoint.front().x + 2;  //�µ���ͷ��ͷ�����������ڵ�һ������(����ͷ)x����+2 
        nexthead.y = snakepoint.front().y;
        break;
    case 'L':
        nexthead.x = snakepoint.front().x - 2;
        nexthead.y = snakepoint.front().y;
        break;
    case 'U':
        nexthead.x = snakepoint.front().x;
        nexthead.y = snakepoint.front().y - 1;  //��Ϊ����̨��x������y��һ�룬����������x����ͷ����Ҫ�������Ƕ���
        break;
    case 'D':
        nexthead.x = snakepoint.front().x;
        nexthead.y = snakepoint.front().y + 1;
    }
}

void Snake::sleep(int& score, int& sleeptime)
{
    if (score < 10)
    {
        sleeptime = 120;
    }
    else if (score <20)
    {
        sleeptime = 80 ;
    }
    else if (score <30)
    {
        sleeptime = 50 ;
    }
    else
    {
        sleeptime = 30 ;
    }
    Sleep(sleeptime);                                   //�ٶ�������ӿ�
}

void Snake::move(Food& food, int& score,int& sleeptime,int& x)
{
    Snakepoint nexthead;
    Control(nexthead);
    snakepoint.insert(snakepoint.begin(), nexthead);    //����ͷ����������ͷ��

    Show_information(score ,sleeptime);
    Gameover(score,x);

    if (snakepoint[0].x == food.getFood_x() && snakepoint[0].y == food.getFood_y()) //��ͷ��ʳ���غ�
    {
        Pos(snakepoint[0].x, snakepoint[0].y);          //�Ե�ʳ��ʱ�����û���ƶ��������߻Ῠ��һ��
        cout << "��";                                   //�������һ����ͷ�͵�һ���������߲�����
        Pos(snakepoint[1].x, snakepoint[1].y);
        cout << "��";

        score++;                                        //�Ե�ʳ��÷�+1
        food.randfood();                                //���²���һ��ʳ��
        return ;                                        //ֱ�ӽ��������ƶ�
    }

    //��ÿ�ƶ�һ�Σ�������ǰ��һ�Σ���ӡ�����Ĳ��ֳ���β�������඼�����ǣ�������������β
    for (int i = 0; i < snakepoint.size(); i++)         //�����������ж�ʳ���������Ƿ��غϲ����������
    {                                            
        Pos(snakepoint[i].x, snakepoint[i].y);
        if (!i)                                         //��ͷ
            cout << "��";
        else
            cout << "��";

        //���ʳ��ˢ�µ��������ϣ������²���һ��ʳ��
        if (snakepoint[i].x == food.getFood_x() && snakepoint[i].y == food.getFood_y())
            food.randfood();
    }

    Pos(snakepoint.back().x, snakepoint.back().y);      //������β���ĵط�����ո� ��������ϵ���β
    cout << "  ";
    snakepoint.pop_back();                              //ɾ�����������һ������   ��������ϵ���β
}

Snake::Snake()
{
    Direction = 'R';
    Snakepoint temp;                                    //��ʱ�ṹ�������ڴ�����
    for (int i = 5; i >= 0; i--)                        //���򴴽���ʼ������ʼ��ͷ����
    {
        temp.x = 22 + (i << 1);                         //ż�� ����ͷ������������
        temp.y = 7;
        snakepoint.push_back(temp);                     //����ββ������ʱ����
    }
}