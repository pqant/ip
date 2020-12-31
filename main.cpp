#include <iostream>

void TestOneArray() {
    int students_score[5] = {15, 33, 44, 22, 66};
    for (int i = 0; i < sizeof(students_score) / sizeof(students_score[0]); ++i) {
        std::cout << students_score[i] << std::endl;
    }
}

int* GenerateTestOneArray(const int& size) {
    int* students_score = new int[size]{15, 33, 44, 22, 66};
    return students_score;
}


int* TestOneArrayAppend(const int& score, const int arrLength) {
    int* oldScores = GenerateTestOneArray(arrLength);
    int* newScores = new int[arrLength + 1];
    for (int i = 0; i < arrLength; ++i) {
        newScores[i] = oldScores[i];
    }
    newScores[arrLength] = score;
    delete[] oldScores;
    return newScores;
}

#include "vector"

void TakeUnlimitedValuesFromTheUser() {
    std::vector<int> vec;

    // read integers 1 at a time from the user,
    // will stop when non-integer input is entered
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(vec));

    // print out the vector
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

int* TestOneArrayInsert(const int& value, int index, int arrLength) {
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

int* TestOneArrayDelete(int index, int arrLength) {
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

std::vector<int> test1() {
    std::vector<int> t;
    t.emplace_back(1);
    t.emplace_back(3);
    return t;
}

std::vector<int>& test2(std::vector<int>& t) {
    //never use a local value to send outside. it can cause dangling problem!
    t.emplace_back(4);
    t.emplace_back(5);
    return t;
}

void test3(std::vector<int>& t) {
    t.emplace_back(6);
    t.emplace_back(7);
}

void test4(std::vector<int> t) {
    t.emplace_back(60);
    t.emplace_back(70);
}


void bubble_sort(int elements[], int arrLen) {
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
    for (int i = 0; i < a.size(); i++) {
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
    int startIndex = 0, end = 0, total = elements[startIndex];
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

#include "unordered_map";

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


int main() {
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
    /*
    Node* p = head;
    while (p != nullptr) {
        std::cout << "DATA : " << p->data << ((p->next == nullptr) ? " [TAIL]" : "") << std::endl;
        p = p->next;
    }
    std::cout << "end" << std::endl;
    */

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
}

