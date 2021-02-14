#include <iostream>
#include <unordered_map>
#include <set>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

[[maybe_unused]] void TestOneArray() {
#if 0
    int students_score[5] = {15, 33, 44, 22, 66};
    for (int i = 0; i < sizeof(students_score) / sizeof(students_score[0]); ++i) {
        std::cout << students_score[i] << std::endl;
    }
#endif
}

int* GenerateTestOneArray(const int& size) {
    int* students_score = new int[size]{15, 33, 44, 22, 66};
    return students_score;
}


[[maybe_unused]] int* TestOneArrayAppend(const int& score, const int arrLength) {
    int* oldScores = GenerateTestOneArray(arrLength);
    int* newScores = new int[arrLength + 1];
    for (int i = 0; i < arrLength; ++i) {
        newScores[i] = oldScores[i];
    }
    newScores[arrLength] = score;
    delete[] oldScores;
    return newScores;
}

struct r {
public:
    void x() {
        std::cout << "x called" << std::endl;
    }
};


#include "vector"

[[maybe_unused]] void TakeUnlimitedValuesFromTheUser() {
    std::vector<int> vec;
    r _r{};
    _r.x();
    // read integers 1 at a time from the user,
    // will stop when non-integer input is entered
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(vec));

    // print out the vector
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

[[maybe_unused]] int* TestOneArrayInsert(const int& value, int index, int arrLength) {
    if (index <= 0 || index > arrLength + 1) {
        return nullptr;
    }
    int* oldScores = GenerateTestOneArray(arrLength);
    int* newScores = new int[arrLength + 1];
    --index;
    for (int i = 0; i < arrLength + 1; ++i) {
        if (i < index) {
            newScores[i] = oldScores[i];
        } else if (i == index) {
            newScores[i] = value;
        } else {
            newScores[i] = oldScores[i - 1];
        }
    }
    delete[] oldScores;
    return newScores;
}

[[maybe_unused]] int* TestOneArrayDelete(int index, int arrLength) {
    if (index <= 0 || index > arrLength) {
        return nullptr;
    }
    int* oldScores = GenerateTestOneArray(arrLength);
    int* newScores = new int[arrLength - 1];
    --index;
    for (int i = 0; i < arrLength; ++i) {
        if (i < index) {
            newScores[i] = oldScores[i];
        } else if (index == i) {
            continue;
        } else {
            newScores[i - 1] = oldScores[i];
        }
    }
    delete[] oldScores;
    return newScores;
}

[[maybe_unused]] std::vector<int> test1() {
    std::vector<int> t;
    t.emplace_back(1);
    t.emplace_back(3);
    return t;
}

[[maybe_unused]] std::vector<int>& test2(std::vector<int>& t) {
    //never use a local value to send outside. it can cause dangling problem!
    t.emplace_back(4);
    t.emplace_back(5);
    return t;
}

[[maybe_unused]] void test3(std::vector<int>& t) {
    t.emplace_back(6);
    t.emplace_back(7);
}

[[maybe_unused]] void test4(std::vector<int> t) {
    t.emplace_back(60);
    t.emplace_back(70);
}


[[maybe_unused]] void bubble_sort(int elements[], int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        for (int j = 0; j < arrLen - 1 - i; j++) {
            if (elements[j] > elements[j + 1]) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}


typedef struct Node {
    std::string data;
    struct Node* next;
} Node;

Node* _head;
Node* _tail;

Node* addNewNode(Node* currentNode, const std::string& data) {
    if (currentNode != nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        currentNode->next = newNode;
        newNode->next = nullptr;
        _tail = newNode;
        return newNode;
    } else {
        _head = new Node();
        _head->data = data;
        _head->next = nullptr;
        _tail = _head;
        return _head;
    }
}

void PrintAllLinkedList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

void FreeAllLinkedList() {
    Node* p = _head;
    Node* temp;
    while (p != nullptr) {
        temp = p;
        p = p->next;
        delete temp;
    }
    _head = nullptr;
    _tail = nullptr;
    std::cout << "all deleted!" << std::endl;
}

template<typename T, typename R>
void showListAndSize(T list[], R length) {
    std::cout << "length as parameter : " << length << std::endl;
    for (int i{0}; i < length; ++i) {
        std::cout << list[i] << std::endl;
        if (list[i] == 0) {
            list[i] = i * 2;
        }
    }
}

template<typename T>
void printAll(T list[], const int length, const std::string& seperator = "", bool lineByLine = true) {
    for (int i = 0; i < length; ++i) {
        if (lineByLine) {
            std::cout << list[i] << std::endl;
        } else {
            std::cout << list[i] << ((i == length - 1) ? "" : seperator);
        }
    }
    if (length != 0 && !lineByLine) {
        std::cout << std::endl;
    }
}

template<typename T>
T* updateMe(T list[], const int length) {
    for (int i = 0; i < length; ++i) {
        list[i] = i * 5;
    }
    return list;
}

template<typename T>
T* updateMe_WRONG_1(const int length) {
    T list[length]; // there is no new operator.. it means that you'll send an address that belong a invalid stack !
    for (int i = 0; i < length; ++i) {
        list[i] = i * 10;
    }
    return list;
}

template<typename T>
T* updateMe_CORRECT_1(const int length) {
    T* list = new int[length];
    for (int i = 0; i < length; ++i) {
        list[i] = i * 10;
    }
    return list;
}

void sortArr(int list[], const int arrLength) {
    for (int i = 0; i < arrLength; ++i) {
        for (int j = 0; j < arrLength - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(const int items[], const int itemsLength, const int search) {
    if (itemsLength == 0) return -1;
    int left = 0;
    int right = itemsLength - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        //std::cout << "left " << left << ", right : " << right << ", middle : " << middle << std::endl;
        if (items[middle] == search) {
            return middle;
        }
        if (search < items[middle]) {
            right = --middle;
        } else {
            left = ++middle;
        }
    }
    return -1;
}

void rotateToLeft(int list[], const int arrLen, int rotateCount) {
    if (arrLen == 0 || rotateCount <= 0) return;
    while (rotateCount-- != 0) {
        int first = list[0];
        for (int i = 0; i < arrLen - 1; ++i) {
            list[i] = list[i + 1];
        }
        list[arrLen - 1] = first;
    }
}

void rotateToRight(int list[], const int arrLen, int rotateCount) {
    if (arrLen == 0 || rotateCount <= 0) return;
    while (rotateCount-- != 0) {
        int last = list[arrLen - 1];
        for (int i = arrLen - 1; i > 0; --i) {
            list[i] = list[i - 1];
        }
        list[0] = last;
    }
}

int maxSubArraySum(const std::vector<int>& a) {
    int maxSoFar = 0, maxEndingHere = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] > 0) {
            maxEndingHere = maxEndingHere + a[i];
        } else {
            maxEndingHere = 0;
        }
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

void simpleDoublerForEven(int list[], const int arrLength) {
    int end = arrLength - 1;
    for (int i = arrLength - 1; i >= 0; i--) {
        if (list[i] == -1) continue;
        list[end] = list[i];
        if (list[i] % 2 == 0) {
            list[end - 1] = list[i];
            end--;
        }
        end--;
    }
}

void simpleZeroRightShifter(int list[], const int arrLength) {
    for (int i = arrLength - 1; i >= 0; i--) {
        if (list[i] != 0) continue;
        for (int j = i; j < arrLength - 1; ++j) {
            list[j] = list[j + 1];
        }
        list[arrLength - 1] = 0;
    }
}

template<typename T>
void print_arr(const T* elements, size_t size) {
    while (size--) {
        std::cout << *elements++ << std::endl;
    }
    std::cout << "\n--------------------------------------\n";
}


template<typename T>
void reverse(T elements[], const int size) {
    if (size <= 0) return;
    for (int i = 0; i < size / 2; ++i) {
        int temp = elements[i];
        elements[i] = elements[size - i - 1];
        elements[size - i - 1] = temp;
    }
}

std::string FindSumArrayTarget(int elements[], const size_t arrLength, const int target) {
    std::string result = "[]";
    if (arrLength <= 0) return result;
    size_t startIndex = 0, end = 0, total = elements[startIndex];
    while (startIndex < arrLength - 1) {
        if (startIndex > end) {
            end = startIndex;
            total = elements[startIndex];
        }
        if (total < target) {
            if (end == arrLength - 1) {
                break;
            }
            end++;
            total += elements[end];
        } else if (total > target) {
            total -= elements[startIndex];
            startIndex++;
        } else {
            return "[" + std::to_string(elements[startIndex]) + "," + std::to_string(elements[end]) + "]";
        }
    }
    return result;
}

/*
std::string sumSubArrayToZero(int elements[], size_t arrLength) {
    std::string result = "";
    if (arrLength <= 0)return result;
    int sum = 0, target = 0;
    std::unordered_map<int, int> map = {};
    for (int i = 0; i < arrLength - 1; ++i) {
        sum += elements[i];
        if (sum == target) {
            return "[0," + std::to_string(i) + "]";
        }
        if (map.contains(sum)) {
            return "[" + std::to_string(map[sum] + 1) + "," + std::to_string(i) + "]";
        }
        map[sum] = i;
    }
    return result;
}
*/

int BinarySearchUpgraded(int elements[], size_t arrLength, const int target) {
    if (arrLength <= 0) return -1;
    int low = 0, high = arrLength - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;// Bug! (low + high) / 2;
        if (elements[mid] == target) {
            return mid;
        } else if (elements[mid] < target) {
            low = ++mid;
        } else {
            high = ++mid;
        }
    }
    return -1;
}


int BinarySearchRecFIMostLeft(int arr[], int low, int high, int search) {
    if (low > high)
        return -1;
    int middle = low + (high - low) / 2;
    if (arr[middle] == search && (middle == 0 || arr[middle - 1] != search)) {
        return middle;
    }
    if (arr[middle] >= search)
        return BinarySearchRecFIMostLeft(arr, low, middle - 1, search);
    return BinarySearchRecFIMostLeft(arr, middle + 1, high, search);
}

int BinarySearchRecFIMostRight(int arr[], int low, int high, int search, int arrLen) {
    if (low > high)
        return -1;
    int middle = low + (high - low) / 2;
    if (arr[middle] == search && (middle == arrLen - 1 || arr[middle + 1] != search)) {
        return middle;
    }
    if (arr[middle] > search)
        return BinarySearchRecFIMostRight(arr, low, middle - 1, search, arrLen);
    return BinarySearchRecFIMostRight(arr, middle + 1, high, search, arrLen);
}

int BinarySearchRecFITotal(int arr[], int low, int high, int search, int arrLen, int total = 0) {
    int sum = (BinarySearchRecFIMostRight(arr, low, arrLen, search, arrLen) -
               BinarySearchRecFIMostLeft(arr, low, arrLen, search));
    return (sum == 0 ? -1 : sum) + 1;
}

int FirstOccurenceFinder(int elements[], size_t arrLength, const int target) {
    if (arrLength <= 0) return -1;
    int low = 0, high = arrLength - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;// Bug! (low + high) / 2;
        if ((elements[mid] > target) ||
            (elements[mid] == target && mid > 0 && elements[mid - 1] == target)) {
            high = --mid;
        } else if (elements[mid] < target) {
            low = ++mid;
        } else if (elements[mid] == target) {
            return mid;
        }
    }
    return -1;
}

int FindClosestFinder(int elements[], size_t arrLength, const int target) {
    if (arrLength <= 0) return -1;
    int low = 0, high = arrLength - 1;
    int min = elements[low + (high - low) / 2];
    auto setMin = [&](const int mid) {
        if (abs(target - elements[mid]) < abs(target - min)) {
            min = elements[mid];
        }
    };
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (elements[mid] > target) {
            setMin(mid);
            high = --mid;
        } else if (elements[mid] < target) {
            setMin(mid);
            low = ++mid;
        } else if (elements[mid] == target) {
            return mid;
        }
    }
    return min;
}

#include <math.h>

