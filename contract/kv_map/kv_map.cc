#include <chainsql/contract.h>
#include <chainsql/map.h>
#include <chainsql/check.h>
#include <chainsql/print.h>

struct person {
    std::string name;
    std::string title;
    int age;
};

class [[chainsql::contract]] kv_map : public chainsql::contract {
public:
    using contract::contract;

    [[chainsql::action]]
    void test() {
        persons[1] = {"peersafe", "inc", 10};
        persons[2] = {"zongxiang", "inc", 12};

        chainsql::check(persons.contains(1), "persion's 1 exits");
        chainsql::check(persons.contains(2), "persion's 2 exits");

        chainsql::check(persons.contains(3) == false, "persion's 3 not exits");

        {
            person p = persons[1].element.value;
            chainsql::print_f("1: name = %, title = %, age = % \n", p.name, p.title, p.age);
        }

        {
            person p = persons[2].element.value;
            chainsql::print_f("2: name = %, title = %, age = % \n", p.name, p.title, p.age);
        }
    }

private:
    chainsql::kv::map<chainsql::name("person"), int, person> persons;
};