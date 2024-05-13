#ifndef MY_CANTEEN_H
#define MY_CANTEEN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
// 菜品类
#include <iostream>

#include<memory>
class Dish
{
private:
    std::string name;
    double price;
    std::string taste;

public:
    Dish(std::string dish_name, double dish_price, std::string dish_taste)
        : name(dish_name), price(dish_price), taste(dish_taste) {}

    std::string &getName() { return name; }
    double getPrice() { return price; }
    std::string &getTaste() { return taste; }

    void setDish(std::string dish_name, double dish_price, std::string dish_taste)
    {
        name = dish_name;
        price = dish_price;
        taste = dish_taste;
    }
};

// 窗口类
class Window
{
private:
    std::string name;
    

public:
    std::vector<Dish> dishes;
    Window(std::string window_name) : name(window_name) {}

    std::string &getName() { return name; }
    void addDish(Dish &dish) { dishes.push_back(dish); }
    void setWindow(std::string window_name){name=window_name;}
    std::vector<Dish> &getDishes() { return dishes; }
};

// 饭堂类
class Canteen
{
private:
    std::string name;
    

public:
    std::vector<Window> windows;
    Canteen(std::string canteen_name) : name(canteen_name) {}
    Canteen(){};
    std::string &getName() { return name; }
    void addWindow(Window &window) { windows.push_back(window); }
    void setCanteen(const std::string &canteen_name)
    {name=canteen_name;
    }
    std::vector<Window> &getWindows() { return windows; }
};



#endif