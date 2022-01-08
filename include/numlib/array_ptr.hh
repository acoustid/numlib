#pragma once

#include "base.hh"

namespace numlib {

template <typename T>
class ArrayPtr {
 public:
  ArrayPtr(T* ptr, size_t size) : ptr_(ptr), size_(size) {}

  T &operator[](size_t i) { return ptr_[i]; }
  const T &operator[](size_t i) const { return ptr_[i]; }

    T* data() { return ptr_; }
    const T* data() const { return ptr_; }

    size_t size() const { return size_; }

 private:
    T* ptr_;
    size_t size_;
};

template <typename T, typename Deletor>
class OwnedArrayPtr {
 public:
    OwnedArrayPtr(T* ptr, size_t size, Deletor d) : ptr_(ptr), size_(size), d_(d) {}

    OwnedArrayPtr(const OwnedArrayPtr& o) = delete;
    OwnedArrayPtr& operator=(const OwnedArrayPtr& o) = delete;
    void operator=(OwnedArrayPtr&& o) = delete;
    
    ~OwnedArrayPtr() {
        d_(ptr_);
    }

    T &operator[](size_t i) { return ptr_[i]; }
    const T &operator[](size_t i) const { return ptr_[i]; }
    
        T* data() { return ptr_; }
        const T* data() const { return ptr_; }
    
        size_t size() const { return size_; }
    
     private:
        T* ptr_;
        size_t size_;
        Deletor d_;
    };

template<typename T>
ArrayPtr<T> Vector(T* ptr, size_t size) {
    return ArrayPtr<T>(ptr, size);
}

template<typename T, typename Deletor>
OwnedArrayPtr<T, Deletor> Vector(T* ptr, size_t size, Deletor d) {
    return OwnedArrayPtr<T, Deletor>(ptr, size, d);
}

} // namespace numlib
