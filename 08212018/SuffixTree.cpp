#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class SuffixTreeNode  //��׺���Ľ����
{
public:
	SuffixTreeNode() { }
	void insertString(string s,int idx);  //����׺���в���һ���ַ���
	vector<int> getIndex(string s);  //��ȡ�ַ�����Դ�ַ����г��ֵ�λ��
	~SuffixTreeNode(); 
private:
	map<char,SuffixTreeNode*> subTreeNode;  //���������Ե������һ���ַ��Լ�ָ��ý���ָ��
	vector<int> index;  //������ַ�����S�е���ʼλ��
	//�����ж���Ӵ������ߴ�һ�������������ҵ������ͬ�Ӵ�
};
void SuffixTreeNode::insertString(string s,int idx)
{//������׺��
	index.push_back(idx);  //�ַ�������ʼλ�ñ���.�ŵ������ԭ�򣬴�root��㿪ʼ���ȵ��ֺ�һ���ַ���ʱ��Str�ѱ��ľ���Ҳ����mapû��Ԫ���ˣ�����������indexȴҪ����
	if(s.length()>0)  //����ַ�����û�кľ����ݹ�������¹����׺��
	{
		char value = s[0];  //���value��ֵ�����ַ����ĵ�һ���ַ�
		//�жϸ��ַ��ڲ��ڸý���map�У��ھͼ������²�����һ���ַ������ھ��½�һ����㲢�ڵ�ǰ����map�б��������Ϣ
		SuffixTreeNode* next = NULL;
		if(subTreeNode.find(value)!=subTreeNode.end())  //�������д��ڸ��ַ���nextָ��ָ��ý��
		{
			next = subTreeNode.find(value)->second;
		}
		else  //û�и��ַ������½�һ����㣬���ڵ�ǰ����map�б�������ַ�ֵ���Լ�������ַ���ָ��
		{
			SuffixTreeNode* node = new SuffixTreeNode;
			subTreeNode.insert(::make_pair(value,node));
			next = node;
		}
		//�ݹ������ַ����е���һ���ַ����Ź����׺��
		string subStr = s.substr(1);
		next->insertString(subStr,idx);  //����Ӵ�����ʼλ����idx���Ժ�һֱ������������
	}
}
vector<int> SuffixTreeNode::getIndex(string s)
{
	//�����ַ�ƥ�䣬��󷵻����һ���ַ���ָ��Ľ���vector
	if(""==s)  //�ɹ�ƥ�䵽��󷵻ظý���index
		return index;
	else
	{
		if(subTreeNode.find(s[0])!=subTreeNode.end())
			return ((subTreeNode.find(s[0]))->second)->getIndex(s.substr(1));  //��������ƥ��
		else 
		{//�Ҳ�����ֱ�ӷ��ؿ�
			return vector<int>(0);
		}
	}
}
SuffixTreeNode::~SuffixTreeNode()
{//�����ͷŶ�̬����Ľ���ڴ�
	for(auto it = subTreeNode.begin();it!=subTreeNode.end();++it)
	{
		delete it->second;  //������һ���ݹ����
		it->second = NULL;
	}
}

class SuffixTree
{
public:
	SuffixTree(string str);  //���ַ�����Դ������ʼ��һ����׺��
	vector<int> getIndex(string str);  //��ȡһ���ַ�����Դ���г��ֵ�λ��
	~SuffixTree();
private:
	SuffixTreeNode* _root;
};

SuffixTree::SuffixTree(string str)
{
	_root = new SuffixTreeNode();
	for(int idx=0;idx!=str.length();++idx)
	{
		string subStr = str.substr(idx);
		_root->insertString(subStr,idx);
	}
}
vector<int> SuffixTree::getIndex(string str)
{
	return _root->getIndex(str);
}
SuffixTree::~SuffixTree()
{
	delete _root;
	_root = NULL;
}
int main(int argc,char** argv)
{
	string testString = "mississippi";
	string arr[4] = {"is","sip","hi","sis"};
	SuffixTree tree(testString);
	for(int idx=0;idx!=4;++idx)
	{
		vector<int> ans = tree.getIndex(arr[idx]);
		cout<<arr[idx]<<" ";
		if(0!=ans.size())
		{
			for(int iidx=0;iidx!=ans.size();++iidx)
			{
				cout<<ans[iidx]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"not find!"<<endl;
		}
	}
	//system("pause");
}
//is 1 4
//sip 6
//hi not find!
//sis 3
//�밴���������. . .
