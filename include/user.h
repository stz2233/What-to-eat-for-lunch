#include <../include/public.h>

class User
{

    

public:
    std::vector<Canteen> canteens;
    User(std::vector<Canteen> canteens) : canteens(canteens)
    {
    }

    void displayCanteens(std::vector<Canteen> &canteens);
    void displayWindows(Canteen &canteen);
    void displayDishes(Window &window);
    void searchDishesByTaste(std::vector<Canteen> &canteens, std::string taste);
    void searchDishesByName(std::vector<Canteen> &canteens, std::string name);
};
