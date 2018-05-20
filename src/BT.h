#pragma once
#include<stack>
//Custom implementation of a BinaryTree



template<class T>
class BTCustom;

template<class T>
class BTCPre;


template <class T>
class BTNodeCustom
{
private:
	T info;
	BTNodeCustom* left;
	BTNodeCustom* right;

public:
	BTNodeCustom();
	BTNodeCustom(T i);
	BTNodeCustom(T i, T l, T r);
	BTNodeCustom(T i, BTNodeCustom* l, BTNodeCustom* r);
	void setNodeLeft(T i);
	void setNodeRight(T i);
	void setNodeLeft(BTNodeCustom* i);
	void setNodeRight(BTNodeCustom* i);
	T getInfo();

	friend class BTCustom<T>;
	friend class BTCPre<T>;
};

template<class T>
BTNodeCustom<T>::BTNodeCustom()
{
}

template<class T>
T BTNodeCustom<T>::getInfo() {
	return info;
}

template<class T>
BTNodeCustom<T>::BTNodeCustom(T i){
	this->info = i;
}

template<class T>
BTNodeCustom<T>::BTNodeCustom(T i, T l, T r) {
	this->info = i;
	this->left = new BTNodeCustom(l);
	this->right = new BTNodeCustom(r);
}

template<class T>
BTNodeCustom<T>::BTNodeCustom(T i, BTNodeCustom* l, BTNodeCustom* r) {
	this->info = i;
	this->left = l;
	this->right = r;
}

template<class T>
void BTNodeCustom<T>::setNodeLeft(T i){
	this->left->info = i;
}

template<class T>
void BTNodeCustom<T>::setNodeRight(T i) {
	this->right->info = i;
}

template<class T>
void BTNodeCustom<T>::setNodeLeft(BTNodeCustom* i) {
	this->left = i;
}

template<class T>
void BTNodeCustom<T>::setNodeRight(BTNodeCustom* i) {
	this->right = i;
}



template <class T>
class BTCustom
{
public:
	BTCustom(T source);
	BTNodeCustom<T>* getRoot();
private:
	BTNodeCustom<T>* root;
	friend class BTCPre<T>;
	bool isEmpty() const;
};

template<class T>
bool BTCustom<T>::isEmpty() const
{
	return (root == 0) ? true : false;
}


template<class T>
BTCustom<T>::BTCustom(T source)
{
	this->root = new BTNodeCustom<T>(source);
}

template<class T>
BTNodeCustom<T>* BTCustom<T>::getRoot()
{
	return root;
}



template <class T>
class BTCPre {
public:
	BTCPre(const BTCustom<T> &bt);

	void advance();
	T &retrieve() { return itrStack.top()->info; }
	bool isAtEnd() { return itrStack.empty(); }

private:
	stack<BTNodeCustom<T> *> itrStack;

};

template <class T>
BTCPre<T>::BTCPre(const BTCustom<T> &bt)
{
	if (!bt.isEmpty())
		itrStack.push(bt.root);
}

template <class T>
void BTCPre<T>::advance()
{
	BTNodeCustom<T> * actual = itrStack.top();
	BTNodeCustom<T> * seguinte = actual->left;
	if (seguinte)
		itrStack.push(seguinte);
	else {
		while (!itrStack.empty()) {
			actual = itrStack.top();
			itrStack.pop();
			seguinte = actual->right;
			if (seguinte) {
				itrStack.push(seguinte);
				break;
			}
		}
	}
}
