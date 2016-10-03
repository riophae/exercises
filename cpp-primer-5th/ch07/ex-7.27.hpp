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
  char get(pos ht, pos wd) const { return contents[calc_pos(ht, wd)]; }
  Screen& set(char c) { contents[cursor] = c; return *this; }
  Screen& set(pos ht, pos wd, char c)
            { contents[calc_pos(ht, wd)] = c; return *this; }
  Screen& move(pos r, pos c) { cursor = calc_pos(r, c); return *this; }
  const Screen& display(std::ostream& os) const
                      { do_display(os); return *this; }
  Screen& display(std::ostream& os)
                { do_display(os); return *this; }

private:
  pos calc_pos(pos r, pos c) const { return r * width + c; }
  void do_display(std::ostream& os) const { os << contents; }
};

class Window_mgr {
private:
  std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
