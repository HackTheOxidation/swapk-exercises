#include <chrono>
#include <future>
#include <iostream>
#include <iterator>
#include <vector>
#include <thread>
#include <memory>
#include <algorithm>


class Algo
{
public:
  Algo(std::vector<int> v)
    : data_(std::move(v))
  {}
    
  void doAlgo()
  {
    std::chrono::time_point<std::chrono::high_resolution_clock> commence = std::chrono::high_resolution_clock::now();
    std::sort(data_.begin(), data_.end());
    std::chrono::time_point<std::chrono::high_resolution_clock> complete = std::chrono::high_resolution_clock::now();
    duration_ = std::chrono::nanoseconds(complete - commence);
  }
    
  std::chrono::duration<long double> processingTime()
  {
    return duration_;
  }
    
    
  void print()
  {
    std::copy(data_.begin(), data_.end(), std::ostream_iterator<int>(std::cout, " "));
  }
private:
  Algo(const Algo&) = delete; // No copy construction is allowed
    
  Algo& operator=(const Algo&) = delete; // No copy assignment is allowed

  std::vector<int>                    data_;
  std::chrono::nanoseconds            duration_;
};


typedef Algo SmartAlgo;
typedef Algo CoolAlgo;
typedef Algo FantasticAlgo;


int main(int argc, char* argv[])
{
  int i = 0;
  int n = 10000000; // Change at your leasure
    
  std::vector<int> data;
  data.reserve(n);
  generate_n( back_inserter( data ), n, [&i](){return i++;}  );
  random_shuffle( data.begin (), data.end () );

  /* Insert code here ... */
  std::promise<std::shared_ptr<SmartAlgo>> smart_p;
  std::future<std::shared_ptr<SmartAlgo>> smart_f = smart_p.get_future(); 
  std::thread([data](std::promise<std::shared_ptr<SmartAlgo>> p){
    std::shared_ptr<SmartAlgo> algo = std::make_shared<SmartAlgo>(data);
    algo->doAlgo();
    p.set_value_at_thread_exit(algo);
  }, std::move(smart_p)).detach();

  std::promise<std::shared_ptr<CoolAlgo>> cool_p;
  std::future<std::shared_ptr<CoolAlgo>> cool_f = cool_p.get_future(); 
  std::thread([data](std::promise<std::shared_ptr<CoolAlgo>> p){
    std::shared_ptr<CoolAlgo> algo = std::make_shared<CoolAlgo>(data);
    algo->doAlgo();
    p.set_value_at_thread_exit(algo);
  }, std::move(cool_p)).detach();

  std::promise<std::shared_ptr<FantasticAlgo>> fantastic_p;
  std::future<std::shared_ptr<FantasticAlgo>> fantastic_f = fantastic_p.get_future(); 
  std::thread([data](std::promise<std::shared_ptr<FantasticAlgo>> p){
    std::shared_ptr<FantasticAlgo> algo = std::make_shared<FantasticAlgo>(data);
    algo->doAlgo();
    p.set_value_at_thread_exit(algo);
  }, std::move(fantastic_p)).detach();

  smart_f.wait();
  cool_f.wait();
  fantastic_f.wait();

  std::cout << "Done!\nHere are the results:\n";
  std::cout << "SmartAlgo: " << smart_f.get()->processingTime().count() << " ns\n";
  std::cout << "CoolAlgo: " << cool_f.get()->processingTime().count() << " ns\n";
  std::cout << "FantasticAlgo: " << fantastic_f.get()->processingTime().count() << " ns\n";
  
  return 0;
}
