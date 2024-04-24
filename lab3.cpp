#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    double salary;
    double experience;
public:
    Employee(const std::string& _name, double _salary, double _experience)
        : name(_name), salary(_salary), experience(_experience) {}

    virtual double calculateSalary() {
        return salary + salary * (experience * 0.01);
    }

    virtual void printInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Experience: " << experience << " years" << std::endl;
    }
};

class DepartmentManager : public Employee {
private:
    double managerBonus;
    std::string departmentName;
public:
    DepartmentManager(const std::string& _name, double _salary, double _experience, double _managerBonus, const std::string& _departmentName)
        : Employee(_name, _salary, _experience), managerBonus(_managerBonus), departmentName(_departmentName) {}

    double calculateSalary() override {
        return Employee::calculateSalary() + salary * (managerBonus * 0.01);
    }

    void printInfo() override {
        Employee::printInfo();
        std::cout << "Department: " << departmentName << std::endl;
        std::cout << "Manager Bonus: " << managerBonus << "%" << std::endl;
    }
};

int main() {
    // Создание объектов
    Employee employee("John Doe", 50000, 5);
    DepartmentManager manager("Alice Smith", 70000, 8, 10, "Marketing");

    // Статический полиморфизм
    std::cout << "Static Polymorphism:" << std::endl;
    std::cout << "Employee's Salary: " << employee.calculateSalary() << std::endl;
    employee.printInfo();

    std::cout << std::endl;

    std::cout << "Department Manager's Salary: " << manager.calculateSalary() << std::endl;
    manager.printInfo();

    std::cout << std::endl;

    // Динамический полиморфизм
    std::cout << "Dynamic Polymorphism:" << std::endl;
    Employee* empPtr = &employee;
    std::cout << "Employee's Salary: " << empPtr->calculateSalary() << std::endl;
    empPtr->printInfo();

    std::cout << std::endl;

    empPtr = &manager;
    std::cout << "Department Manager's Salary: " << empPtr->calculateSalary() << std::endl;
    empPtr->printInfo();

    return 0;
}
