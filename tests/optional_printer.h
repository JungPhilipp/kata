#include "doctest.h"
#include <optional>
#include <sstream>
#include <string_view>

namespace std {
template <class T> auto toString(const std::optional<T> &o) -> doctest::String {
  if (o) {
    return doctest::toString(*o);
  } else {
    return doctest::toString("{}");
  }
}
} // namespace std
