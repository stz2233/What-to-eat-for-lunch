#include <../include/public.h>
#include <node.h>
class Admin
{
private:
    // std::vector<Canteen> canteens;
    LinkedList *head;

public:
    Admin();
     ~Admin();
     void selectProcess();
    void addCanteen(Canteen &canteen);
    void addWindow(Canteen &canteen, std::string &windowName);
    void addDish(Window &window, std::string &dishName, double price, std::string &taste);
    void deleteCanteen(std::vector<Canteen> &canteens, std::string &canteenName);
    void deleteWindow(Canteen &canteen, std::string &windowName);
    void deleteDish(Window &window, std::string &dishName);
    void sortCanteensByPrice(std::vector<Canteen> &canteens);
    void sortWindowsByPrice(Canteen &canteen);
    void sortDishesByPrice(Window &window);
    LinkedList *getHead();
};
