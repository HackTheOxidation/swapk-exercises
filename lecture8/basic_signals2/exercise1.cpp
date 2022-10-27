#include <boost/signals2.hpp>
#include <string>
#include <iostream>

void f(const std::string& sensorName, double sensorValue) {
  std::cout << "Free function called\n";
  std::cout << "Sensor: " << sensorName << " measured: " << sensorValue << "\n";
}

struct SensorFunctor {
  void operator()(const std::string& sensorName, double sensorValue) {
    std::cout << "Functor function called\n";
    std::cout << "Sensor: " << sensorName << " measured: " << sensorValue << "\n";
  }
};

class Sensor {
  public:
  void measure(const std::string& sensorName, double sensorValue) const {
    std::cout << "Member function called\n";
    std::cout << "Sensor: " << sensorName << " measured: " << sensorValue << "\n";
  }
};

int main(void) {
  boost::signals2::signal<void (const std::string&, double)> sig;

  // Connect the free function
  sig.connect(&f);

  // Connect the functor
  sig.connect(SensorFunctor());

  // Connect a lambda
  sig.connect([](const std::string& sensorName, double sensorValue){
    std::cout << "Lambda function called\n";
    std::cout << "Sensor: " << sensorName << " measured: " << sensorValue << "\n";
  });

  // Connect a reference object
  Sensor sensor;
  sig.connect([&sensor](const std::string& sensorName, double sensorValue){
    sensor.measure(sensorName, sensorValue);
  });

  auto s = "The dubious sensor";
  double v = 21.9;

  sig(s, v);

  return 0;
}
