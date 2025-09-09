#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
private:
    string name;
    unsigned int quantity;
public:
    Item(string name) {
        this->name = name;
        quantity = 1;
    }
    string GetName() {
        return name;
    }
    void IncQuantity() {
        quantity++;
    }
    void DecQuantity() {
        quantity--;
    }
    unsigned int GetQuantity() {
        return quantity;
    }
};

class Inventory {
private:
    vector<Item*> bag;
public:
    void AddItem(Item* item) {
        for (unsigned int i = 0; i < bag.size(); i++) {
            if (item->GetName() == bag[i]->GetName()) {
                bag[i]->IncQuantity();
                return;
            }
        }
        bag.push_back(item);
    }

    void RemoveItem(Item* item) {
        for (unsigned int i = 0; i < bag.size(); i++) {
            if (item->GetName() == bag[i]->GetName()) {
                if (bag[i]->GetQuantity() == 1) {
                    bag.erase(bag.cbegin() + i);
                }
                else {
                    bag[i]->DecQuantity();
                }
                break;
            }
        }
    }

    void GetItems() {
        for (unsigned int i = 0; i < bag.size(); i++) {
            cout << "Name: " << bag[i]->GetName() << " Count: " << bag[i]->GetQuantity() << endl;
        }
    }
};

int main() {
    Inventory inventory;
    Item apple("apple");
    Item banana("banana");
    Item water("water");

    inventory.AddItem(&apple);
    inventory.AddItem(&apple);
    inventory.AddItem(&banana);
    inventory.AddItem(&banana);
    inventory.AddItem(&banana);
    inventory.AddItem(&banana);
    inventory.AddItem(&banana);
    inventory.AddItem(&banana);
    inventory.AddItem(&water);
    inventory.RemoveItem(&banana);
    inventory.RemoveItem(&banana);
    inventory.GetItems();
    return 0;
}
