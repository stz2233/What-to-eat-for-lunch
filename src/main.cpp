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

LinkedList head;

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
    // head=admin.head;
    // admin.addCanteen(canteen2);
    // admin.addCanteen(canteen2);
    // admin.addCanteen(canteen2);
    // 创建用户对象
    User user;
    std::string mima;
    std::string nnn = "12345678";
    while (true)
    {
        user.head = admin.head;
        std::cout << "选择登录模式" << std::endl;
        std::cout << "管理员：0" << std::endl;
        std::cout << "用户：1" << std::endl;
        std::cout << "退出: 其他" << std::endl;
        char chioes;
        std::cin >> chioes;
        if (chioes == '0')
        {
            std::cout << "输入密码" << std::endl;
            std::cin >> mima;
            if (mima == nnn)
            {
                admin.selectProcess();
            }
            else
            {
                std::cout << "密码错误" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (chioes == '1')
        {
            user.selectProcess();
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
