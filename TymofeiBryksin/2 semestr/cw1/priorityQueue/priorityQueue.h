
#pragma once
const int minSize = 10;
const int INF = 10e7;

/// Priority Queue
template <class T>
class PriorityQueue {
public:

    class EmptyQueueException{};

    PriorityQueue();
    ~PriorityQueue();
    ///добавление элемента в очередь
    void enqueue(T value, int priority);

    /// извлечение элемента из очереди
    T dequeue();

    int length() {
        return size;
    }

private:
    struct PriorityQueueElement {
        int priority;
        T value;
    };

    int size;
    int maxSize;
    PriorityQueueElement *elements;
    ///восстановление свойств кучи
    void heapify(int root);

    ///изменене значения элемента
    void increaseKey(int i, PriorityQueueElement key);

    void swap(PriorityQueueElement &a, PriorityQueueElement &b){
        PriorityQueueElement c = a;
        a = b;
        b = c;
    }

};



template <class T>
PriorityQueue<T>::PriorityQueue(): size(0), maxSize(minSize)
{
    elements = new PriorityQueueElement[maxSize];
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] elements;
}

template <class T>
void PriorityQueue<T>::enqueue(T value, int priority)
{
    PriorityQueueElement newElem;
    newElem.value = value;
    newElem.priority = priority;
    size++;
    if (size >= maxSize) {
        maxSize *= 2;
        PriorityQueueElement *temp = new PriorityQueueElement[maxSize];
        for (int i = 0; i < size; i++)
            temp[i] = elements[i];
        delete[] elements;
        elements = temp;
    }

    elements[size - 1].value = value;
    elements[size - 1].priority = -INF;

    increaseKey(size - 1, newElem);


}

template <class T>
T PriorityQueue<T>::dequeue()
{
    if (size < 0)
    {
        std::cout << "!";
        throw EmptyQueueException();
    }
    PriorityQueueElement max = elements[0];
    elements[0] = elements[size - 1];
    size--;
    if (size <= maxSize / 2) {
        maxSize /= 2;
        PriorityQueueElement *temp = new PriorityQueueElement[maxSize];
        for (int i = 0; i < size; i++)
            temp[i] = elements[i];
        delete[] elements;
        elements = temp;
    }
    heapify(0);
    return max.value;

}

template <class T>
void PriorityQueue<T>::heapify(int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest  = root;

    if (left <= size && elements[left].priority > elements[largest].priority)
        root = left;

    if (right <= size && elements[right].priority > elements[largest].priority)
        root = right;

    if (largest != root)
    {
        swap(elements[root], elements[largest]);
        heapify(largest);
    }
}

template <class T>
void PriorityQueue<T>::increaseKey(int i, PriorityQueueElement key)
{
    elements[i] = key;
    while (i >= 0 && elements[i/2].priority < elements[i].priority)
    {
        swap(elements[i], elements[i/2]);
        i = i/2;
    }
}
