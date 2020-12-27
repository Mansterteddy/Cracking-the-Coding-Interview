#ifndef KW_DISPLAY_
#define KW_DISPLAY_
#define ECHO(x) std::cout << #x << " = " << (x) << std::endl
namespace KW {
template<typename RI>
void display(RI first, RI last) {
  if (last <= first) return;
  RI itr = first;
  std::cout << *itr++;
  for (; itr != last; ++itr) {
    std::cout << " " << *itr;
  }
}
}
#endif
