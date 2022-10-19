#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/chop.h"
#include <array>
#include <optional>
#include <span>

namespace kata::test {
namespace {
template <class chop_t> void test_chop(chop_t chop_function) {
  CHECK_EQ(std::nullopt, chop_function(3, {}));
  CHECK_EQ(std::nullopt, chop_function(3, std::to_array({1})));
  CHECK_EQ(std::optional(0), chop_function(1, std::to_array({1})));

  CHECK_EQ(std::optional(0), chop_function(1, std::to_array({1, 3, 5})));
  CHECK_EQ(std::optional(1), chop_function(3, std::to_array({1, 3, 5})));
  CHECK_EQ(std::optional(2), chop_function(5, std::to_array({1, 3, 5})));

  CHECK_EQ(std::nullopt, chop_function(0, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop_function(2, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop_function(4, std::to_array({1, 3, 5})));
  CHECK_EQ(std::nullopt, chop_function(6, std::to_array({1, 3, 5})));

  CHECK_EQ(std::optional(0), chop_function(1, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(1), chop_function(3, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(2), chop_function(5, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::optional(3), chop_function(7, std::to_array({1, 3, 5, 7})));

  CHECK_EQ(std::nullopt, chop_function(0, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop_function(2, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop_function(4, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop_function(6, std::to_array({1, 3, 5, 7})));
  CHECK_EQ(std::nullopt, chop_function(8, std::to_array({1, 3, 5, 7})));
}
} // namespace
TEST_CASE("Chop") { test_chop(&chop); }
} // namespace kata::test
