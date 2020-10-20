
#include<bits/stdc++.h>
using namespace std;

class HuffNode
{
public:
    HuffNode *lchild;
    HuffNode *rchild;
    int data;
    char ch;
    HuffNode(){}
    HuffNode(int d,char c,HuffNode* l,HuffNode* r)
    {
        data=d;
        ch=c;
        lchild=l;
        rchild=r;
    }
    bool operator<(HuffNode &other)
    {
        return data>other.data;
    }
};

typedef HuffNode* HuffTree;//编码表 "a"->"11100011"

map<char,string> huffcode;


////比较两棵树权重的大小
// bool cmp(HuffTree t1,HuffTree t2)
// {
// 	return t1->data<ta->data;
// }
// 建树
HuffTree BuildHuffTree(map<char,int> values)
{
    priority_queue<HuffTree> queue;
    HuffTree *trees=new HuffTree[values.size()];
    int i=0;
    for(map<char,int>::iterator it=values.begin(); it!=values.end();it++)
    {
        HuffNode* root=new HuffNode();
        root->ch=it->first;
        root->data=it->second;
        root->lchild=NULL;
        root->rchild=NULL;
        trees[i++]=root;
        queue.push(root);
    }

    while(queue.size()!=1)
    {
        HuffTree t1=queue.top();
        queue.pop();

        HuffTree t2=queue.top();
        queue.pop();

        HuffTree newtree=new HuffNode(t1->data+t2->data,' ',t1,t2);
        queue.push(newtree);
    }

    HuffTree t1=queue.top();
    return t1;
    //int length=values.size();

//	while(length>1)
//	{
//		sort(trees,trees+length,cmp);//排序
//
//		HuffNode* root=new HuffNode();
//		root->data=trees[0]->data+trees[1]->data;
//		root->lchild=trees[0];
//		root->rchild=trees[1];
//
//		trees[0]=root;
//		swap(trees[1],trees[length-1]);
//		length--;
//	}

//	return trees[0];

}
//得到编码表 	map<char,string>
void getHuffRoute(HuffTree tree,char *route,int n)
{
    if(tree->lchild==NULL && tree->rchild==NULL)
    {
        cout<<"char="<<tree->ch<<" codelen= "<<n<<" code: "<<string(route,n)<<endl;
        huffcode[tree->ch]=string(route,n);//路径复制
        return;
    }
    route[n]='0';
    getHuffRoute(tree->lchild,route,n+1);
    route[n]='1';
    getHuffRoute(tree->rchild,route,n+1);
}

//编码
string Encoded(string str)
{
    string codedstr;
    for(int i=0;i<str.length();i++)//对每个字符进行编码
    {
        codedstr.append(huffcode[str[i]]);//key-value
    }
    return codedstr;
}

string Decoded(string codedstr)//译码
{
    int lastsubindex=0;
    bool finded=false;
    string decodedstr;
    while(lastsubindex<codedstr.length())
    {
        finded=false;
        for(int i=1;!finded && i<codedstr.length();i++)
        {
            finded=false;

            for(int i=1;!finded && i<codedstr.length();i++)
            {
                string sub=codedstr.substr(lastsubindex,i);/////////////////////
                for(map<char,string>::iterator it =huffcode.begin();it!=huffcode.end();i++)
                {
                    if(sub.compare(it->second)==0)
                    {
                        codedstr+=(it->first);
                        lastsubindex+=i;
                        finded=true;
                        break;
                    }
                }
            }
        }
    }
    return decodedstr;
}

int main()
{
    //明文
    const char *str="aaaabbbcccdddeefffggghh";
    map<char,int> values;//'a'->5	'b'->4
    for(int i=0;i<strlen(str);i++)
    {
        huffcode[str[i]]=="N";//key=str[i] 	value="N"
        values[str[i]]=0;
    }
    for(int i=0;i<strlen(str);i++)
    {
        values[str[i]]=values[str[i]]+1;
    }
    for(map<char,int>::iterator it=values.begin();it!=values.end();it++)
    {
        cout<<it->first<<" occure count= "<<it->second<<endl;
    }
    HuffTree tree=BuildHuffTree(values);

    char route[100]={0};
    int n=0;

    getHuffRoute(tree,route,n);

    for(map<char,string>::iterator it=huffcode.begin();it!=huffcode.end();it++)
    {
        cout<<it->first<<":"<<it->second.c_str()<<endl;
    }
    cout<<"orginal txt:"<<str<<endl;
    string codedstr=Encoded(string(str));
    cout<<"coded txt："<<codedstr.c_str();
    cout<<endl
        <<"encoded txt:"<<Decoded(codedstr).c_str();

    return 1;
}
