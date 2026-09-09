#include <iostream>
#include <string>

using namespace std;

const int max_items = 1000;

class Factory {
public:
    string name;
    int laptopsProducedMonth, workers;
    double workerSalary;

    Factory(string nm = "", int lpm = 0, double ws = 0.0, int wr = 0) : name(nm), laptopsProducedMonth(lpm), workerSalary(ws), workers(wr) {}
};

class Supplier {
public:
    string name;
    double cost;

    Supplier(string nm = "", double c = 0.0) : name(nm), cost(c) {}
};

class SalesPoint {
public:
    string name;
    double priceLaptop;

    SalesPoint(string nm = "", double pc = 0.0) : name(nm), priceLaptop(pc) {}
};

class EquipmentFactory {
public:
    string name;
    double cost;

    EquipmentFactory(string nm = "", double c = 0.0) : name(nm), cost(c) {}
};

class Accessory {
public:
    string name;
    double price;
    int accessoryProducedMonth;

    Accessory(string nm = "", double pc = 0.0, int ap = 0) : name(nm), price(pc), accessoryProducedMonth(ap) {}
};

class Company {
private:
    Factory factories[max_items];
    Supplier suppliers[max_items];
    SalesPoint salesPoints[max_items];
    EquipmentFactory equipmentFactories[max_items];
    Accessory accessories[max_items];

public:
    int factoryCount = 0, supplierCount = 0, salesPointCount = 0, equipmentFactoryCount = 0, accessoryCount = 0;

    int getFactoryCount() const { return factoryCount; }
    int getSupplierCount() const { return supplierCount; }
    int getSalesPointCount() const { return salesPointCount; }
    int getEquipmentFactoryCount() const { return equipmentFactoryCount; }
    int getAccessoryCount() const { return accessoryCount; }

    void AddFactory(const string& name, int laptopsProduced, double workerSalary, int workers) {
        for (int i = 0; i < factoryCount; i++)
        {
            if (factories[i].name == name)
            {
                cout << "\nЗавод " << name << " с таким названием уже есть.\n";
                return;
            }
        }
        if (factoryCount < max_items) {
            factories[factoryCount++] = Factory(name, laptopsProduced, workerSalary, workers);
            cout << "\nЗавод " << name << " добавлен\n";
        }
        else {
            cout << "Лимит заводов достигнут\n";
        }
    }

    void AddSupplier(const string& name, double cost) {
        for (int i = 0; i < supplierCount; i++)
        {
            if (suppliers[i].name == name)
            {
                cout << "\nПоставщик " << name << " с таким названием уже есть.\n";
                return;
            }
        }
        if (supplierCount < max_items) {
            suppliers[supplierCount++] = Supplier(name, cost);
            cout << "Поставщик " << name << " добавлен\n";
        }
        else {
            cout << "\nЛимит поставщиков достигнут\n";
        }
    }

    void AddSalesPoint(const string& name, double price) {
        for (int i = 0; i < salesPointCount; i++)
        {
            if (salesPoints[i].name == name)
            {
                cout << "\nТорговая точка " << name << " с таким названием уже есть.\n";
                return;
            }
        }
        if (salesPointCount < max_items) {
            salesPoints[salesPointCount++] = SalesPoint(name, price);
            cout << "Точка продаж " << name << " добавлена\n";
        }
        else {
            cout << "\nЛимит точек продаж достигнут\n";
        }
    }

    void AddEquipmentFactory(const string& name, double cost) {
        for (int i = 0; i < equipmentFactoryCount; i++)
        {
            if (equipmentFactories[i].name == name)
            {
                cout << "\nЗавод оборудования " << name << " с таким названием уже есть.\n";
                return;
            }
        }
        if (equipmentFactoryCount < max_items) {
            equipmentFactories[equipmentFactoryCount++] = EquipmentFactory(name, cost);
            cout << "Завод оборудования " << name << " добавлен\n";
        }
        else {
            cout << "\nЛимит заводов оборудования достигнут\n";
        }
    }

