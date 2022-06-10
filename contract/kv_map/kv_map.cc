#include <chainsql/contract.h>
#include <chainsql/map.h>
#include <chainsql/array.h>
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

        // test map
        {
            persons[1] = {"peersafe", "inc", 10};
            persons[2] = {"zongxiang", "inc", 12};

            chainsql::check(persons.contains(1), "persion's 1 exits");
            chainsql::check(persons.contains(2), "persion's 2 exits");

            chainsql::check(persons.contains(3) == false, "persion's 3 not exits");

            {
                person p = persons[1].element.value;
                chainsql::check(
                    (p.name == "peersafe" && p.title == "inc" && p.age == 10),
                    "mismatch p[1] in a map");
            }

            {
                person p = persons[2].element.value;
                chainsql::check(
                    (p.name == "zongxiang" && p.title == "inc" && p.age == 12),
                    "mismatch p[2] in a map");
            }

            persons.erase(1);
            chainsql::check(persons.contains(1) == false, "persion's 1 not exits after erasing");
        }

        // test array
        {
            chainsql::kv::array<chainsql::name("test.array"), person> vec;
            vec.append({"peersafe", "inc", 10});
            vec.append({"zongxiang", "inc", 12});

            chainsql::check(vec.size() == 2, "array's size should be 2");

            chainsql::check(vec.contains(0), "persion's 0 exits");
            chainsql::check(vec.contains(1), "persion's 1 exits");
            chainsql::check(vec.contains(2) == false, "persion's 2 not exits");

            {
                person p = vec[0].element.value;
                chainsql::check(
                    (p.name == "peersafe" && p.title == "inc" && p.age == 10),
                    "mismatch p0"
                );
            }

            {
                person p = vec[1].element.value;
                chainsql::check(
                    (p.name == "zongxiang" && p.title == "inc" && p.age == 12),
                    "mismatch p1"
                );
            }

            vec.remove(0);
            chainsql::check(vec.size() == 1, "array's size should be 1");
            {
                person p = vec[0].element.value;
                chainsql::check(
                    (p.name == "zongxiang" && p.title == "inc" && p.age == 12),
                    "mismatch p[0] in an array"
                );
            }
        }
    }

private:
    chainsql::kv::map<chainsql::name("person"), int, person> persons;
};