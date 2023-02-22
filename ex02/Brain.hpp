#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
 private:
  std::string ideas_[100];
 public:
  Brain(void);
  Brain(const Brain &copy);
  ~Brain();

  Brain &operator=(const Brain &src);

  const std::string *getIdeas() const;
  void setIdea(int index, std::string idea);
};

#endif