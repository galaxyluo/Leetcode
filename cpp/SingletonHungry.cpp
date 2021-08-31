#include <iostream>

class Singleton {
private:
    static Singleton *instance; //静态单例指针
    Singleton();                //私有构造函数
public:
    static Singleton *getInstance();  //公共接口用于获取实例
};

Singleton::Singleton() {
    std::cout << "Create a Singleton." << std::endl;
}

Singleton* Singleton::getInstance() {
    return instance;
}

Singleton *Singleton::instance = new Singleton();