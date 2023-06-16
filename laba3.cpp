
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <chrono>
#include <map>
#include <list>
#include <set>

using namespace std;
unsigned int hash1(string key) {
    unsigned int ans = 1;
    for (int i = 0; i < key.size(); i++)
        ans *= (key[i] - 'a');

    return ans;
}

unsigned int hash2(string key) {
    unsigned int ans = 0;

    for (int i = 0; i < key.size(); i++)
        ans = 37 * ans + (key[i] - 'a');

    return ans;
}
class Student {
public:

    string fname;
    string lname;
    string mname;
    string faculty;
    int mark;
    unsigned int getHash1() const;
    unsigned int getHash2() const;
    unsigned int hash_1 = 0, hash_2 = 0;

    Student();
    Student(ifstream& in);
    ~Student();

    Student& operator= (const Student& A);
    friend ostream& operator<< (ostream& out, const Student& A);
};

Student::Student() {
    fname = "";
    lname = "";
    mname = "";
    faculty = "";

    mark = 0;
}

Student::Student(ifstream& in) {
    in >> fname >> lname >> mname >> faculty >> mark;
    hash_1 = hash1(fname);
    hash_2 = hash2(fname);
}

Student::~Student() {

}
unsigned int Student::getHash1() const {
    return hash_1;
}

unsigned int Student::getHash2() const {
    return hash_2;
}
Student& Student::operator= (const Student& A) {
    fname = A.fname;
    lname = A.lname;
    mname = A.mname;
    faculty = A.faculty;
    mark = A.mark;
    hash_1 = A.hash_1;
    hash_2 = A.hash_2;

    return *this;
}

ostream& operator<< (ostream& out, const Student& A) {
    out << A.fname << " ";
    out << A.lname << " ";
    out << A.mname << " ";
    out << A.faculty << " ";
    out << A.mark << " ";

    out << endl;

    return out;
}

bool operator== (const Student& A, const Student& B) {
    return ((A.fname == B.fname) &&
        (A.lname == B.lname) &&
        (A.mname == B.mname) &&
        (A.faculty == B.faculty) &&
        (A.mark == B.mark));
}

bool operator!= (const Student& A, const Student& B) {
    return !(A == B);
}

bool operator> (const Student& A, const Student& B) {
    if (A == B)
        return false;

    if (A.mark != B.mark)
        return (A.mark > B.mark);

    if (A.fname != B.fname)
        return (A.fname > B.fname);

    if (A.lname != B.lname)
        return (A.lname > B.lname);

    if (A.mname != B.mname)
        return (A.mname > B.mname);



    return false;
}

bool operator< (const Student& A, const Student& B) {
    return (A != B && !(A > B));
}

bool operator >= (const Student& A, const Student& B) {
    return (A == B || A > B);
}

bool operator <= (const Student& A, const Student& B) {
    return (A == B || A < B);
}

template <typename T>
void selectSort(T a[], size_t size)
{
    long i, j, k;
    T x;
    for (i = 0; i < size - 1; i++)
    { // i - current step
        k = i;
        x = a[i];
        for (j = i + 1; j < size; j++) // loop for searching minimal element
        {
            if (a[j] < x)
            {
                k = j; x = a[j]; // k - minimal element index
            }
        }
        a[k] = a[i]; a[i] = x; // swap minimal element and a[i]
    }
}


template <typename T>
void bubbleSort(T* A, size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
}

