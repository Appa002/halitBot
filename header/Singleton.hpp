//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_SINGLETON_HPP
#define MYBOT_SINGLETON_HPP

template<class T> class Singleton{
private:
    static T* instance;
public:
    static T* get(){
        if(!instance)
            instance = new T;
        return instance;
    }

    static void del(){
        if(instance)
            delete instance;
    }
};

template <class T> T* Singleton<T>::instance = 0;

#endif //MYBOT_SINGLETON_HPP
