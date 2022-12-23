/**
 * @file main.cpp
 * @author Ahmed Hesham
 * @brief A class that simulates the STL vector
 * @version 1.0
 * @date 2022-12-23
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;
/**
 * @brief tepelate class
 * 
 * @tparam T 
 */
template <class T>
class AhmedVector{
 private:
  int size, capacity;
  T* data;
 public:
/**
 * @brief Construct a new Ahmed Vector object
 * 
 */
  AhmedVector():capacity(5),size(0), data (new T[capacity])
  {}
  /**
   * @brief Construct a new Ahmed Vector object
   * 
   * @param cap 
   */
  AhmedVector(int cap){
    capacity = cap;
    size = 0;
    data = new T[capacity];
  }/**
   * @brief Destroy the Ahmed Vector object
   * 
   */
  ~AhmedVector(){
    delete[] data;
  }
  /**
   * @brief to overloaded operator to accec valuue in the vector
   * 
   * @param indx 
   * @return T& 
   */
  T& operator[](int indx){
    if(indx > size-1){
      cout << "An error has occured, index out of range." << endl;
      exit(-1);
    }
    return data[indx];
  }
  /**
   * @brief  pushing values back in the vector
   * 
   * @param item 
   */
  void push_back(T item){
    if(size < capacity){
      data[size++] = item;
    }
    else{
      cout << "Resizing to " << capacity*2 << endl;
      T* newdata = new T[capacity*2];
      capacity *= 2;

      for(int i = 0; i < size; i++){
        newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
      newdata = nullptr;
      data[size++] = item;
    }
  }
/**
 * @brief Construct a new Ahmed Vector object
 * 
 * @param elements 
 * @param value 
 */
  AhmedVector(int elements,T value)
  {
    size = elements;
    capacity = elements+5;
    data = new T[capacity];
    for(int i=0;i<size;i++)
    {
      data[i]=value;
    }
  }
  /**
   * @brief Construct a new Ahmed Vector object
   * 
   * @param other 
   */
  AhmedVector(const AhmedVector&other)
  {
    size=other.size;
    capacity=other.capacity;
    data = new T[capacity];
    for(int i=0;i<size;i++)
    {
      data[i]=other.data[i];
    }


  }
  /**
   * @brief oveloaded opaerator to assign vector to another one
   * 
   * @param other 
   * @return AhmedVector<T>& 
   */
  AhmedVector<T>& operator=(const AhmedVector& other){
    if(other.size>size)
    {
      delete []data;
      capacity = other.size+5;
      data = new T[capacity];
    }
    for(int i=0;i<other.size;i++)
    {
      data[i] = other.data[i];
    }
    size=other.size;
  }
  /**
   * @brief checking if the vector is empty
   * 
   * @return true 
   * @return false 
   */
  bool empty()
  {
    return (size==0);
  }
  /**
   * @brief Get the size object
   * 
   * @return int 
   */
  int get_size()
  {
    return size;
  }
  /**
   * @brief Get the capacity object
   * 
   * @return int 
   */
  int get_capacity()
  {
    return capacity;
  }
  /**
   * @brief checking if 2 vvectors are equal or not
   * 
   * @param other 
   * @return true 
   * @return false 
   */
  bool operator ==(const AhmedVector &other)
  {
    if(size!=other.size)return false;
    for(int i=0;i<size;i++)
    {
      if(data[i]!=other.data[i])return false;
    }
    return true;
  }
  /**
   * @brief checking if 2 vvectors are not equal or not
   * 
   * @param other 
   * @return true 
   * @return false 
   */
  bool operator !=(const AhmedVector &other)
  {
    if(size!=other.size)return true;
    for(int i=0;i<size;i++)
    {
      if(data[i]!=other[i])return true;
    }
    return false;
  }
  /**
   * @brief erasing the last element of the vector
   * 
   */
  void pop_back()
  {
    if(size==0)
    {
      cout<<"Its already empty!"<<endl;
    }
    else {
      size--;
      T* newdata = new T[capacity];
      for(int i = 0; i < size; i++){
        newdata[i] = data[i];
      }
      swap(newdata,data);
      newdata = nullptr;
      delete []newdata;
    }
  }
  /**
   * @brief Construct a new Ahmed Vector object
   * 
   * @param list 
   */
  AhmedVector(const initializer_list<T>&list)
  {
    size = 0;
    capacity = list.size()+5;
    data = new T[capacity];
    for(auto elem:list)
    {
      push_back(elem);
    }
  }
  /**
   * @brief geting element at position "indix"
   * 
   * @param indix 
   * @return T& 
   */
  T& at(int indix)
  {
    if(indix<0||indix>=size)
    {
      cout<<"OUT OF BONDERY"<<endl;
    }
    else{
      return data[indix];
    }
  }
  /**
   * @brief geting the first element of the vector
   * 
   * @return T& 
   */
  T& front()
  {
    return data[0];
  }
  /**
   * @brief inserting element at a spaciefic indix
   * 
   * @param indix 
   * @param val 
   */
  void insert(int indix,T val)
  {
    if(size!=capacity)
    {
      for(int i=size-1;i>=indix;i--)
      {
        data[i+1]=data[i];
      }
      data[indix]=val;
      size++;
    }
    else{
      capacity*=2;
      T* newdata = new T[capacity];
      for(int i = 0; i < size; i++){
        newdata[i] = data[i];
      }
      swap(newdata,data);
      newdata = nullptr;
      delete []newdata;
      insert(indix,val);
    }
  }
  /**
   * @brief erasing element at a spaciefic element
   * 
   * @param indix 
   */
  void erase(int indix)
  {
    if(indix<0||indix>=size)
    {
      cout<<"invalid indix"<<endl;
    }
    else if(size==0)
    {
      cout<<"invalid opaeration"<<endl;
    }
    else{
      for(int i=indix;i<size-1;i++)//1 2 3 4 5 6 7
      {
        data[i]=data[i+1];
      }
      pop_back();

    }
  }
  /**
   * @brief erasing all elements frm the vector
   * 
   */
  void clear()
  {
    size =0;
  }
  /**
   * @brief 
   * 
   * @return T& 
   */
  T&back()
  {
    return data[size-1];
  }
  /**
   * @brief getting the address of the last element of a vector 
   * 
   * @return T* 
   */
  T* begin()
  {
    return &data[0];
  }
  /**
   * @brief  getting the address of the first element of a vector
   * 
   * @return T* 
   */
  T* end()
  {
    return &data[size-1];
  }
/**
 * @brief overloaded operator to print the elements of the vector
 * 
 * @tparam U 
 * @param out 
 * @param my 
 * @return ostream& 
 */
  template<class U>
  friend  ostream & operator << (std::ostream &out,const  AhmedVector<U> &my);



};
/**
 * @brief overloaded operator to print the elements of the vector
 * 
 * @tparam T 
 * @param out 
 * @param my 
 * @return ostream& 
 */
template<class T>
ostream & operator <<(std::ostream &out,const  AhmedVector<T> &my)
{
  for(int i=0;i<my.size;i++)
  {
    out<<my.data[i]<<endl;
  }
  return out;

}
/**
 * @brief the main function
 * 
 * @return int 
 */
int main(){
  AhmedVector <string> vec{"ab","cd","ef","gh","ij"};
  AhmedVector<string>vec2;
  vec2=vec;
 /* vec.push_back((string) "Hello");
  vec.push_back((string) "Neehaw");
  vec.push_back((string) "Bonjour");
  vec.push_back((string) "Guten Tag");
  vec.push_back((string) "Salam Alykum");
  vec.push_back((string) "Hola");
  vec[0] = "Hellooooo";
  */

  /*for(int i = 0; i < vec.get_size(); i++){
    cout << vec[i] << endl;
  }
  cout << endl << endl;
  AhmedVector <string> vec2(vec);
   */

  //vec2[0] = "Salam Alykum231";

  /*for(int i = 0; i < vec2.get_size(); i++){
    cout << vec2[i] << endl;
  }
  vec2[3]="";
  cout<<(vec==vec2)<<endl;
  cout<<vec2;
  */

  //vec.erase(1);
  //vec.insert(1,"4s");
  //cout<<vec;//1 2 3 4 5 6 7 8
  //cout<<vec2;
  cout<<*(vec.end());
}
