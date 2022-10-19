#include <inttypes.h>
#include <optional>
#include <ranges>
#include <span>

namespace kata {
constexpr auto chop(int target, std::span<const int> elements) noexcept
    -> std::optional<size_t> {
  const auto result = std::ranges::find(elements, target);
  const size_t index = result - begin(elements);
  return index < elements.size() ? std::optional(index) : std::nullopt;
}
} // namespace kata
