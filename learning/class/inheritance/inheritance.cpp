#include <iostream>
#include <string>

class Parent {
public:
    int x, y;

    Parent() {
        x = 0; y = 0;
    }
};

class Child : public Parent {
public:
    Child() {
        x = 1; y = 2;
    }

    int getX() {
        return x;
    }
};

int main() {
    Child C1();
    std::cout << C1.getX() << std::endl;
}
