#include <iostream>
#define MAX 5 // Maksimal ukuran antrian

using namespace std;

class Queue {
private:
    int items[MAX], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Cek apakah antrian kosong
    bool isEmpty() {
        return front == -1;
    }

    // Cek apakah antrian penuh
    bool isFull() {
        return rear == MAX - 1;
    }

    // Menambahkan elemen ke dalam antrian
    void enqueue(int element) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    // Menghapus elemen dari antrian
    int dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return -1;
        } else {
            int elem = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            cout << "Deleted " << elem << endl;
            return elem;
        }
    }

    // Menampilkan elemen antrian
    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Antrian: ";
            for (int i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    
    q.dequeue();

    q.display();

    return 0;
}