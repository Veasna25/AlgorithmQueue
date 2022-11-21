#include <iostream>
using namespace std;

struct Customer
{
    string sex;
    int tel;
    Customer *next;
};

struct MyQueue
{
    int n;
    Customer *myFront, *myRear;
};

MyQueue *createEmptyQueue()
{
    MyQueue *mq;
    mq = new MyQueue();
    mq->n = 0;
    mq->myFront = NULL;
    mq->myRear = NULL;

    return mq;
}

void enqueue(MyQueue *q, string newSex, int newTel) // insert end
{
    Customer *e;
    e = new Customer;
    e->sex = newSex;
    e->tel = newTel;
    e->next = NULL;
    if (q->n == 0)
    {

        q->myFront = e;
        q->myRear = e;
    }
    else
    {
        q->myRear->next = e;
        q->myRear = e;
    }

    q->n = q->n + 1;
}

void dequeue(MyQueue *q) // delete begin
{
    Customer *e;
    if (q->n == 0)
    {
        cout << "Can not dequeue. Data underflow!\n";
    }
    else
    {
        e = q->myFront;
        q->myFront = q->myFront->next;

        delete e;
    }
    q->n = q->n - 1;
}

void displayQueue(MyQueue *q)
{
    Customer *tmp;

    tmp = q->myFront;
    cout << "No\tDescription\n";
    while (tmp != NULL)
    {
        cout << tmp->no << "\t" << tmp->description << "\n";
        tmp = tmp->next;
    }
    cout << endl;
}

main()
{
    MyQueue *q1;
    q1 = createEmptyQueue();

    while (true)
    {
        int choice;
        cout << "Please choose one of the options below: \n";
        cout << "\t1. Add tasks\n";
        cout << "\t2. Display tasks\n";
        cout << "\t3. Select task\n";
        cout << "\t4. Exit\n";
        cin >> choice;
        if (choice == 1)
        {

            cout << "Please enter the task No and Description(enter -1 to stop): \n";
            while (true)
            {
                int no;
                string description;
                cout << "No: \n";
                cin >> no;
                if (no != -1)
                {
                    cout << "Description: \n";
                    cin >> description;
                    enqueue(q1, no, description);
                }
                else
                {
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            if (q1->n != 0)
            {
                cout << "The tasks are: \n";
                displayQueue(q1);
            }
            else
            {
                cout << "Woohoo! You completed all the tasks!\n";
            }
        }
        else if (choice == 3)
        {
            Task *tmp;
            string choice1;
            if (q1->n != 0)
            {
                tmp = q1->myFront;
                cout << "No\tDescription\n";
                cout << tmp->no << "\t" << tmp->description << "\n";
                cout << "Do you want to perform a task in your queue now?(Y/N)\n";
                cin >> choice1;
                if (choice1 == "Y")
                {
                    dequeue(q1);
                }
                else if (choice1 != "Y" || choice1 != "N")
                {
                    cout << "Please choose Y or N\n";
                }
            }
            else
            {
                cout << "Woohoo! You completed all the tasks!\n";
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Please choose one of the choices above!\n";
        }
    }
}
