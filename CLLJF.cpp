#include <iostream>
using namespace std;

void JosephusPosition(int m, List CL){
	List<int>::Iterator ite = CL.begin(); 
	int i = 1;
	while (CL.size() != 1){
		
			• i = 1;
		• while (count < m - 1){
			ite++
				i++;
		}
		
		  CL.RemoveNext(ite);
	}
	cout << "Last person is " << *ite;
}


template <class T>
class Node
{
public:
	int data;
	Node<T> *next;

	Node(int d)
	{
		data = d;
		next = nullptr;
	}

};

template <class T>
class List
{
private:
	Node<T> *head;
	Node<T> *tail;
	class Iterator
	{
	private:

		Node<T> *iterator;
	public:

		Iterator(Node<T> *t = NULL)
		{
			iterator = t;
		}

		T & operator*()
		{
			return iterator->data;

		}
		Iterator & operator++()
		{
			if (iterator)
				iterator = iterator->next;
			return (*this);
		}
		bool operator==(const Iterator & l) const
		{
			return iterator == l.iterator;
		}
		bool operator!=(const Iterator & l) const
		{
			return !(iterator == l.iterator);
		}
	};

public:

	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertAtStart(T const element)
	{
		if (head == nullptr)
		{
			Node<T> *n = new Node<T>(element);
			tail = n;
			head = n;
			n->next = head;
			//head->next = tail;
			tail->next = head;
		}
		else
		{
			Node<T> *n = new Node<T>(element);
			n->next = head;
			head->next=tail;
			head = n;
		}
	}
	void insertAtEnd(T const element)
	{
		if (head == nullptr)
		{
			Node<T> *n = new Node<T>(element);
			tail = n;
			head = n;
			n->next = head;
			head->next = tail;
			tail->next = head;
		}
		else
		{
			Node<T> *n = new Node<T>(element);
			tail->next = n;
			tail = n;
			tail->next = head;
		}
	}

	void insertAfter (T const v1,T const v2)
	{
		Node<T>*n = head;
		int bOOL = 0;
		for (; n->next != head&&bOOL == 0; n = n->next)
		{
			if (n->data == v1)
			{
				Node<T>*n2 = new Node<T>(v2);
				n2->next = n->next;
				n->next = n2;
				if (n->next== tail){					
					n2->next = head;
				}
				bOOL = 1;
			}
		}
	}

    void DeleteAtStart()
	{

		if (head->next == tail)
		{
			Node<T>*n = head;
			head = tail;
			delete n;
		}
		else if (head = nullptr)
			;
		else
		{
			Node<T>*n = head;
			head = head->next;
			delete n;
		}
	}

	void DeleteAtEnd()
	{
		if (head->next == tail)
		{
			Node<T>*n = tail;
			tail = head;
			head = tail;
			delete n;
		}
		else if (tail = nullptr)
			;
		else
		{
			Node<T> *n = head;
			for (; n != tail; n = n->next)
				;
			delete tail;
			tail = n;
		}
	}

	void print()
	{
		//Node<T> *n=head;
		///*n = head;
		//for (; n!= tail; n = n->next)
		//	cout << n->data << "->";
		//cout << endl;*/
		//do{
		//	cout << n->data << " ";
		//	n=n->next;
		//} while (n != tail->next);
		//cout << endl;
		Iterator T(*head);
		do{
			cout << *T << " ";
			T++;
		} while (T!=tail)

	}

	bool isEmpty(){
		if (!head)
			return 0;
	}
	Iterator begin(){
		Iterator I(head);
		return I;
	}
	Iterator End(){
		Iterator I(tail);
		return I;
	}


};

int main()
{

	List<int> L1;
	L1.insertAtStart(7);
	L1.insertAtStart(9);
	L1.insertAtEnd(10);
	L1.insertAtEnd(2);
	L1.insertAfter(2, 1);
	L1.print();


	system("pause");
	return 0;
}