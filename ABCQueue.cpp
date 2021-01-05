#include<iostream> 
using namespace std;
#define size 5

class  ABCQueue
{
public:
	// InitializING front and rear 
	int rear;
	int front;
	int count;

	// Circular Queue 
	int* circular_array;

	ABCQueue()
	{
		front = -1;
		rear = -1;
		count = 0;
	    circular_array = new int[size];
	}

	bool isEmpty() {
		if (front == -1 && rear == -1) {
			return true;
		}
		else
			return false;
	}

	bool isFull() {
		if (count == size)
			return true;
		else
			return false;
	}

	void EnQueue(int value) 
	{
		if (!isFull())
		{
			if (isEmpty())/*if list is empty insert at front*/
			{
				front = 0;
				rear = 0;
				circular_array[rear] = value;
			}
			else if (front != 0 && rear == size - 1) {
				rear = 0;
				circular_array[rear] = value;
			}
			else {
				rear++;
				circular_array[rear] = value;
			}
		}
		else {
			cout << "queue is full\n";
		}
		count++;
	}


	int DeQueue() 
	{
		int value = circular_array[front];
		if (!isEmpty()) 
		{
			circular_array[front] = -1;
			/*if queue has only one element and that is dequeued*/
			if (front == rear) {
				front = -1;
				rear = -1;
				count--;
			}
			/*if element to be dequeued is at last index */
			else if (front == size - 1) {
				front = 0;
				count--;
			}
			else {
				front++;
				count--;
			}
		}
		else {
			cout << "list is empty\n";
		}
		return value;
	}


	void printQueue()
	{
		if (!isEmpty()) {
			if (rear >= front) 
			{
				for (int i = front; i <= rear; i++)
				{
					cout << "queue[ "<<i<<" ] = " <<circular_array[i] <<"\n" ;
					
				}
			}
			else 
			{
				/*prints values from front to last index*/
				for (int i = front; i < size; i++) {
					cout << "queue[ " << i << " ] = " << circular_array[i] << "\n";
					
				}
				/*prints the values that are enqueued at front where elements were previously dequeued*/
				for (int i = 0; i <= rear; i++) {
					cout << "queue[ " << i << " ] = " << circular_array[i] << "\n";
					
				}
			}
		}
		else {
			cout << "queue is empty\n";
		}

	}
	/*void Clear() – release the memory allocated by queue */
	void clear() {
		front = -1;
		rear = -1;
		printQueue();
	}

	/*RegisterPatient(): This method assigns an Id (which is auto-generated) to a patient and register him/her to the system.*/
	void RegisterPatient(string name) {
		if (!isFull())
		{
			if (isEmpty())/*if list is empty insert at front*/
			{
				front = 0;
				rear = 0;
				circular_array[rear] = rear;
				cout << "patient \" "<<name<<" \" !!\n you are registered to waiting room and your  id is " << rear << endl<<endl;
			}
			else if (front != 0 && rear == size - 1) {
				rear = 0;
				circular_array[rear] = rear;
				cout << "patient \" " << name << " \" !! \nyou are registered to waiting room and your  id is " << rear << endl << endl;;
			}
			else {
				rear++;
				circular_array[rear] = rear;
				cout << "patient \" " << name << " \" !! \nyou are registered to waiting room and your  id is " << rear << endl << endl;;
			}
		}
		else {
			cout << "waiting room  is full\n";
		}
		count++;
	}

    /*ServePatient():This method calls a patient to provide hospital service to him/her.*/
	void ServePatient() {
		int value = circular_array[front];
		if (!isEmpty())
		{
			circular_array[front] = -1;
			/*if queue has only one element and that is dequeued*/
			if (front == rear) {
				front = -1;
				rear = -1;
				count--;
			}
			/*if element to be dequeued is at last index */
			else if (front == size - 1) {
				front = 0;
				count--;
			}
			else {
				front++;
				count--;
			}
		}
		else {
			cout << "waiting room  is empty\n";
		}
		cout<<"the patient with id : \" "<<value<<" \" is served and leaves the waiting room\n";
	}

     /*CancelAll():This method cancels all appointments of the patients so that the doctor can go to lunch.*/
	void CancelAll() {
		cout << "cancling all patients from waiting room so that doctor can go to lunch...........\n";
		front = -1;
		rear = -1;
		cout << "\nnow after cancelling all checking the queue for its emptiness\n";
		ShowAllPatient();
	}

