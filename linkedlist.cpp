#include "linkedlist.h"
vectors::vectors()
{
	this->x = 0;
	this->y = 0;
}
vectors::vectors(int x, int y)
{
	this->x = x;
	this->y = y;
}
int vectors::getx() const
{
	return this->x;
}
int vectors::gety()const
{
	return this->y;
}
bool vectors::operator==(const vectors & that)
{
	
	if (this->x==that.x  && this->y == that.y)
	{
		return true;
	}
	return false;
}
bool operator<(const vectors& left, const vectors& right)
{
	if (left.x < right.x && left.y < right.y)
	{
		return true;
	}
	return false;
	
}
void vectors::print()
{
	cout << "value of x: " << this->getx() << endl << "value of y: " << this->y << endl;
	return ;
}
ostream& operator<<( ostream& strn, const vectors& that)
{
	
	strn<<"value of x: "<< that.getx()<<endl << "value of y: " <<that.gety()<<endl;
	return strn;
}
void linkedlist::appendlist(const vectors& that)
{
	vectors* creatnode = new vectors{ that };
	creatnode->next = nullptr;
	if (!head)
	{
		head = creatnode;
	}
	else
	{
		vectors* traverse = head;
		while (traverse->next)
		{
			traverse = traverse->next;
		}
		traverse->next = creatnode;
	}

}
void linkedlist::printlist()
{
	vectors* traverse = head;
	while (traverse)
	{
		traverse->print();
		traverse=traverse->next;
	}
}
void linkedlist::deletelist(const vectors& that)
{
	if (!this->head)
	{
		return;
	}
	else
	{
		vectors* nextnode = head,
			*previousnode = NULL;
		while (nextnode != NULL &&  !(vectors {nextnode->getx(),nextnode->gety()}==that))
		{
			previousnode = nextnode;
			nextnode=nextnode->next;
		}
		if (!previousnode)
		{
			head = nextnode->next;
			delete nextnode;
		}
		else if (nextnode)
		{
			previousnode->next=nextnode->next;
			delete nextnode;
		}
		else
		{
			cout << "no value found with this input " << that;
		}
	}
}
void linkedlist::insertlist(const vectors& that)
{
	vectors* creatnode = new vectors{ that };
	creatnode->next = NULL;
	if (!this->head)
	{
		head = creatnode;
	}
	else
	{
		vectors* nextnode=head,
			*previousnode = NULL;
		while (nextnode!=NULL && nextnode->getx()<that.getx() && nextnode->gety()< that.gety())
		{
			previousnode = nextnode;
			nextnode = nextnode->next;
		}
		if (!previousnode)
		{
			head = creatnode;
			creatnode->next = nextnode;
		}
		else
		{
			previousnode->next = creatnode;
			creatnode->next = nextnode;
		}
	}

}
