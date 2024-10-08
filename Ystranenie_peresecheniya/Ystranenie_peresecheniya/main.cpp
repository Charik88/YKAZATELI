//
//  main.cpp
//  Ystranenie_peresecheniya
//
//  Created by Anastasiya Charykova on 08.10.2024.
//

/* Задача 2. Устранение пересечения
Описание

Исправьте в коде ошибку, из-за которой не освобождаются ресурсы. Сообщение destructor called должно быть выведено 2 раза.

#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::shared_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <memory>

// Используя std::weak_ptr вместо std::shared_ptr для члена parent, мы разрываем циклическую ссылку. std::weak_ptr - это слабая ссылка, которая не увеличивает счетчик ссылок, позволяя ресурсам быть освобождены, когда общий указатель выходит из области видимости.

class node{
public:
int m_value; // значение узла
std::weak_ptr<node> parent; // используем std::weak_ptr для хранения указателя на родительский узел
node(int value) : m_value{ value }{}; // конструктор класса node
~node(){ // деструктоор
std::cout << "destructor called\n";} // вывод
};

int main(){
    {
        auto node1 = std::make_shared<node>(1); // создаем узел 1
        auto node2 = std::make_shared<node>(2); // сооздаем узел 2
        node1->parent = node2; // устанавливаем указатель на узел 2 как родительский узел
        node2->parent = node1; // устанавливаем указатель на узел 1 как родительский узел
    }
    return 0;
}