    void AddAccessory(const string& name, double price, int accessoryProducedMonth) {
        for (int i = 0; i < accessoryCount; i++)
        {
            if (accessories[i].name == name)
            {
                cout << "\nАксессуар " << name << " с таким названием уже есть.\n";
                return;
            }
        }
        if (accessoryCount < max_items) {
            accessories[accessoryCount++] = Accessory(name, price, accessoryProducedMonth);
            cout << "Аксессуар " << name << " добавлен\n";
        }
        else {
            cout << "\nЛимит аксессуаров достигнут\n";
        }
    }

    void RemoveFactory(const string& name) {
        if (factoryCount == 0) {
            cout << "У вас нет заводов для удаления.\n";
            return;
        }
        for (int i = 0; i < factoryCount; ++i) {
            if (factories[i].name == name) {
                factories[i] = factories[--factoryCount];
                cout << "Завод " << name << " удален\n";
                return;
            }
        }
        cout << "Завод не найден.\n";
    }

    void RemoveSupplier(const string& name) {
        if (supplierCount == 0) {
            cout << "У вас нет поставщиков для удаления.\n";
            return;
        }
        for (int i = 0; i < supplierCount; ++i) {
            if (suppliers[i].name == name) {
                suppliers[i] = suppliers[--supplierCount];
                cout << "Поставщик " << name << " удален\n";
                return;
            }
        }
        cout << "Поставщик не найден.\n";
    }

    void RemoveSalesPoint(const string& name) {
        if (salesPointCount == 0) {
            cout << "У вас нет точек продаж для удаления.\n";
            return;
        }
        for (int i = 0; i < salesPointCount; ++i) {
            if (salesPoints[i].name == name) {
                salesPoints[i] = salesPoints[--salesPointCount];
                cout << "Точка продаж " << name << " удалена\n";
                return;
            }
        }
        cout << "Точка продаж не найдена.\n";
    }

    void RemoveEquipmentFactory(const string& name) {
        if (equipmentFactoryCount == 0) {
            cout << "У вас нет заводов оборудования для удаления.\n";
            return;
        }
        for (int i = 0; i < equipmentFactoryCount; ++i) {
            if (equipmentFactories[i].name == name) {
                equipmentFactories[i] = equipmentFactories[--equipmentFactoryCount];
                cout << "Завод оборудования " << name << " удален\n";
                return;
            }
        }
        cout << "Завод оборудования не найден.\n";
    }

    void RemoveAccessory(const string& name) {
        if (accessoryCount == 0) {
            cout << "У вас нет аксессуаров для удаления.\n";
            return;
        }
        for (int i = 0; i < accessoryCount; ++i) {
            if (accessories[i].name == name) {
                accessories[i] = accessories[--accessoryCount];
                cout << "Аксессуар " << name << " удален\n";
                return;
            }
        }
        cout << "Аксессуар не найден.\n";
    }

    void UpdateFactory(const string& name, int laptopsProduced, double workerSalary, int workers) {
        if (factoryCount == 0) {
            cout << "У вас нет заводов для обновления.\n";
            return;
        }
        for (int i = 0; i < factoryCount; ++i) {
            if (factories[i].name == name) {
                factories[i].laptopsProducedMonth = laptopsProduced;
                factories[i].workerSalary = workerSalary;
                factories[i].workers = workers;
                cout << "Производство завода " << name << " обновлено\n";
                return;
            }
        }
        cout << "Завод не найден.\n";
    }

    void UpdateSupplierCost(const string& name, double cost) {
        if (supplierCount == 0) {
            cout << "У вас нет поставщиков для обновления.\n";
            return;
        }
        for (int i = 0; i < supplierCount; ++i) {
            if (suppliers[i].name == name) {
                suppliers[i].cost = cost;
                cout << "Стоимость поставщика " << name << " обновлена\n";
                return;
            }
        }
        cout << "Поставщик не найден.\n";
    }

    void UpdateSalesPoint(const string& name, double price) {
        if (salesPointCount == 0) {
            cout << "У вас нет точек продаж для обновления.\n";
            return;
        }
        for (int i = 0; i < salesPointCount; ++i) {
            if (salesPoints[i].name == name) {
                salesPoints[i].priceLaptop = price;
                cout << "Стоимость в точке продаж " << name << " обновлена\n";
                return;
            }
        }
        cout << "Точка продаж не найдена.\n";
    }

