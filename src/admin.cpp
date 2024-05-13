#include <../include/admin.h>

Admin::Admin()
{
    head = new LinkedList();
}

Admin::~Admin()
{
    delete head;
}

void Admin::showMenu()
{
    std::cout << "管理员操作菜单：" << std::endl;
    std::cout << "1. 更改食堂名称" << std::endl;
    std::cout << "2. 选择食堂（内部更改）" << std::endl;
    std::cout << "3. 退出管理员系统" << std::endl;
}

void Admin::selectProcess()
{
    while (true)
    {
        showMenu();
        char option;
        std::cout << "请选择操作编号：";
        // option=std::cin.get();
        std::cin >> option;
        // std::cin.ignore();
        switch (option)
        {
        case '1':
        {
            displayCanteens(head);
            Canteen *canteen_temp;
            int sum;
            std::string name;
            std::cout << "请输入要更改的食堂序号：";
            std::cin >> sum;
            std::cin.ignore();
            std::cout << "请输入要更改的食堂名字：";

            std::getline(std::cin, name, '\n');
            bool ddd = head->printList(sum, canteen_temp);
            if (ddd)
            {
                canteen_temp->setCanteen(name);
                std::cout << "修改成功" << std::endl;
            }

            break;
        }
        case '2':
        {
            while (true)
            {
                displayCanteens(head);
                int sum;
                std::string name;
                std::cout << "选择食堂:";
                std::cin >> sum;
                Canteen *canteen_temp;

                if (head->printList(sum, canteen_temp))
                {
                    int n = 0;
                    std::cout << "窗口序号 ：" << std::endl;
                    for (auto window : canteen_temp->getWindows())
                    {
                        std::cout << n << ". " << window.getName() << std::endl;
                        n++;
                    }
                    std::cout << std::endl;
                    std::cout << "1. 更改窗口名称" << std::endl;
                    std::cout << "2. 选择窗口（更改菜品）" << std::endl;
                    std::cout << "3. 返回" << std::endl;
                    std::cin >> sum;
                    if (sum == 1)
                    {
                        int sum_window;
                        std::cout << "请输入窗口序号：";
                        std::cin >> sum_window;
                        std::cout << "请输入修改后窗口名字：";
                        std::cin >> name;
                        canteen_temp->windows[sum_window].setWindow(name);
                        std::cout << "修改成功" << std::endl;
                        break;
                    }
                    else if (sum == 2)
                    {
                        std::cout << "请输入窗口序号：";
                        std::cin >> sum;
                        if (canteen_temp->windows.size() > sum)
                        {
                            int i = 0;
                            for (auto dish : canteen_temp->windows[sum].dishes)
                            {
                                std::cout << i << ". " << dish.getName() << std::endl;
                            }
                            std::cout << std::endl;
                            std::cout << "1 .修改" << std::endl;
                            std::cout << "2. 删除" << std::endl;
                            std::cout << "3. 添加" << std::endl;
                            std::cout << "4. 排序" << std::endl;
                            std::cin >> i;

                            switch (i)
                            {
                            case 1:
                            {
                                std::cout << "输入菜品序号";
                                int dish_num;
                                std::cin >> dish_num;
                                double price;
                                std::string taste;
                                std::cout << "请输入修改后菜品价格：";
                                std::cin >> price;
                                std::cout << "请输入修改后菜品口味：";
                                std::cin >> taste;
                                std::cout << "请输入修改后菜品名字：";
                                std::cin >> name;
                                if (canteen_temp->windows[sum].dishes.size() > i)
                                {

                                    canteen_temp->windows[sum].dishes[dish_num].setDish(name, price, taste);
                                    std::cout << "修改成功" << std::endl;
                                }
                                else
                                {
                                    std::cout << "输入错误" << std::endl;
                                }
                                break;
                            }
                            case 2:
                            {
                                std::cout << "请输入要删除的菜品序号：";
                                std::cout << "输入菜品序号";
                                int dish_num;
                                std::cin >> dish_num;
                                if (canteen_temp->windows[sum].dishes.size() > dish_num)
                                {
                                    canteen_temp->windows[sum].dishes.erase(canteen_temp->windows[sum].dishes.begin() + dish_num);
                                    std::cout << "删除成功" << std::endl;
                                }
                                else
                                {
                                    std::cout << "输入错误" << std::endl;
                                }
                            }
                            case 3:
                            {
                                std::cout << "添加菜品";
                                double price;
                                std::string taste;
                                std::cout << "请输入修改后菜品价格：";
                                std::cin >> price;
                                std::cout << "请输入修改后菜品口味：";
                                std::cin >> taste;
                                std::cout << "请输入修改后菜品名字：";
                                std::cin >> name;
                                addDish(canteen_temp->windows[sum], name, price, taste);
                            }
                            case 4:
                            {
                                sortDishesByPrice(canteen_temp->windows[sum]);
                                for(auto dish : canteen_temp->windows[sum].getDishes() ){
                                   std::cout<<"菜名："<<dish.getName()<<"价格："<<dish.getPrice()<<"口味"<<std::endl;
                                }
                            }
                            default:
                                break;
                            }
                        }
                        else
                        {
                        }
                        break;
                    }
                    else if (sum == 3)
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "输入错误" << std::endl;
                }
            }
            // 更改窗口名称
            break;
        }
        case '3':
        {
            return;
        }
        break;
        default:
        {
            std::cout << "输入错误，请重新输入" << std::endl;
            break;
        }
        }
    }
}

