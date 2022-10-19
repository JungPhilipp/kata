#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/chop.h"
#include <array>
#include <optional>
#include <span>

namespace kata::test {
TEST_CASE("Chop") {

  CHECK_EQ(std::nullopt, chop(3, {}));
  CHECK_EQ(std::nullopt, chop(3, std::to_array({1})));
  CHECK_EQ(std::optional(0), chop(1, std::to_array({1})));

  CHECK_EQ(std::optional(0), chop(1, std::to_array({1, 3, 5})));
  CHECK_EQ(std::optional(1), chop(3, std::to_array({1, 3, 5})));
  CHECK_EQ(std::optional(2), chop(5, std::to_array({1, 3, 5})));

  CHECK_EQ(std::nullopt, chop(0, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop(2, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop(4, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop(6, std::to_array({1, 3, 5})));

  CHECK_EQ(std::optional(0), chop(1, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(1), chop(3, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(2), chop(5, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(3), chop(7, std::to_array({1, 3, 5, 7})));

  CHECK_EQ(std::nullopt, chop(0, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop(2, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop(4, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop(6, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop(8, std::to_array({1, 3, 5, 7})));
}
} // namespace kata::test
