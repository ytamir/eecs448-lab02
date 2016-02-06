/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
        return m_size;//returns m_size
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

        temp = m_front; // set temp equlals to old node
        while (temp != nullptr)
                {
            if (temp->getValue() == value)// if temp's value is equal to the value parametar then the value is in linked list
                        {
                                return true;
                        }
                        temp = temp->getNext();

                }
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
    if (isEmpty())// if it is empty
        {
                return false;

        }
    else if (m_size == 1) // if size is one
        {
        removeFront();// remove only one
        m_size--; // lower size
                return true;
        }
    else// if 2 or more are in list
        {
        Node<T>* temp1 = m_front;// create temp node
        Node<T>* temp2 = m_front;// create another temp node
        while (temp1->getNext() != nullptr)// loop through temp1 node
                {
            temp1 = temp1->getNext(); // change values of temp1
                }
        while (temp2->getNext() != temp1)//loop through temp2 node until it doesnt equal temp1
                {
            temp2 = temp2->getNext();//change values of temp2
                }

        delete temp1;// delete temp one node
                temp2->setNext(nullptr);
        m_size--;//lower the size
                return true;
        }

}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
