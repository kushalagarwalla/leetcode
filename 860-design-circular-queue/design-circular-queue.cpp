class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularQueue(int k) {
        size=k;
        arr=new int [size];
        rear=-1;
        front=-1;
    }
    
    bool enQueue(int value) {
        //check if queue is full
        if((front==0 && rear==size-1) || (rear==(front-1)))
        {
            return false;
        }
        //when queue is empty
        else if(front==-1)
        {
            front=rear=0;
        }
        //when rear is at end of array and start of array is empty
        else if(rear==size-1 && front!=0)
        {
            rear=0; //to maintain cyclic nature
        }
        //for normal case
        else
        {
           rear++;
        }
        //push inside the queue
        arr[rear]=value;
        return true;
    }
    
    bool deQueue() {
        //check if queue is empty
        if(front==-1)
            return false;
        //when queue has only one element
        if(front==rear)
            front=rear=-1;
        //when front has reached end of array
        else if(front==size-1)
            front=0; //to maintain cyclic nature
        else
            front++;
        return true;
    }
    
    int Front() {
        if(front==-1)   //check if queue is empty
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear==-1)    //check if queue is empty
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((front==0 && rear==size-1) || (rear==(front-1)))
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */