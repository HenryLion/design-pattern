//组合模式

/*
将对象组合成树形结构以表示“部分-整体”的层次结构。
使得用户对单个对象和组合对象的使用具有一致性 GOF
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

// 组成类接口
class component
{
public:
	virtual void Process () = 0;
};


// 组合类
class composite : public component
{
public:
	composite (string name = "com"):com_name (name) {}
	void addNode (component *node)
	{
		m_coms.push_back (node);
	}
	int get_list_size () { return m_coms.size(); }
	virtual void Process ()
	{
		cout << "composite::Process: " << com_name << endl;
		list<component*>::iterator iter;
		for (iter = m_coms.begin(); iter != m_coms.end(); ++iter)
		{
			(*iter)->Process();
		}
	}
private:
	list<component *> m_coms;
	string com_name; // 组合对象名字
};

// 单个类
class single : public component
{
public:
	single (string name="default leaf"):leaf_name(name) {}
	virtual void Process ()
	{
		cout << "single::Process: " << leaf_name << endl;
	}
private:
	string leaf_name; // 单个对象名字
};

int main (void)
{

	component *leaf1 = new single("leaf1");
	component *leaf2 = new single ("leaf2");
	component *leaf3 = new single ("leaf3");
	component *leaf4 = new single ("leaf4");
	composite *treenode1 = new composite("node1");
	composite *treenode2 = new composite("node2");
	
	composite *root = new composite("root_tree");
	
	treenode1->addNode (leaf1);
	treenode2->addNode (leaf2);
	treenode1->addNode (leaf3);
	treenode1->addNode (leaf4);

	root->addNode(treenode1);
	root->addNode(treenode2);
	cout << root->get_list_size() << endl;
	cout << treenode1->get_list_size() << endl;
	cout << treenode2->get_list_size() << endl;
	
	root->Process(); // 统一的Process接口即可以执行composite类中的组合对象，也可以执行single类中的单个对象。
	return 0;
}