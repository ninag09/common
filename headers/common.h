/*  common.h
    Includes basic header files and functions to accept input
    
    Usage:
    input variable from stdin
        T val = in<T>();
    
    input vector
    i)   inputCharVec(vector<char>&, fromFile=false)
    ii)  inputStrVec(vector<string>&, fromFile=false)
    iii) inputIntVec(vector<int>&, fromFile=false)

    input vector from stdin
    i)For INT, CHAR and STR
        vecType<Type, T> v;
        v.inVec<T>(vector<T>& elements);
    ii)other numbers(float,unsigned,double,long,...)
        input(vector<T>& elements);
    
    input vector from file
        vecType<Type, T> v;
        v.inVec<T>(vector<T>& elements, true);

    print vector
    default (bool)format - (false)print horizantally
        printVec<T>(vector<T>& elements,[format]);

    split sentence into words and store in vector as strings
    default (char)delimiter - (' ')space
        splitStrToVec(string& str, vector<string>& elem, [delimiter]);

    read one line from file and store in vector as int
    default (char)delimiter - (' ')space
        intVecFromFile(vector<int>& elem, [delimiter]);
*/

#include <vector>
#include <string>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>
#include "graph.h"
#include "buffers.h"

#if defined __GNUC__
#define likely(x) __builtin_expect ((x), 1)
#define unlikely(x) __builtin_expect ((x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

#ifndef DISABLE_TRACE
#define TRACE(line) std::cout << line << endl;
#define TLINE(line) std::cout << line;
#else
#define TRACE(line) ((void)0);
#define TLINE(line) ((void)0);
#endif
#define OUT(line) std::cout << line;
#define eol std::endl

#ifdef DEBUG_TRACE
#define SET_TRACE() std::ofstream outfile("/Users/Nithesh/test/Log.txt",std::ios::out|std::ios::app);
#define TDEBUG(line) outfile << line;
#else
#define SET_TRACE()
#define TDEBUG(line) ((void)0);
#endif

SET_TRACE();

using std::vector;
using std::string;
using std::list;
using std::queue;
using std::fstream;
using std::stack;
using std::map;
using std::unordered_map;
using std::unordered_set;

const std::string STRING     = "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE";
const std::string INTEGER    = "i";
const std::string CHARACTER  = "c";

enum Type{
    INT,
    STR,
    CHAR
};

void readFile(std::vector<int>&);
void readFile(std::vector<std::string>&, Type type);
void splitStrToVec(std::string&, std::vector<std::string>&, char delim=' ');
void intVecFromFile(std::vector<std::string>&, char delim=' ');

template <class T>
T in(){
    T val;
    std::cin >> val; 
    return val;
};

template <class T>
void inputCharVec(std::vector<T>& vec, bool fromFile=false){
    T t;
    if((typeid(t).name() != CHARACTER) || fromFile){
        std::cout << "Input Failed" << std::endl;
        return;
    }
    while(std::cin >> t){
        if(t == '.') break;
        vec.push_back(t);
    }
    return;
}

template <class T>
void inputStrVec(std::vector<T>& vec, bool fromFile=false){
    T t;
    if(typeid(t).name() != STRING){
        std::cout << "Input Failed" << std::endl;
        return;
    }
    if(fromFile){
        readFile(vec, STR);
        return;
    }
    while(std::cin >> t){
        if(t == ".") break;
        vec.push_back(t);
    }
    return;
}

template <class T>
void inputIntVec(std::vector<T>& vec, bool fromFile=false){
    T t;
    if(typeid(t).name() != INTEGER){ 
        std::cout << "Input Failed" << std::endl;
        return;
    }
    if(fromFile){
        readFile(vec);
        return;
    }
    while(true){
        if(!(std::cin >> t)) break;
        vec.push_back(t);
    }
    return;
}

/* 
//TODO: Do not delete!!
//      above functions depend on GCC typeid implementation      

template <class T>
class Vec{
    public:
        virtual void input(std::vector<T>& vec, bool fromFile=false);
};

template <class T>
class strVec : public Vec<std::string>{
    public:
    void input(std::vector<std::string>& vec,bool fromFile){
        if(fromFile){
            readFile(vec, STR);
            return;
        }
        std::string t;
        while(std::cin >> t){
            if(t == ".") break;
            vec.push_back(t);
        }
        return;
    }
};

// Doesn't work properly with string and char.
// Use template specialization types implemented
// below with Type or use derived class strVec 
template <class T>
void Vec<T>::input(std::vector<T>& vec, bool fromFile){
    if(fromFile){
        readFile(vec);
        return;
    }
    T t;
    while(true){
        if(!(std::cin >> t)) break;
        vec.push_back(t);
    }
    return;
}
*/

template <Type type, class T>
class vecType{
    public:
        void inVec(std::vector<T>& vec, bool fromFile=false);
};

template<>
void vecType<INT, int>::inVec(std::vector<int>& vec, bool fromFile){
    if(!fromFile){
        int t;
        while(true){
            if(!(std::cin >> t)) break;
            vec.push_back(t);
        }
        return;
    }
    readFile(vec);
    return;
}

template<>
void vecType<STR, std::string>::inVec(std::vector<std::string>& vec, bool fromFile){
    if(fromFile){
        readFile(vec, STR);
        return;
    }
    std::string t;
    while(std::cin >> t){
        if(t == ".") break;
        vec.push_back(t);
    }
    return;
}

template<>
void vecType<CHAR, char>::inVec(std::vector<char>& vec, bool fromFile){
    if(fromFile) return;
    char t;
    while(std::cin >> t){
        if(t == '.') break;
        vec.push_back(t);
    }
    return;
}

void readFile(std::vector<int>& vec){
    std::string in_str;
    std::ifstream in_file("/Users/Nithesh/test/input.txt");
    if(in_file.is_open()){
        while(getline(in_file,in_str))
            vec.push_back(stoi(in_str));
        in_file.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return;
}

template <class T>
void printVec(std::vector<T> vec, bool printVertical=false){
    if(!printVertical){
        for(auto i: vec)
            std::cout << i << " ";
        std::cout << std::endl;
        return;
    }
    for(auto i: vec) std::cout << i << std::endl;
}

void readFile(std::vector<std::string>& vec, Type type){
    std::string in_str;
    std::ifstream in_file("/Users/Nithesh/test/input.txt");
    if(in_file.is_open()){
        while(getline(in_file,in_str))
            vec.push_back(in_str);
        in_file.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return;
}

void splitStrToVec(std::string& str, std::vector<std::string>& result, char delim){
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim))
        result.push_back(item);
    return;
}

void intVecFromFile(std::vector<std::string>& result, char delim){
    std::string in_str;
    std::ifstream in_file("/Users/Nithesh/test/input.txt");
    if(in_file.is_open()){
        getline(in_file,in_str);
        in_file.close();
    }
    else{
        std::cout << "Unable to open file" << std::endl;
        return;
    }
    std::stringstream ss(in_str);
    std::string item;
    while (std::getline(ss, item, delim))
        result.push_back((item));
    return;
}

typedef struct graphNode{
    int val;
    std::vector<graphNode*> neigh;
    graphNode(int x): val(x) {};
}graphnode;

typedef struct treeNode{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int x): val(x), left(NULL), right(NULL) {};
}treenode;

typedef struct listNode{
    int val;
    listNode* next;
    listNode* prev;
    listNode(int x): val(x), next(NULL), prev(NULL) {};
}listnode;

