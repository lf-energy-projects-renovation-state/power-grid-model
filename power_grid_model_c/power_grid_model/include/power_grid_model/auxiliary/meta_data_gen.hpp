// SPDX-FileCopyrightText: 2022 Contributors to the Power Grid Model project <dynamic.grid.calculation@alliander.com>
//
// SPDX-License-Identifier: MPL-2.0

#pragma once
#ifndef POWER_GRID_MODEL_META_DATA_GEN_HPP
#define POWER_GRID_MODEL_META_DATA_GEN_HPP

#include <map>
#include <string>

#include "../all_components.hpp"
#include "../power_grid_model.hpp"
#include "input.hpp"
#include "meta_data.hpp"
#include "meta_gen/input.hpp"
#include "meta_gen/output.hpp"
#include "meta_gen/update.hpp"
#include "output.hpp"
#include "update.hpp"

// generate of meta data
namespace power_grid_model {

namespace meta_data {

// template function to add meta data
template <class CT>
void add_meta_data(AllPowerGridMetaData& meta) {
    meta["input"][CT::name] = get_meta<typename CT::InputType>{}();
    meta["update"][CT::name] = get_meta<typename CT::UpdateType>{}();
    meta["sym_output"][CT::name] = get_meta<typename CT::template OutputType<true>>{}();
    meta["asym_output"][CT::name] = get_meta<typename CT::template OutputType<false>>{}();
    meta["sc_output"][CT::name] = get_meta<typename CT::ShortCircuitOutputType>{}();
}

template <class T>
struct MetaDataGeneratorImpl;

template <class... ComponentType>
struct MetaDataGeneratorImpl<ComponentList<ComponentType...>> {
    using FuncPtr = std::add_pointer_t<void(AllPowerGridMetaData& meta)>;
    static constexpr std::array<FuncPtr, sizeof...(ComponentType)> func_arr{&add_meta_data<ComponentType>...};

    static AllPowerGridMetaData create_meta() {
        AllPowerGridMetaData meta{};
        for (auto const func : func_arr) {
            func(meta);
        }
        return meta;
    }
};

using MetaDataGenerator = MetaDataGeneratorImpl<AllComponents>;

inline AllPowerGridMetaData const& meta_data() {
    static AllPowerGridMetaData const meta_data = MetaDataGenerator::create_meta();
    return meta_data;
}

}  // namespace meta_data

}  // namespace power_grid_model

#endif
