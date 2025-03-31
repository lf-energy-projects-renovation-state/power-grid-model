// SPDX-FileCopyrightText: Contributors to the Power Grid Model project <powergridmodel@lfenergy.org>
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "common.hpp"

#include <ranges>

namespace power_grid_model {

// couting iterator
struct IdxRange : public std::ranges::iota_view<Idx, Idx> {
    using iterator = decltype(std::ranges::iota_view<Idx, Idx>{}.begin());

    IdxRange() = default;
    IdxRange(Idx stop) : std::ranges::iota_view<Idx, Idx>{Idx{0}, stop} {}
    IdxRange(Idx start, Idx stop) : std::ranges::iota_view<Idx, Idx>{start, stop} {}
    IdxRange(iterator start, iterator stop) : std::ranges::iota_view<Idx, Idx>{start, stop} {}
};
using IdxCount = typename IdxRange::iterator;

} // namespace power_grid_model
