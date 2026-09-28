#include <iostream>
using namespace std;
const int MAX = 5; // maximum size of circular queue
int cq[MAX];
int front = -1, rear = -1;
void enqueue(int x){
	//case 1: que is full
	if((front == 0 && rear == MAX-1) || (front == rear + 1)){
		cout<<"Queue overflow! cannot insert "<<x<<endl;
		return;
	}
	//case 2: que is empty
	if(front == -1){
		front = 0;
		rear = 0;
		cq[rear] = x;
	}
	// case 3: wrap around ( circular movement)
	else if(rear == MAX -1 && front != 0){
		rear = 0;
		cq[rear] = x;
	}
	//case 4: Normal case
	else{
		rear = rear + 1;
		cq[rear] = x;
	}
	cout<<x<<" inserted into circular queue."<<endl;
	
}
void display(){
	if(front == -1){
		cout<<"queue is empty, nothing to show"<<endl;
		return;
	}
	else if(rear >= front){
		for(int i = front; i<=rear; i++){
			cout<<cq[i]<< " ";
		}
	}else{
		for(int i=front; i<MAX; i++){
			cout<<cq[i]<<" ";
		}
		for(int i=0; i<= rear; i++){
			cout<<cq[i]<<" ";
		}
	}
	cout<<endl;
}

void dequeue(){
	if(front == -1|| rear == -1){
		cout<<"Queue underflow, cannot delete from empty"<<endl;
		return;
	}
	int deleted = cq[front];
	
	if(front == rear){
		front = -1; rear = -1;
	}else if(front == MAX-1){
		front = 0;
	}else{
		front++;
	}
	cout<<deleted<<" is deleted successfully from the circular queue"<<endl;
}

int main(){
	cout<<"front: "<<front<<" rear: "<<rear<<endl;
	enqueue(10); cout<<"front: "<<front<<" rear: "<<rear<<endl;
	enqueue(20);
	enqueue(30);cout<<"front: "<<front<<" rear: "<<rear<<endl;
	enqueue(40);
	enqueue(50);cout<<"front: "<<front<<" rear: "<<rear<<endl;
	
	display();cout<<"front: "<<front<<" rear: "<<rear<<endl;
	
	enqueue(60);cout<<"front: "<<front<<" rear: "<<rear<<endl;
	dequeue();
	dequeue();cout<<"front: "<<front<<" rear: "<<rear<<endl;
	display();
	dequeue();
	dequeue();
	dequeue();cout<<"front: "<<front<<" rear: "<<rear<<endl;
	display();cout<<"front: "<<front<<" rear: "<<rear<<endl;
	dequeue();cout<<"front: "<<front<<" rear: "<<rear<<endl;
	
	return 0;
}
