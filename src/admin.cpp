#include<../include/admin.h>

Admin::Admin(){
    head = new LinkedList();
}

Admin::~Admin(){
    delete head;
}

void Admin::addCanteen(Canteen& canteen) {
    // 添加饭堂到饭堂列表
    head->addNode(canteen);
}

void Admin::addWindow(Canteen& canteen,  std::string& windowName) {
    // 在指定饭堂下添加窗口
    Window newWindow(windowName);
    canteen.addWindow(newWindow);
}

void Admin::addDish(Window& window,  std::string& dishName, double price,  std::string& taste) {
    // 在指定窗口下添加菜品
    Dish newDish(dishName, price, taste);
    window.addDish(newDish);
}

void Admin::deleteCanteen(std::vector<Canteen>& canteens,  std::string& canteenName) {
    // 从饭堂列表中删除指定名称的饭堂
    auto it = std::find_if(canteens.begin(), canteens.end(), [&canteenName]( Canteen& c) {
        return c.getName() == canteenName;
    });

    if (it != canteens.end()) {
        canteens.erase(it);
    }
}

void Admin::deleteWindow(Canteen& canteen,  std::string& windowName) {
    // 从指定饭堂下删除指定名称的窗口
    std::vector<Window>& windows = canteen.getWindows();
    auto it = std::find_if(windows.begin(), windows.end(), [&windowName]( Window& w) {
        return w.getName() == windowName;
    });

    if (it != windows.end()) {
        windows.erase(it);
    }
}

void Admin::deleteDish(Window& window,  std::string& dishName) {
    // 从指定窗口下删除指定名称的菜品
    auto& dishes = window.getDishes();
    auto it = std::find_if(dishes.begin(), dishes.end(), [&dishName]( Dish& d) {
        return d.getName() == dishName;
    });

    if (it != dishes.end()) {
        dishes.erase(it);
    }
}

LinkedList *Admin::getHead()
    {
        return head;
    }

void Admin::sortCanteensByPrice(std::vector<Canteen>& canteens) {
    // 对饭堂列表按价格排序
    // std::sort(canteens.begin(), canteens.end(), []( Canteen& a,  Canteen& b) {
    //     // 定义你的比较逻辑在这里
    //     // 例如: return a.getAveragePrice() < b.getAveragePrice();
    // });
}

void Admin::sortWindowsByPrice(Canteen& canteen) {
    // 对指定饭堂下的窗口按价格排序
    auto& windows = canteen.getWindows();
    for (auto& window : windows) {
        std::sort(window.getDishes().begin(), window.getDishes().end(), []( Dish& a,  Dish& b) {
            return a.getPrice() < b.getPrice();
        });
    }
}

void Admin::sortDishesByPrice(Window& window) {
    // 对指定窗口下的菜品按价格排序
    std::sort(window.getDishes().begin(), window.getDishes().end(), []( Dish& a,  Dish& b) {
        return a.getPrice() < b.getPrice();
    });
}