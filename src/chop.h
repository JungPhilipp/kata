#include <inttypes.h>
#include <optional>
#include <ranges>
#include <span>

namespace kata {
constexpr auto range_chop(int target, std::span<const int> elements) noexcept
    -> std::optional<size_t> {
  const auto result = std::ranges::find(elements, target);
  const size_t index = result - begin(elements);
  return index < elements.size() ? std::optional(index) : std::nullopt;
}

constexpr auto recursive_chop(int target,
                              std::span<const int> elements) noexcept
    -> std::optional<size_t> {
  if (elements.empty())
    return {};
  const auto pivot_index = elements.size() / 2;
  const auto pivot_element = elements[pivot_index];

  if (pivot_element == target) {
    return {pivot_index};
  } else if (pivot_element < target) {
    return recursive_chop(target, elements.subspan(0, pivot_index));
  } else {
    return recursive_chop(target, elements.subspan(pivot_index))
        .transform([&](const auto e) { return pivot_index + e; });
  }
}
} // namespace kata