void Admin::addCanteen(Canteen &canteen)
{
    // 添加饭堂到饭堂列表
    head->addNode(canteen);
}

void Admin::addWindow(Canteen &canteen, std::string &windowName)
{
    // 在指定饭堂下添加窗口
    Window newWindow(windowName);
    canteen.addWindow(newWindow);
}

void Admin::addDish(Window &window, std::string &dishName, double price, std::string &taste)
{
    // 在指定窗口下添加菜品
    Dish newDish(dishName, price, taste);
    window.addDish(newDish);
}

void Admin::deleteCanteen(std::vector<Canteen> &canteens, std::string &canteenName)
{
    // 从饭堂列表中删除指定名称的饭堂
    auto it = std::find_if(canteens.begin(), canteens.end(), [&canteenName](Canteen &c)
                           { return c.getName() == canteenName; });

    if (it != canteens.end())
    {
        canteens.erase(it);
    }
}

void Admin::deleteWindow(Canteen &canteen, std::string &windowName)
{
    // 从指定饭堂下删除指定名称的窗口
    std::vector<Window> &windows = canteen.getWindows();
    auto it = std::find_if(windows.begin(), windows.end(), [&windowName](Window &w)
                           { return w.getName() == windowName; });

    if (it != windows.end())
    {
        windows.erase(it);
    }
}

void Admin::deleteDish(Window &window, std::string &dishName)
{
    // 从指定窗口下删除指定名称的菜品
    auto &dishes = window.getDishes();
    auto it = std::find_if(dishes.begin(), dishes.end(), [&dishName](Dish &d)
                           { return d.getName() == dishName; });

    if (it != dishes.end())
    {
        dishes.erase(it);
    }
}

LinkedList *Admin::getHead()
{
    return head;
}

void Admin::displayCanteens(LinkedList *head)
{
    // 显示所有饭堂信息
    Canteen canteen_temp;
    int i = 0;
    for (int n = 0; n != -1; n++)
    {
        if (head->printList(n, canteen_temp))
        {
            std::cout << i << ". 饭堂: " << canteen_temp.getName() << std::endl;
            i++;
        }
        if (n == -1)
        {
            break;
        }
    }
}

void Admin::sortCanteensByPrice(std::vector<Canteen> &canteens)
{
    // 对饭堂列表按价格排序
    // std::sort(canteens.begin(), canteens.end(), []( Canteen& a,  Canteen& b) {
    //     // 定义你的比较逻辑在这里
    //     // 例如: return a.getAveragePrice() < b.getAveragePrice();
    // });
}

void Admin::sortWindowsByPrice(Canteen &canteen)
{
    // 对指定饭堂下的窗口按价格排序
    auto &windows = canteen.getWindows();
    for (auto &window : windows)
    {
        std::sort(window.getDishes().begin(), window.getDishes().end(), [](Dish &a, Dish &b)
                  { return a.getPrice() < b.getPrice(); });
    }
}

void Admin::sortDishesByPrice(Window &window)
{
    // 对指定窗口下的菜品按价格排序
    std::sort(window.getDishes().begin(), window.getDishes().end(), [](Dish &a, Dish &b)
              { return a.getPrice() < b.getPrice(); });
}