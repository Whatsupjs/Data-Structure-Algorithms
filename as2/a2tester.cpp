#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

using namespace std;

int main()
{
	BST<int> tree;
	int ch;
	int data;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Display Tree " << endl;
		cout << " 6. Print Tree Depth " << endl;
		cout << " 7. Print Maximum Value" << endl;
		cout << " 8. Remove a value " << endl;
		cout << " 9. Find value " << endl;
		cout << " 10. Exit " << endl;
		cout << " Enter your option : ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << " Enter a positive Number to be inserted : ";
			cin >> data;
			if (data < 0) {
				cout << "You entered a negative Number, try again..." << endl;
			}
			cout << "Value " << data << (tree.insertData(data) ? " inserted." : " not inserted.") << endl;
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			tree.printTreeInorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			tree.printTreePreorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			tree.printTreePostorder();
			break;
		case 5: cout << endl;
			cout << " Display Tree " << endl;
			cout << " --------------------" << endl;
			//tree.displayTree();
			tree.displayTree();
			break;
		case 6: cout << endl;
			cout << " Print Tree Depth " << endl;
			cout << " --------------------" << endl;
			cout << "Depth of the tree: " << tree.treeDepth() << endl;
			break;
		case 7: cout << endl;
			cout << " Print Maximum Value " << endl;
			cout << " --------------------" << endl;
			cout << tree.maxTreeValue() << endl;
			break;
		case 8: cout << " Enter a positive value to be deleted : ";
			cin >> data;
			cout << "Value " << data << (tree.removeData(data) ? " deleted." : " does not exist.") << endl;
			break;
		case 9: cout << " Enter a positive number to be found : ";
			cin >> data;
			if (data < 0)
				cout << "You entered a negative Number, try again..." << endl;
			else
				cout << "Value " << data << (tree.exists(data) ? " exists." : " does not exist.") << endl;
			break;
		case 10:
			return 0;

		}
	}
}