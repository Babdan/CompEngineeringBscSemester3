// By Bogdan Itsam Dorantes-Nikolaev, COMP201 Lab, Instructor: Mustafa Ersen (November 17th, 2022)

// Import the necessary packages
import java.util.Arrays;

// Array based queue implementation class definition
public class MyQueue<E> {
    // Data fields
    private E[] data;
    public int size;
    private int first;

    // Construct a queue with the default capacity 8
    public MyQueue(int capacity) {
        this.first = -1;
        this.data = (E[]) new Object[capacity];
        this.size = 0;
    }

    // Returns true if the queue is empty and false otherwise.
    public boolean isEmpty() {
        return this.size == 0;
    }
    // Returns the element at the start (head) of the queue without removing it (returns null if the queue is empty).
    public E peek() {
        if (isEmpty()) {
            return null;
        }
        return data[first];
    }
    // Adds the given element e to the end (tail) of the queue and returns true if the queue is not full, returns false otherwise.

    public boolean enqueue(E e) {
        if (size >= data.length) {
            return false;
        }
        if (isEmpty()) {
            first = 0;
        }
        int index = (first + size) % data.length;
        data[index] = e;
        size++;
        return true;
    }
    // Removes and returns the element at the start (head) of the queue (returns null if the queue is empty).
    public E dequeue() {
        if (isEmpty()) {
            return null;
        }
        E result = data[first];
        data[first] = null;
        first = (first + 1) % data.length;
        size--;
        return result;
    }
    // Returns both the queue contents and the internal array contents as a string.
    @Override
    public String toString() {
        E[] temp = (E[]) new Object[size];
        for (int i = 0; i < size; i++) {
            temp[i] = data[(first + i) % data.length];
        }
        return Arrays.toString(temp) + " and Inner Array: " + Arrays.toString(data);
    }
}