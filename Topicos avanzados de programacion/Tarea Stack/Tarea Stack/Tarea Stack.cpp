#pragma once

#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
class LStack
{
public:
    LStack() : count(0) {}

    void Push(T value)
    {
        data.push_front(value);
        count++;
    }

    T Pop()
    {
        if (data.empty())
        {
            cout << "Advertencia, intentó sacar más elementos, esta LStack ya está vacía." << endl;
            return {};
        }

        T value = data.front();
        data.pop_front();
        count--;
        return value;
    }

    T Peak()
    {
        if (data.empty())
        {
            cout << "Advertencia, esta LStack ya está vacía. No hay elemento para hacer Peak." << endl;
            return {};
        }

        return data.front();
    }

    int Count()
    {
        return count;
    }

private:
    forward_list<T> data;
    int count;
};


int main()
{
    LStack<int> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "Elemento en la cima (Peak): " << stack.Peak() << endl; // 30
    cout << "Cantidad de elementos: " << stack.Count() << endl;     // 3

    cout << "Pop: " << stack.Pop() << endl;                         // 30
    cout << "Pop: " << stack.Pop() << endl;                         // 20

    cout << "Elemento en la cima ahora: " << stack.Peak() << endl;  // 10
    cout << "Cantidad de elementos: " << stack.Count() << endl;     // 1

    stack.Pop(); // Quita el 10
    stack.Pop(); // Advertencia

    return 0;
}
