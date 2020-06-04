class MyCircularQueue {
public:
    int *ar;
    int ms,cs,f,r;
    MyCircularQueue(int k) {
        ms=k;
        sr = new int[ms];
        cs=0;
        f=0;
        r=ms-1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){return false;}
        r=(r+1)%ms;
        ar[r]=value;
        cs++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){return false;}
        f=(f+1)%ms;
        cs--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){return -1;}
        return ar[f];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){return -1;}
        return ar[r];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cs==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ms==cs;
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