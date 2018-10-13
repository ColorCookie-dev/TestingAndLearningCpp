#include <iostream>

struct Vec2 {
public:
    int x;
    int y;

    Vec2() {
        x = 0;
        y = 0;
    }
    Vec2(int a, int b) {
        x = a;
        y = b;
    }
};

class Player {
    
private:
    int speed = 5;
    Vec2 vec;

public:
    Player(Vec2 v, int sspeed) {
        vec.x = v.x; vec.y = v.y;
        std::cout << vec.x << std::endl;
        std::cout << vec.y << std::endl;
        speed = sspeed;
    }

    void move(Vec2 v) {
        vec.x += v.x * speed;
        vec.y += v.y * speed;
    } 

    // Destructor
    ~Player() {
        std::cout << "Destructor Called\n";
    }
};

int main() {
    // making the player object
    Player player(Vec2(5, 4), 5);

    // moving the player
    player.move(Vec2(5, 4));

    // std::cout << v.x << std::endl;
    // std::cout << v.y << std::endl;

}