template <typename T>
void shakerSort(T* A, size_t n) {
    long j, k = n - 1;
    long lb = 1, ub = n - 1;
    T x;
    do {
        for (j = ub; j > 0; j--) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
}

template <typename T>
int linearSearch(T* A, size_t n, string keyName) {
    for (size_t i = 0; i < n; i++)
        if (A[i].fname == keyName)
            return i;
    return -1;
}

template <typename T>
int binarySearch(T* A, size_t n, string keyName) {

    size_t left = 0, right = n, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (A[mid].fname == keyName)
            return mid;
        if (A[mid].fname > keyName)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
Student* data100 = new Student[100],
        * data500 = new Student[500],
        * data1000 = new Student[1000],
        * data5000 = new Student[5000],
        * data10000 = new Student[10000],
        * data50000 = new Student[50000],
        * data100000 = new Student[100000];

void readData() {
    ifstream in100("100.txt");
    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Student(in100);
    in100.close();


    ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Student(in500);
    in500.close();

    ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Student(in1000);
    in1000.close();

    ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Student(in5000);
    in5000.close();

    ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Student(in10000);
    in10000.close();

    ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Student(in50000);
    in50000.close();

    ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Student(in100000);
    in100000.close();
}
class HashTable1 {
public:
    Student** table;
    unsigned int sizes[20000] = { 0 };

    HashTable1() {

    }

    HashTable1(Student* data, size_t n) {
        int counter = 0;

        table = new Student * [20000];

        std:: cout << "Creating hash table from data with value of " << n << endl;

        for (size_t i = 0; i < 20000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++) {
            unsigned int hash = hash1(data[i].fname);
            if (table[hash] == nullptr) {
                table[hash] = new Student[1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Student* tmp = new Student[old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        std::cout << counter << " collisions" << endl;
    }
};

class HashTable2 {
public:
    Student** table;
    unsigned int sizes[40000] = { 0 };

    HashTable2() {

    }

    HashTable2(Student* data, size_t n) {
        int counter = 0;

        table = new Student * [40000];

        std::cout << "Creating hash table from data with value of " << n << endl;

        for (size_t i = 0; i < 40000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++) {
            unsigned int hash = hash2(data[i].fname);
            if (table[hash] == nullptr) {
                table[hash] = new Student[1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Student* tmp = new Student[old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        std:: cout << counter << " collisions" << endl;
    }
};

Student findWithHashTable(HashTable1 hashTable, string key) {
    unsigned int hash = hash1(key);

    if (hashTable.table[hash] == nullptr)
        return Student();
    else
    {
        for (int i = 0; i < hashTable.sizes[hash]; i++)
            if (hashTable.table[hash][i].fname == key)
                return hashTable.table[hash][i];
        return Student();
    }
}

Student findWithHashTable(HashTable2 hashTable, string key) {
    unsigned int hash = hash2(key);

    if (hashTable.table[hash] == nullptr)
        return Student();
    else
    {
        for (int i = 0; i < hashTable.sizes[hash]; i++)
            if (hashTable.table[hash][i].fname == key)
                return hashTable.table[hash][i];
        return Student();
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "aldjfaljf" << endl;
    readData();

    std::cout << "Data has read" << endl;

    int choice;

    cout << "Which hash-function you'll test:\n\n1. Simple\n2. Hard\n\n";
    cin >> choice;
    cout << endl << endl;
    if (choice == 1) {
        HashTable1 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

    }
    if (choice == 2) {
        HashTable2 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

    }
}

/*
int main() {
    setlocale(LC_ALL, "Russian");

    Student* data100 = new Student[100],
        * data500 = new Student[500],
        * data1000 = new Student[1000],
        * data5000 = new Student[5000],
        * data10000 = new Student[10000],
        * data50000 = new Student[50000],
        * data100000 = new Student[100000];

    ifstream in100("100.txt");

    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Student(in100);
    in100.close();


    ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Student(in500);
    in500.close();

    ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Student(in1000);
    in1000.close();

    ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Student(in5000);
    in5000.close();

    ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Student(in10000);
    in10000.close();

    ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Student(in50000);
    in50000.close();

    ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Student(in100000);
    in100000.close();

    int choice;
    cout << "Сортировка:\n1. Select sort\n2. Bubble sort\n3. Shaker sort\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        selectSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        selectSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        selectSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        selectSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        selectSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        selectSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        selectSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100select.txt"),
            out500("500select.txt"),
            out1000("1000select.txt"),
            out5000("5000select.txt"),
            out10000("10000select.txt"),
            out50000("50000select.txt"),
            out100000("10000select.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 2) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        bubbleSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        bubbleSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        bubbleSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        bubbleSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        bubbleSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        bubbleSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        bubbleSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100bubble.txt"),
            out500("500bubble.txt"),
            out1000("1000bubble.txt"),
            out5000("5000bubble.txt"),
            out10000("10000bubble.txt"),
            out50000("50000bubble.txt"),
            out100000("10000bubble.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 3) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        shakerSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        shakerSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        shakerSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        shakerSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        shakerSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        shakerSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        shakerSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100shaker.txt"),
            out500("500shaker.txt"),
            out1000("1000shaker.txt"),
            out5000("5000shaker.txt"),
            out10000("10000shaker.txt"),
            out50000("50000shaker.txt"),
            out100000("10000shaker.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    return 0;
}
*/

