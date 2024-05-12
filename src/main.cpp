#include <../include/admin.h>
#include <../include/user.h>

// 生成菜单
// void generateMenu(const std::vector<Canteen> &canteens)
// {
//     std::cout << "Menu:" << std::endl;
//     for (const auto &canteen : canteens)
//     {
//         std::cout << "In " << canteen.getName() << ":" << std::endl;
//         for (const auto &window : canteen.getWindows())
//         {
//             std::cout << "- Window: " << window.getName() << std::endl;
//             for (const auto &dish : window.getDishes())
//             {
//                 std::cout << "  - " << dish.getName() << ": $" << dish.getPrice() << std::endl;
//             }
//         }
//     }
// }

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
    // admin.addCanteen(canteen2);
    // admin.addCanteen(canteen2);
    // admin.addCanteen(canteen2);
    // 创建用户对象
    User user = User(admin.getHead());

    user.selectProcess();
    // // 显示所有饭堂信息
    // user.displayCanteens(user.getHead());

    // // 显示第一个饭堂的窗口信

    return 0;
}
