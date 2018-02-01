 ///
 /// @file    String.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-01 15:38:00
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class String
{ //23�����ģʽ֮����ģʽ
        class charProxy;
        public:
                String():_pstr(new char[2])
                {
                        cout<<"String()"<<endl;
                        initRefcount();
                }
                String(const char *);
                String(const String&);
                String& operator=(const String&);
                ~String()
                {
                        cout<<"~String()"<<endl;
                        decreaseRefcount();
                        if(0==useCount())
                        {
                                delete []_pstr;
                        }
                }
                int useCount()
                {
                        return _pstr[strlen(_pstr)+1];
                }
                charProxy operator[](int index); //����д����������Ҫ����һ����ʱ����Ͳ�����һ��������
                // char& operator[](int idx)const;  //���ֶ������������const�ؼ��֣���Ȼ��ǰ�溯����������
        private:
                char* _pstr;
                void initRefcount()
                {
                        _pstr[strlen(_pstr)+1] = 1;
                }
                void increaseRefcount()
                {
                        ++_pstr[strlen(_pstr)+1];
                }
                void decreaseRefcount()
                {
                        --_pstr[strlen(_pstr)+1];
                }
                class charProxy
                {
                        public:  //��Щ����һ��Ҫ�ǹ���
                                charProxy(String& str,int index):_str(str),_index(index)
                                {
                                        cout<<"charProxy(String&,int)"<<endl;
                                }
                                char& operator=(char ch);         //Ƕ�������棬Ҳ���ܷ��ض�������;��ΪǶ�����������ʱ��
                                operator char()
                                { //����ת����������Charproxyת��char
                                        cout<<"operator char()"<<endl;
                                        return _str._pstr[_index];
                                }
                        private:
                                String& _str;
                                int _index;
                };
                friend ostream& operator<<(ostream&,const String&);
                friend istream& operator>>(istream&,String&);
};
#if 0
//operator[]()�������ֶ���������д����
char & String::operator[](int idx)const       //�������ֶ�д����������
{
        cout<<"operator [](int)const"<<endl;
        return _pstr[idx];
}
#endif
String::String(const char* tmp)
{
        cout<<"String(const char*)"<<endl;
        _pstr = new char[strlen(tmp)+2];
        strcpy(_pstr,tmp);
        initRefcount();  //���ü�������Ϊ1
}
String::String(const String& lhs)
{
        cout<<"String(const String&)"<<endl;
        _pstr = lhs._pstr;
        increaseRefcount();
}
String& String::operator=(const String& lhs)
{
        cout<<"String& operator=(const String&)"<<endl;
        decreaseRefcount();
        if(0==useCount())
        {
                delete []_pstr;
        }
        _pstr = lhs._pstr; // ǳ����
        increaseRefcount();
        return *this; 
}
ostream& operator<<(ostream& os,const String& rhs)
{
        cout<<"ostream& operator<<(ostream& os,const String&)"<<endl;
        os<<rhs._pstr<<endl;
        return os;
}
istream& operator>>(istream& is,String& s)
{
        cout<<"istream& operator>>(istream&,String&)"<<endl;
        is>>s._pstr;
        return is;
}
String::charProxy String::operator[](int index)
{
        cout<<"charProxy operator[](int)"<<endl;
        return charProxy(*this,index);     //������ʱǶ�������
}
char& String::charProxy::operator=(char ch)
{
        cout<<"char& operator=(char)"<<endl;
        if(_index>=0&&_index<strlen(_str._pstr))
        {
                if(1==_str.useCount())  //������û�й����ڴ�ʱ
                {
                        _str._pstr[_index] = ch;  //�޸�
                        return _str._pstr[_index];
                }
                else
                {
                        _str.decreaseRefcount();  //�й����ڴ�
                        char* _strtmp = new char[strlen(_str._pstr)+2];
                        strcpy(_strtmp,_str._pstr);
                        _str = _strtmp;  //��������˹��캯���Ϳ������캯��,������֮�������������
                        _str[_index] = ch;  //�����ٴε���[]���غ���,�����޸�
                        _str.initRefcount();
                        return _str._pstr[_index];
                }
        }
}
int main()
{
        String s1("hello,world");
        String s2(s1);
        cout<<"��������"<<s1[1]<<endl;
        cout<<s1.useCount()<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"д������"<<endl;
        s1[1] = 'm';
        cout<<"--------------------------"<<endl;
        cout<<s1[1]<<endl;
        cout<<s1.useCount()<<endl;
        return 0;
}
//String(const char*)
//String(const String&)
//charProxy operator[](int)
//charProxy(String&,int)
//operator char()
//��������e
//2
//--------------------------
//д������
//charProxy operator[](int)
//charProxy(String&,int)
//char& operator=(char)
//String(const char*)
//String& operator=(const String&)
//~String()
//charProxy operator[](int)
//charProxy(String&,int)
//char& operator=(char)
//--------------------------
//charProxy operator[](int)
//charProxy(String&,int)
//operator char()
//m
//1
//~String()
//~String()
