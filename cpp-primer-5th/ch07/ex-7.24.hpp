#include <string>
#include <vector>

class Screen {
public:
  using pos = std::string::size_type;

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

public:
  Screen() = default;
  Screen(pos ht, pos wd):
         height(ht), width(wd), contents(ht * wd, ' ') { }
  Screen(pos ht, pos wd, char c):
         height(ht), width(wd), contents(ht * wd, c) { }

  char get() const { return contents[cursor]; }
  char get(pos ht, pos wd) const;
  Screen& move(pos r, pos c);

private:
  pos calc_pos(pos r, pos c) const { return r * width + c; }
};

inline
Screen& Screen::move(pos r, pos c) {
  cursor = calc_pos(r, c);
  return *this;
}

inline
char Screen::get(pos r, pos c) const {
  return contents[calc_pos(r, c)];
}

class Window_mgr {
private:
  std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
