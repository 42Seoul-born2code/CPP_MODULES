#ifndef CONVERTOR_HPP_
#define CONVERTOR_HPP_

#include <string>

class Convertor {
 private:
  std::string value_;
 public:
  Convertor();
  Convertor(const std::string &value);
  Convertor(const Convertor &copy);
  ~Convertor();

  Convertor &operator=(const Convertor &src);

  const std::string &GetValue() const;
  void SetValue(const std::string &value);

  void convert() const;
  void convertChar() const;
  void convertInt() const;
  void convertFloat() const;
  void convertDouble() const;
  bool isNan(double num) const;
  bool isInf(double num) const;
};

#endif //CONVERTOR_HPP_