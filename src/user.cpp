#include<../include/user.h>

void User::displayCanteens(std::vector<Canteen>& canteens) {
    // 显示所有饭堂信息
    for (auto& canteen : canteens) {
        std::cout << "饭堂: " << canteen.getName() << std::endl;
    }
}

void User::displayWindows(Canteen& canteen) {
    // 显示指定饭堂下的所有窗口信息
    std::cout << "饭堂" << canteen.getName() << "的窗口:" << std::endl;
    for (auto& window : canteen.getWindows()) {
        std::cout << "- " << window.getName() << std::endl;
    }
}

void User::displayDishes(Window& window) {
    // 显示指定窗口下的所有菜品信息
    std::cout << "窗口" << window.getName() << "的菜品:" << std::endl;
    for (auto& dish : window.getDishes()) {
        std::cout << "- 名称: " << dish.getName() << ", 价格: " << dish.getPrice() << ", 口味: " << dish.getTaste() << std::endl;
    }
}

void User::searchDishesByTaste(std::vector<Canteen>& canteens, std::string taste) {
    // 根据口味搜索菜品，并显示菜品和窗口信息
    std::cout << "搜索口味为：" << taste << " 的菜品：" << std::endl;
    for (auto& canteen : canteens) {
        for (auto& window : canteen.getWindows()) {
            for (auto& dish : window.getDishes()) {
                if (dish.getTaste() == taste) {
                    std::cout << "- 名称：" << dish.getName() << "，价格：" << dish.getPrice() << "，窗口：" << window.getName() << "，饭堂：" << canteen.getName() << std::endl;
                }
            }
        }
    }
}

void User::searchDishesByName(std::vector<Canteen>& canteens, std::string name) {
    // 根据名称搜索菜品，并显示菜品和窗口信息
    std::cout << "搜索名称为：" << name << " 的菜品：" << std::endl;
    for (auto& canteen : canteens) {
        for (auto& window : canteen.getWindows()) {
            for (auto& dish : window.getDishes()) {
                if (dish.getName() == name) {
                    std::cout << "- 名称：" << dish.getName() << "，价格：" << dish.getPrice() << "，窗口：" << window.getName() << "，饭堂：" << canteen.getName() << std::endl;
                }
            }
        }
    }
}