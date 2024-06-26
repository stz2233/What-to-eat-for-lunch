#include <../include/public.h>
#include<node.h>
class User
{
    
public:
    LinkedList *head;
    std::vector<Canteen> canteens;
    User(LinkedList *temp) ;
    User(){};
    void displayCanteens(LinkedList *head) ;
    void displayWindows(Canteen &canteen,int sumber);
    void displayDishes(Window &window,int sumber);
    void searchDishesByTaste(std::vector<Canteen> &canteens, std::string taste);
    void searchDishesByName(std::vector<Canteen> &canteens, std::string name);
    bool selectProcess();
    LinkedList *getHead();
};
