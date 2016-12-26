#include "Composite.h"

int main(void) {
	IComponent* p_root = new CComposite("root");
	IComponent* p_subroot = new CComposite("sub_root");

	p_root->add(new CLeaf("leaf1"));
	p_root->add(new CLeaf("leaf2"));
	p_root->add(new CLeaf("leaf3"));
	p_subroot->add(new CLeaf("leaf4"));
	p_subroot->add(new CLeaf("leaf5"));
	p_subroot->add(new CLeaf("leaf6"));
	p_root->add(p_subroot);

	// 调用所有对象的功能
	p_root->operation();

	delete p_root;
}