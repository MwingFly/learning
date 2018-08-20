#include<iostream>
#include<string.h>
using namespace std;
const int branchNum = 26;  //26��Ӣ���ַ�
class Trie_node
{
public:
	Trie_node():isStr(false){ memset(next,NULL,sizeof(next)); }
public:
	bool isStr;  //��¼�˴��Ƿ񹹳�һ����
	Trie_node* next[branchNum];  //ָ�����������ָ��,�����±���൱����ĸ��ֵ
};
class Trie
{
public:
	Trie():_root(new Trie_node())	{}
	void insert(const char* word);
	bool search(const char* word)const;
	void deleteTrie(Trie_node* root);
	Trie_node* getTrie()const{ return _root; }
private:
	Trie_node* _root;
};
void Trie::insert(const char* word)
{
	Trie_node* cur = getTrie();
	while(*word)
	{
		if(cur->next[*word - 'a']==NULL)
		{
			Trie_node* node = new Trie_node();
			cur->next[*word - 'a'] = node;
		}
		cur = cur->next[*word - 'a'];  //ָ����һ��
		++word;
	}
	//������ϣ��ַ������һ�������Ϊtrue����ʾ�����Ѿ���һ��������
	cur->isStr = true;
}
bool Trie::search(const char* word)const
{
	Trie_node* cur = getTrie();
	while(*word&&NULL!=cur)  //���ʻ�ûƥ���꣬��һ���ַ����ڣ��ͽ�������ƥ��
	{
		cur = cur->next[*word - 'a'];
		++word;
	}
	//�ж��ǲ����ҵ�������ַ���
	return (cur!=NULL && cur->isStr);  //ע��������ж�˳�������һ�����㣬�����жϵڶ����������һ���������ֱ�ӷ��أ���һ���������
	// ���cur==NULL,���ж�cur->isStr��Ҫ�δ���
}
void Trie::deleteTrie(Trie_node* root)
{
	if(NULL!=root)
	{
		for(int idx=0;idx!=branchNum;++idx)
		{
			deleteTrie(root->next[idx]);
			delete root;
			root = NULL;
		}
	}
}
int main()
{
	Trie myTrie;
	const char* arr[] = {"mei","hao","hello","world"};
	for(int idx=0;idx!=4;++idx)
	{
		myTrie.insert(arr[idx]);
	}
	cout<<endl;
	for(int idx=0;idx!=4;++idx)
	{
		cout<<myTrie.search(arr[idx])<<" ";
	}
	cout<<endl;
	cout<<myTrie.search("meihao")<<endl;
}
//
//1 1 1 1
//0
//�밴���������. . .
