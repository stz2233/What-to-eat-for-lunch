#include <../include/user.h>

User::User(LinkedList *temp) : head(temp)
{
}

bool User::selectProcess()
{
    int choice;
    std::cout << "1. 查看饭堂信息" << std::endl;
    std::cout << "1. 查找菜品" << std::endl;
    std::cout << "其他. 返回" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        while (true)
        {
            displayCanteens(head);
            std::cout << "请选择饭堂" << std::endl;

            int choice_canteen;
            std::cin >> choice_canteen;

            Canteen canteen_temp;
            head->printList(choice, canteen_temp);
            displayWindows(canteen_temp, 0);

            std::cout << "请选择窗口" << std::endl;

            int choice_window;
            std::cin >> choice_window;

            displayDishes(canteen_temp.getWindows()[choice_window - 1], 0);
            std::cout << "按任意键退出" << std::endl;
            getchar();
            getchar();
            break;
        }

        break;
    }
    case 2:
    {
        while (true)
        {
            std::cout << "1. 按菜品口味查找" << std::endl;
            std::cout << "2. 按菜品名称查找" << std::endl;
            std::cout << "其他. 返回" << std::endl;
            int choice_1;
            std::cin >> choice_1;
            switch (choice_1)
            {
            case 1:
            {
                std::string taste;
                std::cout << "请输入菜品口味" << std::endl;
                std::cin >> taste;
                searchDishesByTaste(canteens, taste);
                continue;
            }
            case 2:
            {
                std::string name;
                std::cout << "请输入菜品名称" << std::endl;
                std::cin >> name;
                searchDishesByName(canteens, name);
                continue;
            }
            
            }
            break;
        }
    }
    default:
        break;
    }
}

void User::displayCanteens(LinkedList *head)
{
    // 显示所有饭堂信息
    Canteen canteen_temp;
    for (int n = 0; n != -1; n++)
    {
        if (head->printList(n, canteen_temp))
        {
            std::cout << "饭堂: " << canteen_temp.getName() << std::endl;
        }
        if (n == -1)
        {
            break;
        }
    }
}

void User::displayWindows(Canteen &canteen, int sumber)
{
    // 显示指定饭堂下的所有窗口信息
    std::cout << "饭堂" << canteen.getName() << "的窗口:" << std::endl;
    for (auto &window : canteen.getWindows())
    {
        std::cout << "- " << window.getName() << std::endl;
    }
}

void User::displayDishes(Window &window, int sumber)
{
    // 显示指定窗口下的所有菜品信息
    std::cout << "窗口" << window.getName() << "的菜品:" << std::endl;
    for (auto &dish : window.getDishes())
    {
        std::cout << "- 名称: " << dish.getName() << ", 价格: " << dish.getPrice() << ", 口味: " << dish.getTaste() << std::endl;
    }
}

void User::searchDishesByTaste(std::vector<Canteen> &canteens, std::string taste)
{

    Canteen canteen_temp;
    for (int n = 0; n != -1; n++)
    {
        if (head->printList(n, canteen_temp))
        {
            for (auto &window : canteen_temp.getWindows())
            {
                for (auto &dish : window.getDishes())
                {
                    if (hasCommonCharacter(dish.getTaste() ,taste))
                    {
                        std::cout << "- 名称：" << dish.getName() << "，价格：" << dish.getPrice() << "，窗口：" << window.getName() << "，饭堂：" << canteen_temp.getName() << std::endl;
                    }
                }
            }
        }
        if (n == -1)
        {
            break;
        }
    }
}

void User::searchDishesByName(std::vector<Canteen> &canteens, std::string name)
{
    // 根据名称搜索菜品，并显示菜品和窗口信息
    std::cout << "搜索名称为：" << name << " 的菜品：" << std::endl;

    Canteen canteen_temp;
    for (int n = 0; n != -1; n++)
    {
        if (head->printList(n, canteen_temp))
        {
            for (auto &window : canteen_temp.getWindows())
            {
                for (auto &dish : window.getDishes())
                {
                    if (hasCommonCharacter(dish.getName(), name))
                    {
                        std::cout << "- 名称：" << dish.getName() << "，价格：" << dish.getPrice() << "，窗口：" << window.getName() << "，饭堂：" << canteen_temp.getName() << std::endl;
                    }
                }
            }
        }
        if (n == -1)
        {
            break;
        }
    }
}

LinkedList *User::getHead()
{
    return head;
}