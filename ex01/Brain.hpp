#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define IDEA_CNT 100

class Brain {
 private:
  std::string ideas_[IDEA_CNT];
 public:
  Brain(void);
  Brain(const Brain &copy);
  ~Brain();

  Brain &operator=(const Brain &src);

  const std::string *getIdeas() const;
  void setIdea(int index, std::string idea);
};

#endif