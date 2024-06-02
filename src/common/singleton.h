#pragma once

namespace mkr {
    template <typename T>
    class singleton {
    private:
        static T* instance_;

    public:
        singleton() {}

        virtual ~singleton() {}

        static T& instance() {
            return instance_ ? *instance_ : *(instance_ = new T());
        }

        static void destroy() {
            if (!instance_) { return; }
            delete instance_;
            instance_ = nullptr;
        }
    };

    template <typename T>
    T* singleton<T>::instance_ = nullptr;
} // mkr