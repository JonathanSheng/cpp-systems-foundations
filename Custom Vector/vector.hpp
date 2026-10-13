#include <cstddef>
#include <initializer_list>
template <typename T>

class Vector {
    private:
        T* elem = nullptr; //pointer to the start of the contiguous array
        int size_ = 0; //Number of active elements in Vector
        int capacity_ = 0; //memory upper bound

    public:

        Vector() = default;

        Vector(int s) {
            elem = new T[s];
            size_ = s;
            capacity_ = s;
        }

        Vector(std::initializer_list<T> list){
            elem = new T[list.size()];
            int i = 0;
            for (const auto& val: list){
                elem[i++] = val;
            }
            size_ = list.size();
            capacity_ = list.size();
        }

        ~Vector(){
            delete[] elem;
            size_ = 0;
            capacity_ = 0;
        };

        //Create a new copy of another Vector, so we need to allocate new object
        //copy constructor
        Vector(const Vector& a) : elem{new T[a.capacity_]}, size_{a.size_}, capacity_{a.capacity_}{
             for (int i = 0; i != size_; ++i){
                elem[i] = a[i];
             }   
        };

        //copy assignment
        //We don't delete elem and then copy since it can error and corrupt existing array
        //worst case it errors and we never set the original array and can try again
        Vector& operator=(const Vector& a){
            if (this == &a){
                return *this;
            }
            T* temp = new T[a.capacity_]; //carve out contiguous a.size_ slots
            for (int i = 0; i < a.size_; ++i){
                temp[i] = a[i];
            }
            delete[] elem;
            elem = temp;
            size_ = a.size_;
            capacity_ = a.capacity_;
            return *this;
        };

        //move constructor
        Vector(Vector&& a) :elem {a.elem}, size_{a.size_}, capacity_{a.capacity_} {
            a.elem = nullptr;
            a.size_ = 0;
            a.capacity_ = 0;
        };

        //move assignment
        //we need to clear existing memory before overwrite
        Vector& operator=(Vector&& a){
            if (this == &a){
                return *this;
            }

            delete[] elem;

            elem = a.elem;
            size_ = a.size_;
            capacity_ = a.capacity_;
            a.elem = nullptr;
            a.size_ = 0;
            a.capacity_ = 0;
            return *this;

        };

        T& operator[](int i){
            return elem[i];
        }

        const T& operator[](int i) const {
            return elem[i];
        }
        
        void pop_back(){
            size_--;
        }
        void push_back(T element){
            if (size_ == capacity_){
                int new_cap = (capacity_ == 0) ? 1: capacity_ * 2;
                T* temp = new T[new_cap];
                for (int i = 0; i < size_; ++i){
                    temp[i] = elem[i];
                }
                delete[] elem;
                elem = temp;
                capacity_ = new_cap;
            }
            elem[size_] = element;
            size_++;
        }

        void reserve(int new_cap){
            if (new_cap <= capacity_){
                return;
            }
            T* temp = new T[new_cap];
            for (int i = 0; i < size_; ++i){
                temp[i] = elem[i];
            }
            delete[] elem;
            elem = temp;
            capacity_ = new_cap;
        }

        void erase(int idx){
            for (int i = idx; i < size_ - 1; ++i){
                elem[i] = elem[i+1];
            }
            size_--;
        }

        void insert(int idx, T value){
            if (size_ == capacity_){
                int new_cap = (capacity_ == 0) ? 1: capacity_ * 2;
                T* temp = new T[new_cap];
                for (int i = 0; i < size_; ++i){
                    temp[i] = elem[i];
                }
                delete[] elem;
                elem = temp;
                capacity_ = new_cap;
            }
            for (int i = size_; i >= idx; --i){
                if (i == idx){
                    elem[i] = value;
                }
                else{
                    elem[i] = elem[i-1];
                }
            }
            size_++;
        }

        void clear(){
            size_ = 0;
        }
        
        T& front(){
            return elem[0];
        }

        const T& front() const{
            return elem[0];
        }

        T& back(){
            return elem[size_ - 1];
        }

        const T& back() const{
            return elem[size_ - 1];
        }

        T* begin(){
            return elem;
        }
        
        const T* begin() const{
            return elem;
        }

        T* end(){
            return elem + size_;
        }

        const T* end() const{
            return elem + size_;
        }
        
        int size() const{
            return size_;
        }

        bool empty() const{
            return size_ == 0;
        }

        int capacity() const{
            return capacity_;
        }
};