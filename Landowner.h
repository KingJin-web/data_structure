#ifndef LANDOWNER_H
#define LANDOWNER_H
#include <iostream>
#include <vector>
using namespace std;

class Landowner
{
public:
    Landowner();
    //含参构造函数
    Landowner(string);
    Landowner(string, long, int, string);
    virtual ~Landowner();

    //显示信息函数
    void showinfo();

    //初始化向量容器的函数
    void Initcards();

    //显示牌的函数
    void showcards(const vector<int> &); //用引用，节省效率；用const，就是不能修改传进来的数组

    int GetGold() { return m_Gold; }
    void SetGold(int val) { m_Gold = val; }
    long GetExp() { return m_Exp; }
    void SetExp(long val) { m_Exp = val; }
    string GetSex() { return m_Sex; }
    void SetSex(string val) { m_Sex = val; }
    string GetName() { return m_Name; }
    void SetName(string val) { m_Name = val; }

protected:
private:
    int m_Gold;    //金币
    long m_Exp;    //经验
    string m_Sex;  //性别
    string m_Name; //名字

    //定义几个向量容器
    vector<int> currentcards; //当前玩家的手牌数组
    vector<int> packcards;    //默认的一副牌
    vector<int> surpluscards; //摸牌后，剩余的手牌数组
};

#endif // LANDOWNER_H