void Sort(int elements[], size_t arrLength) {
    for (int i = 0; i < arrLength - 1; ++i) {
        for (int j = 0; j < arrLength - i - 1; ++j) {
            if (elements[j] > elements[j + 1]) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

class T {
public :
    void func(int) {

    }

    void func(uint);

    void func(double) {

    }
};

void T::func(uint number) {
    std::cout << number << std::endl;
}

/*
std::unordered_map<int, int> values;

int tailFact(int t) {
    if (t == 0) return 1;
    if (::values.contains(t - 1)) {
        return ::values[t - 1] * tailFact(--t);
    }
    ::values[t] = t * tailFact(--t);
    return ::values[t];
}
*/
#include <chrono>

unsigned long long FactTR(unsigned int a, unsigned long long val) {
    if (a == 0) return val;
    return FactTR(a - 1, a * val);
}

unsigned long long FastFactCalculator(unsigned int val) {
    auto start = std::chrono::high_resolution_clock::now();
    auto res = FactTR(val, 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nTotal Execution Time (FastFactCalculator) : " << duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns Result " << res << std::endl;
    return res;
}

unsigned long long int SlowFactCalcLinear(const unsigned int val) {
    auto start = std::chrono::high_resolution_clock::now();
    std::unordered_map<int, unsigned long long> mapCalc;
    mapCalc[0] = 1;
    for (int j = 1; j <= val; ++j) {
        unsigned long long int calcResult = mapCalc[j - 1] * j;
        mapCalc[j] = calcResult;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nTotal Execution Time (SlowFactCalcLinear) : " << duration_cast<std::chrono::microseconds>(end - start).count() << " ms, Result " << mapCalc[val] << std::endl;
    return mapCalc[val];
}

#include <cstdio>

int arrE[100];

void enumerate(int element, int n) {
    if (element > n) { // Base case
        for (int i = 1; i <= n; i++)
            std::cout << arrE[i];
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        arrE[element] = i;
        enumerate(element + 1, n);
    }
}

void callAsArr(int elements[], size_t arrLength) {
    for (int i = 0; i < arrLength; ++i) {
        std::cout << elements[i] << std::endl;
    }
}

void Permutation(int* elements, size_t arrLength) {
    std::sort(elements, elements + arrLength);
    do {
        std::cout << elements[0] << elements[1] << elements[2] << std::endl;
    } while (std::next_permutation(elements, elements + arrLength));
}

#include <list>

void deleteAndInsert() {
    std::list<int> iList{2, 5, 4, 3, 7, 8, 1, 6, 12, 21, 87, 10};
    // if it's even delete else duplicate
    int index = 0;
    for (auto it = iList.cbegin(); it != iList.cend();) {
        if (*it % 2 == 0) {
            it = iList.erase(it);
        } else {
            it = iList.insert(it, *it);
            advance(it, 2);
        }
    }
    for (const auto& item : iList) {
        std::cout << item << std::endl;
    }
}


struct tr {
public:
    int my;
    int mx;
};

struct S {

private:
    std::string _testValue;
public:
    S(const std::string& testValue) : _testValue(testValue) {
        puts("S()");
    }

    S(const S&) {
        puts("S(const S &)");
    }

    S(S&&) noexcept {
        puts("S(S &&)");
    }

    S& operator=(const S&) {
        puts("operator=(const S &)");
        return *this;
    }

    S& operator=(S&&) {
        puts("operator=(S &&)");
        return *this;
    }

    ~S() {
        puts("~S()");
    }

    const std::string& getTestValue() const {
        return _testValue;
    }

    void setTestValue(const std::string& testValue) {
        _testValue = testValue;
    }

    bool operator==(const S& rhs) const {
        return _testValue == rhs._testValue;
    }

    bool operator!=(const S& rhs) const {
        return !(rhs == *this);
    }
};

class gg {
public:
    gg(const std::string& name) : _name(name) {

    }

    virtual ~gg() {
        std::cout << "deleted" << std::endl;
    }

    const std::string& getName() const {
        return _name;
    }

    void setName(const std::string& name) {
        _name = name;
    }

    bool operator==(const gg& rhs) const {
        return _name == rhs._name;
    }

    bool operator!=(const gg& rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream& operator<<(std::ostream& os, const gg& gg) {
        return os << "_name: " << gg._name;
    }

private:
    std::string _name;

};

struct M {
private:
    [[maybe_unused]] int _mValue;
public:
    M() : _mValue(0) {}

    M(const int mValue) : _mValue(mValue) {

    }
};

#include <cstring>

class xx {
    xx(const int& x) = delete;

    xx() {

    }
};
// ******************************************************************************************** //

class Person {
private:
    int _id{0};
    char* _p{nullptr};
public:
    //copy ctor
    Person(const Person& other);

    //move ctor
    Person(Person&& other) noexcept;

    //copy assignment
    Person& operator=(const Person& other);
    ////////////////////////////////////////////////////////////////// merge for copy + move assigment   Person& operator=(Person other);
    ////////////////////////////////////////////////////////////////// for swap -> void swap_z(Person& other);

    //move assigment
    Person& operator=(Person&& other) noexcept;


    Person(const char* p, int id);

    ~Person();

    int getId() const {
        return _id;
    }

    void setId(int id) {
        _id = id;
    }

    char* getP() const {
        return _p;
    }

    void setP(char* p) {
        _p = p;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    operator std::string() const;

    void Print() const;

    Person operator+(const Person& other) const;

};

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  //
//copy ctor
Person::Person(const Person& other) : _id{other._id} {
    std::cout << "copy ctor" << std::endl;
    _p = static_cast<char*>(std::malloc(std::strlen(other.getP()) + 1));
    if (!_p) {
        std::cerr << " not enough memory " << std::endl;
        std::exit(EXIT_FAILURE);
    }
    ////////////////std::cout << "Record storage has been allocated successfully! The memory address : " << static_cast<void*>(_p) << std::endl;
    strcpy(_p, other.getP());
}

//move ctor
Person::Person(Person&& other) noexcept: _p(other.getP()), _id(other.getId()) {
    std::cout << "move ctor" << std::endl;
    other.setP(nullptr);
}


//custom ctor
Person::Person(const char* p, int id) : _id{id} {
    std::cout << "custom ctor" << std::endl;
    _p = static_cast<char*>(std::malloc(std::strlen(p) + 1));
    if (!_p) {
        std::cerr << " not enough memory " << std::endl;
        std::exit(EXIT_FAILURE);
    }
    /////////////std::cout << "Record storage has been allocated successfully! The memory address : " << static_cast<void*>(_p) << std::endl;
    strcpy(_p, p);
}

void Person::Print() const {
    std::cout << "name : " << _p << " , id : " << _id << std::endl;
}

//copy assignment

Person& Person::operator=(const Person& other) {
    std::cout << "copy assignment" << std::endl;
    if (this != &other) {
        // to prevent self assigment!
        _id = other.getId();
        std::free(_p);
        _p = static_cast<char*>(std::malloc(std::strlen(other.getP()) + 1));
        if (!_p) {
            std::cerr << " not enough memory " << std::endl;
            std::exit(EXIT_FAILURE);
        }
        strcpy(_p, other.getP());
    }
    return *this;
}

//swap_z
//Person& Person::operator=(Person other) {
//    std::cout << "copy & swap_z " << std::endl;
//    swap_z(other);
//    return *this;
//}
/***************************************** */
//void Person::swap_z(Person& other) {
//    std::swap_z(_id, other._id);
//    std::swap_z(_p, other._p);
//}
/***************************************** */


Person& Person::operator=(Person&& other) noexcept {
    std::cout << "move assignment" << std::endl;
    if (this != &other) {
        // to prevent self assigment!
        std::free(_p);
        _p = other.getP();
        _id = other.getId();
        //reset
        other.setId(0);
        other.setP(nullptr);
    }
    return *this;
}


//destructor
Person::~Person() {
    std::cout << "destructor" << std::endl;
    if (_p) {
        //std::cout << "The memory address of destructing object is " << static_cast<void*>(_p) << std::endl;
        std::free(_p);
    }
}

Person::operator std::string() const {
    return std::string(_p);
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    return os << "Person Data : " << std::string(person) << std::endl;
}

Person Person::operator+(const Person& other) const {
    if (this == &other) {
        return *this;
    }
    return Person((std::string(*this) + "_" + std::string(other.getP())).c_str(), 1);
}


//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  //

// ******************************************************************************************** //

void PrintP_Wrong(Person p) {
    std::cout << "person is printing.. " << std::endl;
    p.Print();
    getchar(); // p will be destruct!!!
}

void PrintP(const Person& p) {
    std::cout << "person is printing.. " << std::endl;
    p.Print();
    getchar();
}

int Simple_B1(const int& val) {
    if (val == 0) return 1;
    return 2;
}

int& Simple_B2(const int& val) {
    int a = val;
    if (val % 2 == 0) return a;
    return ++a;
}


int&& Simple_B3(const int& val) {
    int a = val;
    if (val % 2 == 0) return std::move(a);
    return std::move(++a);
}

int&& Simple_B4(const int& val) {
    int a = val;
    if (val % 2 == 0) return int(a);
    return int(++a);
}

int sm(const int&& val) {
    if (val % 2 == 0) return 1;
    else return 3;
}


// *********************************************************************************************** */
class num {
private:
    int _value{0};
public:

    num(const int& val);

    num& operator++();

    num operator++(int);

    num& operator--();

    num operator--(int);

    friend std::ostream& operator<<(std::ostream& os, const num& num);

    operator std::string() const;
};

num& num::operator++() {
    ++_value;
    return *this;
}

num num::operator++(int) {
    num temp = *this;
    _value++;
    return temp;
}

num& num::operator--() {
    --_value;
    return *this;
}

num num::operator--(int) {
    num temp = *this;
    temp._value++;
    return temp;
}

num::operator std::string() const {
    return std::to_string(this->_value);
}

num::num(const int& value) {
    _value = value;
}

std::ostream& operator<<(std::ostream& os, const num& num) {
    return os << std::string(num);
}
// *********************************************************************************************** */


int&& simpleMath(int& value) {
    int temp = value;
    std::cout << "address of temp             " << &temp << std::endl;
    return std::move(++temp);
}

class xf {
private:
    std::string _name;
public:
    explicit xf(const std::string&);

    explicit xf(const char*&);

    explicit xf(char*&&) noexcept;

    void print() const;
};

xf::xf(const std::string& value) {
    std::cout << "xf::xf(const std::string&)" << std::endl;
    _name = value;
}

void xf::print() const {
    std::cout << _name << std::endl;
}

xf::xf(const char*& value) {
    std::cout << "xf::xf(const char*&)" << std::endl;
    _name = std::string(value);
}

xf::xf(char*&& value) noexcept {
    std::cout << "xf::xf(const char*&&)" << std::endl;
    _name = std::string(std::move(value));
}

int generateError(const int&& numerator, int&& denominator) {
    if (denominator == 0)
        throw std::overflow_error("Divide by Zero exception { manual! }");
    return numerator / denominator;
}

#include <stdexcept>

class MF {
private:
    int _value = {0};
public:
    MF() = default;

    MF(const int&);

    MF(const MF& cOther);

    MF(MF&& mOther) noexcept;

    MF& operator=(const MF& cOther);

    MF& operator=(MF&& mOther) noexcept;

    virtual ~MF();

    int getValue() const;

    void setValue(int value);
};

MF::MF(const int& val) {
    _value = val;
}

int MF::getValue() const {
    return _value;
}

void MF::setValue(int value) {
    _value = value;
}

MF::~MF() {
    std::cout << "MF::~MF()" << std::endl;
};

MF::MF(const MF& cOther) {
    std::cout << "MF::MF(const MF& cOther)" << std::endl;
    _value = cOther.getValue();
}

MF::MF(MF&& mOther) noexcept {
    std::cout << "MF::MF(MF&& mOther)" << std::endl;
    *this = std::move(mOther);
}

void PrintMF(MF mf) {
    std::cout << "My value : " << mf.getValue() << std::endl;
}

MF& MF::operator=(const MF& cOther) {
    if (this != &cOther) {
        _value = cOther.getValue();
    }
    return *this;
}

MF& MF::operator=(MF&& mOther) noexcept {
    if (this != &mOther) {
        _value = mOther.getValue();
    }
    return *this;
}

typedef MF* MFPointer;
typedef MF& MFRef;


class QQ {
public:
    static QQ __q;
};

class Multiply {
private :
    int _value{1};
    std::string _tempValue;
public :
    Multiply(const int& value) : _value(value) {

    }

    virtual const std::string& speak() {
        return _tempValue;
    }

    virtual ~Multiply() {

    }

    const std::string& getTempValue() const {
        return _tempValue;
    }

    void setTempValue(const std::string& tempValue) {
        _tempValue = tempValue;
    }

    int operator()(const int& value) const {
        return _value * value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Multiply& multiply) {
        os << "_value: " << multiply._value << " _tempValue: " << multiply._tempValue;
        return os;
    }
};

class Ml : public Multiply {
private:
    std::string _n;
public:
    Ml(const std::string& name) : Multiply(1), _n(name) {};

    const std::string& speak() override {
        return Multiply::speak();
    }


};


template<typename T>
void swap_z(T& l, T& r) {
    T temp = std::move(l);
    l = std::move(r);
    //l = (T&&)r;
    //l = static_cast<T&&>(r);
    r = std::move(temp);
}


template<typename T, typename B>
void swap(T&& l, T&& r, B&& pb, const std::function<void(const bool&, const T&, const T&)>& printFunc) {
    printFunc(pb, const_cast<T&>(l), const_cast<T&>(r));
    T temp = l;
    l = r;
    r = temp;
    printFunc(pb, const_cast<T&>(l), const_cast<T&>(r));
}

class test {
public:
    void speak() {
        std::cout << "speak!" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const test& test);
};

int* spliceArr(const int splitArr[], size_t arrLen) {
    if (arrLen == 0) return nullptr;
    int* returnVal = new int[arrLen - 1];
    for (int i = 1; i < arrLen; ++i) {
        returnVal[i - 1] = splitArr[i];
    }
    return returnVal;
}

int recSum(int arrForSum[], size_t arrLen) {
    if (arrLen == 0) return 0;
    if (arrLen == 1) {
        return arrForSum[0];
    }
    int* newArr = spliceArr(arrForSum, arrLen);
    for (int i = 0; i < arrLen - 1; ++i) {
        std::cout << "newArr[" << i << "]:" << newArr[i] << std::endl;
    }
    //delete newArr;
    return arrForSum[0] + recSum(newArr, arrLen - 1);
}

int* quickSort(int arrQ[], size_t arrLen) {
    if (arrLen < 2) {
        return arrQ;
    }
    int arrLeftCnt = 0;
    int arrRightCnt = 0;

    int pivot = arrLen / 2;
    for (int i = 0; i < arrLen; ++i) {
        if (arrQ[i] < arrQ[pivot]) {
            ++arrLeftCnt;
        } else if (arrQ[i] > arrQ[pivot]) {
            ++arrRightCnt;
        }
    }
    int* arrLeft = new int[arrLeftCnt + 1];
    int* arrRight = new int[arrRightCnt];
    arrLeftCnt = 0;
    arrRightCnt = 0;
    for (int i = 0; i < arrLen; ++i) {
        if (arrQ[i] < arrQ[pivot]) {
            arrLeft[arrLeftCnt++] = arrQ[i];
        } else if (arrQ[i] > arrQ[pivot]) {
            arrRight[arrRightCnt++] = arrQ[i];
        }
    }
    arrLeft[arrLeftCnt] = arrQ[pivot];
    arrRightCnt = (arrRightCnt != 0) ? arrRightCnt-- : 0;
    int* left = quickSort(arrLeft, arrLeftCnt);
    int* right = quickSort(arrRight, arrRightCnt);
    int* all = new int[arrLeftCnt + arrRightCnt];
    for (int i = 0; i < arrLeftCnt; ++i) {
        all[i] = left[i];
    }
    for (int i = arrLeftCnt; i < arrLeftCnt + arrRightCnt; ++i) {
        all[i] = right[i];
    }
    return quickSort(all, arrLeftCnt + arrRightCnt);
}

void fx() {
    int vc, vd, xa;
    std::cout << "a:" << xa << std::endl;

}

int strlen(char arrStr[]) {
    int i = 0;
    int result = 0;
    while (arrStr[i++] != '\0') {
        ++result;
    }
    return result;
}

struct baseSame {
    int _x;
};


struct Same : private baseSame {
    int x{0};
    int y{0};
    char t1{'A'};
    char t2{'B'};

    void print() const {
        std::cout << "x: " << x << "\n,y: " << y << "\n";
    }

    void reset() {
        x = {0};
        y = {0};
    }

    Same(int x, int y) : x(x), y(y) {
        std::cout << "custom ctor" << std::endl;
    }

    Same() = default;

    Same(const Same& other) : x(other.x), y(other.y) {
        std::cout << "copy ctor" << std::endl;
    }

    Same(Same&& other) noexcept: x(std::move(other.x)), y(std::move(other.y)) {
        std::cout << "move ctor" << std::endl;
    }

    Same& operator=(Same& other) {
        std::cout << "copy assigment operator" << std::endl;
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Same& operator=(Same&& other) {
        std::cout << "move assigment operator" << std::endl;
        if (this != &other) {
            x = std::move(other.x);
            y = std::move(other.y);
            other.reset();
        }
        return *this;
    }

    operator std::string() {
        return "--->> X:" + std::to_string(x) + ", Y: " + std::to_string(y);
    }
};
//__attribute__((packed));

unsigned int SumForMe(int* numbers, size_t lenForNumbers) noexcept(false) {
    if (lenForNumbers == 0)
        throw std::string("There is no item to sum up!");
    unsigned int total = 0;
    for (int i = 0; i < lenForNumbers - 1; ++i) {
        total += numbers[i];
    }
    if (total < 100) {
        throw total;
    }
    return total;
}

#include <exception>

class MyException : public std::exception {
    std::string _value;
public:
    MyException(const std::string& value) : _value{value} {

    }

    virtual const char* what() const _NOEXCEPT override {
        return _value.c_str();
    }
};

int tt(const std::string& val) noexcept(false) {
    auto len = std::strlen(val.c_str());
    if (len == 0) {
        throw MyException("val length is 0!");
    }
    return len;
}

void tex() {
    int f;

    std::cout << f << "\n";
}

void fxx(int&& par);

void g(int&& x) {
    //fxx(x); // ERROR..
    //fxx(static_cast<int&&>(x));
    //fxx(std::move(x));
}

class ZZ {
private:
    int _a;
public:
    ZZ() = default;

    void printA(const std::string& addComment) {
        std::cout << addComment << ": " << _a << std::endl;
    }
};

template<typename T>
void PrintX(T* arrAll, const size_t& len) {
    for (size_t i = 0; i < len; ++i) {
        std::cout << arrAll[i] << std::endl;
    }
}

#include "assert.h"

template<typename T>
T* copyme(T* s, T* d, size_t len) {
    if (len <= 0) return nullptr;
    T* pret = d;
    while (len--) {
        *d++ = *s++;
    }
    return pret;
}


enum class Test {
    value1, value2, value3
};

std::ostream& operator<<(std::ostream& os, const test& test) {
    os << "_test: " << test;
    return os;
}

class xqqq {
    int _a;
public:
    int getA() const {
        return _a;
    }

    void setA(int a) {
        _a = a;
    }

    friend std::ostream& operator<<(std::ostream& os, const xqqq& xqqq) {
        os << "_a: " << xqqq._a;
        return os;
    }
};

#include <initializer_list>

template<typename T>
size_t FindAndDelete(std::multiset<T>& items, const std::initializer_list<T>& deleteItems) {
    size_t cnt = 0;
    for (const auto& val : deleteItems)
        cnt += items.erase(val);
    return cnt;
}

auto main4() -> int {
    using namespace std;
    cout << "hello world! \n";
    return 0;
}

int CountDigit(const long long int& number) {
    if (number == 0) return 0;
    return 1 + CountDigit(number / 10);
}

#include <math.h>

typedef long long int mynum;

int CountDigitByLog(const mynum& number) {
    return floor(log10(number) + 1);
}

bool powerofTwo(int x) {
    return x && !(x & --x);
}

std::string reverse(std::string& str) {
    for (int i = 0; i < str.length() / 2; ++i) {
        char temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp;
    }
    return str;
}

size_t countSetBit(int x) {
    if (x == 0) return 0;
    size_t total = 0;
    while (x != 0) {
        x = x & (x - 1);
        total++;
    }
    return total;
}

bool isBitSetAtIndex(int x, size_t index) {
    return (x & (1 << (index - 1)));
}


std::string filler(std::string&& val, size_t maxLength, char with = '\0') {
    if (val.length() > maxLength) return val;
    int currLength = val.length();
    std::string temp = "";
    for (int i = 0; i < maxLength - currLength; ++i) {
        temp += with;
    }
    return temp + val;
}

std::string DecToBinary(int number, std::string outVal) {
    if (number < 2) return filler("1" + reverse(outVal), 8, '0');
    if (number % 2 == 0) {
        return DecToBinary(number >> 1, outVal + "0");
    }
    return DecToBinary(number >> 1, outVal + "1");
}

size_t powerGeneration(const std::string& text) {
    using namespace std;
    size_t count = 1 << text.length();
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < text.length(); ++j) {
            if ((i & (1 << j)) != 0) {
                cout << text[j];
            }
        }
        cout << "\n";
    }
    return count;
}

size_t powerGeneration(const std::string& text, int len = 0) {
    using namespace std;
    size_t count = 1 << text.length();
    size_t countForReturn = 0;
    for (int i = 0; i < count; ++i) {
        int c = 0;
        string _temp;
        for (int j = 0; j < text.length(); ++j) {
            if ((i & (1 << j)) != 0) {
                _temp += text[j];
                ++c;
            }
        }
        if (c == len) {
            countForReturn++;
            cout << _temp << "\n";
        } else if (len == 0) {
            cout << _temp << "\n";
        }
    }
    return (len == 0) ? count : countForReturn;
}

void mirrorPrint(int x) {
    using namespace std;
    if (x < 1) {
        cout << "\n";
        return;
    }
    cout << x;
    mirrorPrint(x - 1);
    cout << x;
}


void printrec(int x) {
    using namespace std;
    if (x < 1) return;
    printrec(x - 1);
    cout << x;
}

typedef long long unsigned llu;

llu tailRec(llu x, int temp) {
    if (temp == 1)
        return x;
    return tailRec(x * (temp - 1), --temp);
}

llu tailRecCaller(llu x) {
    if (x <= 1) return x;
    return tailRec(x, x);
}

bool isPalindrome(const std::string& val, int l, int r) {
    if (val.length() == 0) return false;
    if (l >= r) return true;
    if (val[l] != val[r]) return false;
    return isPalindrome(val, ++l, --r);
}

#include <stdlib.h>

int sumRec(int n, int sum) {
    if (n < 10) return sum + n;
    return sumRec(n / 10, sum + (n - ((n / 10) * 10)));
}

int sumRecEasy(int n, int sum) {
    if (n < 10) return sum + n;
    return sumRec(n / 10, sum + n % 10);
}

int sumRecCaller(int n) {
    return sumRecEasy(n, 0);
}

void reverseArryRec(int* itemArr, size_t arrLen, int l, int r) {
    if (arrLen == 0) return;
    if (l >= r) return;
    int temp = *(itemArr + r);
    *(itemArr + r) = *(itemArr + l);
    *(itemArr + l) = temp;
    reverseArryRec(itemArr, arrLen, ++l, --r);
}

void rotateRight(int arrRotate[], int n, int d) {
    if (d == 0 || n == 0 || d >= n) return;
    auto swap = [&](const int l, const int r) {
        int temp = arrRotate[l];
        arrRotate[l] = arrRotate[r];
        arrRotate[r] = temp;
    };
    swap(0, d - 1);
    swap(d, n - 1);
    for (int i = 0; i < n / 2; ++i) {
        int temp = arrRotate[i];
        arrRotate[i] = arrRotate[n - i - 1];
        arrRotate[n - i - 1] = temp;
    }
}

std::string getString(const int& t) {
    if (t == 100) return "100";
    return {};
}

int maxSum(std::vector<int> arrSubArray, size_t maxLength, int k = 3) {
    using namespace std;
    int sum = 0;
    if (maxLength < k) return -1;
    int index = 0;
    for (auto it = std::begin(arrSubArray); it != std::end(arrSubArray); ++it) {
        if (index >= maxLength) break;
        if (index == 0) {
            int kC = k;
            while (kC != 0) {
                sum += arrSubArray[--kC];
                index++;
            }
            continue;
        }
        if (sum - *std::prev(it) + arrSubArray[index] > sum) {
            sum = sum - *std::prev(it) + arrSubArray[index];
        }
        index++;
    }
    return sum;
}

int maxSum(int arrSubArray[], size_t maxLength, int k = 3) {
    using namespace std;
    int sum = 0;
    if (maxLength < k) return -1;
    int index = 0;
    for (int i = 0; i < maxLength; ++i) {
        if (index >= maxLength) break;
        if (index == 0) {
            int kC = k;
            while (kC != 0) {
                sum += arrSubArray[--kC];
                index++;
            }
            continue;
        }
        if (sum - arrSubArray[i - 1] + arrSubArray[index] > sum) {
            sum = sum - arrSubArray[i - 1] + arrSubArray[index];
        }
        index++;
    }
    return sum;
}

size_t gitSum(int arrGitSum[], int arrLength, int from, int to) {
    if (from > to) return -1;
    if (from > arrLength - 1 || from < 0) return -1;
    if (to > arrLength - 1 || to < 0) return -1;
    size_t sum{0};
    for (int i = from; i <= to; ++i) {
        sum += arrGitSum[i];
    }
    return sum;
}

void prefixSumSmart(int arrNumbersAll[], int arrLength, int arrSumGit[]) {
    if (arrLength <= 0) return;
    arrNumbersAll[0] = *arrSumGit;
    for (int i = 1; i < arrLength; ++i) {
        arrNumbersAll[i] = arrNumbersAll[i - 1] + arrSumGit[i];
    }
}

size_t gitSumSmart(int arrGitSumForLookup[], int arrLength, int from, int to) {
    if (from > to) return -1;
    if (from > arrLength - 1 || from < 0) return -1;
    if (to > arrLength - 1 || to < 0) return -1;
    if (from != 0)
        return arrGitSumForLookup[to] - arrGitSumForLookup[from - 1];
    return arrGitSumForLookup[to];
}

int findSubSetXJustForPositiveNumbers(int arrForNums[], int arrLen, int target = 0) {
    int totalTargetCount = 0;
    if (arrLen <= 1) return totalTargetCount;
    int total = 1 << arrLen;
    total++;
    using namespace std;
    for (int i = 0; i < total; ++i) {
        int temp = 0;
        for (int j = 0; j < arrLen; ++j) {
            if ((i & (1 << j)) > 0) {
                temp += arrForNums[j];
                cout << arrForNums[j] << " ";
            }
        }
        if (temp != 0)
            cout << "\n";
        if (temp != 0 && temp == target)
            ++totalTargetCount;
    }
    if (target == 0)
        --totalTargetCount;
    return totalTargetCount;
}

#include <sstream>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void CombinationForSum(int arrForComb[], int arrLen, int& targetFound, std::string curr = "", int index = 0, const int target = 0, bool showAll = false) {
    if (index == arrLen) {
        if (showAll)
            std::cout << curr;
        std::vector<std::string> numbers = split(curr, ',');
        int sum = 0;
        for (const auto& number : numbers) {
            sum += std::stoi(number);
        }
        if (numbers.size() != 0 && sum == target) {
            if (!showAll)
                std::cout << curr;
            std::cout << " (*)\n";
            targetFound++;
        }
        if (showAll)
            std::cout << "\n";
        return;
    }
    CombinationForSum(arrForComb, arrLen, targetFound, curr, index + 1, target);
    CombinationForSum(arrForComb, arrLen, targetFound, curr + (curr == "" ? "" : ",") + std::to_string(arrForComb[index]), index + 1, target);
}

void subStrRec(const std::string& a, std::string curr = "", int index = 0) {
    if (index == a.length()) {
        std::cout << curr << "\n";
        return;
    }
    subStrRec(a, curr, index + 1);
    subStrRec(a, curr + a[index], index + 1);
}

void CombinationForSumStr(const std::string& strForComb, int& targetFound, std::string curr = "", int index = 0, const int target = 0) {
    if (index == strForComb.length()) {
        std::cout << curr << "\n";
        std::vector<std::string> numbers = split(curr, ',');
        int sum = 0;
        for (const auto& number : numbers) {
            sum += std::stoi(number);
        }
        if (numbers.size() != 0 && sum == target) {
            targetFound++;
        }
        return;
    }
    CombinationForSumStr(strForComb, targetFound, curr, index + 1, target);
    CombinationForSumStr(strForComb, targetFound, curr + (curr == "" ? "" : ",") + strForComb[index], index + 1, target);
}

int BinarySearchRec(int arrM[], int low, int high, int search) {
    if (low <= high) {
        int middle = low + (high - low) / 2;
        if (arrM[middle] == search)
            return middle;
        if (arrM[middle] > search)
            return BinarySearchRec(arrM, low, --middle, search);
        return BinarySearchRec(arrM, ++middle, high, search);
    }
    return -1;
}

int FindInArray(int arrInf[], int l, int h, int search) {
    if (arrInf[0] == search)
        return 0;
    int i = 1;
    while (arrInf[i] < search)
        i *= 2;
    if (arrInf[i] == search)
        return i;
    return BinarySearchRec(arrInf, i / 2, i, search);
}

int pop(unsigned x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

#include <unordered_set>

int findUnique(int arrUn[], int arrLen) {
    std::unordered_set<int> allItems = {};
    for (int i = 0; i < arrLen; ++i) {
        //if (!allItems.contains(arrUn[i])) {
        allItems.insert(arrUn[i]);
        //}
    }
    return allItems.size();
}

#include <unordered_map>

std::unordered_map<int, int> getUMap(int arrUn[], int arrLen) {
    std::unordered_map<int, int> allItems = {};
    for (int i = 0; i < arrLen; ++i) {
        allItems[arrUn[i]]++;
    }
    return allItems;
}

using ll = long long;
using llu = long long unsigned;

template<typename K, typename V>
V find(std::unordered_map<K, V> allItems, K search) {
    using namespace std;
    auto item = allItems.find(search);
    if (item != allItems.end()) {
        return item->second;
    }
    return V{};
}

std::string enter_a_value(const std::string& desc = "Please enter a value :") {
    using namespace std;
    cout << desc << "\n";
    std::string s;
    std::getline(std::cin >> std::ws, s);
    cout << "\n---------------------------\n";
    return s;
}

// check a subarray with 0 sum! O(n)
bool custom_sum(int arrZs[], int arrLen, int target = 0) {
    if (arrLen <= 0) return false;
    std::unordered_set<int> keys;
    keys.insert(0);
    int preTemp = arrZs[0];
    keys.insert(arrZs[0]);
    for (int i = 1; i < arrLen; ++i) {
        int prefixSum = preTemp + arrZs[i];
        if (keys.find(prefixSum - target) != keys.end()) {
            return true;
        }
        keys.insert(prefixSum);
        preTemp = prefixSum;
    }
    return false;
}

// Time : O(n) , Space : O(n)
std::pair<int, int> find_2_sum(int arrSum[], int arrLen, const int search) {
    if (arrLen <= 0) return std::make_pair<int, int>(-1, -1);
    std::unordered_set<int> _ul;
    while (arrLen--) {
        if (_ul.find(search - arrSum[arrLen]) != _ul.end()) {
            return std::make_pair<int, int>(std::move(arrSum[arrLen]), search - arrSum[arrLen]);
        }
        _ul.insert(arrSum[arrLen]);
    }
    return std::make_pair<int, int>(-1, -1);
}

// Time : O(nlogn) ,Space : o(1)
std::pair<int, int> find_2_sum_2(int arrSum[], int arrLen, const int search) {
    // it must be sorted!!!
    [&](const bool active) {
        if (!active) return;
        for (int i = 0; i < arrLen - 1; ++i) {
            for (int j = 0; j < arrLen - 1; ++j) {
                if (arrSum[j] > arrSum[j + 1]) {
                    int temp = arrSum[j];
                    arrSum[j] = arrSum[j + 1];
                    arrSum[j + 1] = temp;
                }
            }
        }
    }(false);

    if (arrLen <= 0) return std::make_pair<int, int>(-1, -1);
    int l = 0;
    int h = arrLen - 1;
    while (l < h) {
        std::cout << "l : " << arrSum[l] << ", h:" << arrSum[h] << "\n";
        int sum = arrSum[l] + arrSum[h];
        if (sum == search) {
            return std::make_pair<int, int>(std::move(arrSum[l]), std::move(arrSum[h]));
        }
        if (sum > search) {
            h--;
        } else {
            l++;
        }
    }
    return std::make_pair<int, int>(-1, -1);
}

char find_repeating_first_char(const std::string& text) {
    if (text.empty()) return '\0';
    std::unordered_set<char> _li;
    for (const auto& item : text) {
        if (_li.find(item) != _li.end()) {
            return item;
        }
        _li.insert(item);
    }
    return '\0';
}

char find_non_repeating_char(const std::string& text) {
    if (text.empty()) return '\0';
    std::unordered_map<char, int> _li;
    char result = text[0];
    for (int i = text.length() - 1; i >= 0; --i) {
        _li[text[i]]++;
        if (_li[text[i]] == 1) {
            result = text[i];
        }
    }
    return result;
}

void find_perm_str(char arrChars[], int arrLen, std::string curr = "", int index = 0) {
    if (arrLen <= 0) return;
    if (arrLen == index) {
        std::cout << curr << "\n";
        return;
    }
    find_perm_str(arrChars, arrLen, curr, index + 1);
    find_perm_str(arrChars, arrLen, curr + arrChars[index], index + 1);
}

bool all_char_is_unique(const std::string& text) {
    int t = 0;
    for (int i = 0; i < text.length(); ++i) {
        if ((t & (1 << (text[i] - 'a'))) > 0) {
            return false;
        }
        t |= (1 << (text[i] - 'a'));
    }
    return true;
}

template<typename T>
void reverse_array(T* arrR, int b, int e) {
    while (b < e) {
        std::swap(arrR[b], arrR[e]);
        b++;
        e--;
    }
}


void rotate_right(char* text, int n, int d) {
    if (d == 0 || n == 0 || d == n) return;
    if (d > n)
        d = d % n;
    reverse_array(text, 0, n - 1); // 0,n-1
    reverse_array(text, 0, d - 1); // 0,d-1
    reverse_array(text, d, n - 1); // d,n-1
}


void rotate_left(char* text, int n, int d) {
    if (d == 0 || n == 0 || d == n) return;
    if (d > n)
        d = d % n;
    reverse_array(text, 0, d - 1); // 0,d-1
    reverse_array(text, d, n - 1); // d,n-1
    reverse_array(text, 0, n - 1); // 0,n-1
}

// O(n*n!)
// Note that there are n! permutations and it requires O(n) time to
// print a permutation.
void permutation_list(std::string& a, int l, int r) {
    std::cout << "l:" << l << ",r:" << r << "\n";
    if (l == r) {
        std::cout << a << "\n";
    } else {
        for (int i = l; i <= r; ++i) {
            std::swap(a[l], a[i]);
            permutation_list(a, l + 1, r);
            std::swap(a[l], a[i]);
        }
    }
}

#include <stack>

void simple_stack_work() {
    using namespace std;
    std::stack<int> ss;
    ss.push(1);
    ss.push(2);
    cout << "top element: " << ss.top() << "\n";
    cout << "popping element\n";
    ss.pop();
    cout << "top element: " << ss.top() << "\n";
    cout << "popping element\n";
    cout << "top element: " << ss.top() << "\n";
    cout << "size: " << ss.size() << "\n";

}

bool do_something(const int l, const int r) {
    return (l ^ 1) < (r ^ 1);
}

struct custom_stack {
    int cap;
    int top;
    int* arr;

    custom_stack(int cap) : cap(cap), top(-1) {
        arr = new int[cap];
    }
};

void stock_span() {
    int prices[] = {10, 5, 2, 7, 18, 15, 16, 17};
    for (int i = 0; i < sizeof(prices) / sizeof(*prices); i++) {
        int span = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (prices[j] > prices[i])
                break;
            span++;
            //cout << "i,j : ["<< i <<","<< j << "]" << "\n";
        }
        std::cout << span << "\n";
    }
}

int char_to_num_x(const char& c) {
    return 0;
}

#include <math.h>

int str_to_int(const std::string& value) {
    if (value.empty()) return 0;
    int val = 0;
    auto char_to_num = [](const char& c) {
        if (c >= 48 && c <= 57) {
            return c - 48;
        }
        return 0;
    };
    for (int i = value.size() - 1; i >= 0; --i) {
        val += char_to_num(value[i]) * pow(10, value.size() - 1 - i);
    }
    return val;
}

void fast_io(const bool active) {
    std::ios_base::sync_with_stdio(active);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    // if you disable this setting then you must your flush your text with one of "\n"+manual flash or just "std::endl" manually.
}

bool is_power_of_2(const int& number) {
    if (number == 0) return number;
    return ((number & (number - 1)) == 0);
}

#include <string>

bool is_rotated(const std::string& value, const std::string& matchWith) {
    bool result = false;
    if (value.size() != matchWith.size()) return result;
    std::string temp = value + value;
    if (temp.find(matchWith) != std::string::npos) {
        result = true;
    }
    return result;
}

int count_distinct_by_unorderedset(int arrDisc[], int len) {
    // BigO(1) (it's using hashtable!) --- UNORDERED
    std::unordered_set<int> temp(arrDisc, arrDisc + len);
    return temp.size();
}

int count_distinct_by_set(int arrDisc[], int len) {
    // BigO(NlogN)  ( it's using balanced binary search tree ) ----- ORDERED
    std::set<int> temp(arrDisc, arrDisc + len);
    return temp.size();
}

void print_2D_array(int* arr2D, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << *((arr2D + i * c) + j) << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
void delete_in_loop_from_vector(std::vector<T>& myV, decltype(myV[0])& itemToD) {
    myV.template emplace_back(22);
    for (auto it = myV.begin(); it != myV.end(); ++it) {
        std::cout << *it << " ";
        if (*it == itemToD) {
            std::cout << "found..\n";
            it = myV.erase(it);
        }
    }
}

#include <map>
#include <regex>


template<typename T, typename P>
auto which(const T& t, const P& p) -> decltype((t > p) ? t : p) {
    std::cout << ">>t :" << t << ", " << typeid(t).name() << "\n";
    std::cout << ">>p :" << p << ", " << typeid(p).name() << "\n";
    return (t > p) ? t : p; //return widens from small to large one..in this case it's always return as double!
}

template<typename T, int limit>
void lamb_pub(const std::vector<T>& item) {
    static T _index = 0;
    for (auto it = item.begin(); it != item.end(); ++it) {
        if (_index >= limit) return;
        std::cout << *it << "\n";
        _index++;
    }
};

template<typename T>
struct Pair {
    T _a{};
    T _b{};

    Pair(T a, T b) : _a(a), _b(b) {

    }

    T getA() const;

    void setA(T a);
};

template<typename T>
T Pair<T>::getA() const {
    return _a;
}

template<typename T>
void Pair<T>::setA(T a) {
    _a = a;
}

auto main_new() -> int {
    return 0;
}

void sort_couples(int student_numbers[], int lenSNumbers, int student_notes[], int lenSNotes) {
    std::vector<std::pair<int, int>> allItems;
    for (int i = 0; i < lenSNumbers; ++i) {
        allItems.emplace_back(std::make_pair(student_numbers[i], student_notes[i]));
        //allItems.push_back({student_numbers[i],student_notes[i]});
    }
    sort(allItems.begin(), allItems.end(), std::greater<std::pair<int, int>>());
    /*
    sort(allItems.begin(), allItems.end(), [](const std::pair<int, int>& first, const std::pair<int, int>& second) {
        return first.second > second.second;
    });
     */
    for (const auto& item : allItems) {
        std::cout << "student no : " << item.first << ", student note : " << item.second << "\n";
    }
}

void reserve_index(int numbers[], int lenSNumbers) {
    std::vector<std::pair<int, int>> allItems;
    for (int i = 0; i < lenSNumbers; ++i) {
        allItems.emplace_back(std::make_pair(numbers[i], i));
    }
    sort(allItems.begin(), allItems.end(), [](const std::pair<int, int>& first, const std::pair<int, int>& second) {
        return first.first < second.first;
    });
    for (const auto& item : allItems) {
        std::cout << "no : " << item.first << ", index : " << item.second << "\n";
    }
}

#include <list>
#include <forward_list>

void josephus_problem(const int& size, const int& k) {
    using namespace std;
    if (size <= 0 || k <= 0)return;
    list<int> victims;
    for (int i = 0; i < size; ++i) {
        victims.emplace_back(i);
    }
    auto tmpIt = victims.begin();
    while (victims.size() != 1) {
        int fwd{};
        while (fwd < k - 1) {
            tmpIt = std::next(tmpIt, 1);
            fwd++;
            if (tmpIt == victims.end()) {
                tmpIt = victims.begin();
            }
        }
        cout << *tmpIt << " will be delete!" << "\n";
        tmpIt = victims.erase(tmpIt);
        if (tmpIt == victims.end()) {
            tmpIt = victims.begin();
        }
    }
    cout << "survivor : " << victims.front() << "\n";
}


void find_max_in_every_k_items_wise(std::vector<int>& v, const int& k) {
    using namespace std;
    if (v.empty() || k <= 0) return;
    bool done = false;
    int index{};
    //use a deq!
}


std::vector<int> find_max_in_every_k_item(const std::vector<int>& v, const int& k) {
    using namespace std;
    if (v.empty() || k <= 0) return std::vector<int>{};
    vector<int> items(v.size() - k + 1); // n-k+1 items max!
    bool done = false;
    int index{};
    for (auto it = v.begin(); it != v.end(); ++it) {
        int temp = *it;
        for (auto itx = it; itx != it + k; ++itx) {
            temp = std::max(*itx, temp);
            if (itx == v.end()) {
                done = true;
                break;
            }
        }
        items[index++] = temp;
        if (done) break;
    }
    return items;
}

void print_k_max(int arrForKMax[], const int lenArr, const int k) {
    using namespace std;
    deque<int> deq;
    for (int i = 0; i < k; i++) {
        while (!deq.empty() && arrForKMax[i] >= arrForKMax[deq.back()])
            deq.pop_back();
        deq.push_back(i);
    }
    for (int i = k; i < lenArr; i++) {
        cout << arrForKMax[deq.front()];
        while (!deq.empty() && deq.front() <= i - k)
            deq.pop_front();
        while (!deq.empty() && arrForKMax[i] >= arrForKMax[deq.back()])
            deq.pop_back();
        deq.push_back(i);
    }
    cout << arrForKMax[deq.front()] << " ";
}

void previous_gereater_element(int arrGL[], int len) {
    if (len <= 0) return;
    using namespace std;
    stack<int> stack;
    stack.push(arrGL[0]);
    cout << -1 << " ";
    for (int i = 1; i < len; ++i) {
        while (!stack.empty() && stack.top() <= arrGL[i])
            stack.pop();
        cout << (stack.empty() ? -1 : stack.top()) << " ";
        stack.push(arrGL[i]);
    }
    cout << "\n";
}

void print_next_greater(int elements[], int len) {
    if (len <= 0) return;
    using namespace std;
    stack<int> stack;
    vector<int> printV(len);
    stack.push(elements[len - 1]);
    printV.emplace_back(-1);
    for (int i = len - 2; i >= 0; --i) {
        while (!stack.empty() && stack.top() <= elements[i])
            stack.pop();
        printV.emplace_back(stack.empty() ? -1 : stack.top());
        stack.push(elements[i]);
    }
    std::reverse(printV.begin(), printV.end());
    for (const int& item:printV)
        cout << item << " ";
    cout << "DONE!\n";
}

#include <deque>
#include <queue>

void write_to_n(int baseDigits[], int len, int n) {
    if (n <= 0) return;
    using namespace std;
    queue<string> q;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (baseDigits[i] < baseDigits[j]) {
                int temp = baseDigits[i];
                baseDigits[i] = baseDigits[j];
                baseDigits[j] = temp;
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        q.push(to_string(baseDigits[i]));
    }
    for (int i = 0; i < n; ++i) {
        string item = q.front();
        cout << item << "\n";
        q.pop();
        for (int i = 0; i < len; ++i) {
            if (item == "0") continue;
            q.push(item + to_string(baseDigits[i]));
        }
    }
}

struct person {
    int id = -1;

    /*
    person() : id{-1} {

    }
    */

    person(int id) : id{id} {
    }

    bool operator()(const person& lhs, const person& rhs) const {
        return lhs.id < rhs.id;
    }

};

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while (!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

void simple_pq_2() {
    std::priority_queue<int> q;

    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    for (int n : data)
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int>>
            q2(data.begin(), data.end());

    print_queue(q2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for (int n : data)
        q3.push(n);

    print_queue(q3);
}


void simple_pq(int items[], int len) {
    using namespace std;

    auto person_cmp = [](const person& l, const person& r) { return l.id < r.id; };
    priority_queue<person, vector < person>, decltype(person_cmp) > pq5;

    pq5.push(person{1});
    pq5.push(person{2});
    pq5.push(person{3});
    while (!pq5.empty()) {
        cout << pq5.top().id << "\n";
        pq5.pop();
    }
    return;

    int a = 10;
    int b = a ^1;
    int j = 10;
    while (j--) {
        int c = b ^1;
        b = c;
        cout << b << "\n";
    }

    return;


    priority_queue<int, vector < int>, greater < int >> pq3(items, items + len); // by descending (default!!!)
    while (!pq3.empty()) {
        cout << pq3.top() << " ";
        pq3.pop();
    }
    return;


    priority_queue<int, vector < int>, greater < int >> pq2(items, items + len); // by ascending
    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    return;


    priority_queue<int> pq;
    for (int i = 0; i < len; ++i) {
        pq.emplace(items[i]);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return;

    int lenPq = pq.size();
    for (int i = 0; i < lenPq; ++i) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

#include <set>

void simple_set(int arrElements[], int len) {
    using namespace std;
    auto print_set = [](const auto& set) {
        for (const auto& item : set) {
            cout << item << "\n";
        }
        auto it = set.begin();
        while (it != set.end()) {
            cout << "value : " << *it << "\n";
            it++;
        }
    };
    if (len <= 0) {

    } else {
        auto comp = [](const auto& l, const auto& r) { return l < r; };
        set<int, decltype(comp)> set;
        //less<T> -> ascending
        //greater<T> -> descending
        set.insert(3);
        set.insert(13);
        set.insert(13);
        set.insert(-3);
        set.insert(43);
        set.insert(33);
        //bool(*)(int, int)
        print_set(set);

        //auto lexical_compare = [](int a, int b) { return to_string(a) < to_string(b); };
        //set<int, decltype(lexical_compare)> s;
    }
}

#define sizeMe(a) (sizeof((a)) / sizeof((*a)))

template<typename T>
T doSomething(const T& a, const T& b) {
    return a + b;
}

int main() {
    using namespace std;
    cout << std::boolalpha;


    int (* tempCaller)(const int&, const int&) = &doSomething;

    cout << tempCaller(1, 2) << "\n";
    return 0;


    int aX[] = {1, 2, 3, 4, 5};
    cout << "sizeMe(aX) : " << sizeMe(aX) << "\n";
    for (int i = -1; i <= 3; ++i) {
        cout << aX[i + 1] << " ";
    }
    return 0;

    cout << sizeMe(aX) << "\n";
    return 0;

    int xP = 10;
    size_t xY = sizeof(xP++);

    cout << "xP = " << xP << "\n";
    cout << "xY = " << xY << "\n";

    return 0;

    int a[10] = {0};
    printf("sizeof (int*) = %zu\n", sizeof(int*));
    printf("sizeof (double*) = %zu\n", sizeof(double*));
    printf("sizeof a      = %zu\n", sizeof a);
    printf("sizeof &a[0]  = %zu\n", sizeof &a[0]);
    printf("sizeof a[0]  = %zu\n", sizeof a[0]);

    return 0;

    auto printArr = []<typename T>(const char* desc, vector<T> vec) {
        if (vec.size() == 0) return;
        cout << desc << "\n";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    };

    vector<int> listSample = {1, 2, 3, 4, 5, 6, 6, 7, 8};
    vector<int> listSample1 = listSample;
    vector<int> listSample3 = listSample;
    cout << "cap : " << listSample.capacity() << "\n";
    listSample.emplace_back(33);
    cout << "cap : " << listSample.capacity() << "\n";
    printArr(">.first", listSample);

    listSample.erase(listSample.begin() + 5, listSample.begin() + 7);

    printArr(">.after erasing. ( deleting 6 6 )", listSample);


    printArr(">>. listSample1", listSample1);
    std::remove(listSample1.begin(), listSample1.end(), 6);
    printArr(">>. listSample1 (after deletion with std::remove)", listSample1);

    printArr(">>>. listSample3", listSample3);
    listSample3.erase(std::remove(listSample3.begin(), listSample3.end(), 6), listSample3.end());
    printArr(">>>. listSample3 (after deletion with erase + std::remove )", listSample3);


    return 0;






    //cout << *(listSample+5) << "\n";  // in case array
    cout << *(listSample.begin() + 5) << "\n";
    auto setComp = [](const int& a, const int& b) { return a > b; };
    set<int, decltype(setComp)> mySet;
    mySet.insert(3);
    mySet.insert(33);
    mySet.insert(23);
    mySet.insert(-3);
    cout << "set..\n";
    cout << "top : " << *mySet.begin() << "\n\n";
    cout << "back : " << *mySet.rbegin() << "\n\n";

    for (const auto& item : mySet) {
        cout << item << " ";
    }
    cout << "\n";
    //cout <<"set : " << *(mySet.begin()+3) << "\n"; NO!!! ERROR!! There is no iteration declaration for +,-.. operators..
    //std::erase(listSample+5,listSample+6);


    return 0;
    //cout << "INT_MAX : " << INT_MAX << ", INT_MIN" << INT_MIN << "\n";
    // ?? cout << "sizeof lambda (unevaluated lambda function ) : " << sizeof(decltype([](const int a, const int b) { return a / b; }));
    //return 0;

    int arr_set[] = {10, 1, 2, 3, 4, 4};

    simple_set(arr_set, sizeof(arr_set) / sizeof(*arr_set));
    return 0;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (arr_set[i] > arr_set[j]) {
                int temp = arr_set[i];
                arr_set[i] = arr_set[j];
                arr_set[j] = temp;
            }
        }
    }
    for (const auto& arrSet : arr_set) {
        cout << arrSet << "\n";
    }

    return 0;


    simple_pq_2();
    return 0;

    int numpq[] = {133, 199, 43, 2};
    simple_pq(numpq, sizeof(numpq) / sizeof(*numpq));
    return 0;

    int digits[] = {0, 1, 3, 2, 4, 5, 6, 7, 8, 9};
    write_to_n(digits, sizeof(digits) / sizeof(*digits), 120);
    return 0;

    int gnextg1[] = {5, 15, 10, 8, 6, 12, 9, 18};
    print_next_greater(gnextg1, sizeof(gnextg1) / sizeof(*gnextg1));
    return 0;

    int gprevious1[] = {20, 30, 10, 5, 15};
    previous_gereater_element(gprevious1, sizeof(gprevious1) / sizeof(*gprevious1));
    return 0;

    int _aq[] = {20, 40, 30, 10, 60};
    print_k_max(_aq, 5, 3);
    return 0;

    deque<int> dq;

    int _k = 3;
    std::vector<int> xTempVec = {10, 8, 5, 12, 15, 7, 6};
    find_max_in_every_k_items_wise(xTempVec, _k);
    cout << "k : " << _k << "\n";
    for (const auto& item : xTempVec) {
        cout << item << " ";
    }
    cout << "\n";
    return 0;

    auto items_in = find_max_in_every_k_item({10, 8, 5, 12, 15, 7, 6}, _k);
    cout << "k : " << _k << "\n";
    for (const auto& item : items_in) {
        cout << item << " ";
    }
    cout << "\n";
    return 0;

    josephus_problem(6, 2);
    return 0;

    forward_list<int> fListM;
    fListM.assign({1, 2, 33, 4, 5});
    fListM.sort([](const int& l, const int& r) { return l < r; });
    forward_list<int> fListN;
    fListN.assign({10, 20, 30});
    fListM.merge(fListN);
    cout << "fListM\n";
    for (const auto& item : fListM) {
        cout << item << " ";
    }
    cout << "\n";
    cout << "fListM.max_size : " << fListM.max_size() << "\n";
    cout << "fListN.max_size : " << fListN.max_size() << "\n";
    cout << "fListN\n";
    fListN = {1, 2, 2, 3, 4, 4, 1, 1, 1, 5};
    fListN.unique();
    for (const auto& item : fListN) {
        cout << item << " ";
    }

    return 0;

    list<int> myList = {10, 20, 30, 40, 20, 40};
    auto itF = myList.begin();
    itF = myList.erase(itF);
    myList.remove(40);
    myList.insert(itF, 2, 7);
    myList.insert(itF, 1, 100);
    int ff = 100;
    auto* tt = &ff;
    cout << *tt << "\n";

    forward_list<int> fList;
    fList.assign({1, 2, 3, 4, 5});
    fList.assign(myList.begin(), myList.end());

    for (const auto& item : fList) {
        cout << item << "\n";
    }

    return 0;

    int nums[] = {20, 40, 30, 10};
    reserve_index(nums, sizeof(nums) / sizeof(*nums));

    return 0;

    int student_numbers[] = {1003, 4003, 4002, 4000};
    int student_notes[] = {10, 100, 80, 40};
    sort_couples(student_numbers, sizeof(student_numbers) / sizeof(*student_numbers), student_notes, sizeof(student_notes) / sizeof(*student_notes));

    return 0;

    cout << typeid(std::cout).name() << "\n";

    return 0;

    auto lam = []<typename T, int limit>(const std::vector<T>& item) {
        static T _index = 0;
        for (auto it = item.begin(); it != item.end(); ++it) {
            if (_index >= limit) return;
            std::cout << *it << "\n";
            _index++;
        }
    };

    //??std::set<int,string> dddd;
    std::vector<int> __listV20 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    lamb_pub<int, 3>(__listV20);

    return 0;


    for (auto it = __listV20.begin(); it != __listV20.end(); ++it) {
        if (*it == 2) {
            std::advance(it, 2);
            cout << "previous : " << *std::prev(it) << "\n";
        }
        cout << "item : " << *it << "\n";
    }

    __listV20.front() = 1000;
    __listV20.back() = 2000;


    return 0;

    int _arx[] = {1, 2, 3, 4, 5, 6, 4};
    sort(std::begin(_arx), std::end(_arx), greater<decltype(*_arx)>());
    for (int i = 0; i < sizeof(_arx) / sizeof(*_arx); ++i) {
        cout << _arx[i] << "\n";
    }
    return 0;

    vector<int> vList09 = {3, 2, 2, 4, 1, 1, 3};

    std::cout << *std::min_element(vList09.begin(), vList09.end()) << "\n";

    return 0;

    auto cnt = std::count_if(vList09.begin(), vList09.end(), [&](const int& val) {
        return val % 2 == 0;
    });
    cout << "even number count : " << cnt << "\n";
    return 0;


    auto pT = which<int, double>(1, 1.1);
    auto xT = which<int, double>(2, 1.1);
    cout << "pT :" << pT << ", " << typeid(pT).name() << "\n";
    cout << "xT :" << xT << ", " << typeid(xT).name() << "\n";


    //cout <<"int :"<<int{}<<", "<<  typeid(int{}).name() << "\n";
    //cout <<"double :"<<double{} <<", "<<  typeid(double{}).name() << "\n";


    return 0;
    auto lambdaSimpleGeneric = []<typename T>(T x = 10, T y = 20) -> T {
        return x + y;
    };


    std::for_each(vList09.begin(), vList09.end(), [](decltype(vList09[0]) par) {
        cout << "value : " << par << "\n";
    });

    return 0;

    cout << lambdaSimpleGeneric(10, 20) << "\n";


    vector<int> vList10 = {3, 2, 2, 4, 1, 1, 3};
    int del = 4;
    delete_in_loop_from_vector(vList10, del);
    cout << "\n ...";
    for (const auto& item : vList10) {
        cout << item << " ";
    }
    return 0;

    int elma[][4] = {{1,   2,   3,   4},
                     {10,  20,  30,  40},
                     {100, 200, 300, 400}};
    print_2D_array(&elma[0][0], 3, 4);

    return 0;
    set<int> __s;
    __s.insert(1);
    __s.insert(2);
    __s.insert(3);
    __s.insert(4);
    __s.insert(5);
    int vall = *__s.lower_bound(2); // BigO(logN)... so use this !
    cout << vall << "\n";
    return 0;


    int uArr[] = {1, 2, 9, 10, 13, 14, 15};
    cout << "Lowerbound : " << *std::lower_bound(std::begin(uArr), std::end(uArr), 3) << "\n"; // BigO(N)
    cout << "Upperbound : " << *std::upper_bound(std::begin(uArr), std::end(uArr), 3) << "\n";

    return 0;

    cout << "count distinct ( wisely ) : " << count_distinct_by_unorderedset(uArr, sizeof(uArr) / sizeof(*uArr)) << "\n";

    vector<int> vList2 = {3, 2, 2, 4, 1, 1, 3};
    int ans = 0;
    for (const auto& item : vList2) {
        ans = ans ^ item;
    }

    std::unordered_set<int> tUS(vList2.begin(), vList2.end());
    [&tUS]() {
        for (const auto& item : tUS) {
            cout << "item  :" << item << "\n";
        }
    }();
    return 0;

    cout << ans << "\n";

    return 0;
    string regText = "eralp I344 okul G43!!...43";
    regex regExp("[A-Z][0-9][0-9]");

    std::smatch matched;

    while (regex_search(regText, matched, regExp)) {
        cout << "item :" << matched.str() << "\n";
        regText = matched.suffix();
    }

    return 0;

    std::cout << is_rotated("eralp", "alper") << "\n";
    return 0;


    std::map<int, int> __map = {{1,  23},
                                {13, 433}};
    for (const auto& item : __map) {
        cout << "key : " << item.first << " , value : " << item.second << "\n";
    }
    return 0;

    map<int, int>::iterator _it = __map.begin();
    cout << typeid(_it).name() << "\n";

    return 0;

    auto _do = 133.43;
    auto* dp = new auto(_do);
    cout << typeid(dp).name() << "\n";
    return 0;


#if 0
    fast_io(false);
    int __n;
    cin >>__n;
    cout << __n << "\n";
#endif
    for (int i = 0; i < 10; ++i) {
        cout << i << "  : " << is_power_of_2(i) << "\n";
    }
    return 0;

    vector<int> vList{1, 2, 3, 4};
    for (int i = 0; vList[i]; ++i) {
        vList[i] = 1;
    }
    for (auto& item : vList) {
        item += 100;
    }
    for_each(vList.begin(), vList.end(), [](int& c) {
        c += 300;
    });

    for (const auto& item : vList) {
        cout << item << "\n";
    }
    return 0;

    int __a, __b;
    tie(__a, __b) = std::make_tuple(1, 4);

    cout << __a << "\n" << __b;

    return 0;

    int xea[5] = {-1};
    int sizeX = sizeof(xea) / sizeof(*xea);
    while (sizeX) {
        xea[--sizeX] = -1;
    }
    for (const auto& item : xea) {
        cout << item << "\n";
    }
    return 0;

    string ttt = "343653";
    cout << str_to_int(ttt) << "\n";
    return 0;

    vector<int> aTeam = {1, 2, 4, 2, 1, 3, 4, 3, 53};
    std::sort(begin(aTeam), end(aTeam), [](const int& l, const int& r) {
        return l < r;
    });

    for (const auto& item : aTeam) {
        cout << item << "\n";
    }
    return 0;

    int* aff, ffff; /// be careful!

    stock_span();
    return 0;

    cout << "3<4 ?" << do_something(3, 4) << "\n";
    cout << "5<4 ?" << do_something(5, 4) << "\n";
    return 0;


    simple_stack_work();
    return 0;

    string text_perm = enter_a_value("Please enter a text");
    permutation_list(text_perm, 0, text_perm.size() - 1);
    return 0;

    char arrCharPerm[] = {'a', 'b', 'c', 'd', 'e'};

    cout << "is sorted ? : " << std::is_sorted(std::begin(arrCharPerm), std::end(arrCharPerm)) << "\n";

    auto arrReset = [&arrCharPerm] {
        arrCharPerm[0] = 'a';
        arrCharPerm[1] = 'b';
        arrCharPerm[2] = 'c';
        arrCharPerm[3] = 'd';
        arrCharPerm[4] = 'e';
    };

    for (int j = 0; j < 5; ++j) {
        rotate_left(arrCharPerm, sizeof(arrCharPerm) / sizeof(*arrCharPerm), j);
        for (int i = 0; i < sizeof(arrCharPerm) / sizeof(*arrCharPerm); ++i) {
            cout << arrCharPerm[i];
        }
        cout << " (r:" << j << ")" << "\n";
        if (j == 0)
            cout << "-----------------------\n";
        arrReset();
    }
    return 0;

#if 0
    reverse_array_new_style(arrCharPerm,0,4);
    for (int i = 0; i < sizeof(arrCharPerm) / sizeof(*arrCharPerm); ++i) {
        cout << arrCharPerm[i];
    }
    cout << "\n";
    return 0;
#endif
    for (int j = 0; j < 5; ++j) {
        rotate_right(arrCharPerm, sizeof(arrCharPerm) / sizeof(*arrCharPerm), j);
        for (int i = 0; i < sizeof(arrCharPerm) / sizeof(*arrCharPerm); ++i) {
            cout << arrCharPerm[i];
        }
        cout << " (r:" << j << ")" << "\n";
        if (j == 0)
            cout << "-----------------------\n";
        arrReset();
    }
    return 0;

#if 0
    char arrCharPerm[] = {'a', 'b', 'c'};
    find_perm_str(arrCharPerm, sizeof(arrCharPerm) / sizeof(*arrCharPerm), "", 0);
    return 0;
#endif

#if 0
    std::string find_non_repeating_char_Value = enter_a_value();
    cout << "find_non_repeating_char :" << find_non_repeating_char(find_non_repeating_char_Value) << "\n";
    return 0;
#endif

#if 0
    std::string valueAllCharIsUnique = enter_a_value();
    cout << "all_char_is_unique :"<< all_char_is_unique(valueAllCharIsUnique) << "\n";
    return 0;
#endif

    return 0;
    std::string valueffVal = enter_a_value();
    cout << find_repeating_first_char(valueffVal) << "\n";
    return 0;

    char* strxxx = "eralp";
    //strxxx[0] = 'E';
    string stryyy = "eralp";
    stryyy[0] = 'E';

    cout << sizeof(strxxx) << ", " << sizeof(stryyy) << "\n";
    cout << strxxx << ", " << stryyy << "\n";

    return 0;


    int find_2_sum_2Arr[] = {1, 2, 3, 7, 8, 10, 11, 14};

    int find_2_sum_2Number = std::stoi(enter_a_value());
    auto find_2_sum_2Result = find_2_sum_2(find_2_sum_2Arr, sizeof(find_2_sum_2Arr) / sizeof(*find_2_sum_2Arr), find_2_sum_2Number);
    cout << "[" << find_2_sum_2Result.first << "," << find_2_sum_2Result.second << "]\n";
    return 0;

#if 0
    int find_2_sumNumber = enter_a_value<int>();
    auto find_2_sumResult = find_2_sum(find_2_sumArr, sizeof(find_2_sumArr) / sizeof(*find_2_sumArr), find_2_sumNumber);
    cout << "[" << find_2_sumResult.first << "," << find_2_sumResult.second << "]\n";
    for (int i = 0; i < sizeof(find_2_sumArr) / sizeof(*find_2_sumArr); ++i) {
        cout <<"--------->> : "<< find_2_sumArr[i] << "\n";
    }
    return 0;
#endif

    int arrZs[] = {5, 3, 8, -2, 8, 10};
    int searchForSum = std::stoi(enter_a_value());
    bool zsResult = custom_sum(arrZs, sizeof(arrZs) / sizeof(*arrZs), searchForSum);
    cout << zsResult << "\n";
    return 0;

    int arrUn[] = {1, 1, 1, 1, 12, 3, 4, 2, 2, 3, 4};
#if 0
    int resUn = findUnique(arrUn, sizeof(arrUn) / sizeof(*arrUn));
    cout << resUn;
    return 0;
#endif

    std::unordered_map<int, int> resUMP = getUMap(arrUn, sizeof(arrUn) / sizeof(*arrUn));
    for (const auto& item : resUMP) {
        cout << item.first << ":" << item.second << "\n";
    }

    cout << "result --> " << find(resUMP, 32) << "\n";

    return 0;

    int pConvertI;
    std::string pConvertStringI;
    cout << "Please enter a number to convert from decimal to binary : \n";
    cin >> pConvertI;
    cout << "result : " << DecToBinary(pConvertI, pConvertStringI) + "\n";
    cout << "bitCount : " << pop(pConvertI) << "\n";
    return 0;

    cout << "executing..\n";
    cout << "looking for (in infinity) ?\n";
    int numberInf = -1;
    cin >> numberInf;
    int listXFFInf[] = {1, 2, 3, 4, 5, 6, 19, 30, 40};
    auto resxxFFInf = FindInArray(listXFFInf, 0, 0, numberInf);
    cout << "found index " << resxxFFInf << "\n";
    return 0;

    cout << "executing..\n";
    cout << "looking for ?\n";
    int number = -1;
    cin >> number;
    int listX[] = {2, 3, 3, 3, 5, 5, 4, 3};
    sort(begin(listX), end(listX));
    for (const auto& item : listX) {
        cout << item << " ";
    }
    cout << "\n";
    auto resxxL = BinarySearchRecFIMostLeft(listX, 0, (sizeof(listX) / sizeof(*listX)), number);
    cout << "found index ( most left )  : " << resxxL << "\n";
    auto resxxR = BinarySearchRecFIMostRight(listX, 0, (sizeof(listX) / sizeof(*listX)), number, (sizeof(listX) / sizeof(*listX)));
    cout << "found index ( most right ) : " << resxxR << "\n";

    auto resxxT = BinarySearchRecFITotal(listX, 0, (sizeof(listX) / sizeof(*listX)), number, (sizeof(listX) / sizeof(*listX)), 0);
    cout << "found index ( total      ) : " << resxxT << "\n";

    return 0;


    unsigned x = 1;
    x <<= 5;
    cout << x << "\n";
    return 0;


    int subSumWithComb[] = {6, 4, -2, -2, 8};
    int targetDetectedForSum = 0;
    int targetForSum = 0;
    CombinationForSum(subSumWithComb, sizeof(subSumWithComb) / sizeof(*subSumWithComb), targetDetectedForSum, "", 0, targetForSum, false);
    cout << "targetForSum : " << targetForSum << ", result Arr (targetDetectedForSum) : " << targetDetectedForSum << "\n";
    return 0;

    string subSumWithCombStr = "123";
    int targetDetectedForSumStr = 0;
    int targetForSumStr = 2;
    CombinationForSumStr(subSumWithCombStr, targetDetectedForSumStr, "", 0, targetForSumStr);
    cout << "result Str:" << targetDetectedForSumStr << "\n";
    return 0;


    int subSum[] = {1, 2, 3}; // it doesn't work with findSubSetXJustForPositiveNumbers because 1's count is different in negative numbers..
    int resSub = findSubSetXJustForPositiveNumbers(subSum, sizeof(subSum) / sizeof(*subSum), 2);
    cout << "result :" << resSub << "\n";
    return 0;

    string combStringx;
    cout << "please enter a text ... \n";
    cin >> combStringx;
    subStrRec(combStringx, "", 0);
    return 0;


    int arrSumGit[] = {2, 8, 3, 9, 6, 5, 4};
    int arrSumPrefixAll[sizeof(arrSumGit) / sizeof(*arrSumGit)] = {};
    prefixSumSmart(arrSumPrefixAll, sizeof(arrSumPrefixAll) / sizeof(*arrSumPrefixAll), arrSumGit);
    int sumForGit = gitSumSmart(arrSumPrefixAll, sizeof(arrSumPrefixAll) / sizeof(*arrSumPrefixAll), 0, 2);
    cout << "gitSum(0,2) : " << sumForGit << "\n";

    sumForGit = gitSumSmart(arrSumPrefixAll, sizeof(arrSumPrefixAll) / sizeof(*arrSumPrefixAll), 1, 3);
    cout << "gitSum(1,3) : " << sumForGit << "\n";

    sumForGit = gitSumSmart(arrSumPrefixAll, sizeof(arrSumPrefixAll) / sizeof(*arrSumPrefixAll), 2, 6);
    cout << "gitSum(2,6) : " << sumForGit << "\n";

    return 0;
    int arrSumArr[] = {1, 12, 3, 41, 5};
    int sumForArr1 = maxSum(arrSumArr, sizeof(arrSumArr) / sizeof(*arrSumArr), 3);
    cout << "max sum by arr : " << sumForArr1 << "\n";

    std::vector<int> arrSum = {1, 12, 3, 41, 5};
    int sumForArrV = maxSum(arrSum, arrSum.size(), 3);
    cout << "max sum by vector: " << sumForArrV << "\n";

    return 0;
    cout << getString(193).empty() ? "true" : "false";
    return 0;

    int arrM[] = {1, 2, 3, 4, 5};
    rotateRight(arrM, sizeof(arrM) / sizeof(*arrM), 2);
    for (int i = 0; i < sizeof(arrM) / sizeof(*arrM); ++i) {
        cout << arrM[i] << "\n";
    }

    return 0;


    reverseArryRec(arrM, sizeof(arrM) / sizeof(*arrM), 0, (sizeof(arrM) / sizeof(*arrM)) - 1);
    for (int i = 0; i < sizeof(arrM) / sizeof(*arrM); ++i) {
        cout << arrM[i] << "\n";
    }
    return 0;

    string combString;
    cout << "please enter a text ... \n";
    cin >> combString;
    subStrRec(combString, "", 0);
    return 0;

    int numDigiSum;
    cout << "please enter a number to sum all digits ... \n";
    cin >> numDigiSum;
    cout << sumRecCaller(numDigiSum) << "\n";
    return 0;


    string palCheck;
    cout << "please enter a text to check whether is palindrome or not ... \n";
    cin >> palCheck;
    cout << (isPalindrome(palCheck, 0, palCheck.length() - 1) ? "true" : "false") << "\n";
    return 0;

    llu pTailNumber;
    cout << "please enter a number to do calculation by tail rec ... \n";
    cin >> pTailNumber;
    cout << tailRecCaller(pTailNumber) << "\n";
    //printrec(5);
    //mirrorPrint(3);
    return 0;

    size_t totalCount = powerGeneration("eralp", 3);
    cout << "Total Element Count : " << totalCount << "\n";
    return 0;


    cout << countSetBit(5) << "\n";
    cout << countSetBit(4) << "\n";

    return 0;


    cout << (isBitSetAtIndex(5, 1) ? "true" : "false") << "\n";
    cout << (isBitSetAtIndex(5, 2) ? "true" : "false") << "\n";
    cout << (isBitSetAtIndex(5, 3) ? "true" : "false") << "\n";

    return 0;


    int pNumber;
    cout << "please enter a number to check whether that is power of 2 or not ... \n";
    cin >> pNumber;
    cout << (powerofTwo(pNumber) ? "true" : "false") << "\n";
    return 0;

    int pConvert;
    std::string pConvertString;
    cout << "Please enter a number to convert from decimal to binary : \n";
    cin >> pConvert;
    cout << "result : " << DecToBinary(pConvert, pConvertString) + "\n";
    return 0;
    long long int num;
    cout << "Please enter your number... \n";
    cin >> num;
    //cout << "Digit Count : " << CountDigit(num) << "\n";
    cout << "Digit Count : " << CountDigitByLog(num) << "\n";

    return 0;

    cout << "executing..\n";
    cout << "looking for ?\n";
    int searchNumberX = -1;
    cin >> number;
    int listXFF[] = {1, 2, 3, 4, 5, 6, 19, 30, 40};
    auto resxxFF = BinarySearchRec(listXFF, 0, (sizeof(listXFF) / sizeof(*listXFF)), searchNumberX);
    cout << "found index ( from 1 ) : " << (resxxFF == -1 ? resxxFF : ++resxxFF) << "\n";
    return 0;

    //auto x{1, 4, 5};
    initializer_list<int> x_{1, 4, 5, 4, 5, 5, 6, 444, 44};
    for (auto pInt = x_.begin(); pInt != x_.end(); ++pInt) {
        cout << *pInt << "\n";
    }
    return 0;

    auto y{12};
    string _a{10, 'A'};
    string _b(10, 'B');
    //cout << _a.length() << "\n";
    //auto list = {1,2,3,4,5};
    for (auto _aIt = _a.begin(); _aIt != _a.end(); ++_aIt) {
        cout << *_aIt << "\n";
    }
    //cout << _b.length() << "\n";
    return 0;
}

int main3() {
    using namespace std;
    multiset<int> _list = {1, 2, 3, 4, 5, 7, 8, 9, 9, 9};
    FindAndDelete(_list, {1, 2, 9});
    for (const auto& item : _list) {
        cout << item << "\n";
    }
    return 0;
}

int main2() {

    Test tte = static_cast<Test>(2);
    std::cout << "tte : " << static_cast<int>(tte) << "\n";
    return 0;

    int dg = 100;
    const int* fzz = &dg;

    return 0;

    char str[7] = "Ahmet\0";

    auto cxxx = "emre";
    auto& chhh = "emre";


    return 0;
    int _eee = 200;
    auto* fzzzz = &_eee;



    //////////////////////// DİKKAT ////////////////////////
    const char* e = "emre";
    auto ex = e; // ex -> const char *
    //////////////////////// DİKKAT ////////////////////////
    const char eggx[5] = "emre";
    auto& ddx = "emre"; // ddx -> const char(&)[5]
    const char (& otherx)[5] = eggx;


    int agggg[]{1, 2, 4, 5, 5};
    auto& ffxx = agggg; // array decay YOK!!!!!
    ffxx[2] = 3000;
    print_arr(agggg, 5);
    int(& copppy)[5] = agggg; // array decay YOK!!!!!
    copppy[0] = 4000;
    print_arr(copppy, 5);
    return 0;

    int* const gaa = nullptr;

    int ffa = 300;
    //gaa = &ffa; ERROR.. It's valid as reference semantic rules!

    int gga = 400;
    int* const ptr = &ffa;
    //ptr = &gg; ERROR ! top level const ( pointer const )
    std::cout << "*ptr : " << (*ptr) << std::endl;

    const int* ptr2 = &ffa;
    ptr2 = &gga; // Low level const!
    std::cout << "*ptr2 : " << (*ptr2) << std::endl;


    return 0;

    int __len = 7;

    int _arx[7]{1, 2, 4, 5, 3, 2, 4};
    int _arz1[7] = {1};
    int _arz2[7]{1};

    print_arr(_arz2, 7);
    return 0;
    int _ary[7]{};

    copyme<int>(_arx, _ary, __len);
    print_arr(_ary, 7);
    return 0;
    char* nameF = "eralp"; // hatalı cünkü sağ taraf const char *!
    int _dde = 200;
    char _axx = 'A';
    std::cout << typeid(_dde).name() << std::endl;
    std::cout << typeid(nameF).name() << std::endl;
    std::cout << typeid(_axx).name() << std::endl;

    char* cnameF = const_cast<char*>(nameF);
    //nameF[0] = 'y'; //BAD_ACCESS_ERR
    //nameF[0] = 'x'; //BAD_ACCESS_ERR
    return 0;
    int sd = 100;
    int hdd = 200;
    const int* pxd = &sd;
    pxd = &hdd;

    hdd = 400;

    //*pxd =3300; pointer to cost!!

    std::cout << "pxd : " << *pxd << std::endl;

    return 0;


    int const _ac = 10;
    const int _bc = 10;

    int _fff = 100;
    int* const agg = &_fff;
    *agg = 300;

    int* gg = &_fff;
    gg = const_cast<int*> (&_ac);
    *gg = 4000;

    const int _fd = 100;
    int* faa = const_cast<int*>(&_fd);
    *faa = 440;
    std::cout << "_fd :" << _fd << std::endl;

    return 0;


    int valuesx[2] = {0, 0};
    int ix = 0;
    valuesx[ix] = ix++; //0,0
    valuesx[ix] = ++ix; //0,1
    PrintX<int>(valuesx, 2);
    return 0;


    int valX = 4;


    std::cout << (valX << 3) << std::endl;

    return 0;

    ZZ z1 = ZZ();
    z1.printA("z1");
    ZZ z2 = ZZ{};
    z1.printA("z2");
    ZZ* z3 = new ZZ;
    z1.printA("z3");
    ZZ* z4 = new ZZ();
    z1.printA("z4");
    ZZ* z5 = new ZZ{};
    z1.printA("z5");

    delete z3;
    delete z4;
    delete z5;

    return 0;
    tex();

    return 0;


    int _f1 = 100;
    int _f2 = 200;
    int _f3 = 300;

    _f1 = _f2 = _f3++;

    std::cout << "_f1 : " << _f1 << ",_f2 : " << _f2 << ",_f3 : " << _f3 << std::endl;

    return 0;

    try {
        throw MyException("val length is 0!!!");
        //std::cout << "total length : " << tt("") << std::endl;
    }
    catch (std::exception& ex) {
        std::cerr << "ERR : " << ex.what() << std::endl;
    }
    return 0;
    int myNumbersForSum[4] = {1, 3, 200};
    auto result = 0;
    try {
        result = SumForMe(myNumbersForSum, sizeof(myNumbersForSum) / sizeof(myNumbersForSum[0]));
    } catch (const unsigned int& errNumber) {
        std::cerr << "ERR - Sum is less than 100..!! it can't be! Total : " << errNumber << std::endl;
    }
    catch (const std::string& errStr) {
        std::cout << "ERR - Sum error is : " << errStr << std::endl;
    }
    catch (...) {
        std::cout << "ERR - Generic error" << std::endl;
    }
    std::clog << "Total : " << result << std::endl;
    return 0;

    Same s = {1, 3};
    std::cout << "sizeof(s)" << sizeof(s) << std::endl;

    return 0;

    s.print();
    Same y;
    y.print();
    y = s;
    y.print();

    Same z = std::move(y);
    Same g;
    g = std::move(z);

    z.print();
    std::cout << "g: " << std::string(g) << std::endl;

    return 0;

    int ddda = (1, 3, 4, 4, 55);
    std::cout << "ddda : " << ddda << std::endl;
    Same* sPtr = &s;
    std::cout << "-----------by variables" << std::endl;
    std::cout << "s.x:" << s.x << std::endl;
    std::cout << "s.y:" << s.y << std::endl;
    std::cout << "-----------by pointer" << std::endl;
    std::cout << "sPtr->x:" << sPtr->x << std::endl;
    std::cout << "sPtr->y:" << sPtr->y << std::endl;
    std::cout << "(*sPtr).x:" << (*sPtr).x << std::endl;
    std::cout << "(*sPtr).y:" << (*sPtr).y << std::endl;

    return 0;


    int arrx[] = {10, 20};
    int* p2 = arrx;
    std::cout << (*p2++) << std::endl;
    return 0;

    int qValue = 100;
    int mValue = 200;
    int fValue = 400;

    const int* _qq1 = &qValue;
    _qq1 = &mValue; // OK
    //*_qq1 = 5000; ERROR!!

    int* const cc = &qValue;
    //cc = &fValue; // ERROR !!

    const int* const dd = &fValue;
    //dd = &mValue; // ERROR !!
    //*dd = 5000; //ERROR!!


    std::cout << *_qq1 << std::endl;

    return 0;

    int* _temp;

    try {
        std::cout << _temp << std::endl;
        std::cout << *_temp << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "errx: " << ex.what() << std::endl;
    }
    return 0;

    int _ddd = 4444;
    std::cout << *(&_ddd) << std::endl;

    char myText[] = {'a', 'b', 'c', 'd', '\0'};
    std::cout << strlen(myText) << std::endl;

    return 0;

    char strx[] = "eralp";
    char* _a1 = &strx[0];
    char* _a2 = &strx[1];
    char* stry[] = {_a1, _a2};
    *_a2 = 'B';


    std::cout << "..first\n";
    for (const auto& item : strx) {
        std::cout << item << std::endl;
    }
    std::cout << "..second\n";
    for (const auto& item : stry) {
        std::cout << *item << std::endl;
    }

    char __a = 'a';
    char* __b = &__a;


    char strz[] = {'a', 'v', 'c'};
    std::cout << strz << std::endl;


    char strz_valid[] = {'a', 'v', 'c', '\0'};
    std::cout << strz_valid << std::endl;


    return 0;

    std::vector<int> _all = {1, 2, 3, 4};
    for (const auto& _item : _all) {
        std::cout << _item << std::endl;
    }


    for (std::vector<int>::iterator it = _all.begin(); it != _all.end(); ++it) {
        std::cout << "iteration value : " << *it << " , adress of it: " << &(*it) << std::endl;
    }
    return 0;
    fx();
    return 0;

    int _a = 10, _b = 20;

    std::cout << (double) _a / _b << std::endl;
    std::cout << static_cast<double>(_a / _b) << std::endl;
    std::cout << static_cast<double>(_a) / static_cast<double>(_b) << std::endl;

    return 0;

    int _f = 1;
    {
        int _f = 2;
        std::cout << "_f : " << _f;
    }
    std::cout << "_f : " << _f;

    return 0;
    int _x, _y;
    std::cout << "Enter X : " << std::endl;
    std::cin >> _x;
    std::cout << "Enter Y : " << std::endl;
    std::cin >> _y;
    std::cout << "Result of (X+Y) : " << _x + _y << std::endl;
    std::clog << "test log" << std::endl;

    return 0;
    char* testM;

    testM = static_cast<char*>(std::malloc(3));
    testM = static_cast<char*>(std::malloc(5));
    return 0;

    return 0;
    int myArr[5] = {1, 3, 43, 4, 3};
    /*
    int* resultQS = quickSort(myArr, sizeof(myArr) / sizeof(myArr[0]));
    for (int i = 0; i < 5; ++i) {
        std::cout << "number : " << resultQS[i] << std::endl;
    }
    delete resultQS;
    */
    int resultx = recSum(myArr, sizeof(myArr) / sizeof(myArr[0]));
    std::cout << "Sum of myArr is : " << resultx << std::endl;
    return 0;

    test{}.speak();
    return 0;

    std::vector<int> iVec = {10}; // 10
    std::vector<int> iVec2(5); // 0,0,0,0,0
    std::vector<int> iVec3(10, 3); // 3,3,3,3,3,3,3,3,3,3
    std::vector<int> iVec4{4, 5, 3}; //4,5,3

    std::cout << "size of ivec4 : " << iVec4.size() << std::endl;
    for (const auto& item : iVec4) {
        std::cout << item << std::endl;
    }
    return 0;


    Person _p10x("era", 1);
    Person _p20x("mam", 2);
    //_p10x = _p20x; // non swap_z & copy ( = op)
    _p10x = std::move(_p20x);


    /*
     * Whe the copy constructor method is active
        custom ctor
        custom ctor
        copy assignment
        destructor
        destructor
     */


    return 0;

    std::function<void(const bool&, const Person&, const Person&)> printMeLong = [&](const bool& print, const Person& p1, const Person& p2) {
        if (print) return;
        p1.Print();
        p2.Print();
    };
    auto printMeAuto = [&](const Person& p1, const Person& p2) {
        p1.Print();
        p2.Print();
    };


    enum type {
        copy, move
    };

    type opType = type::copy;
    if (opType == type::copy) {
        Person _p10("era", 1);
        Person _p11("fatih", 2);
        std::cout << "before swaping.." << std::endl;
        printMeLong(false, _p10, _p11);
        swap_z(_p10, _p11);
        std::cout << "after swaping.." << std::endl;
        printMeLong(false, _p10, _p11);
        // ok but full of cost!
    }
    if (opType == type::move) {
        swap(Person{"era", 1}, Person{"Fatih", 2}, false, printMeLong);
    }


    return 0;
    Person _p1("era", 1);
    Person _p2 = _p1; // call copy constructor!!!
    //_p1.operator=(_p2); // copy assigment ok!
    _p1 = _p2; // call copy assigment!!!
    _p1.setId(500);
    _p2.setId(700);
    _p1.Print();
    _p2.Print();
    return 0;

    std::cout << "sizeof(char) : " << sizeof(char) << ", sizeof(int) : " << sizeof(int) << std::endl;
    return 0;


    Person pa1("eralp", 0);
    Person pa2("era", 1);

    Person pa3 = static_cast<const Person>(pa1);

    return 0;

    Multiply mp4(4);
    std::cout << mp4(5) << std::endl;
    return 0;
    /*
    PrintMF(54);
    PrintMF(MF(44));
    */
    MF vf(44);
    MF xfx;
    xfx = vf;

    MF xfx2;
    xfx2 = std::move(vf);
    PrintMF(vf);
    getchar();

    std::cout << "Application is terminating..." << std::endl;

    return 0;
    try {
        //std::string fm = static_cast<std::string>(p);
        std::string val = std::to_string(generateError(1, 0));
        return 0;
    } catch (std::overflow_error& ex) {
        std::cerr << "catched -> " << ex.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return 0;


    char* p = nullptr;
    try {
        //std::string fm = static_cast<std::string>(p);
        std::string fm = p;
        return 0;
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return 0;

    xf _xf1 = static_cast<xf>(std::string("eee"));
    _xf1.print();
    const char* xc = "eralppp";
    xf _xf2 = static_cast<xf>(xc);
    _xf2.print();
    xf _xf3 = static_cast<xf>("sav");


    _xf3.print();

    return 0;


    return 0;


    int a1 = 200;
    std::cout << "address of a1 (before call)" << &a1 << std::endl;
    a1 = simpleMath(a1);
    std::cout << "address of a1  (after call)" << &a1 << std::endl;

    return 0;
    auto printMe = [](num& xx) -> void {
        std::cout << "xx : " << xx << std::endl;
        std::cout << "xx++ : " << xx++ << std::endl;
        std::cout << "++xx : " << ++xx << std::endl;
        std::cout << "xx : " << xx << std::endl;
    };


    num* num2 = new(std::nothrow)
    num(100);
    if (num2 == nullptr) {
        std::cerr << "Allocation error : " << std::endl;
        return 1;
    }
    printMe(*num2);
    delete num2;


    try {
        num xx{33};
        printMe(xx);
        return 0;
    } catch (std::bad_alloc& err) {
        std::cerr << "ERR : " << err.what() << std::endl;
    }


    int a = Simple_B4(35);
    int ff = sm(int{a});
    std::cout << a << std::endl;
    return 0;


    std::cout << "hello" << std::endl;
    Person px{"test", 1};


    Person px2 = px;

    std::cout << "My Concat Person : " << px + px2 << std::endl;
    return 0;


    PrintP(px2);


    px.Print();
    return 0;
    {
        const char* myText = "eralp";
        //std::cout << "1. The memory address of myText object is " << &myText << std::endl;
        //std::cout << "2. The memory address of myText object is " << static_cast<const void*>(myText) << std::endl;
    }
    return 0;
    const auto dataForMe = []() {
        std::vector<int> _values;
        return _values;
    }();

    M m;
    S s1("ee");
    S s2("ee");

    if (s1 == s2) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
    return 0;

    tr _t;
    std::cout << "tr.mx : " << _t.mx << ", " << "tr.my : " << _t.my << std::endl;

    return 0;
    deleteAndInsert();
    return 0;
    int myNumbers[] = {1, 2, 3};
    Permutation(myNumbers, sizeof(myNumbers) / sizeof(myNumbers[0]));
    return 0;

    std::list<int> myList = {1, 3, 4, 5, 6, 6};
    for (int i = 0; i < myList.size(); ++i) {
        /// ?? std::cout << myList[i] << std::endl;
    }

    return 0;
    std::vector<int> elements = {1, 3, 4, 5, 4};
    callAsArr(&elements[0], elements.size());
    return 0;

    enumerate(1, 5);
    return 0;
    SlowFactCalcLinear(60);
    FastFactCalculator(60);
    return 0;
    T t;
    t.func(12);
    t.func(12u);
    t.func(12.);

    int elementsToSortV1[] = {10, 30, 20, 40, 50, 60, 70};
    int searchV1 = 23;
    int arrLenV1 = sizeof(elementsToSortV1) / sizeof(elementsToSortV1[0]);
    Sort(elementsToSortV1, arrLenV1);
    print_arr(elementsToSortV1, arrLenV1);
    int binSearchResV1 = FindClosestFinder(elementsToSortV1, arrLenV1, searchV1);
    if (binSearchResV1 == -1) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found most closest element index : " << binSearchResV1 << std::endl;
    }
    return 0;

    /*
    int elementsToSort[] = {1, 45, 4, 3, 3, 2, 234, 5};
    int search = 3;
    int arrLen = sizeof(elementsToSort) / sizeof(elementsToSort[0]);
    Sort(elementsToSort, arrLen);
    print_arr(elementsToSort, arrLen);
    int binSearchRes = FirstOccurenceFinder(elementsToSort, arrLen, search);
    if (binSearchRes == -1) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found index : " << binSearchRes << std::endl;
    }
    return 0;

    int targetZeroSumElements[]{-1, 2, 1, -4, 2, 3, -1, 2};
    std::string result0 = sumSubArrayToZero(targetZeroSumElements, sizeof(targetZeroSumElements) / sizeof(targetZeroSumElements[0]));
    std::cout << "result : " << result0 << std::endl;
    return 0;

    char name[4] = "me";
    for (int i = 0; i < (sizeof(name) / sizeof(name[0])); ++i) {
        std::cout << name[i] << std::endl;
    }
    return 0;

    int targetSumElements[]{1, 2, 8, 24, 3, 4};
    std::string result = FindSumArrayTarget(targetSumElements, sizeof(targetSumElements) / sizeof(targetSumElements[0]), 7);
    std::cout << "result : " << result << std::endl;
    return 0;

    int d = 100;
    if (d == 100;d + 2 == 102) {
        std::cout << "d 102" << std::endl;
    }
    std::cout << "d\t" << d << std::endl;
    return 0;

    //int myListProc[] = {2, 4, 1, 0, 3, -1, -1, -1};
    int myListProc[] = {1, 1, 2, 1, 3, 5, 4, 5, 2};
    print_arr(myListProc, 9);
    return 0;


    int getLen = sizeof(myListProc) / sizeof(myListProc[0]);
    reverse<int>(myListProc, getLen);
    printAll(myListProc, getLen);
    return 0;
    simpleZeroRightShifter(myListProc, getLen);
    printAll(myListProc, getLen);
    return 0;
    std::vector<int> arr = {1, -2, 3, 4, -4, 6, -14, 8, 2, 8, -7, 6};
    std::cout << "Max sub array sum :" << maxSubArraySum(arr);
    return 0;

    int listAllItems[] = {1, 2, 3, 4, 5};
    printAll(listAllItems, 5, "", false);
    for (int i = 1; i < 10; ++i) {
        rotateToRight(listAllItems, 5, 1);
        printAll(listAllItems, 5, "", false);
    }
    return 0;

    int listForSort[] = {4, 43, 4, 1, 2, 33, 4, 5, 53, 32, 3};
    int size = sizeof(listForSort) / sizeof(listForSort[0]);
    sortArr(listForSort, size);
    printAll(listForSort, size);
    int indexFound = BinarySearch(listForSort, size, 3);
    if (indexFound != -1) {
        std::cout << "found at " << indexFound << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    return 0;

    std::vector<int> valuesT = test1();
    test4(valuesT);
    for (const auto& item : valuesT) {
        std::cout << item << std::endl;
    }

    return 0;

    int* myNewList = updateMe_CORRECT_1<int>(5);
    printAll<int>(myNewList, 5);
    delete myNewList; // don't forget to call this after finish you job with the object !!!! if you forget then it can cause memory leak problem!
    return 0;

    int myList[30]{1, 2, 3, 4, 5};
    updateMe(myList, 5);
    printAll<int>(myList, 5);
    return 0;

    showListAndSize<int, int>(myList, sizeof(myList) / sizeof(myList[0]));
    std::cout << "-------------" << std::endl;
    printAll<int>(myList, 30);
    return 0;
    addNewNode(nullptr, "__Head__");
    Node* second = addNewNode(_head, "Second");
    addNewNode(second, "Third");
    PrintAllLinkedList(_head);

    FreeAllLinkedList();
        */
    /*
        Node* p = head;
        while (p != nullptr) {
            std::cout << "DATA : " << p->data << ((p->next == nullptr) ? " [TAIL]" : "") << std::endl;
            p = p->next;
        }
        std::cout << "end" << std::endl;
        */    /*


    return 0;
    int arr1[] = {1, 3, 4, 32, 4, 2, 23};
    int arrLenNew = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, arrLenNew);
    for (int i = 0; i < arrLenNew; ++i) {
        std::cout << arr1[i] << std::endl;
    }
    return 0;
    std::vector<int> values = test1();
    //std::vector<int> values2 = test2(values);
    //for (const auto& item : values2) {
    //    std::cout << item << std::endl;
    //}
    test3(values);
    for (const auto& item : values) {
        std::cout << item << std::endl;
    }


    return 0;
    //TestOneArray();
    //int note = 100;
    //int* allScores = TestOneArrayAppend(note);
    //int* allScores = TestOneArrayInsert(note, 4, 5);
    int* allScores = TestOneArrayDelete(3, 5);

    if (allScores != nullptr) {
        for (int i = 0; i < 4; ++i) {
            std::cout << allScores[i] << std::endl;
        }
        delete[] allScores;
    }
    return 0;
    */
}


#pragma clang diagnostic pop