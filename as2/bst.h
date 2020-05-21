#include <iostream> 
#include <iomanip> 
#include <math.h>  
using namespace std;
/* 
node can only have 2 children 
all values in left subtree must  be less than parent node , right subtree must be greater than parent node 

-- when removing child node with child, set parent of child node to root and remove parent node. 
*/
template <typename T>
class BST {

	struct Node {
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data = T{}, Node* left = nullptr, Node* right = nullptr) {
			data_ = data;
			left_ = left;
			right_ = right;
		}
	};

	Node* root_;

	void treeLevel(Node* node, int level, int l, int depth, int low, int high, Node* tree) {

		if (node == nullptr)
			return;
		else if (level == 0) {
			
			tree[(high + low) / 2].data_ = node->data_;
			tree[(high + low) / 2].left_ = node->left_;
			tree[(high + low) / 2].right_ = node->right_;
		}
		else {
			treeLevel(node->left_, level - 1, l, depth, low, (high + low) / 2, tree);
			treeLevel(node->right_, level - 1, l, depth, ((high + low) / 2) + 1, high, tree);

		}
	}



	int maxDepth(Node* node) {

		int depth = 0;
		int leftDepth = 0;
		int rightDepth = 0;

		if (node != nullptr) {

			leftDepth = maxDepth(node->left_);
			rightDepth = maxDepth(node->right_);

			depth = (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;

		}

		return depth;
	}
	
	/* recursive function implementation below :  */

	bool insert(const T& data, Node*& subtree){
        
		bool rc = false;

        if(subtree==nullptr){
            //if tree is empty, make subtree point to the new node
            subtree=new Node(data);
			rc = true;
        }
        else if (data < subtree->data_){
            //if data is smaller than data in subtree's root
            //insert it to the left.
            rc = insert(data,subtree->left_);
        }
        else{
            //otherwise its bigger so we insert it into the right subtree
            rc = insert(data,subtree->right_);
        }

		return rc;
    }

	bool search(const T& data, const Node* subtree) const{
        
		bool rc=false;

        //if it tree is empty, the if is skipped and we return false
        if(subtree != nullptr){
            if(data == subtree->data_){
                
                rc=true;
            }
            else if(data < subtree->data_){
                //data is smaller than that stored in root.
                rc=search(data,subtree->left_);
            }
            else{
                //otherwise its bigger
                rc=search(data,subtree->right_);
            }
            
        }
        return rc;
        
    }

	bool remove(const T& data, Node*& subtree) {
		
		bool rc = false;
		
		//find if data exists in tree
		if (exists(data)) {
			//if value is less than curr node value, traverse left
			if (data < subtree->data_) {
				rc = remove(data, subtree->left_);
			}
			//if value is greater than curr node value, traverse right 
			else if (data > subtree->data_) {
				rc = remove(data, subtree->right_);
			}
			else {
				//if there is no child 
				if (subtree->left_ == nullptr && subtree->right_ == nullptr) {
					delete subtree;
					subtree = nullptr;

					rc = true;
				}
				//if there is no left child
				else if (subtree->left_ == nullptr) {
					Node* rm = subtree;
					subtree = subtree->right_;
					
					delete rm;
					rm = nullptr;
					
					rc = true;
				}
				//if there is no right child
				else if (subtree->right_ == nullptr) {
					Node* rm = subtree;
					subtree = subtree->left_;
					
					delete rm;
					rm = nullptr;
					
					rc = true;
				}
				//if there is 2 child
				
				else {

					//set successor and parent of successor
					Node* psucc = subtree;
					Node* succ = subtree->right_;
					
					//if successor only has right child 
					if (succ->left_ == nullptr) {
						subtree->data_ = succ->data_;
						subtree->right_ = succ->right_;

						delete succ;
						succ = nullptr;

						rc = true;
												
					}

					//find the lowest value of successor in the binary tree. 
					else {
						while (succ->left_ != nullptr) {
							psucc = succ;
							succ = succ->left_;
						}

						subtree->data_ = succ->data_;

						psucc->left_ = succ->right_;

						delete succ;
						succ = nullptr;

						rc = true;
					}
				}
			}
		}
		return rc;
	}

	void inOrderPrint(const Node* subtree) const {
		
		if (subtree != nullptr) {

			//values in left_ are smaller, we need to print them all first
			inOrderPrint(subtree->left_);

			//print value in current node
			std::cout << subtree->data_ << " - ";

			//values in right_ are bigger, we need to print them all after we
			//print current node
			inOrderPrint(subtree->right_);
		}
	}

	void preOrderPrint(const Node* subtree) const {
		
		if (subtree != nullptr) {

			//print value in current node
			std::cout << subtree->data_ << " - ";

			//print left subtree
			preOrderPrint(subtree->left_);

			//print right subtree
			preOrderPrint(subtree->right_);
		}
	}

	void postOrderPrint(const Node* subtree) const {
		
		if (subtree != nullptr) {

			//print left subtree
			postOrderPrint(subtree->left_);

			//print right subtree
			postOrderPrint(subtree->right_);

			//print value in current node
			std::cout << subtree->data_ << " - ";
		}
	}

	int findMax(Node* subtree) {
		int max = subtree->data_;

		if (subtree->right_ != nullptr) {
			max = findMax(subtree->right_);
		}

		return max;
	}

	
public:
	//create empty BST
	BST() {
		root_ = nullptr;
	}

	bool isEmpty() {
		//implement this function
		if (root_ == nullptr)
			return true;
			
		return false;
	}

	bool insertData(const T& value) {
		//implement this function

		return insert(value, root_);
		
	}


	bool exists(const T value) {

		//implement this function
		return search(value, root_);

	};


	//removes a node with value from tree
	bool removeData(const T& value) {

		//implement this function
		return remove(value, root_);

	}

	void printTreeInorder() const {
		//implement this function
		inOrderPrint(root_);
		
		std::cout << std::endl;
	}


	void printTreePreorder() const {
		//implement this function
		preOrderPrint(root_);

		std::cout << std::endl;

	}

	void printTreePostorder() const {
		//implement this function

		postOrderPrint(root_);
		
		std::cout << std::endl;

	}

	int treeDepth() {
		//implement this function
		return maxDepth(root_);
	}

	int maxTreeValue() {
		//implement this function
		
		return findMax(root_);

	}

	int numberOfDigits(int num) {
		int digits = 0;
		while (num) {
			num /= 10;
			digits++;
		}

		return digits;

	}

	void displayTree() {

		int maxDpth = maxDepth(root_) + 1;
		const int dim = (int)pow(2, maxDpth) + 1;
		int max, maxData = -1;

		Node* tree = new  Node[dim];

		if (root_ != nullptr) {


			int hIndex = (int)pow(2, maxDpth) - 1;
			int lIndex = 0;

			int valueBefore = 0;
			for (int i = 0; i < maxDpth; i++) {
				for (int i = 0; i < dim; i++) {

					tree[i].data_ = 0;
					tree[i].left_ = nullptr;
					tree[i].right_ = nullptr;
				}

				treeLevel(root_, i, i, maxDpth, 0, pow(2, maxDpth), tree);

				int digits = 0;

				for (int i = 0; i < dim; i++) {

					if (tree[i].data_ != 0) {

						digits = numberOfDigits(tree[i].data_);

						cout << tree[i].data_;
					}
					else {
						if (digits > 1)
							while (digits > 0) {
								digits--;
							}

						else {
							digits = 0;
							cout << " ";
						}
					}
				}

				cout << endl;


				int space = 0;

				digits = 1;

				for (int i = 0; i < dim; i++) {

					if (tree[i].data_ != 0) {

						digits = numberOfDigits(tree[i].data_);

						if (tree[i].left_ != nullptr && tree[i].right_ != nullptr) {
							cout << "/\\";
							digits -= 2;
						}
						else if (tree[i].left_ != nullptr) {
							cout << "/ ";
							digits -= 2;
						}
						else if (tree[i].right_ != nullptr) {
							cout << " \\";
							digits -= 2;
						}
						else {
							cout << "  ";
							digits -= 2;
						}


					}
					else {
						if (digits > 0) {
							if (digits > 1)
								while (digits > 0) {
									digits--;
									cout << " ";
								}

							else {
								digits = 1;
								cout << " ";
							}
						}
						else {
							digits++;
							if (digits == 0)
								digits = 1;

						}
					}
				}


				cout << endl;

			}
		}
		else {
			cout << "Tree is empty" << endl;
		}



	}

	~BST() {};
};


