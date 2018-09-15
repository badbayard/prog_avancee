#include <iostream>

template <typename T = int, unsigned int Size = 10>
class Tableau {
    private:
        T* data = nullptr;
        unsigned int length = 0;
        unsigned int max_length = Size;

        static unsigned int instance_count;

        void init(unsigned int allocate = Size) {
            data = new T[allocate];
            instance_count++;
        }

        void resize(unsigned int add = Size) {
            max_length += add;
            T* tmp = new T[max_length];
            for (unsigned int i = 0; i < length; i++) {
                tmp[i] = data[i];
            }
            delete [] data;
            data = tmp;
        }

        void clear() {
            delete [] data;
            data = nullptr;
            length = 0;
            max_length = Size;
        }

    public:
        Tableau() {
            init();
        }

        Tableau(const T* tab, unsigned int tab_size) {
            init();
            for (unsigned int i = 0; i < tab_size; i++) {
                insert(tab[i]);
            }
        }

        Tableau(const Tableau<T,Size>& tab) {
            init();
            for (unsigned int i = 0; i < tab.size(); i++) {
                insert(tab[i]);
            }
        }

        Tableau& operator = (const Tableau&<T,Size> tab) {
            if (data != nullptr) {
                clear();
            } else {
                instance_count++;
            }

            data = new T[Size];
            for (unsigned int i = 0; i < tab.size(); i++) {
                insert(tab[i]);
            }

            return *this;
        }

        ~Tableau() {
            clear();
            instance_count--;
        }

        void insert(const T& e) {
            if (length == max_length) {
                resize();
            }
            data[length] = e;
            length++;
        }

        unsigned int size() const {
            return length;
        }

        unsigned int max_size() const {
            return max_length;
        }

        T& operator [] (int i) {
            return data[i];
        }

        const T& operator [] (int i) const {
            return (const T&) data[i];
        }

        friend std::ostream& operator << (std::ostream& out, const Tableau& tab) {
            out << "[";
            for (unsigned int i = 0; i < tab.size(); i++) {
                out << " " << tab[i];
            }
            out << " ]";
            return out;
        }

        void print_instance_details(const char* const& instance_name = "this") {
            std::cout << instance_name << ": " << *this << " (" << size() << "/" << max_size() << " element(s))" << std::endl;
        }

        static unsigned int count_instances() {
            return instance_count;
        }
};

template <typename T, unsigned int Size>
unsigned int Tableau<T, Size>::instance_count = 0;

int main () {
    std::cout << std::endl << "=============== START ===============" << std::endl;
    Tableau<int, 5> t1;
    t1.print_instance_details("t1");
    t1.insert(1);
    t1.insert(2);
    t1.insert(3);
    t1.print_instance_details("t1");

    const int tab[] = { 0, -1, 5, -3, 4, 72 };
    Tableau<int, 10> t2(tab, 6);
    t2.print_instance_details("t2");

    Tableau<int, 10> t3(t1);
    Tableau <int, 5>t4(tab, 2);
    t3.print_instance_details("t3");
    t4.print_instance_details("t4");
    t3 = t4;
    t3.print_instance_details("t3");
    t4.print_instance_details("t4");

    Tableau t5 = t2;
    t5.print_instance_details("t5");
    t5[0] = 100;
    // std::cout << "cin >> t5[2] : ";
    // std::cin >> t5[2];
    t5.insert(-22);
    t2.print_instance_details("t2");
    t5.print_instance_details("t5");

    std::cout << std::endl
              << Tableau<int, 5>::count_instances() << " instance(s) of Tableau<int, 5> created";
    std::cout << std::endl
              << Tableau<int, 10>::count_instances() << " instance(s) of Tableau<int, 10> created";
    std::cout << std::endl
              << Tableau<int, 6>::count_instances() << " instance(s) of Tableau<int, 6> created";
    std::cout << std::endl << "================ END ================" << std::endl << std::endl;
    return 0;
}