    void UpdateEquipmentFactory(const string& name, double cost) {
        if (equipmentFactoryCount == 0) {
            cout << "У вас нет заводов оборудования для обновления.\n";
            return;
        }
        for (int i = 0; i < equipmentFactoryCount; ++i) {
            if (equipmentFactories[i].name == name) {
                equipmentFactories[i].cost = cost;
                cout << "Стоимость завода оборудования " << name << " обновлена\n";
                return;
            }
        }
        cout << "Завод оборудования не найден.\n";
    }

    void UpdateAccessory(const string& name, double price, int production) {
        if (accessoryCount == 0) {
            cout << "У вас нет аксессуаров для обновления.\n";
            return;
        }
        for (int i = 0; i < accessoryCount; ++i) {
            if (accessories[i].name == name) {
                accessories[i].price = price;
                accessories[i].accessoryProducedMonth = production;
                cout << "Стоимость аксессуара " << name << " обновлена\n";
                return;
            }
        }
        cout << "Аксессуар не найден.\n";
    }

    void Finance() {
        int choice,
            choiceCST;
        double
            monthlyIncome = 0,
            monthlyExpenses = 0,
            monthlyIncomeTAX = 0,
            percent = 0.13;

        if (getFactoryCount() > 0 || getSupplierCount() > 0 || getSalesPointCount() > 0 || getEquipmentFactoryCount() > 0 || getAccessoryCount() > 0) {
            for (int i = 0; i < factoryCount; ++i) {
                monthlyExpenses += factories[i].workerSalary * factories[i].workers;
            }
            for (int j = 0; j < supplierCount; ++j) {
                monthlyExpenses += suppliers[j].cost;
            }
            for (int k = 0; k < equipmentFactoryCount; ++k) {
                monthlyExpenses += equipmentFactories[k].cost;
            }

            for (int i = 0; i < salesPointCount; ++i) {
                for (int j = 0; j < factoryCount; ++j) {
                    monthlyIncome += salesPoints[i].priceLaptop * factories[j].laptopsProducedMonth;
                }
            }
            for (int i = 0; i < accessoryCount; ++i) {
                monthlyIncome += accessories[i].price * accessories[i].accessoryProducedMonth;
            }

            for (int i = 0; i < salesPointCount; ++i) {
                for (int j = 0; j < factoryCount; ++j) {
                    monthlyIncomeTAX += salesPoints[i].priceLaptop * factories[j].laptopsProducedMonth;
                }
            }
            for (int i = 0; i < accessoryCount; ++i) {
                monthlyIncomeTAX += accessories[i].price * accessories[i].accessoryProducedMonth;
            }

            double deduct = monthlyIncomeTAX * percent;
            monthlyIncomeTAX -= deduct;
            double monthlyProfit = monthlyIncome - monthlyExpenses;
            double monthlyProfitTAX = monthlyIncomeTAX - monthlyExpenses;


            for (int i = 0; i < 42; i++)
            {
                cout << "#";
            }
            tab_line();

            cout << "\nВведите на сколько месяцев вперёд вы хотите расчитать доход/расход/прибыль, а затем через пробел, налог.\n";
            cout << "Ваше число --> ";
            cin >> choice >> choiceCST;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Неверный ввод.\n";
                return;
            }
            
            tab_6();
            cout << "   Ежемесячный доход(Без налогов): " << monthlyIncome << "\n";
            cout << "   Ежемесячный доход(C налогами): " << monthlyIncomeTAX << "\n";
            cout << "   Ежемесячные расходы: " << monthlyExpenses << "\n";
            cout << "   Ежемесячная прибыль(Без налогов): " << monthlyProfit << "\n";
            cout << "   Ежемесячная прибыль(С налогом): " << monthlyProfitTAX << "\n";
            tab_6();
            cout << "   Годовой доход(Без налогов): " << monthlyIncome * 12 << "\n";
            cout << "   Годовой доход(С налогами): " << monthlyIncomeTAX * 12 << "\n";
            cout << "   Годовые расходы: " << monthlyExpenses * 12 << "\n";
            cout << "   Годовая прибыль(Без налогов): " << monthlyProfit * 12 << "\n";
            cout << "   Годовая прибыль(С налогами): " << monthlyProfitTAX * 12 << "\n";
            tab_6();
            cout << "   Кастомный доход(Без налогов): " << monthlyIncome * choiceCST << "\n";
            cout << "   Кастомный доход(С налогами): " << monthlyIncomeTAX * choiceCST << "\n";
            cout << "   Кастомный расходы: " << monthlyExpenses * choiceCST << "\n";
            cout << "   Кастомный прибыль(Без налогов): " << monthlyProfit * choiceCST << "\n";
            cout << "   Кастомный прибыль(С налогами): " << monthlyProfitTAX * choiceCST << "\n";
            tab_6();


            tab_line_x2();

            return;
        }
        else
        {
            cout << "У вас ничего нету!\n\n";
        }
    }


    void print_Factory() {
        for (int i = 0; i < factoryCount; i++)
        {
            cout << factories[i].name << endl;
        }
    }

    void print_Supplier() {
        for (int i = 0; i < supplierCount; i++)
        {
            cout << suppliers[i].name << endl;
        }
    }

    void print_SalesPoint() {
        for (int i = 0; i < salesPointCount; i++)
        {
            cout << salesPoints[i].name << endl;
        }
    }

    void print_EquipmentFactory() {
        for (int i = 0; i < equipmentFactoryCount; i++)
        {
            cout << equipmentFactories[i].name << endl;
        }
    }

    void print_Accessory() {
        for (int i = 0; i < accessoryCount; i++)
        {
            cout << accessories[i].name << endl;
        }
    }


    void print_Factory_show() {
        if (factoryCount > 0)
        {
            for (int i = 0; i < factoryCount; i++)
            {
                cout << "Ваши заводы:\n";
                cout << i << ". " << factories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету заводов.\n";
        }

    }

    void print_Supplier_show() {
        if (supplierCount > 0)
        {
            for (int i = 0; i < supplierCount; i++)
            {
                cout << "Ваши поставщики:\n";
                cout << i << ". " << suppliers[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету поставщиков.\n";
        }

    }

    void print_SalesPoint_show() {
        if (salesPointCount > 0)
        {
            for (int i = 0; i < salesPointCount; i++)
            {
                cout << "Ваши торговые точки:\n";
                cout << i << ". " << salesPoints[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету торговых точек.\n";
        }

    }

    void print_Equipment_Factory_show() {
        if (equipmentFactoryCount > 0)
        {
            for (int i = 0; i < equipmentFactoryCount; i++)
            {
                cout << "Ваши заводы оборудования:\n";
                cout << i << ". " << equipmentFactories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету заводов оборудования.\n";
        }

    }

    void print_Accessory_show() {
        if (accessoryCount > 0)
        {
            for (int i = 0; i < accessoryCount; i++)
            {
                cout << "Ваши аксессуары:\n";
                cout << i << ". " << accessories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету аксессуаров.\n";
        }

    }


    void print_Factory_Characteristics() {
        int choice;
        if (factoryCount > 0)
        {
            cout << "Ваши заводы:\n";
            for (int i = 0; i < factoryCount; i++)
            {

                cout << i << ". " << factories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету заводов.\n";
        }
        cout << "Выберите завод\n";
        cout << "Ваше число --> ";
        cin >> choice;

        tab_line();

        if (choice >= 0 && choice < max_items)
        {
            Factory factory = factories[choice];
            cout << "Характеристики завода\n";
            cout << "Имя: " << factory.name << endl;
            cout << "Количество рабочих: " << factory.workers << endl;
            cout << "Зарплата рабочего: " << factory.workerSalary << endl;
            cout << "Количество произведённых ноутбуков в месяц: " << factory.laptopsProducedMonth << endl;
            tab_line();
            return;
        }
    }

    void print_Supplier_Characteristics() {
        int choice;
        if (supplierCount > 0)
        {
            cout << "Ваши поставщики:\n";
            for (int i = 0; i < supplierCount; i++)
            {

                cout << i << ". " << suppliers[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету поставщиков.\n";
        }
        cout << "Выберите поставщиков\n";
        cout << "Ваше число --> ";
        cin >> choice;
        tab_line();

        if (choice >= 0 && choice < max_items)
        {
            Supplier supplier = suppliers[choice];
            cout << "Характеристики поставщика\n";
            cout << "Имя: " << supplier.name << endl;
            cout << "Цена поставщика: " << supplier.cost << endl;
            tab_line();
            return;
        }
    }

    void print_Sales_Point_Characteristics() {
        int choice;
        if (salesPointCount > 0)
        {
            cout << "Ваши торговые точки:\n";
            for (int i = 0; i < salesPointCount; i++)
            {

                cout << i << ". " << salesPoints[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету торговых точек.\n";
        }
        cout << "Выберите торговую точку\n";
        cout << "Ваше число --> ";
        cin >> choice;
        tab_line();

        if (choice >= 0 && choice < max_items)
        {
            SalesPoint salepoint = salesPoints[choice];
            cout << "Характеристики торговой точки\n";
            cout << "Имя: " << salepoint.name << endl;
            cout << "Цена ноутбукка: " << salepoint.priceLaptop << endl;
            tab_line();
            return;
        }
    }

    void print_Equipment_Factory_Characteristics() {
        int choice;
        if (equipmentFactoryCount > 0)
        {
            cout << "Ваши заводы оборудования:\n";
            for (int i = 0; i < equipmentFactoryCount; i++)
            {

                cout << i << ". " << equipmentFactories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету заводов оборудования.\n";
        }
        cout << "Выберите завод оборудования\n";
        cout << "Ваше число --> ";
        cin >> choice;
        tab_line();

        if (choice >= 0 && choice < max_items)
        {
            EquipmentFactory equipmentFactory = equipmentFactories[choice];
            cout << "Характеристики завода оборудования\n";
            cout << "Имя: " << equipmentFactory.name << endl;
            cout << "Цена завода оборудования: " << equipmentFactory.cost << endl;
            tab_line();
            return;
        }
    }

    void print_Accessory_Characteristics() {
        int choice;
        if (accessoryCount > 0)
        {
            cout << "Ваши аксессуары:\n";
            for (int i = 0; i < accessoryCount; i++)
            {

                cout << i << ". " << accessories[i].name << endl;
            }
        }
        else
        {
            cout << "У вас нету аксессуаров.\n";
        }
        cout << "Выберите аксессуар\n";
        cout << "Ваше число --> ";
        cin >> choice;
        tab_line();

        if (choice >= 0 && choice < max_items)
        {
            Accessory accessory = accessories[choice];
            cout << "Характеристики аксессуара\n";
            cout << "Имя:" << accessory.name << endl;
            cout << "Количество произведённых аксессуаров в месяц: " << accessory.accessoryProducedMonth << endl;
            cout << "Цена аксессуара: " << accessory.price << endl;
            tab_line();
            return;
        }
    }

    void tab_1() {
        cout << "                   ";
    }
    void tab_2() {
        cout << "                ";
    }
    void tab_3() {
        cout << "                 ";
    }
    void tab_4() {
        cout << "                  ";
    }
    void tab_5() {
        cout << "        ";
    }
    void tab_6() {
        cout << "                                   " << "\n";
    }
    void tab_7() {
        cout << "              ";
    }
    void tab_line() {
        cout << "\n";
    }
    void tab_line_x2() {
        cout << "\n\n";
    }

    void cls() {
        cin.clear();
        cin.ignore(32767, '\n');
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Company company;
    string name, input;
    long long production, workers;
    double cost, price, salary;
    unsigned int choice;

    while (true) {
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();
        company.tab_1();
        cout << "Меню\n";
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();
        company.tab_2();
        cout << "Добавление\n";
        company.tab_6();

        if (company.getFactoryCount() >= max_items || company.getSupplierCount() >= max_items || company.getSalesPointCount() >= max_items || company.getEquipmentFactoryCount() >= max_items || company.getAccessoryCount() >= max_items) {
            cout << "У вас лимит по items\n";
        }
        else
        {
            if (company.getFactoryCount() < max_items)
                cout << "1. Добавить завод\n";
            if (company.getSupplierCount() < max_items)
                cout << "2. Добавить поставщика\n";
            if (company.getSalesPointCount() < max_items)
                cout << "3. Добавить точку продаж\n";
            if (company.getEquipmentFactoryCount() < max_items)
                cout << "4. Добавить завод оборудования\n";
            if (company.getAccessoryCount() < max_items)
                cout << "5. Добавить аксессуар\n";
        }
        company.tab_6();

        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }

        company.tab_line();
        company.tab_3();
        cout << "Удаление\n";
        company.tab_6();
        if (company.getFactoryCount() > 0 || company.getSupplierCount() > 0 || company.getSalesPointCount() > 0 || company.getEquipmentFactoryCount() > 0 || company.getAccessoryCount() > 0) {
            if (company.getFactoryCount() > 0)
                cout << "6. Удалить завод\n";
            if (company.getSupplierCount() > 0)
                cout << "7. Удалить поставщика\n";
            if (company.getSalesPointCount() > 0)
                cout << "8. Удалить точку продаж\n";
            if (company.getEquipmentFactoryCount() > 0)
                cout << "9. Удалить завод оборудования\n";
            if (company.getAccessoryCount() > 0)
                cout << "10. Удалить аксессуар\n";
        }
        else
        {
            company.tab_5();
            cout << "У вас пока что нечего нету\n";
        }
        company.tab_6();
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();

        company.tab_3();
        cout << "Изменить\n";
        company.tab_6();
        if (company.getFactoryCount() > 0 || company.getSupplierCount() > 0 || company.getSalesPointCount() > 0 || company.getEquipmentFactoryCount() > 0 || company.getAccessoryCount() > 0) {
            if (company.getFactoryCount() > 0)
                cout << "11. Изменить информацию завода\n";
            if (company.getSupplierCount() > 0)
                cout << "12. Изменить информацию поставщика\n";
            if (company.getSalesPointCount() > 0)
                cout << "13. Изменить информацию точки продаж\n";
            if (company.getEquipmentFactoryCount() > 0)
                cout << "14. Изменить информацию завода оборудования\n";
            if (company.getAccessoryCount() > 0)
                cout << "15. Изменить информацию аксессуара\n";
        }
        else
        {
            company.tab_5();
            cout << "У вас пока что нечего нету\n";
        }
        company.tab_6();
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();

        company.tab_3();
        cout << "Показать\n";
        company.tab_6();
        if (company.getFactoryCount() > 0 || company.getSupplierCount() > 0 || company.getSalesPointCount() > 0 || company.getEquipmentFactoryCount() > 0 || company.getAccessoryCount() > 0) {
            if (company.getFactoryCount() > 0)
                cout << "16. Показать названия заводов\n";
            if (company.getSupplierCount() > 0)
                cout << "17. Показать названия поставщиков\n";
            if (company.getSalesPointCount() > 0)
                cout << "18. Показать названия точек продаж\n";
            if (company.getEquipmentFactoryCount() > 0)
                cout << "19. Показать названия заводов оборудования\n";
            if (company.getAccessoryCount() > 0)
                cout << "20. Показать названия аксессуаров\n";
        }
        else
        {
            company.tab_5();
            cout << "У вас пока что нечего нету\n";
        }
        company.tab_6();

        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();
        company.tab_7();
        cout << "Характеристики\n";
        company.tab_6();
        if (company.getFactoryCount() > 0 || company.getSupplierCount() > 0 || company.getSalesPointCount() > 0 || company.getEquipmentFactoryCount() > 0 || company.getAccessoryCount() > 0) {
            if (company.getFactoryCount() > 0)
                cout << "21. Показать характеристики заводов\n";
            if (company.getSupplierCount() > 0)
                cout << "22. Показать характеристики поставщиков\n";
            if (company.getSalesPointCount() > 0)
                cout << "23. Показать характеристики точек продаж\n";
            if (company.getEquipmentFactoryCount() > 0)
                cout << "24. Показать характеристики заводов оборудования\n";
            if (company.getAccessoryCount() > 0)
                cout << "25. Показать характеристики аксессуаров\n";
        }
        else
        {
            company.tab_5();
            cout << "У вас пока что нечего нету\n";
        }
        company.tab_6();
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();

        company.tab_4();
        cout << "Прочее\n";
        company.tab_6();
        if (company.getFactoryCount() > 0 || company.getSupplierCount() > 0 || company.getSalesPointCount() > 0 || company.getEquipmentFactoryCount() > 0 || company.getAccessoryCount() > 0)
            cout << "26. Подсчитать финансы\n";

        cout << "27. Выход\n";
        cout << "28. Очистить консоль\n";

        company.tab_6();
        for (int i = 0; i < 42; i++)
        {
            cout << "#";
        }
        company.tab_line();
        cout << "Выберите действие --> ";

        bool invalid = false;
        cin >> input;

        for (char c : input) {
            if (!isdigit(c)) {
                invalid = true;
                break;
            }
        }

        if (invalid) {
            cout << "\nНеверный ввод. Попробуйте снова!\n";
            continue;
        }

        try {
            long long tempChoice = stoll(input);

            if (tempChoice < 0 || tempChoice > UINT_MAX) {
                cout << "\nЧисло слишком велико или мало для выбора действия. Попробуйте снова!\n";
                continue;
            }

            choice = static_cast<unsigned int>(tempChoice);
        }
        catch (const out_of_range&) {
            cout << "\nЧисло слишком велико. Попробуйте снова!\n";
            continue;
        }
        catch (const invalid_argument&) {
            cout << "\nНеверный ввод. Попробуйте снова!\n";
            continue;
        }

        company.tab_line();

        switch (choice) {
        case 1:
            company.cls();
            if (company.factoryCount < max_items) {
                cout << "Введите через пробел имя завода, колво ноутбуков производимых в месяц, зп работника, колво работников: ";
                cin >> name;
                cin >> production;
                cin >> salary;
                cin >> workers;
                if (production < 0 || salary < 0 || workers < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.AddFactory(name, production, salary, workers);
            }
            else {
                cout << "Лимит заводов достигнут.\n";
            }
            break;
        case 2:
            company.cls();
            if (company.supplierCount < max_items) {
                cout << "Введите через пробел имя поставщика, стоимость поставщика: ";
                cin >> name;
                cin >> cost;
                if (cost < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.AddSupplier(name, cost);
            }
            else {
                cout << "Лимит поставщиков достигнут.\n";
            }
            break;
        case 3:
            company.cls();
            if (company.salesPointCount < max_items) {
                cout << "Введите через пробел название точки продаж, цену одного ноутбука: ";
                cin >> name;
                cin >> price;
                if (price < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.AddSalesPoint(name, price);
            }
            else {
                cout << "Лимит точек продаж достигнут.\n";
            }
            break;
        case 4:
            company.cls();
            if (company.equipmentFactoryCount < max_items) {
                cout << "Введите через пробел название точки продаж, цену оборудования: ";
                cin >> name;
                cin >> cost;
                if (cost < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.AddEquipmentFactory(name, cost);
            }
            else {
                cout << "Лимит заводов оборудования достигнут.\n";
            }
            break;
        case 5:
            company.cls();
            if (company.accessoryCount < max_items) {
                cout << "Введите название аксессуара, стоимость, количество аксессуаров: ";
                cin >> name;
                cin >> price;
                cin >> production;
                if (production < 0 || price < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.AddAccessory(name, price, production);
            }
            else {
                cout << "Лимит аксессуаров достигнут.\n";
            }
            break;
        case 6:
            company.cls();
            cout << "Ваши заводы:\n";
            company.print_Factory();
            if (company.factoryCount > 0) {
                cout << "Введите имя завода для удаления: ";
                cin >> name;
                company.RemoveFactory(name);
            }
            else {
                cout << "У вас нет заводов для удаления.\n";
            }
            break;
        case 7:
            company.cls();
            if (company.supplierCount > 0) {
                cout << "Ваши поставщики:\n";
                company.print_Supplier();
                cout << "Введите имя поставщика для удаления: ";
                cin >> name;
                company.RemoveSupplier(name);
            }
            else {
                cout << "У вас нет поставщиков для удаления.\n";
            }
            break;
        case 8:
            company.cls();
            if (company.salesPointCount > 0) {
                cout << "Ваши торговые точки:\n";
                company.print_SalesPoint();
                cout << "Введите название точки продаж для удаления: ";
                cin >> name;
                company.RemoveSalesPoint(name);
            }
            else {
                cout << "У вас нет точек продаж для удаления.\n";
            }
            break;
        case 9:
            company.cls();
            if (company.equipmentFactoryCount > 0) {
                cout << "Ваши заводы оборудования:\n";
                company.print_EquipmentFactory();
                cout << "Введите название завода оборудования для удаления: ";
                cin >> name;
                company.RemoveEquipmentFactory(name);
            }
            else {
                cout << "У вас нет заводов оборудования для удаления.\n";
            }
            break;
        case 10:
            company.cls();
            if (company.accessoryCount > 0) {
                cout << "Ваши аксессуары:\n";
                company.print_Accessory();
                cout << "Введите название аксессуара для удаления: ";
                cin >> name;
                company.RemoveAccessory(name);
            }
            else {
                cout << "У вас нет аксессуаров для удаления.\n";
            }
            break;
        case 11:
            company.cls();
            if (company.factoryCount > 0) {
                cout << "Ваши заводы:\n";
                company.print_Factory();
                cout << "Введите через пробел имя завода которого вы хотите изменить, новое колво ноутбуков производимых в месяц, новая зп работника, новое колво работника: ";
                cin >> name;
                cin >> production;
                cin >> salary;
                cin >> workers;
                if (production < 0 || salary < 0 || workers < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.UpdateFactory(name, production, salary, workers);
            }
            else {
                cout << "У вас нет заводов для обновления.\n";
            }
            break;
        case 12:
            company.cls();
            if (company.supplierCount > 0) {
                cout << "Ваши поставщики:\n";
                company.print_Supplier();
                cout << "Введите через пробел имя поставщика, новую стоимость поставщика: ";
                cin >> name;
                cin >> cost;
                if (cost < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.UpdateSupplierCost(name, cost);
            }
            else {
                cout << "У вас нет поставщиков для обновления.\n";
            }
            break;
        case 13:
            company.cls();
            if (company.salesPointCount > 0) {
                cout << "Ваши торговые точки:\n";
                company.print_SalesPoint();
                cout << "Введите через пробел название точки продаж, новую цену одного ноутбука: ";
                cin >> name;
                cin >> price;
                company.UpdateSalesPoint(name, price);
                if (price < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
            }
            else {
                cout << "У вас нет точек продаж для обновления.\n";
            }
            break;
        case 14:
            company.cls();
            if (company.equipmentFactoryCount > 0) {
                cout << "Ваши заводы оборудования:\n";
                company.print_EquipmentFactory();
                cout << "Введите через пробел название точки продаж, новую цену оборудования: ";
                cin >> name;
                cin >> cost;
                if (cost < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.UpdateEquipmentFactory(name, cost);
            }
            else {
                cout << "У вас нет заводов оборудования для обновления.\n";
            }
            break;
        case 15:
            company.cls();
            if (company.accessoryCount > 0) {
                cout << "Ваши аксессуары:\n";
                company.print_Accessory();
                cout << "Введите название аксессуара, новую стоимость, новое количество аксессуаров: ";
                cin >> name;
                cin >> price;
                cin >> production;
                if (production < 0 || price < 0) {
                    cout << "Минусовые значения/буквы для числа запрещены.\n";
                    break;
                }
                company.UpdateAccessory(name, price, production);
            }
            else {
                cout << "У вас нет аксессуаров для обновления.\n";
            }
            break;
        case 16:
            company.print_Factory_show();
            break;
        case 17:
            company.print_Supplier_show();
            break;
        case 18:
            company.print_SalesPoint_show();
            break;
        case 19:
            company.print_Equipment_Factory_show();
            break;
        case 20:
            company.print_Accessory_show();
            break;
        case 21:
            company.print_Factory_Characteristics();
            break;
        case 22:
            company.print_Supplier_Characteristics();
            break;
        case 23:
            company.print_Sales_Point_Characteristics();
            break;
        case 24:
            company.print_Equipment_Factory_Characteristics();
            break;
        case 25:
            company.print_Accessory_Characteristics();
            break;
        case 26:
            company.Finance();
            break;
        case 27:
            cout << "Выход.\n";
            return 0;
        case 28:
            system("cls");
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова!\n";
            break;
        }
    }
}