     /*CanDoctorGoHome():This method returns true if no one is waiting, otherwise, returns false.*/
	bool CanDoctorGoHome() {
		if (isEmpty())
		{
			cout << "waiting room  is empty so no one is waiting and doctor can go home\n";
			return true;
		}
		else
		{
			cout << "waiting room is not empty so  doctor cannot go home\n";
			return false;
		}
	}

     /*ShowAllPatient():This method shows all ids of the waiting patients in SORTED order. (Hint: use the sorting methods learnt in class using the appropriate data-structure for each task) [Sorted according to their names]*/
	void ShowAllPatient() {
		if (!isEmpty()) {
			if (rear >= front)
			{
				for (int i = front; i <= rear; i++)
				{
					cout << "patient with id : " << i << endl;
				}
			}
			else
			{
				/*prints values from front to last index*/
				for (int i = front; i < size; i++) {
					cout << "patient with id : " << i << endl;
				}
				/*prints the values that are enqueued at front where elements were previously dequeued*/
				for (int i = 0; i <= rear; i++) {
					cout << "patient with id : " << i << endl;
				}
			}
		}
		else {
			cout << "waiting room is empty\n";
		}
	}

};

/***************************************************************************************************
			"HERE GOES OUR MAIN CODE FOR TESTING THE ARRAY BASED STACK FUNCTIONS"
****************************************************************************************************/

int main() {
	/*creating queue object*/
	ABCQueue obj;
	cout << "###############################################################################\n\t\t waiting room management system  \n###############################################################################\n";
	cout << "registering zainab,zahra,maryam,masooma,fatima........\nbecause max_limit  in waiting room is 5\n";
	cout << "\n-----------------------------------------------------------------------------\n";
	obj.RegisterPatient("zainab");
	obj.RegisterPatient("zahra");
	obj.RegisterPatient("maryam");
	obj.RegisterPatient("masooma");
	obj.RegisterPatient("fatima");

	cout << endl;
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl<<"serving patients on first in first out basis \n\n";
	obj.ServePatient();
	obj.ServePatient();
	obj.ServePatient();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "showing all patients in waiting room with their id's\n\n";
	obj.ShowAllPatient();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << "registering ali,urooj,asif into waiting room \n";
	obj.RegisterPatient("ali");
	obj.RegisterPatient("urooj");
	obj.RegisterPatient("asif");
	cout << endl;
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "showing all patients in waiting room with their id's\n\n";
	obj.ShowAllPatient();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << "registering alizah ........\n";
	obj.RegisterPatient("alizah");
	cout<< "as the max_limit for waiting room has reached so another patient cannot be entered\n";
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl<<"can doctor go home \n";
	obj.CanDoctorGoHome();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl<<"cancelling all \n";
	obj.CancelAll();
	cout << "\n-----------------------------------------------------------------------------\n";
	
	/*ABCQueue obj;
	cout << "###############################################################################\n\t\tARRAY BASED CIRCULAR QUEUE \n###############################################################################\n";

	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "EN_QUEUEING ELEMENTS 11,12,13,14 IN QUEUE \n";
	obj.EnQueue(11);
	obj.EnQueue(12);
	obj.EnQueue(13);
	obj.EnQueue(14);
	obj.printQueue();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "(1)DE_QUEUEING FROM THE QUEUE \n";
	obj.DeQueue();
	obj.printQueue();

	cout << endl << "(2)DE_QUEUEING FROM THE QUEUE \n";
	obj.DeQueue();
	obj.printQueue();

	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "EN_QUEUEING ELEMENTS 15,16,17 IN QUEUE \n";
	obj.EnQueue(15);
	obj.EnQueue(16);
	obj.EnQueue(17);
	obj.printQueue();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << endl << "NOW AS SIZE OF ARRAY BASED CIRCULAR QUEUE IS FULL ,SO\nENQUEUEING \" 18 \"IN QUEUE WILL NOT INSERTED IN THE QUEUE\n";
	cout << "EnQueue (18)........\n";
	cout << endl;
	obj.EnQueue(18);
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << "checking by printing the queue\n";
	obj.printQueue();
	cout << "\n-----------------------------------------------------------------------------\n";
	cout << "clearing the queue................ \n";
	obj.clear();*/
}