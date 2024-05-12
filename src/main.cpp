#include <../include/admin.h>
#include <../include/user.h>

int main()
{

    // 创建管理员对象
    Admin admin;

    // 创建一些菜品、窗口和饭堂
    Dish dish1("宫保鸡丁", 25.0, "微辣");
    Dish dish2("鱼香肉丝", 20.0, "酸甜");
    Window window1("川菜窗口");
    window1.addDish(dish1);
    window1.addDish(dish2);
    Canteen canteen1("食堂一");
    canteen1.addWindow(window1);

    Dish dish3("番茄炒蛋", 15.0, "清淡");
    Window window2("家常菜窗口");
    window2.addDish(dish3);
    Canteen canteen2("食堂二");
    canteen2.addWindow(window2);

    // 将饭堂添加到管理员管理列表
    admin.addCanteen(canteen1);
    admin.addCanteen(canteen2);

    // 创建用户对象
    User user(admin.getCanteens());

    
    // 显示所有饭堂信息
    user.displayCanteens(user.canteens);

    // 显示第一个饭堂的窗口信息
     Canteen firstCanteen = user.canteens[0];
    user.displayWindows(firstCanteen);

    // 显示第一个窗口的菜品信息
    Window firstWindow = user.canteens[0].getWindows()[0];
    user.displayDishes(firstWindow);

    // 根据口味搜索菜品
    user.searchDishesByTaste(user.canteens, "微辣");

    // 根据菜品名称搜索菜品
    user.searchDishesByName(user.canteens, "番茄炒蛋");

    return 0;
}