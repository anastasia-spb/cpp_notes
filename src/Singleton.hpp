#pragma once

/*
* Example of a singleton design pattern.
*
* Ensure a class has only one instance,
* and provide a global point of access to it.
*/

class Singleton
{
private:
    /* Here will be the instance stored */
    static Singleton* instance;

    /* Private constructor to prevent instancing */
    Singleton();

    /* Private copy constructor */
    Singleton(const Singleton&);

    /* Private copy assignment operator  */
    Singleton& operator=(const Singleton&);

public:
    /* Static access method. */
    static Singleton* getInstance();
};

Singleton* Singleton::instance = nullptr;


/* if no instance were created -> create and initialize AlgoWrapper object
*  otherwise return pointer to existing instance
*/
Singleton* Singleton::getInstance()
{
    Singleton* tmp_instance = instance;
    if (tmp_instance != nullptr)
    {
        return tmp_instance;
    }

    /* insert memory barrier for thread safe implementation:
    *  std::lock_guard<std::mutex> myLock(myMutex);
    */
    tmp_instance = instance;
    /* double-checked locking */
    if (tmp_instance == nullptr)
    {
        tmp_instance = new Singleton();
        instance = tmp_instance;
    }
    return tmp_instance;
};


Singleton::Singleton()
{}