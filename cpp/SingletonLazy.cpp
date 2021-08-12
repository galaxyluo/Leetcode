#include <iostream>
#include <mutex>
//#include <pthread.h> 
class Singleton{
private:
    Singleton();                    //私有构造函数
    static Singleton *instance;     //静态单例指针
    static std::mutex mutex;        //用于线程安全
    //static pthread_mutex_t mutex; //另一种加锁方式
public:
    static Singleton *getInstance();
};
Singleton::Singleton() {
    //pthread_mutex_init(&mutex); 锁初始化
    std::cout << "Create a singleton." << std::endl;
}
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {      //先判断单例是否已经创建，提高程序效率
        mutex.lock();
        //pthread_mutex_lock(&mutex);
        if (instance == nullptr) {  //这里需要额外判断一次，避免加锁前瞬间的并发创建冲突
            instance = new Singleton();
        }
        mutex.unlock();
        //pthread_mutex_unlock(&mutex);
    }
    return instance;
}
Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mutex;
//pthread_mutex_t Singleton::mutex;
