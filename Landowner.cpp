/**
 *时间：
 *作用：
 *基本描述：
 */
#include "Landowner.h"

Landowner::Landowner()
{
    SetName("默认地主");
    SetExp(0);
    SetGold(1000);
    SetSex("保密");
    cout << "Landowner()" << endl;
    void Initcards();
}

Landowner::Landowner(string name) : m_Name(name)
{
    SetExp(0);
    SetGold(1000);
    SetSex("保密");
    cout << "Landowner(string name):m_Name(name)" << endl;
    Initcards();
    showcards(packcards);
}
Landowner::Landowner(string name, long exp, int gold, string sex) : m_Name(name), m_Exp(exp), m_Gold(gold), m_Sex(sex)
{
    cout << "Landowner(string name, long exp, int gold, string sex)" << endl;
    void Initcards();
}

Landowner::~Landowner()
{
    cout << GetName() << "被释放了" << endl;
}

void Landowner::showinfo()
{
    cout << "昵称：" << GetName() << endl;
    cout << "性别：" << GetSex() << endl;
    cout << "金币：" << GetGold() << endl;
    cout << "经验：" << GetExp() << endl;
}

void Landowner::Initcards()
{
    //生成默认的一副牌
    for (int i = 0; i < 54; i++)
    {
        packcards.push_back(i + 1);
        surpluscards.push_back(i + 1);
        packcards[i] = (i + 1);
    }
    currentcards.clear();
}

//显示牌的函数
void Landowner::showcards(const vector<int> &cards)
{
    for(int i = 0; i < cards.size(); i++)
    {
    cout << i << endl;
    }
    cout << endl;
}
