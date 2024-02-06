#include <iostream>
#include <vector>

class Worker
{
protected:
    std::string name;

public:
    Worker(std::string n) : name(n) {}

    std::string getName() const 
    { 
        return name; 
    }
};

class Department
{
private:
    std::vector<Worker> workers;

public:

    void add(const Worker& worker)
    {
        workers.push_back(worker);
    }


    friend std::ostream& operator<<(std::ostream& out, const Department& department)
    {
        out << "Працівники відділу: ";
        for (const Worker& worker : department.workers)
        {
            out << worker.getName() << ", ";
        }
        out << "\n";
        return out;
    }
};

int main()
{
    system("chcp 1251 > null");

    Worker w1("Антін");
    Worker w2("Івасик");
    Worker w3("Євген");
    Worker w4("Їржик");

    {
        Department department; 
        department.add(w1);
        department.add(w2);
        department.add(w3);
        department.add(w4);

        std::cout << department;
    } 

    std::cout << w1.getName() << " досі працює!\n";
    std::cout << w2.getName() << " досі працює!\n";
    std::cout << w3.getName() << " досі працює!\n";
    std::cout << w4.getName() << " досі працює!\n";

    return 0;
}
