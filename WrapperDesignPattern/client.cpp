#include<iostream>
#include<vector>

using namespace std;

template <typename T>

class VectorWrapper {

    private:
        vector<T> vec;
    

    public:
        VectorWrapper() {}
        ~VectorWrapper() {}

        void addElement(const T& element)
        {
            //in this we can check the specifc condition for pushing in vector:
            vec.push_back(element);
        }

        size_t getSize() const {
            return vec.size();
        }

        void print() const {
            for (const auto element: vec)
            {
                cout<<element<<" ";
            }
            cout<<endl;
        }
};


int main(){
    VectorWrapper<int> intVectorWrapper;

    intVectorWrapper.addElement(10);
    intVectorWrapper.addElement(20);

    cout<<"size of vector is: "<<intVectorWrapper.getSize()<<endl;

    return 0;
}